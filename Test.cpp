/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Test> (fichier Test.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

static void testConstructeur()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{


} //----- fin de testConstructeur

static void testTS()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	TrajetSimple * ts1 = new TrajetSimple("A","B","MT"); //il faut que ts1 soit un pointeur
	Trajet * ts2 = new TrajetSimple("A","C","MT2");

	ts1->Afficher();
	//cout << ts1->Depart();
	//cout << ts1->Arrivee();
	//cout << ts1->Transport();
	ts2->Afficher();
//	cout << ts2->Depart();
//	cout << ts2->Arrivee();
//	cout << ts2->Transport();

	delete ts1;
	delete ts2;
}

static void testTC()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	TrajetSimple *ts1 = new TrajetSimple("A","B","MT");
	Trajet * ts2 = new TrajetSimple("A","C","MT2");

	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts1);
	lt1->Ajouter(ts2);


	TrajetCompose * tc1 = new TrajetCompose(lt1);
	tc1->Afficher();

	//cout << tc1->Depart();
	//cout << tc1->Arrivee();

	ListeTrajets * trajetsTC1 = tc1->Trajets();
	trajetsTC1->Afficher();



	delete lt1;
	delete ts1;
	delete ts2;
	delete tc1;

}

static void test()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
}


static void testListe()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
//	int a = 1, b = 2;
//	int *pt = &a;
//	int *pt2 =&b;
//
//	ListeTrajets lt;
//	lt.Afficher();
//
//	lt.Ajouter(pt);
//	lt.Ajouter(pt2);
//	lt.Afficher();

}

//static void Catalogue() {
//	ListeTrajets *catalogue;
//	catalogue->Afficher();
//}
int main ()
// Algorithme :
{

	ListeTrajets * catalogue = new ListeTrajets;

	TrajetSimple *ts1 = new TrajetSimple("A","B","MT");
	Trajet * ts2 = new TrajetSimple("A","C","MT2");
	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts1);
	lt1->Ajouter(ts2);

	Catalogue *c = new Catalogue;
	c->Ajouter(ts1);
	c->Ajouter(ts2);
	c->Afficher();

	//catalogue = tete;
	//testListe();
	//testTC();



	return 0;
}
