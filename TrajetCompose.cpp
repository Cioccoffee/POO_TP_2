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
#include "TrajetCompose.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//

// Trajet::Méthode ( )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose::Afficher() const
// Algorithme :
{
	int i;
	CelluleTrajet * actuelle;
	actuelle = trajets->Tete;
	Trajet * actuel;
	cout << "Trajet "
	for (i = 0; i < trajets->Taille; i++)
	{
		actuel = actuelle->valeur;
		actuel.Afficher;
		//cout<< "de " << actuel->Depart << " à " << actuel->Arrivee << actuel
		actuelle = actuelle->suivant;
	}
} //----- Fin de Méthode

const char * TrajetCompose::Depart() const
// Algorithme :
//
{

	return trajets->Tete;
} //----- Fin de Méthode

const char * TrajetCompose::Arrivee() const
// Algorithme :
//
{
	return trajets->Queue;
} //----- Fin de Méthode

ListeTrajets * TrajetCompose::Trajets()  const
// Algorithme :
//
{
	return trajets;
} //----- Fin de Méthode

  //------------------------------------------------- Surcharge d'opérateurs
  //Xxx & Xxx::operator = ( const Xxx & unXxx )
  // Algorithme :
  //
  //{
  //} //----- Fin de operator =

  //-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif

	

} //----- Fin de Trajet

TrajetCompose::TrajetCompose()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif



} //----- Fin de Trajet

TrajetCompose::TrajetCompose(ListeTrajets * lt)
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif

	trajets = lt;

} //----- Fin de Trajet

TrajetCompose::~TrajetCompose()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <Trajet>" << endl;
#endif

} //----- Fin de ~Trajet

  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées


