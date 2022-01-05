/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#ifndef SRC_MODELES_TRAJETCOMPOSE_H_
#define SRC_MODELES_TRAJETCOMPOSE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "../structures/Liste.h"
#include <fstream>

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe correspondant à un trajet composé, c'est-à-dire un trajet
// contenant plusieurs trajets simples ou composés
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Afficher() const;

    const char* GetVilleDepart() const;
    const char* GetVilleArrivee() const;

    TypeTrajet GetType() const;

    //-------------------------------------------- Constructeurs - destructeur
    explicit TrajetCompose(Liste* trajets_);

    virtual ~TrajetCompose();

    friend std::ofstream & operator << (std::ofstream & out, const TrajetCompose & trajet);
   
 protected:
    //----------------------------------------------------- Attributs protégés
    Liste* trajets;
    std::ofstream & versFichier(std::ofstream & out) const;
};

#endif  // SRC_MODELES_TRAJETCOMPOSE_H_
