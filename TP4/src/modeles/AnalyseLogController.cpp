/*************************************************************************
                           AnalyseLogController  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
AnalyseLogController & AnalyseLogController::operator=(const AnalyseLogController& _AnalyseLogController) {
}

//-------------------------------------------- Constructeurs - destructeur
AnalyseLogController::AnalyseLogController(const AnalyseLogController& _AnalyseLogController) {
    #ifdef MAP
        std::cout << "Appel au constructeur de copie de <AnalyseLogController>" << std::endl;
    #endif
}

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
