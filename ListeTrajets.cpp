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
		elCourant->valeur = new Trajet;
		elCourant = tete;
		while (elCourant->suivant != NULL) {
			(elCourant->valeur)->Afficher();
			elCourant = elCourant->suivant;
		}

		//Dernier element dont le suivant est null
		(elCourant->valeur)->Afficher();

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
		nouvelElement->valeur = new Trajet;

		nouvelElement->valeur = val;
		//nouvelElement->suivant = new CelluleTrajet;

		dernierElement->suivant = nouvelElement;
		dernierElement = nouvelElement;

	}

	taille++;

} //----- Fin de Méthode

CelluleTrajet * ListeTrajets::Tete() const
// Algorithme :
//
{
	return tete;
} //----- Fin de Tete

CelluleTrajet * ListeTrajets::Queue() const
// Algorithme :
//
{
	return dernierElement;
} //----- Fin de Element

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
	tete->valeur = new Trajet;
	//tete>suivant = new CelluleTrajet;

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


