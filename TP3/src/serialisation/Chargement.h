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
     * Charge et ajoute tous les trajets présents dans un fichier de
     * sauvegarde au catalogue courant.
     */
    static void ChargerSansCritere(Liste& catalogue,
                                   const std::string& nomFichier);

    /**
     * Charge et ajoute les trajets d'un certain type présents dans un
     * fichier de sauvegarde au catalogue courant.
     * 
     * @param catalogue le catalogue à remplir
     * @param nomFichier le nom du fichier
     * @param typeTrajet le type de trajet à charger
     */
    static void ChargerSelonType(Liste& catalogue,
                                 const std::string& nomFichier,
                                 TypeTrajet typeTrajet);

    /**
     * Charge et ajoute au catalogue les trajets présents dans un fichier
     * selon une certaine ville de départ et/ou d'arrivée.
     * 
     * @param catalogue le catalogue à remplir
     * @param nomFichier le nom du fichier
     * @param villeDepart la ville de départ souhaitée ou "" si le
     *                    paramètre est à ignorer
     * @param villeArrivee la ville d'arrivée souhaitée ou "" si le
     *                     paramètre est à ignorer
     */
    static void ChargerSelonVilles(Liste& catalogue,
                                   const std::string& nomFichier,
                                   const std::string& villeDepart,
                                   const std::string& villeArrivee);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Chargement();

    /**
     * Charge un fichier et retourne le JSON contenu à l'intérieur.
     * 
     * @param nomFichier le nom du fichier
     */
    static json chargerFichier(const std::string& nomFichier);

    /**
     * Ajoute au catalogue un objet JSON représentant un trajet.
     * 
     * @param catalogue le catalogue dans lequel ajouter le trajet
     * @param trajetJSON le trajet à ajouter
     */
    static void ajouterTrajet(Liste& catalogue, json trajetJSON);
};

#endif  // SRC_SERIALISATION_CHARGEMENT_H_
