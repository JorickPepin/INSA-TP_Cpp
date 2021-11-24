/*************************************************************************
                           Trajet  -  Classe mère des trajets composés et simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier & François Foltet & Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr & francois.foltet@insa-lyon.fr & jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#ifndef SRC_MODELES_TRAJET_H_
#define SRC_MODELES_TRAJET_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe mère abstraite des trajets

//------------------------------------------------------------------------

class Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0;
    //------------------------------------------------- Surcharge d'opérateurs
    //Trajet& operator=(const Trajet& trajet_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    //Trajet(const Trajet& trajet_);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    //Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet() {}
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
