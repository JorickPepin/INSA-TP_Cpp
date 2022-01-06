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
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Interface>
// Classe statique gérant les affichages console et servant de contrôleur
// entre l'utilisateur et le catalogue.
//------------------------------------------------------------------------

class Interface {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * Affiche un message de bienvenue pour accueillir l'utilisateur
     */
    static void AfficherBienvenue();

    /**
     * Affiche un message de fin lorsque l'utilisateur quitte l'application
     * 
     */
    static void AfficherFin();

    /**
     * Affiche le menu principal du programme permettant de choisir entre
     * l'insertion d'un trajet, l'affichage du catalogue ou la recherche
     * d'un trajet dans le catalogue.
     */
    static void AfficherMenu();

    /**
     * Affiche un message lorsque l'utilisateur choisit une option non supportée
     */
    static void AfficherMauvaisChoix();

    /**
     * Affiche les messages relatifs à l'ajout d'un trajet dans le catalogue
     */
    static void AjouterTrajet(Liste* catalogue_);

    /**
     * Affiche le catalogue dans la console
     */
    static void AfficherTrajets(Liste* catalogue_);

    /**
     * Affiche les messages relatifs à la recherche d'un trajet dans le
     * catalogue ainsi que les résultats obtenus le cas échéant.
     */
    static void RechercherTrajet(Liste* catalogue_);

    /**
     * Sauvegarde le catalogue dans un fichier JSON.
     */
    static void SauvegarderCatalogue(Liste* catalogue_);

    /**
     * Charge un catalogue présent dans un fichier JSON.
     */
    static void ChargerCatalogue(Liste* catalogue_);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Interface();

    /**
     * Affiche les messages relatifs à l'ajout d'un trajet simple dans
     * le catalogue.
     * Méthode privée car appelée par la méthode AjouterTrajet.
     */
    static void ajouterTrajetSimple(Liste* catalogue_);

    /**
     * Affiche les messages relatifs à l'ajout d'un trajet composé dans
     * le catalogue.
     * Méthode privée car appelée par la méthode AjouterTrajet.
     */
    static void ajouterTrajetCompose(Liste* catalogue_);

    /**
     * Retourne un nom de fichier demandé à l'utilisateur
     */
    static std::string recupererNomFichier();

    //----------------------------------------------------- Attributs privés
    /**
     * Entier correspondant à la taille maximale de l'entrée utilisateur
     */
    static const int TAILLE_MAX = 50;
};

#endif  // SRC_INTERFACE_H_
