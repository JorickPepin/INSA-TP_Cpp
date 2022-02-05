/*************************************************************************
                           ApacheLog  -  Représente un log Apache
                             -------------------
    début                : 13/01/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ApacheLog> (fichier ApacheLog.h) ----
#ifndef SRC_MODELES_APACHELOG_H_
#define SRC_MODELES_APACHELOG_H_

//--------------------------------------------------- Interfaces utilisées
#include <istream>
#include <string>

//------------------------------------------------------------- Constantes
extern const char* PATRON;

//------------------------------------------------------------------------
// Rôle de la classe <ApacheLog>
// Représente un log Apache
//------------------------------------------------------------------------

class ApacheLog {
 public:
    //----------------------------------------------------- Méthodes publiques
    std::string GetRessource() const { return ressource; }
    tm GetDateHeure() const { return dateHeure; }

    //-------------------------------------------- Constructeurs - destructeur
    ApacheLog & operator = (const ApacheLog & unApacheLog);
    ApacheLog();
    ApacheLog(const ApacheLog & unApacheLog);
    virtual ~ApacheLog();

    explicit ApacheLog(const std::string & ligne);

    friend std::istream & operator >> (std::istream & is,
                                       ApacheLog & apacheLog);

    friend std::ostream & operator << (std::ostream & os,
                                       const ApacheLog & apacheLog);

 private:
    //------------------------------------------------------- Attributs privés
    /**
     * Adresse IP du client
     */
    std::string adresseIP;

    /**
     * La date à laquelle la requête a été reçue
     */
    tm dateHeure;

    /**
     * Méthode utilisée par le client (GET, HEAD, POST, etc.)
     */
    std::string methode;

    /**
     * Ressource demandée par le client
     */
    std::string ressource;

    /**
     * Protocole HTTP utilisé
     */
    std::string protocole;

    /**
     * Code de statut HTTP     
     */
    int code;

    /**
     * Taille de l'objet retourné au client
     */
    int taille;

    /**
     * Site depuis lequel le client prétend avoir lancé sa requête
     */
    std::string referent;

    /**
     * L'en-tête User-Agent de la requête
     */
    std::string userAgent;

    //----------------------------------------------------- Méthodes privées
    ApacheLog & hydrate(const std::string & ligne);
};

#endif  // SRC_MODELES_APACHELOG_H_
