/*************************************************************************
                           SiteRank  -  Ranking des sites selon le nombre de hits
                             -------------------
    début                : 03/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SiteRank> (fichier SiteRank.h) ------
#ifndef SRC_SITERANK_H_
#define SRC_SITERANK_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <ostream>
#include <string>
#include <unordered_map>

//------------------------------------------------------------------------
// Rôle de la classe <SiteRank>
// Génère un classement des ressources les plus demandées.
//------------------------------------------------------------------------

class SiteRank {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Add1HittoSite(const std::string & site);

    std::ostream & PrintRank(std::ostream & os, unsigned int nbDisplayed = 10);

    friend std::ostream & operator << (std::ostream & os, const SiteRank & sr);

    //------------------------------------------------- Surcharge d'opérateurs
    SiteRank & operator = (const SiteRank & _SiteRank);

    //-------------------------------------------- Constructeurs - destructeur
    SiteRank(const SiteRank & _SiteRank);

    SiteRank();

    virtual ~SiteRank();

 private:
    //------------------------------------------------------- Méthodes privées
    /**
     * @brief Permet de transformer l'unordered map en multimap pour pouvoir
     * afficher le classement.
     */
    void swapMap();

    //------------------------------------------------------- Attributs privés
    std::unordered_map<std::string, unsigned int> hitsBySite;

    bool needSwapMap;
    std::multimap<unsigned int, const std::string *> siteRankbyHits;
};

#endif  // SRC_SITERANK_H_
