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

    const char* GetVilleDepart() const;
    const char* GetVilleArrivee() const;

    TypeTrajet GetType() const;

    //-------------------------------------------------------- Tests unitaires
    friend void testConstructeurTrajetSimple();

    //------------------------------------------------- Surcharge d'opérateurs
    /**
     * Permet de comparer deux trajets simples pour savoir
     * si leurs composantes sont similaires
     * 
     * @return true si les deux trajets ont la même ville de départ, la même
     *         ville d'arrivée et le même moyen de transport, false sinon
     */
    friend bool operator==(const TrajetSimple& t1, const TrajetSimple& t2);

    //-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char* moyenDeTransport_,
                 const char* villeDepart_,
                 const char* villeArrivee_);

    virtual ~TrajetSimple();

 protected:
   std::string toStringFichier() const;
    //----------------------------------------------------- Attributs protégés
    char* moyenDeTransport;
    char* villeDepart;
    char* villeArrivee;
};

#endif  // SRC_MODELES_TRAJETSIMPLE_H_
