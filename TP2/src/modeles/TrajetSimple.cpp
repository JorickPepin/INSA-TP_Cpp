/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple& TrajetSimple::operator=(const TrajetSimple& trajetSimple_) {
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple& trajetSimple_) {
    #ifdef MAP
        std::cout <<
            "Appel au constructeur de copie de <TrajetSimple>" << std::endl;
    #endif
}

TrajetSimple::TrajetSimple() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetSimple>" << std::endl;
    #endif
}

TrajetSimple::~TrajetSimple() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <TrajetSimple>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
