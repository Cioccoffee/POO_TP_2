/*************************************************************************
 TrajetCompose  -  description
 -------------------
 début                : 18 oct. 2017
 copyright            : (C) $YEAR$ par Caraiman and Gallé
 e-mail               : ocaraiman
 *************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier Xxx.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h" 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//TYPEDEF IF NECESSARY

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	TrajetCompose();
	// Mode d'emploi :
	//
	// Contrat :
	//

	TrajetCompose(ListeTrajets * lt);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual void Afficher() const;

	void Ajouter(const Trajet * t);

	const char * Depart() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	const char * Arrivee() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	ListeTrajets * TrajetCompose::Trajets() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	ListeTrajets * trajets;


};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
