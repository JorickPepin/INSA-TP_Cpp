/*************************************************************************
                           Config  -  description
                             -------------------
    début                : 06/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Config> (fichier Config.h) ----------
#ifndef SRC_CONFIG_CONFIG_H_
#define SRC_CONFIG_CONFIG_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes
extern const char* FORMAT_DATE;
extern const char* DOMAINE;

//------------------------------------------------------------------------
// Rôle de la classe <Config>
// Charge et stocke les variables définies dans le fichier de
// configuration du projet.
//------------------------------------------------------------------------

class Config {
 public:
    /**
     * @brief Charge les variables de configuration depuis un fichier
     * 
     * @param nomFichierConfig 
     */
    static void Load(std::string nomFichierConfig = ".env");

 private:
    //----------------------------------------------------- Méthodes privées
    /**
     * @brief Constructeur par défaut mis en privé afin d'éviter une instanciation
     *        de la classe et garder ainsi un comportement statique.
     */
    Config();
};

#endif  // SRC_CONFIG_CONFIG_H_
