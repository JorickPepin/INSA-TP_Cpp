/*************************************************************************
                               Tests unitaires
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

/////////////////////////////////////////////////////////////////  INCLUDE
#include <cstring>
#include "./acutest.h"

#include "../src/structures/Liste.h"
#include "../src/modeles/TrajetSimple.h"

/////////////////////////////////////////////////////////////////    TESTS
//------------------------------------------------------------------ Liste
void testConstructeurDefautListe() {
    Liste liste;
    TEST_CHECK_(liste.Taille() == 0, "la taille de la liste est 0");
}

void testAjoutTrajetListe() {
    Liste* liste = new Liste();
    Trajet* trajet1 = new TrajetSimple("test", "test", "test");
    Trajet* trajet2 = new TrajetSimple("test", "test", "test");

    liste->Ajouter(trajet1);
    TEST_CHECK_(liste->Taille() == 1, "la taille de la liste est 1 après l'ajout d'un élément");

    liste->Ajouter(trajet2);
    TEST_CHECK_(liste->Taille() == 2, "la taille de la liste est 2 après l'ajout de deux éléments");

    delete liste;
}
//----------------------------------------------------------- TrajetSimple
void testConstructeurTrajetSimple() {
    const char* moyenDeTransport = "Voiture";
    const char* villeDepart = "Lyon";
    const char* villeArrivee = "Paris";

    TrajetSimple* t1 = new TrajetSimple(moyenDeTransport, villeDepart, villeArrivee);

    TEST_CHECK_(strcmp(t1->moyenDeTransport, moyenDeTransport) == 0, "le moyen de transport est bien initialisé");
    TEST_CHECK_(strcmp(t1->villeDepart, villeDepart) == 0, "la ville de départ est bien initialisée");
    TEST_CHECK_(strcmp(t1->villeArrivee, villeArrivee) == 0, "la ville d'arrivée est bien initialisée");

    delete t1;
}
//------------------------------------------------------------------------

TEST_LIST = {
    { "Constructeur par défaut d'une liste", testConstructeurDefautListe },
    { "Ajout dans une liste", testAjoutTrajetListe },
    { "Constructeur d'un trajet simple", testConstructeurTrajetSimple },
    { NULL, NULL }
};
