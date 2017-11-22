/*************************************************************************
Trajet  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Trajet> (fichier Trajet.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
//

// Trajet::M�thode ( )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void TrajetCompose::Afficher() const
// Algorithme :
{
	int i;
	CelluleTrajet * actuelle;
	actuelle = trajets->Tete();
	Trajet * actuel;
	cout << "Trajet ";
	for (i = 0; i < trajets->Taille(); i++)
	{
		actuel = actuelle->valeur;
		actuel->Afficher();
		//cout<< "de " << actuel->Depart() << " � " << actuel->Arrivee << actuel
		actuelle = actuelle->suivant;
	}
} //----- Fin de M�thode

void TrajetCompose::Ajouter(const Trajet * t)
// Algorithme :
//
{

} //----- Fin de Ajouter

const char * TrajetCompose::Depart() const
// Algorithme :
//
{
	CelluleTrajet * teteTrajets = trajets->Tete();
	Trajet * trajetEnTete = teteTrajets->valeur;
	return trajetEnTete->Depart();
} //----- Fin de M�thode

const char * TrajetCompose::Arrivee() const
// Algorithme :
//
{
	CelluleTrajet * queueTrajets = trajets->Queue();
	Trajet * trajetEnQueue = queueTrajets->valeur;
	return trajetEnQueue->Depart(); //choisi la méthode adaptée au type (TS ou TC)

} //----- Fin de M�thode

ListeTrajets * TrajetCompose::Trajets()  const
// Algorithme :
//
{
	return trajets;
} //----- Fin de M�thode

  //------------------------------------------------- Surcharge d'op�rateurs
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

/*TrajetCompose::TrajetCompose()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif



} //----- Fin de Trajet*/

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

  //----------------------------------------------------- M�thodes prot�g�es


