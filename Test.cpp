/*************************************************************************
                           Test  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- RÃ©alisation du module <Test> (fichier Test.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systÃ¨me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privÃ©es

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
	Trajet * ts2 = new TrajetSimple("B","C","MT2");

	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts1);
	lt1->Ajouter(ts2);


	TrajetCompose * tc1 = new TrajetCompose(lt1);
	tc1->Afficher();

	//cout << tc1->Depart();
	//cout << tc1->Arrivee();

	ListeTrajets * trajetsTC1 = tc1->Trajets();
	//trajetsTC1->Afficher();



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


static void Menu()
{
	cout<<"Choisissez l'option: "<<endl;
	cout<<"1. Ajouter Trajet Simple "<<endl;
	cout<<"2. Ajouter Trajet Compose "<<endl;
	cout<<"3. Afficher le catalogue des trajets "<<endl;
	cout<<"4. Rechercher un parcours "<<endl;
	cout<<"5. Sortir"<<endl;

	//finir le menu

}

int main ()
// Algorithme :
{

	/*ListeTrajets * catalogue = new ListeTrajets;

	TrajetSimple *ts1 = new TrajetSimple("A","B","MT");
	Trajet * ts2 = new TrajetSimple("A","C","MT2");
	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts1);
	lt1->Ajouter(ts2);*/

	Catalogue *c = new Catalogue;
	//c->Ajouter(ts1);
	//c->Ajouter(ts2);
	//c->Afficher();

	//catalogue = tete;
	//testListe();
	testTC();

	Menu();

	int action;
	scanf("%d",&action);
	switch(action)
	{
		//TS
		case 1 :
			const char * depart;
			const char * arrivee;
			const char * transport;
			cout << "Ville de départ ?";
			scanf("%d", &depart);
			cout << "Ville d'arivée ?";
			scanf("%d", &arrivee);
			cout << "Moyen de transport ?";
			scanf("%d", &transport);

			c->Ajouter(new * TrajetSimple(depart, arrivee, transport));
			break;

		//TC

		case 2 :
			TrajetCompose * tc;
			cout << "De combien de trajets est composé ce trajet composé ?"
			int i = 0;
			int n;
			scanf("%d", &n);
			while(i<n){
				cout << "Saisie du trajet n°"<< i+1;
				const char * depart;
				const char * arrivee;
				const char * transport;
				cout << "Ville de départ ?";
				scanf("%d", &depart);
				cout << "Ville d'arivée ?";
				scanf("%d", &arrivee);
				cout << "Moyen de transport ?";
				scanf("%d", &transport);
				tc->Ajouter(new * TrajetSimple(depart,arrivee,transport));
				i++;
			}
			break;

		//catalogue
		case 3 :
			c->Afficher();
			break;

		//search
		case 4 :
			//appel méthode de recherche
			break;

		//exit
		case 5 :
			//fermer la fenêtre ?
			break;


	}


	return 0;
}
