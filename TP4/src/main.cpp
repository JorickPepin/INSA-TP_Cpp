/*************************************************************************
                                    main
                             -------------------
    début                : 12/01/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

#include <unistd.h>
#include <iostream>
#include <string>
#include "AnalyseLogController.h"

int main(int argc, char *argv[]) {
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

    controleur.Run();
}
