#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char *argv[]) {

    std::string utilisation = "Utilisation : ./analog [-e | -g fichier.dot | -t heure] fichier.log";
    int option;

    while ((option = getopt(argc, argv, "eg:t:")) != -1) {
        switch (option) {
            case 'e':
                std::cout << "option e" << std::endl;
                // exclure les doc avec une extension de type image, CSS ou JS
                continue;
            case 'g':
                std::cout << "option g avec valeur : " << optarg << std::endl;
                // produire un fichier .dot s'appelant [optarg]
                continue;
            case 't':
                std::cout << "option t avec valeur : " << optarg << std::endl;
                // prendre en compte uniquement les logs correspondant à
                // l'intervalle horaire [optarg, optarg + 1]
                continue;

            case '?':
            case 'h':
            case  -1:  // no arg
            default :
                std::cout << utilisation << std::endl;
                break;
        }
        break;
    }

    if (!argv[optind]) {
        std::cout << "Fichier .log manquant\n" << utilisation << std::endl;
        exit(1);
    }

    std::cout << "Nom fichier: " << argv[optind] << std::endl;
} 
