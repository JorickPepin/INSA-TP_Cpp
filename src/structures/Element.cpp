/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 21/11/2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Element.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Element::Taille ( ) const
// Algorithme :
//
{
    int taille = 1;

    if (suivant)
        taille += suivant->Taille();

    return taille;

} //----- Fin de Taille

void Element::Ajouter ( Element* _element )
// Algorithme :
//
{
    if (!suivant)
        suivant = _element;
    else
        suivant->Ajouter(_element);

} //----- Fin de Ajouter

//------------------------------------------------- Surcharge d'opérateurs
Element & Element::operator = ( const Element & _element )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Element::Element ( const Element & _element )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Element>" << endl;
#endif
} //----- Fin de Element (constructeur de copie)


Element::Element ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Element>" << endl;
#endif
} //----- Fin de Element


Element::Element (const Trajet* _trajet) : trajet(_trajet), suivant(nullptr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Element>" << endl;
#endif
} //----- Fin de Element


Element::~Element ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Element>" << endl;
#endif

    delete trajet;
    delete suivant;
} //----- Fin de ~Element


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

