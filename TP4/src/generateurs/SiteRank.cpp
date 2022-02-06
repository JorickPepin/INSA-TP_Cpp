/*************************************************************************
                           SiteRank  -  Ranking des sites selon le nombre de hits
                             -------------------
    début                : 03/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <SiteRank> (fichier SiteRank.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <utility>
//------------------------------------------------------ Include personnel
#include "SiteRank.h"

//------------------------------------------------------------------ Types
using iterator = std::unordered_map<std::string, unsigned int>::const_iterator;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void SiteRank::Add1HittoSite(const std::string & site) {
    // insert si n'est pas dedans (avec initialisation à 0), puis incrémente
    ++hitsBySite[site];
    needSwapMap = true;
}

std::ostream & SiteRank::PrintRank(std::ostream & os,
                                   unsigned int nbDisplayed) {
    std::multimap<unsigned int, const std::string *>::const_reverse_iterator it;
    unsigned int i(0);

    // umap -> multi_map
    swapMap();

    os << "Top " << nbDisplayed << " :\n";

    // TODO est ce qu'on affiche les 10 premier (y compris les exe aequo ?)
    for (it = siteRankbyHits.crbegin(); it != siteRankbyHits.crend()
                                        && i < nbDisplayed; ++it, ++i) {
        os << *it->second << " (" << it->first << " requête" << (it->first > 1 ? "s)" : ")") << '\n';
    }

    return os;
}

//------------------------------------------------- Surcharge d'opérateurs
std::ostream & operator << (std::ostream & os, const SiteRank & sr) {
    iterator it;
    for (it = sr.hitsBySite.cbegin(); it != sr.hitsBySite.cend(); ++it) {
        os << it->first << ':' << it->second << '\n';
    }
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
SiteRank::SiteRank() : needSwapMap(true) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <SiteRank>" << std::endl;
    #endif
}

SiteRank::~SiteRank() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <SiteRank>" << std::endl;
    #endif
    // pas de new => pas de delete
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
void SiteRank::swapMap() {
    if (!needSwapMap) {  // if no changed made
        return;
    }

    // don't need to free the pointers contained in 'siteRankByHits' multimap,
    // because they are still stored in 'hitsBySite' and will be deleted when
    siteRankbyHits.clear();

    for (iterator it = hitsBySite.cbegin(); it != hitsBySite.cend(); ++it) {
        siteRankbyHits.insert(std::make_pair(it->second, &(it->first)));
    }
    needSwapMap = false;
}
