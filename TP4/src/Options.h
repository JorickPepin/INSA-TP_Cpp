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
#include "modeles/ApacheLog.h"
#include <vector>
#include <string>

//------------------------------------------------------------- Constantes
/**
 * Extensions de type image, CSS et JavaScript à exclure lorsque
 * l'option -e est utilisée
 */
extern const std::vector<std::string> EXTENSIONS_A_EXCLURE;

//------------------------------------------------------------------------
// Rôle de la classe <Options>
// 
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
    static bool ExtensionValide(ApacheLog& log);

    /**
     * Indique si l'heure du log correspond à l'intervalle [heure, heure + 1[
     * 
     * @param log le log à vérifier
     * @param heure l'heure souhaitée
     * @return true si l'heure est dans l'intervalle, false sinon
     */
    static bool HeureValide(ApacheLog& log, int heure);

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * Constructeur par défaut mis en privé afin d'éviter une instanciation
     * de la classe et garder ainsi un comportement statique.
     */
    Options();

};

#endif  // SRC_OPTIONS_H_
