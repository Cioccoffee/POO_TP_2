/*************************************************************************
 Catalogue  -  description
 -------------------
 début                : 18 oct. 2017
 copyright            : (C) $YEAR$ par Caraiman and Gallé
 e-mail               : ocaraiman
 *************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Xxx.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//TYPEDEF IF NECESSARY

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue : public ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Catalogue();
	// Mode d'emploi :
	//
	// Contrat :
	//


	virtual ~Catalogue();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
