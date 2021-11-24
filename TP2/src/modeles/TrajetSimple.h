/*************************************************************************
                           TrajetSimple  -  Classe fille de Trajet créant des trajets simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier & François Foltet & Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr & francois.foltet@insa-lyon.fr & jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#ifndef SRC_MODELES_TRAJETSIMPLE_H_
#define SRC_MODELES_TRAJETSIMPLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe permettant d'implémenter des trajets simples c'est à dire des trajets comportant :
//    - Moyen de Transport
//    - Ville de Départ
//    - Ville d'Arrivée
//------------------------------------------------------------------------

class TrajetSimple : public Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques

    void Afficher() const;
    // Mode d'emploi : Méthode pour afficher les trajets simples

    //------------------------------------------------- Surcharge d'opérateurs
    //TrajetSimple& operator=(const TrajetSimple& trajetSimple_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    //TrajetSimple(const TrajetSimple& trajetSimple_);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

   
    TrajetSimple(const char* moyenDeTransport_,const char* villeDepart_,const char* villeArrivee_);
    // Mode d'emploi : Constructeur du trajet simple, création de l'objet TrajetSimple
    // Contrat : les chaines de caractères finissent par '\0'

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char* moyenDeTransport;
    char* villeDepart;
    char* villeArrivee;
};

//--------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif  // SRC_MODELES_TRAJETSIMPLE_H_
