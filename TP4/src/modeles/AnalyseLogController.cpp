/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 04/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AnalyseLogController> (fichier AnalyseLogController.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "AnalyseLogController.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AnalyseLogController::Méthode(liste des paramètres) {
//}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

AnalyseLogController::AnalyseLogController() {
    #ifdef MAP
        std::cout << "Appel au constructeur de <AnalyseLogController>" << std::endl;
    #endif
}

AnalyseLogController::~AnalyseLogController() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <AnalyseLogController>" << std::endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
