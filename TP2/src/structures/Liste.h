/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ------------
#ifndef SRC_STRUCTURES_LISTE_H_
#define SRC_STRUCTURES_LISTE_H_
//--------------------------------------------------- Interfaces utilisées
#include "Element.h"

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
// Classe représentant une liste de trajets simplement chaînée.
//
// La classe contient un pointeur vers le premier élément de la liste
// ainsi qu'un pointeur vers le dernier élément.
//------------------------------------------------------------------------

class Liste {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * @return int la taille de la liste.
     */
    int Taille() const;

    /**
     * Ajoute un trajet à la fin de la liste.
     * 
     * @param trajet_ le trajet à ajouter
     */
    void Ajouter(const Trajet* trajet_);

    /**
     * Affiche le contenu de la liste dans la console.
     */
    void Afficher() const;

    /**
     * @return true si la liste est vide, false sinon
     */
    bool EstVide() const;

    /**
     * @return Element* un pointeur vers le premier élément de la liste
     */
    Element* GetPremier() const { return premier; }

    /**
     * @return Element* un pointeur vers le dernier élément de la liste 
     */
    Element* GetDernier() const { return dernier; }

    //-------------------------------------------- Constructeurs - destructeur
    Liste();

    virtual ~Liste();

 private:
    //----------------------------------------------------- Attributs privés
    Element* premier;
    Element* dernier;
};

#endif  // SRC_STRUCTURES_LISTE_H_
