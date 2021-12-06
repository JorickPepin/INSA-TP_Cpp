/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const {
    Element* element = trajets->Get(0);

    while (element) {
        element->Afficher();

        if ((element = element->GetSuivant())) {
            std::cout << " puis ";
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(Liste* trajets_) : trajets(trajets_) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetCompose>" << std::endl;
    #endif
}

TrajetCompose::~TrajetCompose() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <TrajetCompose>" << std::endl;
    #endif

    delete trajets;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
