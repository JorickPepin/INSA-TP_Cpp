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
void Chargement::ChargerCatalogue(Liste* catalogue_, std::string nomFichier) {

    std::ifstream fichier(CHEMIN_SAUVEGARDE + nomFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture de <" << nomFichier << ">" << std::endl;
        return;
    }

    json json;
    fichier >> json;
    fichier.close();

    for (auto& item : json.items()) {   
        auto& trajetInitial = item.value();
    
        TypeTrajet type = trajetInitial["type"];

        if (type == TypeTrajet::Simple) {
            catalogue_->Ajouter(new TrajetSimple(trajetInitial["transport"], trajetInitial["villeDepart"], trajetInitial["villeArrivee"]));

        } else if (type == TypeTrajet::Compose) {

            Liste* trajets = new Liste();

            for (auto& trajet : trajetInitial["trajets"]) {
                trajets->Ajouter(new TrajetSimple(trajet["transport"], trajet["villeDepart"], trajet["villeArrivee"]));
            }

            catalogue_->Ajouter(new TrajetCompose(trajets));
        }
    }
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées

