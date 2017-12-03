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
#include <cstring>

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
	unsigned int i;
	CelluleTrajet * actuelle = trajets->Tete();
	cout << "Trajet ";

	Trajet * actuel = actuelle->valeur;
	Trajet * precedent =actuel;

	for (i = 0; i < trajets->Taille(); i++)
	{

		actuel = actuelle->valeur;

		//verification contrainte de ville : precedent.arrivee = actuel.depart?
		if(i>0)
		{

			if (strcmp(precedent->Arrivee(),actuel->Depart()) != 0)
			{
				cout<<"non valide "<<endl;
				break;
			}

		}

		//Afichage trajet
		if(i!=0) cout << " - ";
		cout<< "de " << actuel->Depart() << " a " << actuel->Arrivee() << " en " << actuel->Transport()<<endl;


		precedent = actuel;
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
	return trajetEnQueue->Arrivee(); //choisi la méthode adaptée au type (TS ou TC)

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

TrajetCompose::TrajetCompose(const TrajetCompose & t)
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif

trajets = t.trajets;


} //----- Fin de Trajet

TrajetCompose::TrajetCompose(ListeTrajets * lt)
// Algorithme :
{
	trajets = lt;

#ifdef MAP
	//cout << "Appel au constructeur de <Trajet>" << endl;
#endif


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


