/*************************************************************************
                           Chargement  -  description
                             -------------------
    début                : 06/01/2022
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Chargement> (fichier Chargement.h) ----------
#ifndef SRC_SERIALISATION_CHARGEMENT_H_
#define SRC_SERIALISATION_CHARGEMENT_H_

//--------------------------------------------------- Interfaces utilisées
#include "../structures/Liste.h"
#include "../modeles/Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Chargement>
// Classe statique chargeant un catalogue depuis un fichier JSON.
//------------------------------------------------------------------------

class Chargement {
 public:
    //----------------------------------------------------- Méthodes publiques
    
    /**
     * Charge et ajoute les trajets présents dans un fichier de sauvegarde
     * au catalogue courant.
     */
    static void ChargerCatalogue(Liste* catalogue_, std::string nomFichier);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Chargement();

    //----------------------------------------------------- Attributs privés

};

#endif  // SRC_SERIALISATION_CHARGEMENT_H_
