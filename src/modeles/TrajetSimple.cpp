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
#include <cstring>
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const {
    std::cout << villeDepart << " -> " << villeArrivee
        << " en " << moyenDeTransport;
}

//------------------------------------------------- Surcharge d'opérateurs
bool operator==(const TrajetSimple& t1, const TrajetSimple& t2) {
    return (!strcmp(t1.moyenDeTransport, t2.moyenDeTransport) &&
            !strcmp(t1.villeDepart, t2.villeDepart) &&
            !strcmp(t1.villeArrivee, t2.villeArrivee));
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char* moyenDeTransport_,
                           const char* villeDepart_,
                           const char* villeArrivee_) {
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetSimple>" << std::endl;
    #endif

    moyenDeTransport = new char[strlen(moyenDeTransport_) + 1];
    villeDepart = new char[strlen(villeDepart_) + 1];
    villeArrivee = new char[strlen(villeArrivee_) + 1];

    strcpy(moyenDeTransport, moyenDeTransport_);
    strcpy(villeDepart, villeDepart_);
    strcpy(villeArrivee, villeArrivee_);
}

TrajetSimple::~TrajetSimple() {
    #ifdef MAP
        std::cout << "Appel au destructeur de <TrajetSimple>" << std::endl;
    #endif

    delete [] moyenDeTransport;
    delete [] villeDepart;
    delete [] villeArrivee;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
