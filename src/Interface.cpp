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
#include "modeles/TrajetSimple.h"
//------------------------------------------------------------- Constantes

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
    std::cout << "2: Afficher les trajets\n" << std::endl;
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
    std::cout << "\nLe catalogue contient les trajets suivants :" << std::endl;

    catalogue_->Afficher();
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
    // TODO(*): implémenter
}
