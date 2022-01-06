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
#include <fstream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "Sauvegarde.h"
#include "structures/Element.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Sauvegarde::SauvegarderSansCritere(const Liste& catalogue,
                                        const std::string& nomFichier) {
    if(catalogue.EstVide())
        return;
    std::ofstream file(nomFichier);
    if(file.good()){
        const Element * el = catalogue.GetPremier();
        while (el != nullptr && file.good())
        {
            file << *el->GetTrajet();
            file << '\n';
            if(!file.good()){
                std::cerr << "Erreur lors de l'écriture d'un trajet" << std::endl;
                break;
            }
            el = el->GetSuivant();
        }

    }else{
        std::cerr << "Erreur lors de l'ouverture de <" << nomFichier <<">" << std::endl;
    }
    file.close();
}

void Sauvegarde::SauvegarderSelonType(const Liste& catalogue,
                                      const std::string& nomFichier,
                                      TypeTrajet typeTrajet) {
    if(catalogue.EstVide())
            return;

    std::ofstream file(nomFichier);
    if(file.good()){
        const Element * el = catalogue.GetPremier();
        const Trajet * t = nullptr;

        while (el != nullptr && file.good())
        {
            t = el->GetTrajet();
            if (t->GetType() == typeTrajet) {
                file << *t;
                file << '\n';
                if(!file.good()){
                    std::cerr << "Erreur lors de l'écriture d'un trajet" << std::endl;
                    break;
                }
            }            
            el = el->GetSuivant();
        }

    }else{ // !file.good()
        std::cerr << "Erreur lors de l'ouverture de <" << nomFichier <<">" << std::endl;
    }
    file.close();
}
                                    
//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées