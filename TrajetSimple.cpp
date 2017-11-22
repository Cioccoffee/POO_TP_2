/*************************************************************************
 TrajetSimple  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//

// TrajetSimple::Méthode ( )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple:: Afficher () const
// Algorithme :
{
	cout << "de " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
} //----- Fin de Méthode

const char * TrajetSimple:: Depart() const
// Algorithme :
{
	return villeDepart;
} //----- Fin de Méthode

const char * TrajetSimple:: Arrivee() const
// Algorithme :
{
	return villeArrivee;
} //----- Fin de Méthode

const char * TrajetSimple::Transport() const
// Algorithme :
//
{
	return moyenTransport;
} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char * depart, const char * arrivee, const char * transport)
// Algorithme :
		{
#ifdef MAP
	//cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

	villeDepart = depart;
	villeArrivee = arrivee;
	moyenTransport = transport;

} //----- Fin de TrajetSimple



TrajetSimple::~TrajetSimple()
// Algorithme :
{
#ifdef MAP
	//cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


