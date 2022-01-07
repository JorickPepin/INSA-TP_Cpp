/*************************************************************************
                           Sauvegarde  -  description
                             -------------------
    début                : 15/12/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Sauvegarde> (fichier Sauvegarde.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Sauvegarde.h"
#include "../structures/Element.h"

//------------------------------------------------------------- CONSTANTES
static const std::string CHEMIN_SAUVEGARDE = "sauvegardes/";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Sauvegarde::SauvegarderSansCritere(const Liste& catalogue,
                                        const std::string& nomFichier) {

    json json = json::array();

    const Element* element = catalogue.GetPremier();

    while (element) {
        json.push_back(element->GetTrajet()->ToJSON());
        element = element->GetSuivant();
    }

    creerFichier(nomFichier, json);
}

void Sauvegarde::SauvegarderSelonType(const Liste& catalogue,
                                      const std::string& nomFichier,
                                      TypeTrajet typeTrajet) {

    json json = json::array();

    const Element* element = catalogue.GetPremier();

    while (element) {
        const Trajet* trajet = element->GetTrajet();

        if (trajet->GetType() == typeTrajet) {
            json.push_back(trajet->ToJSON());
        }

        element = element->GetSuivant();
    }

    creerFichier(nomFichier, json);
}

void Sauvegarde::SauvegarderSelonVilles(const Liste& catalogue,
                                        const std::string& nomFichier,
                                        const std::string& villeDepart,
                                        const std::string& villeArrivee) {

    json json = json::array();

    const Element* element = catalogue.GetPremier();

    while (element) {
        const Trajet* trajet = element->GetTrajet();

        if (!villeDepart.empty() && !villeArrivee.empty()) {  // les deux villes sont précisées
            if (trajet->GetVilleDepart() == villeDepart && trajet->GetVilleArrivee() == villeArrivee) {
                json.push_back(trajet->ToJSON());
            }

        } else if (!villeDepart.empty()) {  // seule la ville de départ est précisée
            if (trajet->GetVilleDepart() == villeDepart) {
                json.push_back(trajet->ToJSON());
            }

        } else {  // seule la ville d'arrivée est précisée
            if (trajet->GetVilleArrivee() == villeArrivee) {
                json.push_back(trajet->ToJSON());
            }
        }

        element = element->GetSuivant();
    }

    creerFichier(nomFichier, json);
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
void Sauvegarde::creerFichier(const std::string& nomFichier, const json json) {

    if (json.empty()) {
        std::cout << "\nImpossible de sauvegarder : votre sélection ne correspond à aucun trajet." << std::endl;
        return;
    }

    std::ofstream file(CHEMIN_SAUVEGARDE + nomFichier);

    if (file.good()) {
        file << std::setw(4) << json;
        std::cout << "\nSauvegarde effectuée avec succés !" << std::endl;
    } else {
        std::cerr << "\nErreur lors de l'ouverture de <" << nomFichier << ">." << std::endl;
        std::cerr << "Vérifiez que le dossier <" << CHEMIN_SAUVEGARDE << "> est bien présent à la racine." << std::endl;
    }

    file.close();
}
