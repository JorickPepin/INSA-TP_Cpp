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
#include "structures/Liste.h"
#include "modeles/TrajetSimple.h"
//------------------------------------------------------------------------

int main(int argc, char const *argv[]) {
    Liste* liste = new Liste();

    liste->Ajouter(new TrajetSimple());
    liste->Ajouter(new TrajetSimple());

    delete liste;
}
