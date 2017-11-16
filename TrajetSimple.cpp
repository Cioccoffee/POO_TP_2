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

virtual void TrajetSimple:: Afficher () const
// Algorithme :
{
} //----- Fin de Méthode

char * TrajetSimple:: VilleDepart()
// Algorithme :
{
	return 0;
} //----- Fin de Méthode

char * TrajetSimple:: VilleArrivee()
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


