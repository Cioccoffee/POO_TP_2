/*************************************************************************
 ListeTrajets  -  description
 -------------------
 début                : 18 oct. 2017
 copyright            : (C) $YEAR$ par Caraiman and Gallé
 e-mail               : ocaraiman
 *************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier Xxx.h) ----------------
#if ! defined ( ListeTrajets_H )
#define ListeTrajets_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct CelluleTrajet {
	Trajet *valeur;
	CelluleTrajet *suivant;
};

//TYPEDEF IF NECESSARY
//typedef int Tab[];

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	ListeTrajets();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Afficher() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//
	void Ajouter(Trajet * val);

	unsigned int Taille();

	virtual ~ListeTrajets();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	unsigned int taille;
	CelluleTrajet *tete;
	CelluleTrajet * dernierElement; //pointeur vers le dernier element de la liste

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
