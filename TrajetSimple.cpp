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
} //----- Fin de Méthode


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

TrajetSimple::TrajetSimple(const TrajetSimple & t)
{
#ifdef MAP
	//cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

	villeDepart = t.villeDepart ;
	villeArrivee = t.villeArrivee;
	moyenTransport = t.moyenTransport;

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


