/*************************************************************************
 Trajet  -  description
 -------------------
 début                : 18 oct. 2017
 copyright            : (C) $YEAR$ par Caraiman and Gallé
 e-mail               : ocaraiman
 *************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Xxx.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//TYPEDEF IF NECESSARY
//typedef int Tab[];

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Trajet();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual void Afficher() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	virtual const char * Depart() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	virtual const char * Arrivee() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//

	virtual const char * Transport() const;
	// Mode d'emploi :
	//
	// Contrat :
	//
	//
	virtual ~Trajet();
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
