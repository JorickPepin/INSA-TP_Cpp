/*************************************************************************
                           ApacheLog  -  Représente un log Apache
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <ApacheLog> (fichier ApacheLog.cpp) --
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream> 
#include <iomanip>
#include <regex> 
//------------------------------------------------------ Include personnel
#include "ApacheLog.h"

//------------------------------------------------------------- Constantes
const std::string PATRON = "(.*?) - - \\[(.*?) \\+\\d+\\] \"(.*?) (.*?) (HTTP/.*)?\" (.*?) (.*?) \"(.*?)\" \"(.*?)\"";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
ApacheLog::ApacheLog(const std::string ligne) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <ApacheLog>" << std::endl;
    #endif

    std::regex rgx(PATRON);
    std::smatch matchs;

    if (std::regex_search(ligne, matchs, rgx)) {

        this->adresseIP = matchs[1].str();

        std::istringstream ss(matchs[2].str());
        ss >> std::get_time(&this->dateHeure, "%d/%b/%Y:%H:%M:%S");

        this->methode = matchs[3].str();
        this->ressource = matchs[4].str();
        this->protocole = matchs[5].str();
        this->code = std::stoi(matchs[6].str());

        // TODO check taille car peut être "-"
        this->taille = std::stoi(matchs[7].str());

        // TODO supprimer domaine de base du référent
        this->referent = matchs[8].str();

        this->userAgent = matchs[9].str();

        std::cout << this->referent << " " << this->ressource << std::endl;
    } else {
        std::cout << "Match not found\n";
    }
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
