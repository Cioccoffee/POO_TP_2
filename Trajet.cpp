/*************************************************************************
 Trajet  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//

// Trajet::Méthode ( )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Trajet:: Afficher () const
// Algorithme :
{
} //----- Fin de Méthode

const char * Trajet::Depart() const
 // Algorithme :
 //
 {

  } //----- Fin de Méthode

const char * Trajet::Arrivee() const
// Algorithme :
//
{

} //----- Fin de Méthode

const char * Trajet::Transport() const
// Algorithme :
//
{
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet()
// Algorithme :
		{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif


} //----- Fin de Trajet



Trajet::~Trajet()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <Trajet>" << endl;
#endif

} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


