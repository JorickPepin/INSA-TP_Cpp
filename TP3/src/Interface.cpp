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
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Interface.h"
#include "Sauvegarde.h"
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
    std::cout << "4: Sauvegarder le catalogue\n" << std::endl;
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
    int choix;

    do {
        std::cout << "\nQuel type de sauvegarde souhaitez-vous utiliser ?\n" << std::endl;
        std::cout << "0: Quitte" << std::endl;
        std::cout << "1: Sauvegarder sans critère" << std::endl;
        std::cout << "2: Sauvegarder un certain type de trajet\n" << std::endl;

        std::cout << "Choix : ";
        std::cin >> choix;

        switch (choix) {
            case 0:
                break;
            case 1:
                Sauvegarde::SauvegarderSansCritere(*catalogue_, "test");
                break;
            case 2:
                break;
            default:
                Interface::AfficherMauvaisChoix();
                break;
        }
    } while (choix != 0);

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
