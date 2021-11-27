/*************************************************************************
                               Tests unitaires
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

/////////////////////////////////////////////////////////////////  INCLUDE
#include "./acutest.h"

#include "../src/structures/Liste.h"
#include "../src/modeles/TrajetSimple.h"

/////////////////////////////////////////////////////////////////    TESTS
//------------------------------------------------------------------ Liste
void testConstructeurDefaut_Liste() {
    Liste liste;
    TEST_CHECK_(liste.Taille() == 0, "la taille de la liste est 0");
}

void testAjoutTrajet_Liste() {
    Liste* liste = new Liste();
    Trajet* trajet1 = new TrajetSimple("test", "test", "test");
    Trajet* trajet2 = new TrajetSimple("test", "test", "test");

    liste->Ajouter(trajet1);
    TEST_CHECK_(liste->Taille() == 1, "la taille de la liste est 1 après l'ajout d'un élément");

    liste->Ajouter(trajet2);
    TEST_CHECK_(liste->Taille() == 2, "la taille de la liste est 2 après l'ajout de deux éléments");

    delete liste;
}
//--------------------------------------------------------------- <Classe>

//------------------------------------------------------------------------

TEST_LIST = {
    { "Constructeur par défaut d'une liste", testConstructeurDefaut_Liste },
    { "Ajout dans une liste", testAjoutTrajet_Liste },
    { NULL, NULL }
};
