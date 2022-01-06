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
#include "structures/Element.h"

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

    Sauvegarder(nomFichier, json);
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

    Sauvegarder(nomFichier, json);
}

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthodes privées
void Sauvegarde::Sauvegarder(const std::string& nomFichier, const json json) {
    std::ofstream file(CHEMIN_SAUVEGARDE + nomFichier);

    if (file.good()) {
        file << std::setw(4) << json;
    } else {
        ErreurOuverture(nomFichier);
    }

    file.close();
}

void Sauvegarde::ErreurOuverture(const std::string& nomFichier) {
    std::cerr << "\nErreur lors de l'ouverture de <" << nomFichier << ">" << std::endl;
    std::cerr << "Vérifiez que le dossier <" << CHEMIN_SAUVEGARDE << "> est bien présent à la racine" << std::endl;
}
