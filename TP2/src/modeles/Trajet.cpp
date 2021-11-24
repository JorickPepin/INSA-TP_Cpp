/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
Trajet& Trajet::operator=(const Trajet& catalogue_) {
}

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet(const Trajet& trajet_) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <Trajet>" << std::endl;
    #endif
}

Trajet::Trajet() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Trajet>" << std::endl;
    #endif
}

Trajet::~Trajet() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Trajet>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
