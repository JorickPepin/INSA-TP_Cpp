/*************************************************************************
                           SiteGraph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SiteGraph> (fichier SiteGraph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "SiteGraph.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type SiteGraph::Méthode(liste des paramètres) {
//}


//------------------------------------------------- Surcharge d'opérateurs
SiteGraph & SiteGraph::operator=(const SiteGraph& _SiteGraph) {
}

//-------------------------------------------- Constructeurs - destructeur
SiteGraph::SiteGraph(const SiteGraph& _SiteGraph) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <SiteGraph>" << std::endl;
    #endif
}

SiteGraph::SiteGraph() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <SiteGraph>" << std::endl;
    #endif
}

SiteGraph::~SiteGraph() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <SiteGraph>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
