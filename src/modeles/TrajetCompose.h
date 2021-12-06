/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#ifndef SRC_MODELES_TRAJETCOMPOSE_H_
#define SRC_MODELES_TRAJETCOMPOSE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "../structures/Liste.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi : Méthode pour afficher les trajets composés

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    explicit TrajetCompose(Liste* trajets_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés+
    Liste* trajets;
};

//-------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif  // SRC_MODELES_TRAJETCOMPOSE_H_
