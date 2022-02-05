/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 04/02/2022
    copyright            : (C) 2022 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AnalyseLogController> (fichier AnalyseLogController.h) ----------------
#ifndef AnalyseLogController_H_
#define AnalyseLogController_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseLogController>
//
//
//------------------------------------------------------------------------

class AnalyseLogController {
 public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    AnalyseLogController& operator=(const AnalyseLogController& _AnalyseLogController);
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    AnalyseLogController(const AnalyseLogController& _AnalyseLogController);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AnalyseLogController();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AnalyseLogController();
    // Mode d'emploi :
    //
    // Contrat :
    //

 protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <AnalyseLogController>

#endif  // AnalyseLogController_H_
