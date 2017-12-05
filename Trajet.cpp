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
//#include ""

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//


void Trajet:: Afficher () const
// Algorithme :
{
	cout<<"afficher mere"<<endl;
} //----- Fin de Méthode

const char * Trajet::Depart() const
 // Algorithme :
 //
 {
	cout <<"je suis ds mere"<<endl;
	return villeDepart;

  } //----- Fin de Méthode

const char * Trajet::Arrivee() const
// Algorithme :
//
{
	return villeArrivee;

} //----- Fin de Méthode

const char * Trajet::Transport() const
// Algorithme :
//
{
	return moyenTransport;
} //----- Fin de M�thode

/*virtual ListeTrajets * Trajet::Trajets()  const
// Algorithme :
//
{
	ListeTrajets * lt;
	return lt;
} //----- Fin de M�thode*/

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


//	villeDepart = "dgs";
//	villeArrivee ="fsseds";
//	moyenTransport ="fseds";

} //----- Fin de Trajet

Trajet::Trajet(Trajet * t)
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


