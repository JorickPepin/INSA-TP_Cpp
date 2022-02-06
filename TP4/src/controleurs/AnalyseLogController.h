/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 03/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <AnalyseLogController> ----------------
#ifndef SRC_ANALYSELOGCONTROLLER_H_
#define SRC_ANALYSELOGCONTROLLER_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "../generateurs/SiteRank.h"
#include "../generateurs/SiteGraph.h"
#include "../options/Options.h"

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseLogController>
// Contrôleur de l'analyse du fichier de logs.
//------------------------------------------------------------------------

class AnalyseLogController {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * Lance l'analyse du fichier.
     */
    void Run();

    //------------------------------------------------- Surcharge d'opérateurs
    AnalyseLogController & operator = (
        const AnalyseLogController & _AnalyseLogController);

    //-------------------------------------------- Constructeurs - destructeur
    AnalyseLogController(const AnalyseLogController & _AnalyseLogController);

    AnalyseLogController(bool optionG, bool optionE, bool optionT,
                         int heure, std::string nomFichierDot,
                         std::string nomFichierLog);

    AnalyseLogController();

    virtual ~AnalyseLogController();

 private:
    //------------------------------------------------------- Attributs privés
    std::string nomFichierDot;
    std::string nomFichierLog;

    SiteRank* siteRank;
    SiteGraph* siteGraph;
    Options* options;
};

#endif  // SRC_ANALYSELOGCONTROLLER_H_
