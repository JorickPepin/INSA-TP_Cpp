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

const char* TrajetCompose::GetVilleDepart() const {
    return trajets->GetPremier()->GetTrajet()->GetVilleDepart();
}

const char* TrajetCompose::GetVilleArrivee() const {
    return trajets->GetDernier()->GetTrajet()->GetVilleArrivee();;
}

TypeTrajet TrajetCompose::GetType() const {
    return TypeTrajet::Compose;
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

std::ofstream & TrajetCompose::versFichier(std::ofstream & out) const{
    //TODO
    out << "C:" << this->GetVilleDepart() << '%' << this->GetVilleArrivee() <<'{';

    const Element *  el = trajets->GetPremier();
    while (el != nullptr)
    {
        out << *el->GetTrajet();
        el = el->GetSuivant();
    }
    out << '}';
    return out;
}

std::ofstream & operator << (std::ofstream & out, const TrajetCompose & trajet){
    trajet.versFichier(out);
    return out;
}
