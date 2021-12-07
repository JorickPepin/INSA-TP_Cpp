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
#include <cstring>

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

    virtual const char* GetVilleDepart() const = 0;
    virtual const char* GetVilleArrivee() const = 0;

    /**
     * Indique si le trajet invoquant la méthode permet de se déplacer
     * de la ville de départ à la ville d'arrivée passées en paramètres.
     * 
     * @param villeDepart_ 
     * @param villeArrivee_ 
     * @return true si le trajet permet d'aller de la ville de départ
     *         à la ville d'arrivée, false sinon
     */
    virtual bool Correspond(const char* villeDepart_, const char* villeArrivee_) const {
        return (!strcmp(GetVilleDepart(), villeDepart_) &&
                !strcmp(GetVilleArrivee(), villeArrivee_));
    }

    //-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet() {}
};

#endif  // SRC_MODELES_TRAJET_H_
