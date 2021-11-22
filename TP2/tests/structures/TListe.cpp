/*************************************************************************
                           TListe  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TListe> (fichier TListe.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TListe.h"
#include "../acutest.h"
#include "../../src/structures/Liste.h"
#include "../../src/modeles/TrajetSimple.h"
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void testConstructeurDefaut() {
    Liste liste;
    TEST_CHECK_(liste.Taille() == 0, "la taille de la liste est 0");
}

void testAjoutTrajet() {
    Liste* liste = new Liste();
    Trajet* trajet1 = new TrajetSimple();
    Trajet* trajet2 = new TrajetSimple();

    liste->Ajouter(trajet1);
    TEST_CHECK_(liste->Taille() == 1, "la taille de la liste est 1 après l'ajout d'un élément");

    liste->Ajouter(trajet2);
    TEST_CHECK_(liste->Taille() == 2, "la taille de la liste est 2 après l'ajout de deux éléments");

    delete liste;
}

TEST_LIST = {
    { "Constructeur par défaut d'une liste : Liste ( ); ", testConstructeurDefaut },
    { "Ajout dans une liste : void Ajouter ( const Trajet* _trajet ); ", testAjoutTrajet },
    { NULL, NULL }
};
