/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) --------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Liste.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
int Liste::Taille() const {
    int taille = 0;

    if (premier) {
        taille = premier->Taille();  // calcul de la taille de manière récursive
    }

    return taille;
}

void Liste::Ajouter(const Trajet* trajet_) {
    if (this->EstVide()) {  // si la liste est vide, premier et dernier pointent vers le même élément
        premier = new Element(trajet_);
        dernier = premier;
    } else {
        dernier->Ajouter(new Element(trajet_));
        dernier = dernier->GetSuivant();  // dernier pointe désormais vers le dernier élément ajouté
    }
}

void Liste::Afficher() const {
    Element* element = premier;

    while (element) {
        std::cout << " ";
        element->Afficher();
        std::cout << std::endl;
        element = element->GetSuivant();
    }
}

bool Liste::EstVide() const {
    return this->Taille() == 0;
}

//-------------------------------------------- Constructeurs - destructeur
Liste::Liste() : premier(nullptr), dernier(nullptr) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <Liste>" << std::endl;
    #endif
}

Liste::~Liste() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <Liste>" << std::endl;
    #endif

    delete premier;
}
