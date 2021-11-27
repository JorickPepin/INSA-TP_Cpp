/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Interface> (fichier Interface.h) ----------------
#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

//--------------------------------------------------- Interfaces utilisées
#include "structures/Liste.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Interface>
//
//
//------------------------------------------------------------------------

class Interface {
 public:
    //----------------------------------------------------- Méthodes publiques
    static void AfficherMenu();
    // Mode d'emploi :
    // 

    static void AjouterTrajet(Liste& catalogue_);
    // Mode d'emploi :
    // 

    static void AfficherTrajets(Liste& catalogue_);
    // Mode d'emploi :
    // 

    //------------------------------------------------- Surcharge d'opérateurs
    Interface& operator=(const Interface& interface_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Interface(const Interface& interface_);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Interface();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Interface();
    // Mode d'emploi :
    //
    // Contrat :
    //

 private:
    //----------------------------------------------------- Méthodes privées
    static void AjouterTrajetSimple(Liste& catalogue_);
    static void AjouterTrajetCompose(Liste& catalogue_);
    //----------------------------------------------------- Attributs privés
    static const int TAILLE_MAX = 50;
};

//-------------------------------- Autres définitions dépendantes de <Interface>

#endif  // SRC_INTERFACE_H_
