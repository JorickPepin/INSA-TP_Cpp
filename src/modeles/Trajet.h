/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#ifndef SRC_MODELES_TRAJET_H_
#define SRC_MODELES_TRAJET_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs
    Trajet& operator=(const Trajet& _trajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Trajet(const Trajet& _trajet);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//--------------------------------- Autres définitions dépendantes de <Trajet>

#endif  // SRC_MODELES_TRAJET_H_
