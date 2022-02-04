/*************************************************************************
                           SiteRank  -  description
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SiteRank> (fichier SiteRank.h) ----------------
#ifndef SRC_SITERANK_H_
#define SRC_SITERANK_H_

//--------------------------------------------------- Interfaces utilisées

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

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <SiteRank>

#endif  // SRC_SITERANK_H_
