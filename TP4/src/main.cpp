#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "modeles/ApacheLog.h"


// TODO testing
#include "SiteRank.h"
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
        std::cerr << "Fichier .log manquant\n" << utilisation << std::endl;
        exit(1);
    }

    SiteRank sr;
    sr.add1HittoSite("test");
    sr.add1HittoSite("test");
    sr.add1HittoSite("test");   
    sr.add1HittoSite("test2");
    sr.add1HittoSite("test2");
    sr.add1HittoSite("test2");
    sr.add1HittoSite("test2");  
    sr.add1HittoSite("test5");
    std::cout << sr << std::endl;
    sr.PrintRank(std::cout,10);

    /*
    std::cout << "Nom fichier: " << argv[optind] << std::endl;
    const std::string fileName(argv[optind]);

    //new ApacheLog(R"(192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] "GET /temps/4IF16.html HTTP/1.1" 200 12106 "http://intranet-if.insa-lyon.fr/temps/4IF15.html" "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1")");
    std::ifstream file;

    file.open(fileName);
    if(!file.good()){
        std::cerr << "Erreur lors de l'ouverture du fichier" << "\n";
        exit(2);
    }
    
    ApacheLog al;
    while (file.good()){
        file >> al;
        //add1tosite(string); // top 10
        //add1tosite(referent,site);
        std::cout << al << "\n";
    }*/


} 
