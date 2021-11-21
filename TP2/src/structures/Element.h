/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H
//--------------------------------------------------- Interfaces utilisées
#include "../modeles/Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//
//
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Taille ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter ( Element* _element );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Element* GetSuivant ( ) const { return suivant; }
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Element & operator = ( const Element & _element );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Element ( const Element & _element );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Element ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Element ( const Trajet* _trajet );

    virtual ~Element ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    const Trajet* trajet;
    Element* suivant;
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // ELEMENT_H

