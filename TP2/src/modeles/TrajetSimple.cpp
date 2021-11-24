/*************************************************************************
                           TrajetSimple  -  Classe fille de Trajet créant des trajets simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier & François Foltet & Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr & francois.foltet@insa-lyon.fr & jorick.pepin@insa-lyon.fr
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

void TrajetSimple::Afficher() const
{
    std::cout << villeDepart << " -> " << villeArrivee << " en " << moyenDeTransport << std::endl;
}

//------------------------------------------------- Surcharge d'opérateurs
/*TrajetSimple& TrajetSimple::operator=(const TrajetSimple& trajetSimple_) {
}*/

//-------------------------------------------- Constructeurs - destructeur
/*TrajetSimple::TrajetSimple(const TrajetSimple& trajetSimple_) {
    #ifdef MAP
        std::cout <<
            "Appel au constructeur de copie de <TrajetSimple>" << std::endl;
    #endif
}*/

TrajetSimple::TrajetSimple(const char* moyenDeTransport_,const char* villeDepart_,const char* villeArrivee_) 
{
    #ifdef MAP
        std::cout << "Appel au constructeur de <TrajetSimple>" << std::endl;
    #endif
    moyenDeTransport = new char[strlen(moyenDeTransport_)+1];
    villeDepart = new char[strlen(villeDepart_)+1];
    villeArrivee = new char[strlen(villeArrivee_)+1];

    strcpy(moyenDeTransport, moyenDeTransport_);
    strcpy(villeDepart, villeDepart_);
    strcpy(villeArrivee, villeArrivee_);
}

TrajetSimple::~TrajetSimple() 
{
    #ifdef MAP
        std::cout << "Appel au destructeur de <TrajetSimple>" << std::endl;
    #endif
    delete [] moyenDeTransport;
    delete [] villeDepart;
    delete [] villeArrivee;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
