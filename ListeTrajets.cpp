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


void ListeTrajets::Afficher() const
// Algorithme :
// parcours de chaque élément de la liste et son affichage
{
	if (taille == 0) {
		cout << "Liste vide" << endl;
	} else {
		CelluleTrajet *elCourant = tete;
		while (elCourant->suivant != NULL) {
			(elCourant->valeur)->Afficher();
			elCourant = elCourant->suivant;
		}

		//Dernier element dont le suivant est null
		(elCourant->valeur)->Afficher();

	}

} //----- Fin de Méthode

void ListeTrajets::Ajouter(Trajet *val) {
	if (taille == 0) 
	{
		tete->valeur = val;
		tete->suivant = NULL;
		dernierElement = tete;

	} else 
	{
		CelluleTrajet *nouvelElement = new CelluleTrajet;
		nouvelElement->valeur = val;
		nouvelElement->suivant = NULL;

		dernierElement->suivant = nouvelElement;
		dernierElement = nouvelElement;
	}

	taille++;

} //----- Fin de Ajouter

CelluleTrajet * ListeTrajets::Tete() const {
	return tete;
} //----- Fin de Tete

CelluleTrajet * ListeTrajets::Queue() const {
	return dernierElement;
} //----- Fin de Queue

unsigned int ListeTrajets::Taille() 
{
	return taille;
} //----- Fin de Taille

Trajet * ListeTrajets::getTrajet(unsigned int i)
{
	unsigned int j = 0;

	if (taille == 0 || i > taille) {
		return NULL;

	} else {
		CelluleTrajet *elCourant = tete;
		while ((elCourant->suivant != NULL) && (j < i)) {
			elCourant = elCourant->suivant;
			j++;
		}

		//Dernier element dont le suivant est null
		return elCourant->valeur;
	}
}

int ListeTrajets::Retirer(unsigned int i)
// Algorithme :
		{
	if (i == 0) {
		tete = tete->suivant;
	} else {
		CelluleTrajet * precedent = new CelluleTrajet;
		precedent = tete;
		for (unsigned int j = 0; j < i - 1; j++) {
			precedent = precedent->suivant;
		}
		CelluleTrajet * aRetirer = precedent->suivant;
		//on remplace aRetirer par son suivant dans la liste
		precedent->suivant = aRetirer->suivant;
		if (i == taille)
			dernierElement = precedent->suivant; //nouvelle queue
	}
	return 0;
} //----- Fin de Retirer

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

ListeTrajets::ListeTrajets(const ListeTrajets &uneListe) {
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

	while (elSupprime->suivant != dernierElement) {
		elSupprimeSuiv = elSupprime->suivant;
		delete elSupprime;
		CelluleTrajet *elSupprime = elSupprimeSuiv;
	}

	delete elSupprime;
	delete dernierElement;

} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

