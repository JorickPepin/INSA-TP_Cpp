/*************************************************************************
                           Sauvegarde  -  description
                             -------------------
    début                : 15/12/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Sauvegarde> (fichier Sauvegarde.h) ----------
#ifndef SRC_SAUVEGARDE_H_
#define SRC_SAUVEGARDE_H_

//--------------------------------------------------- Interfaces utilisées
#include "structures/Liste.h"

//------------------------------------------------------------------------
// Rôle de la classe <Sauvegarde>
// Classe statique sauvegardant un catalogue dans un fichier texte.
//------------------------------------------------------------------------

class Sauvegarde {
 public:
    //----------------------------------------------------- Méthodes publiques
    static void Sauvegarder(Liste* catalogue_);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Sauvegarde();

    //----------------------------------------------------- Attributs privés

};

#endif  // SRC_SAUVEGARDE_H_
