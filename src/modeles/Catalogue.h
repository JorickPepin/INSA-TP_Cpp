/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Interface de la classe <Catalogue> (fichier Catalogue.h) -------
#ifndef SRC_MODELES_CATALOGUE_H_
#define SRC_MODELES_CATALOGUE_H_

//--------------------------------------------------- Interfaces utilisées
#include "../structures/Liste.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Ajouter(const Trajet* trajet_);
    // Mode d'emploi :
    //

    void Afficher();
    // Mode d'emploi :
    //

    Liste* GetTrajets() const { return trajets; }
    // Mode d'emploi :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Catalogue& operator=(const Catalogue& catalogue_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue(const Catalogue& catalogue_);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

 private:
    //----------------------------------------------------- Méthodes privées

    //----------------------------------------------------- Attributs privés
    Liste* trajets;
};

#endif  // SRC_MODELES_CATALOGUE_H_
