/*************************************************************************
                           ApacheLog  -  Représente un log Apache
                             -------------------
    début                : 13/01/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ApacheLog> (fichier ApacheLog.h) ----
#ifndef SRC_MODELES_APACHELOG_H_
#define SRC_MODELES_APACHELOG_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes
extern const std::string PATTERN;

//------------------------------------------------------------------------
// Rôle de la classe <ApacheLog>
// Représente un log Apache
//------------------------------------------------------------------------

class ApacheLog {
 public:
    //----------------------------------------------------- Méthodes publiques


    //-------------------------------------------- Constructeurs - destructeur
    ApacheLog(const std::string ligne);

 private:
    //------------------------------------------------------- Attributs privés
    
    
};

#endif  // SRC_MODELES_APACHELOG_H_
