/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ------------
#ifndef SRC_STRUCTURES_LISTE_H_
#define SRC_STRUCTURES_LISTE_H_
//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
//
//
//------------------------------------------------------------------------

class Liste {
 public:
    //----------------------------------------------------- Méthodes publiques
    int Taille() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(const Trajet* trajet_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher() const;
    // Mode d'emploi :
    //

    Element* Get(int i) const;
    // Mode d'emploi : retourne le i-ème élément de la liste, le premier
    //                 étant à l'index 0

    bool EstVide() const;
    // Mode d'emploi : retourne true si la liste est vide, false sinon

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Liste();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Liste();
    // Mode d'emploi :
    //
    // Contrat :
    //

 private:
    //----------------------------------------------------- Méthodes privées

    //----------------------------------------------------- Attributs privés
    Element* premier;
};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif  // SRC_STRUCTURES_LISTE_H_
