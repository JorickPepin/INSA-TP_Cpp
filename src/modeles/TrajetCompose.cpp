/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose& TrajetCompose::operator=(const TrajetCompose& _trajetCompose) {
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose& _trajetCompose) {
    #ifdef MAP
        std::cout <<
            "Appel au constructeur de copie de <TrajetCompose>" << std::endl;
    #endif
}

TrajetCompose::TrajetCompose() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetCompose>" << std::endl;
    #endif
}

TrajetCompose::~TrajetCompose() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <TrajetCompose>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
