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
#include <cstring>

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
	TrajetSimple * ts1 = new TrajetSimple("A", "B", "MT"); //il faut que ts1 soit un pointeur
	Trajet * ts2 = new TrajetSimple("A", "C", "MT2");

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
	TrajetSimple *ts1 = new TrajetSimple("A", "B", "MT");
	Trajet * ts2 = new TrajetSimple("B", "C", "MT2");

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

//static void Catalogue() {
//	ListeTrajets *catalogue;
//	catalogue->Afficher();
//}

//A FINIR
static void RechercheSimple(ListeTrajets & catalogue, const char * dep,
		const char * arr) {

	bool trouve = false;

	for (unsigned int i = 0; i < catalogue.Taille(); i++) {

		const char * depart = catalogue.DepartTrajet(i);
		const char * arrivee = catalogue.ArriveeTrajet(i);

		if (strcmp(depart, dep) == 0 && strcmp(arrivee, arr) == 0) {
			trouve = true;
			cout << "Trajet " << i << endl;
			catalogue.getTrajet(i).Afficher();
		}
	}

	if (!trouve)
		cout << "Il n'y a pas des trajets qui correspondent !" << endl;

}

static void testListe()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{

	TrajetSimple *ts1 = new TrajetSimple("A", "B", "MT");
	Trajet * ts2 = new TrajetSimple("B", "C", "MT2");

	TrajetSimple *ts3 = new TrajetSimple("P", "D", "MT3");

	ListeTrajets * lt2 = new ListeTrajets;
	lt2->Ajouter(ts1);
	lt2->Ajouter(ts2);
	TrajetCompose * tc1 = new TrajetCompose(lt2);

	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts3);
	lt1->Ajouter(tc1);

	//cout << ts2->Depart()<<endl;

	//cout << lt1->DepartTrajet(1)<<endl;

	RechercheSimple(*lt1, "P", "D");

}

static void Menu(ListeTrajets & catalogue) {
	cout << "Choisissez l'option: " << endl;
	cout << "1. Ajouter Trajet Simple " << endl;
	cout << "2. Ajouter Trajet Compose " << endl;
	cout << "3. Afficher le catalogue des trajets " << endl;
	cout << "4. Rechercher un parcours " << endl;
	cout << "5. Sortir" << endl;

//Catalogue *c = new Catalogue;

	int action;
	cin >> action;

	while (action != 5
			&& (action == 1 || action == 2 || action == 3 || action == 4)) {
		switch (action) {
		//TS
		case 1: {
			char * depart = new char[20];
			char * arrivee = new char[20];
			char * transport = new char[20];
			;
			cout << "Ville de d�part ?" << endl;
			cin >> depart;
			cout << "Ville d'ariv�e ?" << endl;
			cin >> arrivee;
			cout << "Moyen de transport ?" << endl;
			cin >> transport;

			catalogue.Ajouter(new TrajetSimple(depart, arrivee, transport));
			break;
		}

			//TC

		case 2: {

			ListeTrajets * lt = new ListeTrajets;

			cout << "De combien de trajets est compose ce trajet compose ?"
					<< endl;
			int i = 0;
			int n;
			cin >> n;

			char * arriveePrecedent = new char[20];
			strcpy(arriveePrecedent, "no dest");

			while (i < n) {
				//while(arrivee d'avant != depart de maintenant) => sinon on peut le remplir pour lui
				cout << "Saisie du trajet num " << i + 1 << endl;
				char * depart = new char[20];
				char * arrivee = new char[20];
				char * transport = new char[20];

				cout << "Ville de depart ?" << endl;
				cin >> depart;
				cout << "Ville d'arivee ?" << endl;
				cin >> arrivee;

				while ((strcmp(depart, arriveePrecedent) != 0) && (i != 0)) {
					cout
							<< "Veuillez ressaisir les villes de depart et d'arrivee de votre trajet"
							<< endl;
					cout << "Ville de depart ?" << endl;
					cin >> depart;
					cout << "Ville d'arivee ?" << endl;
					cin >> arrivee;
				}
				cout << "Moyen de transport ?" << endl;
				cin >> transport;

				strcpy(arriveePrecedent, arrivee);
				lt->Ajouter(new TrajetSimple(depart, arrivee, transport));


				i++;
			}
			TrajetCompose * tc = new TrajetCompose(lt);

			cout << "Ville arr : " << tc->Arrivee() << endl;

			catalogue.Ajouter(tc);
			break;
		}

			//catalogue
		case 3: {
			catalogue.Afficher();
			break;
		}

			//search
		case 4: {
			//appel m�thode de recherche
			char * depart = new char[20];
			char * arrivee = new char[20];
			cout << "Quelle est votre ville de d�part ?" << endl;
			cin >> depart;
			cout << "Quelle est votre destination ?" << endl;
			cin >> arrivee;

			RechercheSimple(catalogue, depart, arrivee);
			//rechercheAvancee(catalogue, depart, arrivee);
			//recherche(depart,arrivee,catalogue); doit renvoyer liste => valeur

			break;
		}

		case 5:
			//fermer la fen�tre ?
			break;
		}

		cout << "Veuillez choisir une option: " << endl;
		cout << "1. Ajouter Trajet Simple " << endl;
		cout << "2. Ajouter Trajet Compose " << endl;
		cout << "3. Afficher le catalogue des trajets " << endl;
		cout << "4. Rechercher un parcours " << endl;
		cout << "5. Sortir" << endl;
		cin >> action;
	}

}

ListeTrajets rechercheAvancee(ListeTrajets * catalogue, char * dep, char * arrivee) //retour par valeur pour �viter perte de r�sultat
							  // /!\ constructeur de copie
	{
//	/*char * depart;
//	strcpy(depart,dep);
//	char * arrivee;
//	strcpy(arrivee,arr);*/
//
//	ListeTrajets * intermede = new ListeTrajets;
//	ListeTrajets result = new ListeTrajets;
//
//	//ajout des trajets qui partent du bon endroit
//	for(int i = 0; i < catalogue->Taille(); i++)
//	{
//		if(strcmp(catalogue->getTrajet(i)->Depart(), dep){
//			intermede->Ajouter(new Trajet(catalogue->getTrajet(i)));
//		}
//
//	}
//
//	//recherche des matchs et des resultats valides
//	while(intermede->Taille() > 0)
//	{
//		for(int i = 0; i < intermede->Taille(); i++)
//			{
//
//			//regarder si arrivee matche demande si oui => result
//			if( strcmp(arr, (intermede->getTrajet(i))->Arrivee() ) == 0)
//			{
//				result.Ajouter(intermede->getTrajet(i));
//				intermede->Retirer(i);
//			}
//
//			//sinon regarder si arrivee matche qqch
//			//et cr�er liste de tout ce qui matche pour ce trajet
//			//=> ajouter � sa place tous ceux qui le contiennent augment�
//			else
//			{
//				ListeTrajets * correspondent = new ListeTrajets;
//				for(int j = 0; j < catalogue->Taille(); j++)
//				{
//					if( strcmp( (catalogue.getTrajet(j))->Depart() , (intermede->getTrajet(i))->Arrivee() ) == 0)
//					{
//						correspondent->Ajouter(catalogue.getTrajet(j));
//					}
//				}
//
//				if(correspondent->Taille()==0){
//					intermede->Retirer(i);
//				}
//				else
//				{
//					ListeTrajets aAjouter = new ListeTrajets;
//					aAjouter->Ajouter(intermede.getTrajet(i));
//					for(int j = 0; j < correspondent->Taille(); j++)
//					{
//						aAjouter->Ajouter(correspondent->getTrajet(j));
//						intermede->Ajouter(new TrajetCompose(aAjouter));
//						//aAjouter->Retirer(correspondent->getTrajet(j));
//						aAjouter->Retirer(1);
//
//					}
//					intermede->Retirer(i);
//				}
//			}
//			//sinon poubelle
//
//			}
	//2options here :
	//result.Afficher();
	//return result;
//	}

}


int main()
// Algorithme :
{

	ListeTrajets * catalogue = new ListeTrajets;

//testListe();
//testTC();

	Menu(*catalogue);
//	testListe();

	return 0;
}
