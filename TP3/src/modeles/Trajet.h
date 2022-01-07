/*************************************************************************
                           Trajet  -  Classe mère des trajets composés et simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#ifndef SRC_MODELES_TRAJET_H_
#define SRC_MODELES_TRAJET_H_

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
#include "../../libs/json.hpp"

using json = nlohmann::ordered_json;

//------------------------------------------------------------------ Types
enum TypeTrajet { Simple, Compose };

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe mère abstraite des trajets
//------------------------------------------------------------------------

class Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * Affiche les caractéristiques du trajet dans la console
     */
    virtual void Afficher() const = 0;
    
    virtual const std::string GetVilleDepart() const = 0;
    virtual const std::string GetVilleArrivee() const = 0;

    virtual TypeTrajet GetType() const = 0;

    virtual json ToJSON() const = 0;

    /**
     * Indique si le trajet invoquant la méthode permet de se déplacer
     * de la ville de départ à la ville d'arrivée passées en paramètres.
     * 
     * @param villeDepart_ 
     * @param villeArrivee_ 
     * @return true si le trajet permet d'aller de la ville de départ
     *         à la ville d'arrivée, false sinon
     */
    virtual bool Correspond(const std::string villeDepart_, const std::string villeArrivee_) const {
        return (villeDepart_ == GetVilleDepart() && villeArrivee_ == GetVilleArrivee());
    }

    //-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet() {}
};

#endif  // SRC_MODELES_TRAJET_H_
