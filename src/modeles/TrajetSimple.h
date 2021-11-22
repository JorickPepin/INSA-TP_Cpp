/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
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
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple& operator=(const TrajetSimple& _trajetSimple);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const TrajetSimple& _trajetSimple);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//--------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif  // SRC_MODELES_TRAJETSIMPLE_H_
