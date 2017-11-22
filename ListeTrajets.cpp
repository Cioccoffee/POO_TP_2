/*************************************************************************
 ListeTrajets  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//

// ListeTrajets::Méthode ( )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void ListeTrajets:: Afficher () const
// Algorithme :
{
	if(taille ==0) {
		cout << "Liste vide"<<endl;
	}
	else {
		//cout << *tete->valeur <<endl;

		CelluleTrajet * elCourant = new CelluleTrajet;
		elCourant->valeur = new int;
		elCourant = tete;
		while (elCourant->suivant != NULL) {
			cout << *elCourant->valeur <<endl;
			elCourant = elCourant->suivant;
		}

		//Dernier element dont le suivant est null
		cout << *elCourant->valeur <<endl;

		delete elCourant;
	}

} //----- Fin de Méthode

void ListeTrajets:: Ajouter (Trajet *val)
// Algorithme :
{
	if (taille == 0)
	{
		tete->valeur = val;
		tete->suivant = NULL;
		dernierElement = tete;

	}else
	{
		CelluleTrajet *nouvelElement = new CelluleTrajet;
		nouvelElement->valeur = new int;

		nouvelElement->valeur = val;
		nouvelElement->suivant = NULL;

		dernierElement->suivant = nouvelElement;
		dernierElement = nouvelElement;

	}

	taille++;

} //----- Fin de Méthode

unsigned int ListeTrajets:: Taille ()
// Algorithme :
{
	return taille;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets()
// Algorithme :
		{
#ifdef MAP
	//cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

	tete = new CelluleTrajet;
	tete->valeur = new int;


	dernierElement = new CelluleTrajet;
	dernierElement = tete;
	//	dernierElement->valeur = new int;

	taille = 0;

} //----- Fin de ListeTrajets



ListeTrajets::~ListeTrajets()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

	CelluleTrajet *elSupprime = new CelluleTrajet;
	CelluleTrajet *elSupprimeSuiv = new CelluleTrajet;
	elSupprime = tete;
	while (elSupprime->suivant != dernierElement)  {

		elSupprimeSuiv = elSupprime->suivant;
		delete elSupprime->valeur;
		delete elSupprime;
		CelluleTrajet *elSupprime = new CelluleTrajet;
		elSupprime = elSupprimeSuiv;

	}
	delete elSupprime;
	delete elSupprimeSuiv;
	delete dernierElement;


} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


