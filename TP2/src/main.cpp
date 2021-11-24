/*************************************************************************
                           main  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Interface.h"
#include "modeles/Catalogue.h"
//------------------------------------------------------------------------

int main(int argc, char const *argv[]) {

    Catalogue catalogue;
    int choix;
    
    for ( ; ; ) {
        Interface::AfficherMenu();
        
        std::cin >> choix;

        switch (choix) {
            case 0:
                return 0;
            case 1:
                Interface::AjouterTrajet(catalogue);
                break;
            case 2:
                Interface::AfficherTrajets(catalogue);
                break;
            default:
                break;
        }
    }
}
