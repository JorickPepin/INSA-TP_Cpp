/*************************************************************************
                           SiteGraph  -  Représente un graph de site
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/


//---------- Interface de la classe <SiteGraph> (fichier SiteGraph.h) ----------------
#ifndef SRC_SITEGRAPH_H_
#define SRC_SITEGRAPH_H_

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
#include <fstream>

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

    void addSite(const std::string & referant, const std::string & cible);
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

    friend std::ofstream & operator <<(std::ofstream & os, const SiteGraph & _SiteGraph);
    // Mode d'emploi :
    //  écrit le graph au format GraphViz dans le fichier
    // Contrat :
    //   le fichier doit être ouvert en écriture et vide pour le que le format soit respecter
    //   mode d'ouverture suggeré std::ofstream::trunc
    //

    friend std::ostream & operator <<(std::ostream & os, const SiteGraph & _SiteGraph);
    // Mode d'emploi :
    //  print la multi map 
    // Contrat :
    //   
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
    // cible    : page demandé
    // referant : page où était le navigateur, quand la cible a été demandé
    // <referant,<cible,uint>> : on sait pour site combien de fois il a été referent pour une cible
    std::unordered_map<std::string,std::unordered_map<std::string,unsigned int>> graph;
};

//-------------------------------- Autres définitions dépendantes de <SiteGraph>

#endif  // SRC_SITEGRAPH_H_
