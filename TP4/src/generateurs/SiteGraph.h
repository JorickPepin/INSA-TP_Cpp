/*************************************************************************
                           SiteGraph  -  Représente un graph de site
                             -------------------
    début                : 03/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/


//---------- Interface de la classe <SiteGraph> (fichier SiteGraph.h) ----
#ifndef SRC_SITEGRAPH_H_
#define SRC_SITEGRAPH_H_

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
#include <fstream>

//------------------------------------------------------------------------
// Rôle de la classe <SiteGraph>
// Génère le contenu d'un fichier .dot représentant un graphe de parcours.
//------------------------------------------------------------------------

class SiteGraph {
 public:
    //----------------------------------------------------- Méthodes publiques
    void AddSite(const std::string & referant, const std::string & cible);
    std::ostream & PrintDotGraphTo(std::ostream & os) const;
    // Mode d'emploi :
    //  écrit le graph au format GraphViz dans le fichier
    // Contrat :
    //   le fichier doit être ouvert en écriture et vide pour le que le format
    //   soit respecté
    //   mode d'ouverture suggeré std::ofstream::trunc

    //------------------------------------------------- Surcharge d'opérateurs
    SiteGraph & operator = (const SiteGraph & _SiteGraph);

    friend std::ostream & operator << (std::ostream & os,
                                       const SiteGraph & _SiteGraph);
    // Mode d'emploi :
    //  print la multi map

    //-------------------------------------------- Constructeurs - destructeur
    SiteGraph(const SiteGraph & _SiteGraph);

    SiteGraph();

    virtual ~SiteGraph();

 private:
    //------------------------------------------------------- Attributs privés
    // cible    : page demandé
    // referant : page où était le navigateur, quand la cible a été demandé
    // <referant, <cible, uint>> : on sait pour site combien de fois il a été
    //                             referent pour une cible
    std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>> graph;
};

#endif  // SRC_SITEGRAPH_H_
