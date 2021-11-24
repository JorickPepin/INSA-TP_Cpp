/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
Catalogue& Catalogue::operator=(const Catalogue& catalogue_) {
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(const Catalogue& catalogue_) {
    #ifdef MAP
        std::cout <<
            "Appel au constructeur de copie de <Catalogue>" << std::endl;
    #endif
}

Catalogue::Catalogue() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Catalogue>" << std::endl;
    #endif
}

Catalogue::~Catalogue() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Catalogue>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
