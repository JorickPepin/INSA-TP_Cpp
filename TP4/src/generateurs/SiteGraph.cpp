/*************************************************************************
                           SiteGraph  -  Représente un graph de site
                             -------------------
    début                : 03/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//----- Réalisation de la classe <SiteGraph> (fichier SiteGraph.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "SiteGraph.h"

//------------------------------------------------------------------ Types
using iterator_simple = std::unordered_map<std::string, unsigned int>::const_iterator;
using iterator_double = std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>>::const_iterator;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void SiteGraph::AddSite(const std::string & referant,
                        const std::string & cible) {
    ++graph[referant][cible];
}

std::ostream & SiteGraph::PrintDotGraphTo(std::ostream & os) const {
    iterator_double it1;
    iterator_simple it2;

    os << "digraph{\n";
    for (it1 = graph.cbegin(); it1 != graph.cend(); ++it1) {
        for (it2 = it1->second.cbegin(); it2 != it1->second.cend(); ++it2) {
            // WARNING le format pourrait ne pas être valide un site contient
            // un ", mais normalement ce n'est pas possible
            // (http://www.faqs.org/rfcs/rfc1738.html)
            // format DOT: "   "referant" -> "cible" [label="unsigned int"]\n"
            os << "\t\"" << it1->first << "\"" << " -> \""<< it2->first
               << "\"[label=\"" << it2->second <<"\"]\n";
        }
    }
    os << "}\n";
    return os;
}

//------------------------------------------------- Surcharge d'opérateurs
std::ostream & operator << (std::ostream & os, const SiteGraph & _SiteGraph) {
    iterator_double it1;
    iterator_simple it2;

    for (it1 = _SiteGraph.graph.cbegin(); it1 != _SiteGraph.graph.cend(); ++it1) {
        os << it1->first << '\n';
        for (it2 = it1->second.cbegin(); it2 != it1->second.cend(); ++it2) {
            os << "\t" << it2->first << " : " << it2->second << '\n';
        }
    }
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
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
