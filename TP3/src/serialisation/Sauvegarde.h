/*************************************************************************
                           Sauvegarde  -  description
                             -------------------
    début                : 15/12/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Sauvegarde> (fichier Sauvegarde.h) ----------
#ifndef SRC_SERIALISATION_SAUVEGARDE_H_
#define SRC_SERIALISATION_SAUVEGARDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "../structures/Liste.h"
#include "../modeles/Trajet.h"
#include "../../libs/json.hpp"

using json = nlohmann::ordered_json;

//------------------------------------------------------------------------
// Rôle de la classe <Sauvegarde>
// Classe statique sauvegardant un catalogue dans un fichier JSON.
//------------------------------------------------------------------------

class Sauvegarde {
 public:
    //----------------------------------------------------- Méthodes publiques
    /**
     * Sauvegarde la totalité du catalogue dans un fichier.
     * 
     * @param catalogue le catalogue à sauvegarder
     * @param nomFichier le nom du fichier
     */
    static void SauvegarderSansCritere(const Liste& catalogue,
                                       const std::string& nomFichier);

    /**
     * Sauvegarde les trajets d'un certain type dans un fichier.
     * 
     * @param catalogue le catalogue à sauvegarder
     * @param nomFichier le nom du fichier
     * @param typeTrajet le type de trajet à sauvegarder
     */
    static void SauvegarderSelonType(const Liste& catalogue,
                                     const std::string& nomFichier,
                                     TypeTrajet typeTrajet);

    /**
     * Sauvegarde les trajets du catalogue dans un fichier selon une
     * certaine ville de départ et/ou d'arrivée.
     * 
     * @param catalogue le catalogue à sauvegarder
     * @param nomFichier le nom du fichier
     * @param villeDepart la ville de départ souhaitée ou "" si le
     *                    paramètre est à ignorer
     * @param villeArrivee la ville d'arrivée souhaitée ou "" si le
     *                     paramètre est à ignorer
     */
    static void SauvegarderSelonVilles(const Liste& catalogue,
                                       const std::string& nomFichier,
                                       const std::string& villeDepart,
                                       const std::string& villeArrivee);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Sauvegarde();

    /**
     * Crée un fichier contenant le JSON à sauvegarder.
     * 
     * @param nomFichier le nom du fichier
     * @param json le contenu JSON à sauvegarder
     */
    static void creerFichier(const std::string& nomFichier, const json json);
};

#endif  // SRC_SERIALISATION_SAUVEGARDE_H_
