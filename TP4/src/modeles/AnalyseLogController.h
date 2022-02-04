/*************************************************************************
                           AnalyseLogController  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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

class AnalyseLogController : public Ancetre {
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
