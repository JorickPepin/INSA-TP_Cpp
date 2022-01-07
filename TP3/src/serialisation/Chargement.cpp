/*************************************************************************
                           Chargement  -  description
                             -------------------
    début                : 15/12/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Chargement> (fichier Chargement.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <string>
//------------------------------------------------------ Include personnel
#include "Chargement.h"
#include "../modeles/TrajetSimple.h"
#include "../modeles/TrajetCompose.h"
#include "../../libs/json.hpp"

using json = nlohmann::ordered_json;
//------------------------------------------------------------- CONSTANTES
static const std::string CHEMIN_SAUVEGARDE = "sauvegardes/";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Chargement::ChargerSansCritere(Liste& catalogue,
                                    const std::string& nomFichier) {

    json json = chargerFichier(nomFichier);

    if (json.empty()) {
        return;
    }

    for (auto& item : json.items()) {   
        auto& trajetJSON = item.value();

        ajouterTrajet(catalogue, trajetJSON);
    }
}

void Chargement::ChargerSelonType(Liste& catalogue,
                                  const std::string& nomFichier,
                                  TypeTrajet typeTrajet) {

    json json = chargerFichier(nomFichier);

    if (json.empty()) {
        return;
    }

    for (auto& item : json.items()) {   
        auto& trajetJSON = item.value();

        TypeTrajet type = trajetJSON["type"];

        if (type == typeTrajet) {
            ajouterTrajet(catalogue, trajetJSON);
        }
    }
}

void Chargement::ChargerSelonVilles(Liste& catalogue,
                                    const std::string& nomFichier,
                                    const std::string& villeDepart,
                                    const std::string& villeArrivee) {

    json json = chargerFichier(nomFichier);

    if (json.empty()) {
        return;
    }

    for (auto& item : json.items()) {   
        auto& trajetJSON = item.value();

        TypeTrajet type = trajetJSON["type"];

        std::string villeDepartItem;
        std::string villeArriveeItem;

        if (type == TypeTrajet::Compose) {
            
            auto& trajets = trajetJSON["trajets"];

            json::iterator premierTrajet = trajets.begin();
            json::iterator dernierTrajet = trajets.end();

            --dernierTrajet;  // end() renvoie un pointeur sur l'élément après le dernier 

            villeDepartItem = (*premierTrajet)["villeDepart"];
            villeArriveeItem = (*dernierTrajet)["villeArrivee"];

        } else if (type == TypeTrajet::Simple) {
            villeDepartItem = trajetJSON["villeDepart"];
            villeArriveeItem = trajetJSON["villeArrivee"];
        }


        if (!villeDepart.empty() && !villeArrivee.empty()) {  // les deux villes sont précisées
            if (villeDepartItem == villeDepart && villeArriveeItem == villeArrivee) {
                ajouterTrajet(catalogue, trajetJSON);
            }

        } else if (!villeDepart.empty()) {  // seule la ville de départ est précisée
            if (villeDepartItem == villeDepart) {
                ajouterTrajet(catalogue, trajetJSON);
            }

        } else {  // seule la ville d'arrivée est précisée
            if (villeArriveeItem == villeArrivee) {
                ajouterTrajet(catalogue, trajetJSON);
            }
        }
    }
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
json Chargement::chargerFichier(const std::string& nomFichier) {
    std::ifstream fichier(CHEMIN_SAUVEGARDE + nomFichier);

    json json;

    if (!fichier.is_open()) {
        std::cerr << "\nErreur lors de l'ouverture de <" << nomFichier << ">." << std::endl;
        std::cerr << "Vérifiez que le fichier se trouve dans le dossier <"
                  << CHEMIN_SAUVEGARDE
                  << "> à la racine." << std::endl;
    } else {
        fichier >> json;
    }

    fichier.close();

    return json;
}

void Chargement::ajouterTrajet(Liste& catalogue, json trajetJSON) {

    TypeTrajet type = trajetJSON["type"];

    if (type == TypeTrajet::Simple) {
        catalogue.Ajouter(new TrajetSimple(trajetJSON["transport"], trajetJSON["villeDepart"], trajetJSON["villeArrivee"]));

    } else if (type == TypeTrajet::Compose) {

        Liste* trajets = new Liste();

        for (auto& trajet : trajetJSON["trajets"]) {
            trajets->Ajouter(new TrajetSimple(trajet["transport"], trajet["villeDepart"], trajet["villeArrivee"]));
        }

        catalogue.Ajouter(new TrajetCompose(trajets));
    }
}
