/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
void Interface::AfficherMenu() {
    std::cout << "0: Quitter" << std::endl;
    std::cout << "1: Ajouter un trajet" << std::endl;
    std::cout << "2: Afficher les trajets" << std::endl;
}

void Interface::AjouterTrajet(Liste* catalogue_) {
    std::cout << "Quel type de trajet souhaitez-vous créer ?" << std::endl;
    std::cout << "s: Simple" << std::endl;
    std::cout << "c: Composé" << std::endl << std::endl;
    std::cout << "q: Retour au menu" << std::endl;

    char choix[TAILLE_MAX];
    std::cin >> choix;

    switch (choix[0]) {
        case 's':
            AjouterTrajetSimple(catalogue_);
            break;
        case 'c':
            AjouterTrajetCompose(catalogue_);
            break;
        case 'q':
            break;
        default:
            std::cout << "pas la bonne commande" << std::endl;
            break;
    }
}

void Interface::AfficherTrajets(Liste* catalogue_) {
    std::cout << "Le catalogue contient les trajets suivants :" << std::endl;

    catalogue_->Afficher();
}

//------------------------------------------------- Surcharge d'opérateurs
Interface & Interface::operator=(const Interface& interface_) {
}

//-------------------------------------------- Constructeurs - destructeur
Interface::Interface(const Interface& interface_) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <Interface>"
            << std::endl;
    #endif
}

Interface::Interface() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Interface>" << std::endl;
    #endif
}

Interface::~Interface() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Interface>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Interface::AjouterTrajetSimple(Liste* catalogue_) {
    char villeDepart[TAILLE_MAX];
    char villeArrivee[TAILLE_MAX];
    char transport[TAILLE_MAX];

    std::cout << "Ville de départ : ";
    std::cin >> villeDepart;

    std::cout << "Ville d'arrivée : ";
    std::cin >> villeArrivee;

    std::cout << "Moyen de transport : ";
    std::cin >> transport;

    TrajetSimple* trajet = new TrajetSimple(
        transport, villeDepart, villeArrivee);

    catalogue_->Ajouter(trajet);
}

void Interface::AjouterTrajetCompose(Liste* catalogue_) {
    // TODO(*): implémenter
}
