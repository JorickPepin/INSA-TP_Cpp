/*************************************************************************
                               Tests unitaires
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

/////////////////////////////////////////////////////////////////  INCLUDE
#include <string>
#include "../libs/acutest.h"

#include "../src/structures/Liste.h"
#include "../src/modeles/TrajetSimple.h"
#include "../src/serialisation/Chargement.h"

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

    TEST_CHECK_(moyenDeTransport == t1->moyenDeTransport, "le moyen de transport est bien initialisé");
    TEST_CHECK_(villeDepart == t1->villeDepart, "la ville de départ est bien initialisée");
    TEST_CHECK_(villeArrivee == t1->villeArrivee, "la ville d'arrivée est bien initialisée");

    delete t1;
}
//------------------------------------------------------------- Chargement
void testChargementSansCritere() {
    Liste catalogue;
    const std::string nomFichier = "demo.json";

    Chargement::ChargerSansCritere(catalogue, nomFichier);

    TEST_CHECK_(catalogue.Taille() == 3, "le catalogue contient 3 trajets");
}

void testChargementSelonType() {
    Liste catalogue1;
    Liste catalogue2;
    const std::string nomFichier = "demo.json";

    Chargement::ChargerSelonType(catalogue1, nomFichier, TypeTrajet::Simple);
    Chargement::ChargerSelonType(catalogue2, nomFichier, TypeTrajet::Compose);

    TEST_CHECK_(catalogue1.Taille() == 2, "le catalogue contient 2 trajets simples");
    TEST_CHECK_(catalogue2.Taille() == 1, "le catalogue contient 1 trajet composé");
}

void testChargementSelonVilles() {
    Liste catalogue1;
    Liste catalogue2;
    Liste catalogue3;

    const std::string nomFichier = "demo.json";

    std::string villeDepart = "Lyon";
    std::string villeArrivee = "";

    Chargement::ChargerSelonVilles(catalogue1, nomFichier, villeDepart, villeArrivee);

    TEST_CHECK_(catalogue1.Taille() == 3, "le catalogue contient 3 trajets pour Lyon en ville de départ");

    villeDepart = "";
    villeArrivee = "Bordeaux";

    Chargement::ChargerSelonVilles(catalogue2, nomFichier, villeDepart, villeArrivee);

    TEST_CHECK_(catalogue2.Taille() == 1, "le catalogue contient 1 trajet pour Bordeaux en ville d'arrivée");

    villeDepart = "Lyon";
    villeArrivee = "Paris";

    Chargement::ChargerSelonVilles(catalogue3, nomFichier, villeDepart, villeArrivee);

    TEST_CHECK_(catalogue3.Taille() == 2, "le catalogue contient 2 trajets pour Lyon en ville de départ et Paris en ville d'arrivée");
}
//------------------------------------------------------------------------

TEST_LIST = {
    { "Constructeur par défaut d'une liste", testConstructeurDefautListe },
    { "Ajout dans une liste", testAjoutTrajetListe },
    // { "Getter d'une liste", testGetTrajet },
    { "Méthode EstVide d'une liste", testEstVide },
    { "Constructeur d'un trajet simple", testConstructeurTrajetSimple },
    { "Chargement de tous les trajets du catalogue demo", testChargementSansCritere },
    { "Chargement des trajets du catalogue demo selon leur type", testChargementSelonType },
    { "Chargement des trajets du catalogue demo selon une ville de départ et/ou d'arrivée", testChargementSelonVilles },
    { NULL, NULL }
};
