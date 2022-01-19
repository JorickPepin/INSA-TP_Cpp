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
#include <regex> 
//------------------------------------------------------ Include personnel
#include "ApacheLog.h"

//------------------------------------------------------------- Constantes
const std::string PATTERN = "(.*?) - - \\[(.*?)(?= ) (.*?)\\] \"(.*?) (.*?) (HTTP/.*)?\" (.*?) (.*?) \"(.*?)\" \"(.*?)\"";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
ApacheLog::ApacheLog(const std::string ligne) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <ApacheLog>" << std::endl;
    #endif

    std::regex rgx(PATTERN);
    std::smatch matches;

    if (std::regex_search(ligne, matches, rgx)) {
        for (size_t i = 0; i < matches.size(); ++i) {
            std::cout << i << ": '" << matches[i].str() << "'\n";
        }
    } else {
        std::cout << "Match not found\n";
    }
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
