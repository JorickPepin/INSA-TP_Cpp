/*************************************************************************
                           SiteGraph  -  description
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SiteGraph> (fichier SiteGraph.h) ----------------
#ifndef SRC_SITEGRAPH_H_
#define SRC_SITEGRAPH_H_

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

#endif  // SRC_SITEGRAPH_H_
