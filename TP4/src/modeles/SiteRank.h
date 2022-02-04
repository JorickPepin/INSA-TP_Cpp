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

#endif  // SiteRank_H_
