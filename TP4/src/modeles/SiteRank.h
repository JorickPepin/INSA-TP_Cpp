/*************************************************************************
                           SiteRank  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <SiteRank> (fichier SiteRank.h) ----------------
#ifndef SiteRank_H_
#define SiteRank_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <ostream>
#include <string>
#include <unordered_map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SiteRank>
//
//
//------------------------------------------------------------------------

class SiteRank {
 public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void add1HittoSite(const std::string & site);
    // void add1HittoSite(const std::string & site);;
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::ostream & PrintRank(std::ostream & os, unsigned int nbDisplayed);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend std::ostream & operator <<(std::ostream & os, const SiteRank & sr);
    // std::ostream & operator <<(std::ostream & os, const SiteRank & sr)
    // Mode d'emploi :
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    SiteRank& operator=(const SiteRank& _SiteRank);
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    SiteRank(const SiteRank& _SiteRank);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SiteRank();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SiteRank();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées
    void swapMap();
    // void swapMap();
    // Mode d'emploi :
    //    Permet de transformer l'unordered map en multimap pour pouvoir afficher le classement
    // Contrat :
    //
    //----------------------------------------------------- Attributs protégés
    std::unordered_map<std::string, unsigned int> hitsBySite;

    bool needSwapMap;
    std::multimap<unsigned int, const std::string *> siteRankbyHits;

};

//-------------------------------- Autres définitions dépendantes de <SiteRank>

#endif  // SiteRank_H_
