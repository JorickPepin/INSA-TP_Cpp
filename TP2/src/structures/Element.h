/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) --------
#ifndef SRC_STRUCTURES_ELEMENT_H_
#define SRC_STRUCTURES_ELEMENT_H_
//--------------------------------------------------- Interfaces utilisées
#include "../modeles/Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//
//
//------------------------------------------------------------------------

class Element {
 public:
    //----------------------------------------------------- Méthodes publiques
    int Taille() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(Element* element_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher();
    // Mode d'emploi :
    //

    Element* GetSuivant() const { return suivant; }
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Element& operator=(const Element& element_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Element(const Element& element_);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Element();
    // Mode d'emploi :
    //
    // Contrat :
    //

    explicit Element(const Trajet* trajet_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Element();
    // Mode d'emploi :
    //
    // Contrat :
    //

 private:
    //----------------------------------------------------- Méthodes privées

    //----------------------------------------------------- Attributs privés
    const Trajet* trajet;
    Element* suivant;
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif  // SRC_STRUCTURES_ELEMENT_H_
