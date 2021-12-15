/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Element.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
int Element::Taille() const {
    int taille = 1;

    if (suivant) {
        taille += suivant->Taille();
    }

    return taille;
}

void Element::Ajouter(Element* element_) {
    if (!suivant) {
        suivant = element_;
    } else {
        suivant->Ajouter(element_);
    }
}

void Element::Afficher() {
    trajet->Afficher();
}

//-------------------------------------------- Constructeurs - destructeur
Element::Element(const Trajet* trajet_) : trajet(trajet_), suivant(nullptr) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Element>" << std::endl;
    #endif
}

Element::~Element() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Element>" << std::endl;
    #endif

    delete trajet;
    delete suivant;
}
