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
#include <cstring>


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

ListeTrajets rechercheAvancee(char  * dep, char * arrivee, ListeTrajets * catalogue) //retour par valeur pour éviter perte de résultat
																					// /!\ constructeur de copie
{
	/*char * depart;
	strcpy(depart,dep);
	char * arrivee;
	strcpy(arrivee,arr);*/

	ListeTrajets * intermede = new ListeTrajets;
	ListeTrajets result = new ListeTrajets;

	//ajout des trajets qui partent du bon endroit
	for(int i = 0; i < catalogue->Taille(); i++)
	{
		if(strcpr(catalogue->getTrajet(i), dep){
			intermede->Ajouter(new Trajet(catalogue->getTrajet(i)));
		}

	}

	//recherche des matchs et des resultats valides
	while(intermede->Taille > 0)
	{
		for(int i = 0; i < intermede->Taille(); i++)
			{

			//regarder si arrivee matche demande si oui => result
			if(arr.compare( (intermede->getTrajet(i))->Arrivee() ) == 0)
			{
				result.Ajouter(intermede->getTrajet(i));
			}

			//sinon regarder si arrivee matche qqch
			//et créer liste de tout ce qui matche pour ce trajet
			//=> ajouter à sa place tous ceux qui le contiennent augmenté
			else
			{
				ListeTrajets * correspondent = new ListeTrajets;
				for(int j = 0; j < catalogue->Taille(); j++)
				{
					if( ( (catalogue.getTrajet(j))->Depart() ).compare( (intermede->getTrajet(i))->Arrivee() ) == 0)
					{
						correspondent->Ajouter(catalogue.getTrajet(j));
					}
				}

				if(correspondent->Taille()==0){
					//intermede->Retirer(i);
				}
				else
				{
					ListeTrajets aAjouter = new ListeTrajets;
					aAjouter->Ajouter(intermede.getTrajet(i));
					for(int j = 0; j < correspondent->Taille(); j++)
					{
						aAjouter->Ajouter(correspondent->getTrajet(j));
						intermede->Ajouter(new TrajetCompose(aAjouter));
						//aAjouter->Retirer(correspondent->getTrajet(j));

					}
					//intermede->Retirer(i);
				}
			}
			//sinon poubelle

			}
	}

}

int main ()
// Algorithme :
{

	ListeTrajets * catalogue = new ListeTrajets;

	TrajetSimple *ts1 = new TrajetSimple("A","B","MT");
	Trajet * ts2 = new TrajetSimple("A","C","MT2");
	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts1);
	lt1->Ajouter(ts2);*/

	//Catalogue *c = new Catalogue;
	//c->Ajouter(ts1);
	//c->Ajouter(ts2);
	//c->Afficher();

	//catalogue = tete;
	//testListe();
	testTC();

	Menu();

	int action;
	cin >> action;
	switch(action)
	{
		//TS
		case 1 :
			const char * depart;
			const char * arrivee;
			const char * transport;
			cout << "Ville de départ ?"<<endl;
			cin >> depart;
			cout << "Ville d'arivée ?"<<endl;
			cin >> arrivee;
			cout << "Moyen de transport ?"<<endl;
			cin >> transport;

			catalogue->Ajouter(new  TrajetSimple(depart, arrivee, transport));
			break;

		//TC

		case 2 :
			TrajetCompose * tc = new TrajetCompose; //est-ce qu'il faut qu'il soit dynamique ?????
			cout << "De combien de trajets est composé ce trajet composé ?"<<endl;
			int i = 0;
			int n;
			cin >> n;
			while(i<n){
				//while(arrivee d'avant != depart de maintenant) => sinon on peut le remplir pour lui
				cout << "Saisie du trajet n°"<< i+1;
				const char * depart;
				const char * arrivee;
				const char * transport;
				cout << "Ville de départ ?"<<endl;
				cin >> depart;
				cout << "Ville d'arivée ?"<<endl;
				cin >> arrivee;
				cout << "Moyen de transport ?"<<endl;
				cin >> transport;
				tc->Ajouter(new  TrajetSimple(depart,arrivee,transport));
				i++;
			}
			catalogue->Ajouter(tc);
			break;

		//catalogue
		case 3 :
			c->Afficher();
			break;

		//search
		case 4 :
			//appel méthode de recherche
			char * depart;
			char * arrivee;
			cout << "Quelle est votre ville de départ ?" << endl;
			cin >> depart;
			cout << "Quelle est votre destination ?" << endl;
			cin >> arrivee;

			//recherche(depart,arrivee,catalogue); doit renvoyer liste => valeur

			break;

		//exit
		case 5 :
			//fermer la fenêtre ?
			break;


	}


	return 0;
}
