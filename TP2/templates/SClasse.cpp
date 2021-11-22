/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Xxx.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode(liste des paramètres) {
//}


//------------------------------------------------- Surcharge d'opérateurs
Xxx & Xxx::operator=(const Xxx& _Xxx) {
}

//-------------------------------------------- Constructeurs - destructeur
Xxx::Xxx(const Xxx& _Xxx) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <Xxx>" << std::endl;
    #endif
}

Xxx::Xxx() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Xxx>" << std::endl;
    #endif
}

Xxx::~Xxx() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Xxx>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
