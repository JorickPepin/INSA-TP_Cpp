/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//----------- Réalisation de la classe <AnalyseLogController> ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "AnalyseLogController.h"
#include "modeles/ApacheLog.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void AnalyseLogController::Run() {
    std::ifstream fichierLog;

    fichierLog.open(this->nomFichierLog);
    if (!fichierLog.good()) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << "\n";
        exit(2);
    }

    ApacheLog al;
    while (fichierLog.good()) {
        fichierLog >> al;

        if (this->options->OptionsE() && !this->options->ExtensionValide(al)) {
            continue;
        }

        if (this->options->OptionsT() && !this->options->HeureValide(al)) {
            continue;
        }

        this->siteRank->Add1HittoSite(al.GetRessource());
    }

    this->siteRank->PrintRank(std::cout, 10) << std::endl;
}

//-------------------------------------------- Constructeurs - destructeur
AnalyseLogController::AnalyseLogController() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <AnalyseLogController>"
                  << std::endl;
    #endif
}

AnalyseLogController::AnalyseLogController(bool optionG, bool optionE,
                                           bool optionT, int heure,
                                           std::string nomFichierDot,
                                           std::string nomFichierLog)
    : nomFichierDot(nomFichierDot), nomFichierLog(nomFichierLog) {

    #ifdef MAP
        std::cout << "Appel au constructeur de <AnalyseLogController>"
                  << std::endl;
    #endif

    this->options = new Options(optionG, optionE, optionT, heure);
    this->siteRank = new SiteRank();
    this->siteGraph = new SiteGraph();
}

AnalyseLogController::~AnalyseLogController() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <AnalyseLogController>"
                  << std::endl;
    #endif

    delete siteRank;
    delete siteGraph;
    delete options;
}
