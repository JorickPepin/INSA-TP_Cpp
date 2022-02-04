/*************************************************************************
                           SiteGraph  -  description
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
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
