/*************************************************************************
 TrajetSimple  -  description
 -------------------
 début                : 18 oct. 2017
 copyright            : (C) $YEAR$ par Caraiman and Gallé
 e-mail               : ocaraiman
 *************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier Xxx.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//TYPEDEF IF NECESSARY

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	TrajetSimple(const char * depart, const char * arrivee, const char * transport);
	// Mode d'emploi :
	//
	// Contrat :
	//

	TrajetSimple(TrajetSimple * t);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual void Afficher() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

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

	const char * Transport() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	virtual ~TrajetSimple();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	const char * villeDepart;
	const char * villeArrivee;
	//a revoir
	const char * moyenTransport; //enum ???


};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
