/*************************************************************************
                           AnalyseLogController  -  Controller
                             -------------------
    début                : 03/02/2021
    copyright            : (C) 2021 par Inès Leclercq--Cuvelier, François Foltête, Jorick Pepin
    e-mail               : ines.leclercq---cuvelier@insa-lyon.fr, francois.foltete@insa-lyon.fr, jorick.pepin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AnalyseLogController> (fichier AnalyseLogController.h) ----------------
#ifndef SRC_ANALYSELOGCONTROLLER_H_
#define SRC_ANALYSELOGCONTROLLER_H_

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

#endif  // SRC_ANALYSELOGCONTROLLER_H_
