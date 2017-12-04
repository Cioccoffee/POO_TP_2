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
// parcours de chaque élément de la liste et son affichage

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

Trajet * ListeTrajets::getTrajet(unsigned int i)
{

	unsigned int j = 0;

	if(taille ==0 || i>taille) {
			return NULL;
		}
		else {
			CelluleTrajet *elCourant = tete;
			while ((j<i)&&(elCourant->suivant != NULL)) {
				//(elCourant->valeur)->Afficher();
				elCourant = elCourant->suivant;
				j++;
			}

			//Dernier element dont le suivant est null
			//(elCourant->valeur)->Afficher();
			return elCourant->valeur;
		}
}

//const char * ListeTrajets::DepartTrajet(unsigned int i)
//{
//	CelluleTrajet * courant = tete;
//		for(unsigned int j = 0; j < i && j < taille; j++)
//		{
//			courant = courant->suivant;
//		}
//
//
//		return courant->depart;
//}
//
//const char * ListeTrajets::ArriveeTrajet(unsigned int i)
//{
//	CelluleTrajet * courant = tete;
//		for(unsigned int j = 0; j < i && j < taille; j++)
//		{
//			courant = courant->suivant;
//		}
//
//
//		return courant->arrivee;
//}
//
//char * ListeTrajets::NomTrajet(unsigned int i)
//{
//	CelluleTrajet * courant = tete;
//		for(unsigned int j = 0; j < i && j < taille; j++)
//		{
//			courant = courant->suivant;
//		}
//
//
//		return courant->nomTrajet;
//}

int ListeTrajets::Retirer(unsigned int i)
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
		for(unsigned int j = 0; j < i-1; j++)
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



ListeTrajets::ListeTrajets()
// Algorithme :
		{
#ifdef MAP
	//cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif


	tete = new CelluleTrajet;
	//tete = NULL;
	dernierElement = NULL;
	tete->suivant = dernierElement;

	taille = 0;

} //----- Fin de ListeTrajets



ListeTrajets::ListeTrajets(const ListeTrajets &uneListe)
{
//	ListeTrajets resultat = new ListeTrajets;
//
//	if(uneListe.taille > 0) {
//
//
//		resultat.tete = uneListe->Tete();
//
//		CelluleTrajet * courant = resultat.tete;
//		CelluleTrajet * courantACopier = uneListe->tete;
//
//		while(courantACopier != uneListe->dernierElement) {
//
//			courant->valeur = courantACopier->valeur ;
//			courant->suivant = courantACopier->suivant;
//
//			courant = courant->suivant;
//			courantACopier = courantACopier->suivant;
//
//		}
//
//		dernierElement = new CelluleTrajet;
//		resultat.dernierElement = uneListe->Queue();
//	}
}

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


