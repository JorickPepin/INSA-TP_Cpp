/*************************************************************************
                           Options  -  description
                             -------------------
    début                : 04/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Options> (fichier Options.h) ----------
#ifndef SRC_OPTIONS_H_
#define SRC_OPTIONS_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include "modeles/ApacheLog.h"

//------------------------------------------------------------- Constantes
/**
 * Extensions de type image, CSS et JavaScript à exclure lorsque
 * l'option -e est utilisée
 */
extern const std::vector<std::string> EXTENSIONS_A_EXCLURE;

//------------------------------------------------------------------------
// Rôle de la classe <Options>
// Gestion des options potentiellement utilisées par l'utilisateur
// Options :
//  -g        permet de produire un fichier au format GraphViz du graphe analysé
//  -e        permet d’exclure tous les documents qui ont une extension de type
//            image, CSS ou JS
//  -t heure  permet de ne prendre en compte que les hits qui sont dans le créneau
//            horaire correspondant à l’intervalle [heure, heure+1[
//------------------------------------------------------------------------

class Options {
 public:
    /**
     * @brief Indique si l'extension de la ressource du log correspond
     * à une extension à exclure quand l'option -e est utilisée
     * 
     * @param log le log à vérifier
     * @return true si l'extension ne fait pas partie des extensions à exclure, false sinon
     */
    bool ExtensionValide(const ApacheLog& log);

    /**
     * Indique si l'heure du log correspond à l'intervalle [heure, heure + 1[
     * 
     * @param log le log à vérifier
     * @param heure l'heure souhaitée
     * @return true si l'heure est dans l'intervalle, false sinon
     */
    bool HeureValide(const ApacheLog& log);

    bool OptionsG() const { return optionG; }
    bool OptionsE() const { return optionE; }
    bool OptionsT() const { return optionT; }

    Options(bool optionG, bool optionE, bool optionT, int heure);

    Options();

 private:
    //----------------------------------------------------- Méthodes privées
    bool optionG;
    bool optionE;
    bool optionT;
    int heure;
};

#endif  // SRC_OPTIONS_H_
