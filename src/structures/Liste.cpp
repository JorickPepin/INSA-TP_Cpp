/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Liste.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Liste::Taille ( ) const
// Algorithme :
//
{
    int taille = 0;

    if (premier)
        taille = premier->Taille();

    return taille;
} //----- Fin de Taille


void Liste::Ajouter ( const Trajet* _trajet )
// Algorithme :
//
{
    if (premier)
        premier->Ajouter(new Element(_trajet));
    else 
        premier = new Element(_trajet);

} //----- Fin de Ajouter

//------------------------------------------------- Surcharge d'opérateurs
Liste & Liste::operator = ( const Liste & _liste )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Liste::Liste ( const Liste & _liste )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Liste>" << endl;
#endif
} //----- Fin de Liste (constructeur de copie)


Liste::Liste ( ) : premier(nullptr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
} //----- Fin de Liste


Liste::~Liste ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif

    delete premier;
} //----- Fin de ~Liste


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

