/*************************************************************************
                           main  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Interface.h"
#include "structures/Liste.h"
//------------------------------------------------------------------------

int main() {
    Liste catalogue;
    int choix;

    Interface::AfficherBienvenue();

    do {
        Interface::AfficherMenu();

        std::cout << "Choix : ";
        std::cin >> choix;

        switch (choix) {
            case 0:
                Interface::AfficherFin();
                break;
            case 1:
                Interface::AjouterTrajet(&catalogue);
                break;
            case 2:
                Interface::AfficherTrajets(&catalogue);
                break;
            case 3:
                Interface::RechercherTrajet(&catalogue);
                break;
            case 4:
                Interface::SauvegarderCatalogue(&catalogue);
                break;
            case 5:
                Interface::ChargerCatalogue(&catalogue);
                break;
            default:
                Interface::AfficherMauvaisChoix();
                break;
        }
    } while (choix != 0);
}
