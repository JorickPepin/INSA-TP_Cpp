/*************************************************************************
                           TrajetSimple  -  Classe fille de Trajet créant des trajets simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const {
    std::cout << villeDepart << " -> " << villeArrivee
        << " en " << moyenDeTransport;
}

const std::string TrajetSimple::GetVilleDepart() const {
    return villeDepart;
}

const std::string TrajetSimple::GetVilleArrivee() const {
    return villeArrivee;
}

TypeTrajet TrajetSimple::GetType() const {
    return TypeTrajet::Simple;
}

json TrajetSimple::ToJSON() const {
    json json;

    json["type"] = GetType();
    json["transport"] = moyenDeTransport;
    json["villeDepart"] = villeDepart;
    json["villeArrivee"] = villeArrivee;

    return json;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(std::string moyenDeTransport_,
                           std::string villeDepart_,
                           std::string villeArrivee_) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetSimple>" << std::endl;
    #endif

    moyenDeTransport = moyenDeTransport_;
    villeDepart = villeDepart_;
    villeArrivee = villeArrivee_;
}
