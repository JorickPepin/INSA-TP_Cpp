/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <AnalyseLogController> ----------------
#ifndef SRC_ANALYSELOGCONTROLLER_H_
#define SRC_ANALYSELOGCONTROLLER_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "SiteRank.h"
#include "SiteGraph.h"
#include "Options.h"

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseLogController>
//
//
//------------------------------------------------------------------------

class AnalyseLogController {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Run();

    //------------------------------------------------- Surcharge d'opérateurs
    AnalyseLogController& operator = (const AnalyseLogController& _AnalyseLogController);

    //-------------------------------------------- Constructeurs - destructeur
    AnalyseLogController(const AnalyseLogController& _AnalyseLogController);

    AnalyseLogController(bool optionG, bool optionE, bool optionT,
                         int heure, std::string nomFichierDot,
                         std::string nomFichierLog);

    AnalyseLogController();

    virtual ~AnalyseLogController();

 private:
    //------------------------------------------------------- Méthodes privées

    //------------------------------------------------------- Attributs privés
    std::string nomFichierDot;
    std::string nomFichierLog;

    SiteRank* siteRank;
    SiteGraph* siteGraph;
    Options* options;
};

#endif  // SRC_ANALYSELOGCONTROLLER_H_
