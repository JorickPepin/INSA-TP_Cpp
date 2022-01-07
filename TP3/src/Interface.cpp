/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 24/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Interface> (fichier Interface.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Interface.h"
#include "serialisation/Sauvegarde.h"
#include "serialisation/Chargement.h"
#include "modeles/TrajetSimple.h"
#include "modeles/TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Interface::AfficherBienvenue() {
    std::cout << "----------------------- Catalogue -----------------------" << std::endl;
    std::cout << "Bienvenue sur votre catalogue, que souhaitez-vous faire ?" << std::endl;
}

void Interface::AfficherFin() {
    std::cout << "\nFin du programme, à bientôt !" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

void Interface::AfficherMenu() {
    std::cout << "\n0: Quitter" << std::endl;
    std::cout << "1: Ajouter un trajet" << std::endl;
    std::cout << "2: Afficher les trajets" << std::endl;
    std::cout << "3: Rechercher un trajet" << std::endl;
    std::cout << "4: Sauvegarder le catalogue" << std::endl;
    std::cout << "5: Charger un catalogue\n" << std::endl;
}

void Interface::AfficherMauvaisChoix() {
    std::cout << "\nVotre choix ne correspond à aucune commande." << std::endl;
}

void Interface::AjouterTrajet(Liste* catalogue_) {
    std::cout << "\nQuel type de trajet souhaitez-vous créer ?\n" << std::endl;
    std::cout << "s: Simple" << std::endl;
    std::cout << "c: Composé" << std::endl;
    std::cout << "q: Retourner au menu\n" << std::endl;

    char choix[TAILLE_MAX];

    std::cout << "Choix : ";
    std::cin >> choix;

    switch (choix[0]) {
        case 's':
            ajouterTrajetSimple(catalogue_);
            break;
        case 'c':
            ajouterTrajetCompose(catalogue_);
            break;
        case 'q':
            break;
        default:
            AfficherMauvaisChoix();
            break;
    }
}

void Interface::AfficherTrajets(Liste* catalogue_) {
    if (catalogue_->EstVide()) {
        std::cout << "\nLe catalogue est vide." << std::endl;
    } else {
        std::cout << "\nLe catalogue contient les trajets suivants :" << std::endl;
        catalogue_->Afficher();
    }
}

void Interface::RechercherTrajet(Liste* catalogue_) {
    char villeDepart[TAILLE_MAX];
    char villeArrivee[TAILLE_MAX];

    std::cout << "\nRecherche d'un trajet" << std::endl;

    std::cout << "- Ville de départ : ";
    std::cin >> villeDepart;

    std::cout << "- Ville d'arrivée : ";
    std::cin >> villeArrivee;

    bool trajetTrouve = false;

    if (catalogue_->EstVide()) {
        std::cout << "\nLe catalogue est vide." << std::endl;
    } else {
        Element* courant = catalogue_->GetPremier();

        bool correspond;
        while (courant) {
            correspond = courant->GetTrajet()->Correspond(villeDepart, villeArrivee);

            if (correspond) {
                if (!trajetTrouve) {
                    std::cout << "\nTrajet(s) trouvé(s) :" << std::endl;
                }

                std::cout << " ";
                courant->Afficher();
                std::cout << std::endl;

                trajetTrouve = true;
            }

            courant = courant->GetSuivant();
        }
    }

    if (!trajetTrouve) {
        std::cout << "\nAucun trajet n'a été trouvé." << std::endl;
    }
}

void Interface::SauvegarderCatalogue(Liste* catalogue_) {

    if (catalogue_->EstVide()) {
        std::cout << "\nVous ne pouvez pas sauvegarder un catalogue vide." << std::endl;
        return;
    }

    std::string nomFichier = recupererNomFichier();

    if (nomFichier.empty()) {
        return;
    }

    int choix;

    std::cout << "\nQuel type de sauvegarde souhaitez-vous utiliser ?\n" << std::endl;
    std::cout << "0: Quitter" << std::endl;
    std::cout << "1: Sauvegarder tous les trajets" << std::endl;
    std::cout << "2: Sauvegarder un certain type de trajet" << std::endl;
    std::cout << "3: Sauvegarder pour une certaine ville de départ et/ou d'arrivée\n" << std::endl;

    std::cout << "Choix : ";
    std::cin >> choix;

    switch (choix) {
        case 0:
            break;
        case 1:
            Sauvegarde::SauvegarderSansCritere(*catalogue_, nomFichier);
            break;
        case 2:
            std::cout << "\nQuel type de trajet souhaitez-vous sauvegarder ?\n" << std::endl;
            std::cout << "0: Quitter" << std::endl;
            std::cout << "1: Simple" << std::endl;
            std::cout << "2: Composé\n" << std::endl;

            std::cout << "Choix : ";
            std::cin >> choix;

            switch (choix) {
                case 0:
                    break;
                case 1:
                    Sauvegarde::SauvegarderSelonType(*catalogue_, nomFichier, TypeTrajet::Simple);
                    break;
                case 2:
                    Sauvegarde::SauvegarderSelonType(*catalogue_, nomFichier, TypeTrajet::Compose);
                    break;
            }
            break;
        case 3:
        {
            std::string villeDepart;
            std::string villeArrivee;

            std::cout << "\nQuelles villes souhaitez-vous sauvegarder ? (laisser vide pour ignorer)\n" << std::endl;

            std::cin.ignore();

            std::cout << "Ville de départ : ";
            std::getline(std::cin, villeDepart);

            std::cout << "Ville d'arrivée : ";
            std::getline(std::cin, villeArrivee);

            if (villeDepart.empty() && villeArrivee.empty()) {
                std::cout << "\nVous devez préciser au moins une ville." << std::endl;
                break;
            }

            Sauvegarde::SauvegarderSelonVilles(*catalogue_, nomFichier, villeDepart, villeArrivee);
            break;
        }
        default:
            Interface::AfficherMauvaisChoix();
            break;
    }
}

void Interface::ChargerCatalogue(Liste* catalogue_) {
    std::string nomFichier = recupererNomFichier();

    if (nomFichier.empty()) {
        return;
    }

    int choix;

    std::cout << "\nQuel type de chargement souhaitez-vous utiliser ?\n" << std::endl;
    std::cout << "0: Quitter" << std::endl;
    std::cout << "1: Charger le catalogue en entier" << std::endl;
    std::cout << "2: Charger seulement un certain type de trajet" << std::endl;
    std::cout << "3: Charger les trajets selon une certaine ville de départ et/ou d'arrivée\n" << std::endl;

    std::cout << "Choix : ";
    std::cin >> choix;

    switch (choix) {
        case 0:
            break;
        case 1:
            Chargement::ChargerSansCritere(*catalogue_, nomFichier);
            break;
        case 2:
            std::cout << "\nQuel type de trajet souhaitez-vous charger ?\n" << std::endl;
            std::cout << "0: Quitter" << std::endl;
            std::cout << "1: Simple" << std::endl;
            std::cout << "2: Composé\n" << std::endl;

            std::cout << "Choix : ";
            std::cin >> choix;

            switch (choix) {
                case 0:
                    break;
                case 1:
                    Chargement::ChargerSelonType(*catalogue_, nomFichier, TypeTrajet::Simple);
                    break;
                case 2:
                    Chargement::ChargerSelonType(*catalogue_, nomFichier, TypeTrajet::Compose);
                    break;
            }
            break;
        case 3:
        {
            std::string villeDepart;
            std::string villeArrivee;

            std::cout << "\nQuelles villes souhaitez-vous charger ? (laisser vide pour ignorer)\n" << std::endl;

            std::cin.ignore();

            std::cout << "Ville de départ : ";
            std::getline(std::cin, villeDepart);

            std::cout << "Ville d'arrivée : ";
            std::getline(std::cin, villeArrivee);

            if (villeDepart.empty() && villeArrivee.empty()) {
                std::cout << "\nVous devez préciser au moins une ville." << std::endl;
                break;
            }

            Chargement::ChargerSelonVilles(*catalogue_, nomFichier, villeDepart, villeArrivee);
            break;
        }
        default:
            Interface::AfficherMauvaisChoix();
            break;
    }
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
void Interface::ajouterTrajetSimple(Liste* catalogue_) {
    char villeDepart[TAILLE_MAX];
    char villeArrivee[TAILLE_MAX];
    char transport[TAILLE_MAX];

    std::cout << "\nCréation d'un trajet simple" << std::endl;

    std::cout << "- Ville de départ : ";
    std::cin >> villeDepart;

    std::cout << "- Ville d'arrivée : ";
    std::cin >> villeArrivee;

    std::cout << "- Moyen de transport : ";
    std::cin >> transport;

    TrajetSimple* trajet = new TrajetSimple(
        transport, villeDepart, villeArrivee);

    catalogue_->Ajouter(trajet);
}

void Interface::ajouterTrajetCompose(Liste* catalogue_) {
    Liste* trajets = new Liste();

    char villeDepart[TAILLE_MAX];
    char villeArrivee[TAILLE_MAX];
    char transport[TAILLE_MAX];

    std::cout << "\nCréation d'un trajet composé" << std::endl;

    std::cout << "- Ville de départ : ";
    std::cin >> villeDepart;

    for ( ; ; ) {  // on boucle tant que l'utilisateur continue d'ajouter des trajets
        std::cout << "- Ville suivante (ou 'q' pour arrêter la saisie) : ";
        std::cin >> villeArrivee;

        // l'utilisateur saisit la lettre "q" -> il souhaite arrêter la saisie
        if (strcmp(villeArrivee, "q") == 0) {
            break;
        }

        std::cout << "- Moyen de transport : ";
        std::cin >> transport;

        trajets->Ajouter(new TrajetSimple(transport, villeDepart, villeArrivee));

        // la ville de départ du nouveau trajet devient la ville d'arrivée de l'ancien
        strcpy(villeDepart, villeArrivee);
    }

    if (trajets->Taille() > 0) {  // l'utilisateur a saisi au moins un trajet
        catalogue_->Ajouter(new TrajetCompose(trajets));
    }
}

std::string Interface::recupererNomFichier() {
    std::string nomFichier;

    std::cout << "\nVeuillez entrer un nom de fichier (ou 'q' pour quitter) :\n" << std::endl;
    std::cout << "Nom : ";

    std::cin >> nomFichier;

    if (nomFichier == "q") {
        return "";
    }

    if (nomFichier.find('.') != std::string::npos) {  // un point est présent dans le nom du fichier
        std::cout << "\nLe nom du fichier ne peut pas contenir de caractères '.'." << std::endl;
        return recupererNomFichier();
    }

    return nomFichier + ".json";
}
