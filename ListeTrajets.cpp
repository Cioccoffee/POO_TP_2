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
		CelluleTrajet *elCourant = tete;
		while (elCourant->suivant != NULL) {
			(elCourant->valeur)->Afficher();
			elCourant = elCourant->suivant;
		}

		//Dernier element dont le suivant est null
		(elCourant->valeur)->Afficher();

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
		nouvelElement->valeur = val;
		nouvelElement->suivant = NULL;

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

Trajet ListeTrajets::getTrajet(int i)
{
	CelluleTrajet * courant = new CelluleTrajet;
	courant = tete;
	for(int j = 0; j < i && j < taille; j++)
	{
		courant = courant->suivant;
	}
	return Trajet resultat /*= new */ Trajet(courant->valeur);

}

int ListeTrajets::Retirer(int i)
// Algorithme :
{
	if(i ==0)
	{
		tete = tete->suivant;
	}
	else
	{
		CelluleTrajet * precedent = new CelluleTrajet;
		precedent = tete;
		for(int j = 0; j < i-1; j++)
		{
			precedent = precedent->suivant;
		}
		CelluleTrajet * aRetirer = precedent->suivant;
		//on remplace aRetirer par son suivant dans la liste
		precedent->suivant = aRetirer->suivant;
		if(i == taille) dernierElement = precedent->suivant; //nouvelle queue
	}
	return 0;
} //----- Fin de Méthode

int ListeTrajets::Retirer(Trajet t)
// Algorithme :
{
	return 0;
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
	dernierElement = tete;
	tete->suivant = dernierElement;

	taille = 0;

} //----- Fin de ListeTrajets



///ListeTrajets::ListeTrajets(const ListeTrajets &uneListe)
//{
//	if(uneListe.taille > 0) {
//		tete = new CelluleTrajet;
//		tete = uneListe.tete;
//
//
//		CelluleTrajet * courant = uneListe.tete;
//
//		while(courant->suivant != uneListe.dernierElement) {
//			CelluleTrajet * element = new CelluleTrajet;
//			element = courant->suivant;
//			courant = courant->suivant;
//		}
//
//		dernierElement = new CelluleTrajet;
//		dernierElement = uneListe.dernierElement;
//	}
//}

ListeTrajets::~ListeTrajets()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

	CelluleTrajet *elSupprime = tete;
	CelluleTrajet *elSupprimeSuiv;

	while (elSupprime->suivant != dernierElement)  {
		elSupprimeSuiv = elSupprime->suivant;
		delete elSupprime;
		CelluleTrajet *elSupprime = elSupprimeSuiv;
	}

	delete elSupprime;
	delete dernierElement;

} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


