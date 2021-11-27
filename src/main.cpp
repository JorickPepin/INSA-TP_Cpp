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
#include "structures/Liste.h"
//------------------------------------------------------------------------
bool estValide(int choix) {
    return !(choix < 1 || choix > 2);
}

int main(int argc, char const *argv[]) {
    Liste* catalogue = new Liste();
    int choix;

    do {
        Interface::AfficherMenu();

        std::cin >> choix;

        switch (choix) {
            case 0:
                // TODO(*): ajouter message de fin
                break;
            case 1:
                Interface::AjouterTrajet(catalogue);
                break;
            case 2:
                Interface::AfficherTrajets(catalogue);
                break;
            default:
                break;
        }
    } while (estValide(choix));

    delete catalogue;
}
