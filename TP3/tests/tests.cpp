/*************************************************************************
                               Tests unitaires
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

/////////////////////////////////////////////////////////////////  INCLUDE
#include <string>
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
/*
void testGetTrajet() {
    Liste* liste = new Liste();

    const Trajet* trajet1 = new TrajetSimple("Voiture", "Lyon", "Paris");
    const Trajet* trajet2 = new TrajetSimple("Train", "Toulouse", "Bordeaux");

    liste->AjouterTrajet(trajet1);
    liste->AjouterTrajet(trajet2);

    TEST_CHECK_(liste->GetPremier()->GetTrajet() == trajet1, "le premier trajet de la liste est le même que le premier trajet ajouté");
    TEST_CHECK_(liste->GetDernier()->GetTrajet() == trajet2, "le deuxième trajet de la liste est le même que le deuxième trajet ajouté");

    delete liste;
}*/

void testEstVide() {
    Liste* liste = new Liste();

    TEST_CHECK_(liste->EstVide() == true, "la liste est indiquée vide quand aucun trajet n'a été inséré");

    liste->Ajouter(new TrajetSimple("Voiture", "Lyon", "Paris"));

    TEST_CHECK_(liste->EstVide() == false, "la liste est indiquée non vide quand un trajet a été inséré");

    delete liste;
}

//----------------------------------------------------------- TrajetSimple
void testConstructeurTrajetSimple() {
    const std::string moyenDeTransport = "Voiture";
    const std::string villeDepart = "Lyon";
    const std::string villeArrivee = "Paris";

    TrajetSimple* t1 = new TrajetSimple(moyenDeTransport, villeDepart, villeArrivee);

    TEST_CHECK_(moyenDeTransport.compare(t1->moyenDeTransport) == 0, "le moyen de transport est bien initialisé");
    TEST_CHECK_(villeDepart.compare(t1->villeDepart) == 0, "la ville de départ est bien initialisée");
    TEST_CHECK_(villeArrivee.compare(t1->villeArrivee) == 0, "la ville d'arrivée est bien initialisée");

    delete t1;
}
//------------------------------------------------------------------------

TEST_LIST = {
    { "Constructeur par défaut d'une liste", testConstructeurDefautListe },
    { "Ajout dans une liste", testAjoutTrajetListe },
    // { "Getter d'une liste", testGetTrajet },
    { "Méthode EstVide d'une liste", testEstVide },
    { "Constructeur d'un trajet simple", testConstructeurTrajetSimple },
    { NULL, NULL }
};
