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
#include <string>
#include <regex> 
//------------------------------------------------------ Include personnel
#include "ApacheLog.h"

//------------------------------------------------------------- Constantes
const std::string PATTERN = "(.*?) - - \\[(.*?)\\] \"(.*?) (.*?) (HTTP/.*)?\" (.*?) (.*?) \"(.*?)\" \"(.*?)\"";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

ApacheLog::ApacheLog(){
    #ifdef MAP
        std::cout << "Appel au constructeur de <ApacheLog>" << std::endl;
    #endif
}

ApacheLog::~ApacheLog(){
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

ApacheLog & ApacheLog::hydrate(const std::string & ligne){
    std::regex rgx(PATTERN);
    std::smatch matches;

    if (std::regex_search(ligne, matches, rgx)) {

        this->adresseIP = matches[1].str();
        this->dateHeure = matches[2].str();
        this->methode = matches[3].str();
        this->ressource = matches[4].str();
        this->protocole = matches[5].str();
        this->code = std::stoi(matches[6].str());
        this->taille = (matches[7].str() != "-" )? std::stoi(matches[7].str()) : 0;
        // TODO supprimer domaine de base du référent
        this->referent = matches[8].str();
        this->userAgent = matches[9].str();
    } else {
        std::cerr << "Match not found\n";
    }
    return *this;
}


std::istream & operator >> (std::istream & is, ApacheLog & apacheLog){
    std::string s;
    std::getline(is,s);
    apacheLog.hydrate(s);

    return is;
}

std::ostream & operator << (std::ostream & os, const ApacheLog & apacheLog){
    os << apacheLog.referent << " " <<apacheLog.ressource;
    return os;
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
