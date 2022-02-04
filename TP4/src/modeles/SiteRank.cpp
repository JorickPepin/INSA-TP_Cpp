/*************************************************************************
                           SiteRank  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SiteRank> (fichier SiteRank.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "SiteRank.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type SiteRank::Méthode(liste des paramètres) {
//}


//------------------------------------------------- Surcharge d'opérateurs
SiteRank & SiteRank::operator=(const SiteRank& _SiteRank) {
}

//-------------------------------------------- Constructeurs - destructeur
SiteRank::SiteRank(const SiteRank& _SiteRank) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <SiteRank>" << std::endl;
    #endif
}

SiteRank::SiteRank() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <SiteRank>" << std::endl;
    #endif
}

SiteRank::~SiteRank() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <SiteRank>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
