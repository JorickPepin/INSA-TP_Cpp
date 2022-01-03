/*************************************************************************
                           Sauvegarde  -  description
                             -------------------
    début                : 15/12/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Sauvegarde> (fichier Sauvegarde.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "Sauvegarde.h"
#include "structures/Element.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Sauvegarde::SauvegarderSansCritere(const Liste& catalogue,
                                        const std::string& nomFichier) {

    std::cout << "\nSauvegarder" << std::endl;
    
    
        
    Element * elem = catalogue.GetPremier();
    while(elem){
        // sauvegarde dans le fichier
        //fichier << elem->GetTrajet();
        // fichier         
        // elem = elem->GetSuivant();
    }
    // TODO(*): générer fichier .txt à partir du catalogue
}

void Sauvegarde::SauvegarderSelonType(const Liste& catalogue,
                                      const std::string& nomFichier,
                                      TypeTrajet typeTrajet) {

    if (typeTrajet == TypeTrajet::Simple) {
        std::cout << "simple" << std::endl;
    } else if (typeTrajet == TypeTrajet::Compose) {
        std::cout << "composé" << std::endl;
    }

    std::cout << nomFichier << std::endl;
/*
    Element* elem = catalogue.GetPremier();

    while (elem) {

        if (typeTrajet == elem->GetTrajet()->GetType()) {

        }

        elem = elem->GetSuivant();
    }*/

    std::cout << "pas encore implémenté" << std::endl;
}
                                    
//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées

