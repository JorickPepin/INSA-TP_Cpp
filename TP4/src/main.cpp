#include <iostream>
#include <string>
#include <unistd.h>
#include "modeles/ApacheLog.h"

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

    new ApacheLog(R"(192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] "GET /temps/4IF16.html HTTP/1.1" 200 12106 "http://intranet-if.insa-lyon.fr/temps/4IF15.html" "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1")");
} 
