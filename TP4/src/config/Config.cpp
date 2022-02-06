/*************************************************************************
                           Config  -  description
                             -------------------
    début                : 06/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Config> (fichier Config.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "Config.h"

//------------------------------------------------------------- Constantes
const char* FORMAT_DATE;
const char* DOMAINE;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Config::Load(std::string nomFichierConfig) {
    std::ifstream fichierConfig(nomFichierConfig);

    if (fichierConfig.is_open()) {
        std::string ligne;
        while (getline(fichierConfig, ligne)) {
            ligne.erase(std::remove_if(
                ligne.begin(), ligne.end(), isspace), ligne.end());

            // commentaire ou ligne vide
            if (ligne[0] == '#' || ligne.empty()) {
                continue;
            }

            auto delimiteur = ligne.find("=");
            auto cle = ligne.substr(0, delimiteur);
            auto valeur = ligne.substr(delimiteur + 1);

            if (cle == "FORMAT_DATE") {
                FORMAT_DATE = valeur.c_str();
            } else if (cle == "DOMAINE") {
                DOMAINE = valeur.c_str();
            }
        }
    } else {
        std::cerr << "Le fichier de configuration " << nomFichierConfig
                  << " n'a pas pu être ouvert." << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!FORMAT_DATE || !DOMAINE) {
        std::cerr << "Les variables FORMAT_DATE et DOMAINE doivent être "
                  << "définies dans le fichier de configuration." << std::endl;
        exit(EXIT_FAILURE);
    }
}
