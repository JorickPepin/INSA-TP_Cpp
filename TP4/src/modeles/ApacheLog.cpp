/*************************************************************************
                           ApacheLog  -  Représente un log Apache
                             -------------------
    début                : 13/01/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <ApacheLog> (fichier ApacheLog.cpp) --
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
//------------------------------------------------------ Include personnel
#include "ApacheLog.h"
#include "../config/Config.h"

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs
std::istream & operator >> (std::istream & is, ApacheLog & apacheLog) {
    std::string s;
    std::getline(is, s);
    apacheLog.hydrate(s);

    return is;
}

std::ostream & operator << (std::ostream & os, const ApacheLog & apacheLog) {
    os << apacheLog.referent << " " <<apacheLog.ressource;
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
ApacheLog::ApacheLog() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <ApacheLog>" << std::endl;
    #endif
}

ApacheLog::~ApacheLog() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <ApacheLog>" << std::endl;
    #endif
}

ApacheLog::ApacheLog(const std::string & ligne) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <ApacheLog>" << std::endl;
    #endif

    hydrate(ligne);
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
ApacheLog & ApacheLog::hydrate(const std::string & ligne) {
    std::regex rgx(PATRON);
    std::smatch matchs;

    if (std::regex_search(ligne, matchs, rgx)) {
        this->adresseIP = matchs[1].str();

        std::istringstream ss(matchs[2].str());
        ss >> std::get_time(&this->dateHeure, FORMAT_DATE.c_str());

        this->methode = matchs[3].str();
        this->ressource = matchs[4].str();
        this->protocole = matchs[5].str();
        this->code = std::stoi(matchs[6].str());

        // prise en compte du cas où la taille est "-"
        this->taille = matchs[7].str() != "-" ? std::stoi(matchs[7].str()) : 0;

        std::string referentBrut = matchs[8].str();
        size_t pos = referentBrut.find(DOMAINE);

        // si le référent commence par le domaine défini dans le
        // fichier de configuration, on l'enlève
        if (pos == 0) {
            referentBrut.erase(pos, DOMAINE.length());
        }

        this->referent = referentBrut;
        this->userAgent = matchs[9].str();
    } else {
        this->code = -1;
    }

    return *this;
}
