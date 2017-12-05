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
	if (taille == 0) {
		tete->valeur = val;
		dernierElement = tete;
		tete->suivant = dernierElement;

	} else {
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

unsigned int ListeTrajets::Taille() {
	return taille;
} //----- Fin de Taille

Trajet * ListeTrajets::getTrajet(unsigned int i) {
	unsigned int j = 0;

	if (taille == 0 || i > taille) {
		return NULL;
	} else {
		CelluleTrajet *elCourant = tete;
		while ((j < i) && (elCourant->suivant != NULL)) {
			//(elCourant->valeur)->Afficher();
			elCourant = elCourant->suivant;
			j++;
		}

		//Dernier element dont le suivant est null
		return elCourant->valeur;
	}
}

void ListeTrajets::Retirer(unsigned int i)
// Algorithme :
	{

	//condition existence du trajet
	if (taille == 0 || i > taille)
	{
		//plz sweetie CHANGE THIS !!!!!
	}
		//return NULL;

	else if (i == 0) {
		//cout<<"are we in ?"<<endl;
		if (taille != 1){
			//cout << "suivant de tete = " << endl;
			//((tete->suivant)->valeur) ->Afficher();
			tete = tete->suivant;
			//cout << "nouvelle tete = " << endl;
			//(tete->valeur)->Afficher();
			//taille--;
		}
		else{
			tete->valeur = NULL;
			//cout <<"we acually did the tete->valeur = NULL;"<<endl;
		}

	} else {

		//cout <<"we are in the else actually"<<endl;

		CelluleTrajet * precedent = tete;
		for (unsigned int j = 0; (j < i - 1 ) && (precedent->suivant != NULL); j++) {
			//if (precedent->suivant != NULL)
				precedent = precedent->suivant;
				//cout <<"on parcourt"<<endl;
		}

		CelluleTrajet * aRetirer;

		if (precedent->suivant != NULL) {
			aRetirer = precedent->suivant;

			//cout <<"celui a retirer n'est pas nul"<<endl;

			//on remplace aRetirer par son suivant dans la liste
			if (aRetirer != dernierElement)
			{
				//cout <<"on remplace un element qui est pas le dernier"<<endl;
				precedent->suivant = aRetirer->suivant;
				//taille--;
			}
			else if (i == (taille-1))
			{
				//cout << "on remplace le dernier element"<<endl;
				dernierElement = precedent;
				precedent->suivant = NULL;//nouvelle queue
				//taille--;
			}

		}
	}
	taille--;

} //----- Fin de Retirer

ListeTrajets::ListeTrajets()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

	tete = new CelluleTrajet;
	//tete = NULL;
	//dernierElement = NULL;
	//dernierElement = new CelluleTrajet;
	tete->suivant = dernierElement;

	taille = 0;

} //----- Fin de ListeTrajets

ListeTrajets::ListeTrajets(const ListeTrajets &uneListe) {
	ListeTrajets * resultat = new ListeTrajets;

	if(uneListe.taille > 0) {


		resultat->tete = uneListe.Tete();

		CelluleTrajet * courant = resultat->tete;
		CelluleTrajet * courantACopier = uneListe.tete;

		while(courantACopier != uneListe.dernierElement) {

			courant->valeur = courantACopier->valeur ;
			courant->suivant = courantACopier->suivant;

			courant = courant->suivant;
			courantACopier = courantACopier->suivant;

		}

		dernierElement = new CelluleTrajet;
		resultat->dernierElement = uneListe.Queue();
	}
}

ListeTrajets::~ListeTrajets()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

	CelluleTrajet *elSupprime = tete;
	CelluleTrajet *elSupprimeSuiv=elSupprime;

	if(tete->suivant== dernierElement) cout<<"defdsfs"<<endl;

	//pb dans Ajouter --> revoir

	tete->valeur->Afficher();

	while (elSupprime->suivant != dernierElement) {
		elSupprimeSuiv = elSupprime->suivant;
		delete elSupprime->valeur;
		delete elSupprime;
		elSupprime = elSupprimeSuiv;
		cout<<"dest"<<endl;

	}

	/*delete elSupprimeSuiv;
	delete elSupprime;*/

	delete tete->valeur;
	delete tete;
	//delete dernierElement;


} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

