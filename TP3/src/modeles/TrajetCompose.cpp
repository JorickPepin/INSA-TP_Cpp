/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const {
    Element* element = trajets->GetPremier();

    while (element) {
        element->Afficher();

        if ((element = element->GetSuivant())) {
            std::cout << " puis ";
        }
    }
}

const std::string TrajetCompose::GetVilleDepart() const {
    return trajets->GetPremier()->GetTrajet()->GetVilleDepart();
}

const std::string TrajetCompose::GetVilleArrivee() const {
    return trajets->GetDernier()->GetTrajet()->GetVilleArrivee();;
}

TypeTrajet TrajetCompose::GetType() const {
    return TypeTrajet::Compose;
}

json TrajetCompose::ToJSON() const {
    json json;

    json["type"] = GetType();
    json["trajets"] = json::array();

    Element* element = trajets->GetPremier();

    while (element) {
        json["trajets"].push_back(element->GetTrajet()->ToJSON());
        element = element->GetSuivant();
    }

    return json;
}

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
