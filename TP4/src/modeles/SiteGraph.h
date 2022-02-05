/*************************************************************************
                           SiteGraph  -  Représente un graph de site
                             -------------------
    début                : 04/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
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

class SiteGraph {
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
