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

void utilisation() {
    std::cout <<
        "Utilisation :\n" <<
        "./analog [-e] [-g fichier.dot] [-t heure] fichier.log\n\n" <<
        "Options :\n" <<
        "-e           exclut les documents qui ont une extension de type image, CSS ou JS\n" <<
        "-t heure     exclut les logs n'étant pas dans l’intervalle horaire [heure, heure+1[\n" <<
        "-g fichier   produit un fichier au format DOT du graphe de parcours des logs" << std::endl;
}

int main(int argc, char *argv[]) {
    Config::Load();  // chargement du fichier de configuration

    int option;
    bool erreur = false;

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
            default:
                erreur = true;
                break;
        }
        break;
    }

    if (!argv[optind] || erreur) {
        utilisation();
        exit(EXIT_FAILURE);
    }

    std::string nomFichierLog = argv[optind];

    AnalyseLogController controleur = AnalyseLogController(optionG, optionE,
        optionT, heure, nomFichierDot, nomFichierLog);

    controleur.Run();  // options récupéres, lancement du programme
}
