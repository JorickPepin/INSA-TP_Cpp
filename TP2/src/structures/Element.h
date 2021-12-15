/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) --------
#ifndef SRC_STRUCTURES_ELEMENT_H_
#define SRC_STRUCTURES_ELEMENT_H_
//--------------------------------------------------- Interfaces utilisées
#include "../modeles/Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Element>
// Représente un élément de la liste chaînée, contient donc le trajet
// ainsi que l'élément suivant
//------------------------------------------------------------------------

class Element {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * Permet le calcul de la taille de la liste de manière récursive.
     * Retourne la taille des éléments suivant l'élément appelant la méthode.
     * 
     * @return int le nombre d'éléments suivants
     */
    int Taille() const;

    /**
     * Ajoute un élément à la liste de manière récursive.
     * Si l'élément suivant n'est pas défini, alors il devient l'élément à
     * ajouter, sinon, on appelle la méthode Ajouter de l'élément suivant.
     * 
     * @param element_ l'élément à ajouter à la liste
     */
    void Ajouter(Element* element_);

    /**
     * Affiche le contenu de l'élément dans la console.
     */
    void Afficher();

    Element* GetSuivant() const { return suivant; }
    const Trajet* GetTrajet() const { return trajet; }

    //-------------------------------------------- Constructeurs - destructeur
    explicit Element(const Trajet* trajet_);

    virtual ~Element();

 private:
    //----------------------------------------------------- Attributs privés
    const Trajet* trajet;
    Element* suivant;
};

#endif  // SRC_STRUCTURES_ELEMENT_H_
