/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 24/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Interface> (fichier Interface.h) ----------
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
    static void AfficherBienvenue();
    // Mode d'emploi :
    //

    static void AfficherFin();
    // Mode d'emploi :
    //

    static void AfficherMenu();
    // Mode d'emploi :
    //

    static void AfficherMauvaisChoix();
    // Mode d'emploi :
    //

    static void AjouterTrajet(Liste* catalogue_);
    // Mode d'emploi :
    //

    static void AfficherTrajets(Liste* catalogue_);
    // Mode d'emploi :
    //

 private:
    //----------------------------------------------------- Méthodes privées
    Interface();
    // Mode d'emploi :
    // constructeur par défaut mis en privé afin d'éviter une instanciation
    // de la classe et garder ainsi un comportement statique

    static void ajouterTrajetSimple(Liste* catalogue_);
    static void ajouterTrajetCompose(Liste* catalogue_);
    //----------------------------------------------------- Attributs privés
    static const int TAILLE_MAX = 50;
};

#endif  // SRC_INTERFACE_H_
