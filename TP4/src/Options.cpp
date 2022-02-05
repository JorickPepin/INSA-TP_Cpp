/*************************************************************************
                           Options  -  description
                             -------------------
    début                : 04/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Options> (fichier Options.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "Options.h"

//------------------------------------------------------------- Constantes
const std::vector<std::string> EXTENSIONS_A_EXCLURE = {
    "apng", "avif", "gif", "jpg", "jpeg", "jfif", "pjpeg", "pjp",
    "png", "svg", "webp", "bmp", "ico", "cur", "tif", "tiff",
    "js", "css"
};

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
bool Options::ExtensionValide(const ApacheLog& log) {
    std::string ressource = log.GetRessource();
    std::string extension = ressource.substr(ressource.find_last_of(".") + 1);

    return !(std::find(EXTENSIONS_A_EXCLURE.begin(), EXTENSIONS_A_EXCLURE.end(), extension) != EXTENSIONS_A_EXCLURE.end());
}

bool Options::HeureValide(const ApacheLog& log) {
    return log.GetDateHeure().tm_hour == this->heure;
}

Options::Options(bool optionG, bool optionE, bool optionT, int heure)
    : optionG(optionG), optionE(optionE), optionT(optionT), heure(heure) {

    #ifdef MAP
        std::cout << "Appel au constructeur de <Options>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
