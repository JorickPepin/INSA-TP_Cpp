/*************************************************************************
                                    main
                             -------------------
    début                : 12/01/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

#include <unistd.h>
#include <iostream>
#include <string>
#include "controleurs/AnalyseLogController.h"
#include "config/Config.h"

int main(int argc, char *argv[]) {
    Config::Load();  // chargement du fichier de configuration

    std::string utilisation = "Utilisation : ./analog "
                              "[-e | -g fichier.dot | -t heure] fichier.log";
    int option;

    bool optionE = false, optionG = false, optionT = false;
    int heure = -1;
    std::string nomFichierDot = "";

    while ((option = getopt(argc, argv, "eg:t:")) != -1) {
        switch (option) {
            case 'e':
                optionE = true;
                continue;
            case 'g':
                optionG = true;
                nomFichierDot = optarg;
                continue;
            case 't':
                optionT = true;
                heure = atoi(optarg);
                continue;
            case '?':
            case 'h':
            case  -1:
            default :
                std::cout << utilisation << std::endl;
                break;
        }
        break;
    }

    if (!argv[optind]) {
        std::cerr << "Fichier .log manquant\n" << utilisation << std::endl;
        exit(1);
    }

    std::string nomFichierLog = argv[optind];

    AnalyseLogController controleur = AnalyseLogController(optionG, optionE,
        optionT, heure, nomFichierDot, nomFichierLog);

    controleur.Run();  // options récupéres, lancement du programme
}
