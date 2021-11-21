/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#if ! defined ( LISTE_H )
#define LISTE_H
//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
//
//
//------------------------------------------------------------------------

class Liste 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Taille ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter ( const Trajet* _trajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Liste & operator = ( const Liste & _liste );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Liste ( const Liste & _liste );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Liste ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Liste ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    Element* premier;
};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif // LISTE_H

