/*************************************************************************
                           SiteGraph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <SiteGraph> (fichier SiteGraph.h) ----------------
#ifndef SiteGraph_H_
#define SiteGraph_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SiteGraph>
//
//
//------------------------------------------------------------------------

class SiteGraph : public Ancetre {
 public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    SiteGraph& operator=(const SiteGraph& _SiteGraph);
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    SiteGraph(const SiteGraph& _SiteGraph);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SiteGraph();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SiteGraph();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <SiteGraph>

#endif  // SiteGraph_H_
