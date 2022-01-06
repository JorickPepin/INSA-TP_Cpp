/*************************************************************************
                           TrajetSimple  -  Classe fille de Trajet créant des trajets simples
                             -------------------
    début                : 17/11/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#ifndef SRC_MODELES_TRAJETSIMPLE_H_
#define SRC_MODELES_TRAJETSIMPLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe permettant d'implémenter des trajets simples, c'est-à-dire des
// trajets comportant :
//    - Moyen de Transport
//    - Ville de Départ
//    - Ville d'Arrivée
//------------------------------------------------------------------------

class TrajetSimple : public Trajet {
 public:
    //----------------------------------------------------- Méthodes publiques
    void Afficher() const;

    const std::string GetVilleDepart() const;
    const std::string GetVilleArrivee() const;

    TypeTrajet GetType() const;

    json ToJSON() const;

    //-------------------------------------------------------- Tests unitaires
    friend void testConstructeurTrajetSimple();

    //-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const std::string moyenDeTransport_,
                 const std::string villeDepart_,
                 const std::string villeArrivee_);

 protected:
    //----------------------------------------------------- Attributs protégés
    std::string moyenDeTransport;
    std::string villeDepart;
    std::string villeArrivee;
};

#endif  // SRC_MODELES_TRAJETSIMPLE_H_
