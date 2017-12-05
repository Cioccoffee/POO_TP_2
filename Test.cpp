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

static void RechercheSimple(ListeTrajets & catalogue, const char * dep,
		const char * arr) {
// Algorithme :
// cherche dans le catalogue les trajets qui ont la ville de départ = param2 et ville d'arrivée = param3

	bool trouve = false;

	for (unsigned int i = 0; i < catalogue.Taille(); i++) {

		const char * depart = catalogue.getTrajet(i)->Depart();
		const char * arrivee = catalogue.getTrajet(i)->Arrivee();

		if (strcmp(depart, dep) == 0 && strcmp(arrivee, arr) == 0) {
			trouve = true;
			catalogue.getTrajet(i)->Afficher();
		}
	}

	if (!trouve)
		cout << "Il n'y a pas de trajet qui corresponde !" << endl;

}

static void /*ListeTrajets */rechercheAvancee(ListeTrajets & catalogue,
		char * dep, char * arr) //retour par valeur pour �viter perte de r�sultat
		// /!\ constructeur de copie
		{
//	/*char * depart;
//	strcpy(depart,dep);
//	char * arrivee;
//	strcpy(arrivee,arr);*/
//
	ListeTrajets * intermede = new ListeTrajets;
	ListeTrajets * result = new ListeTrajets;

	//cout << "in recherche avancee"<<endl;
	//cout << catalogue.Taille() <<endl;

	//ajout des trajets qui partent du bon endroit
	for (unsigned int i = 0; i < catalogue.Taille(); i++) {
		if (strcmp((catalogue.getTrajet(i))->Depart(), dep) == 0) {
			intermede->Ajouter(catalogue.getTrajet(i));
			//cout<<"dans le if"<< endl;
		}
		//cout << "i =" << i <<endl;

	}


	//cout << "selectionnés car depart ok = " << endl;
	intermede->Afficher();
	//recherche des matchs et des resultats valides

	//int taille = intermede->Taille();

	
	while (intermede->Taille() > 0) {
		/*cout << "in intermede's while" << endl;
		cout <<"+++++++++++++++++++++++++++++++++++++++"<<endl;
		cout <<"+++++++++++++++++++++++++++++++++++++++" <<endl;
		cout <<"WARNING WARNING WHILE WARNING WARNING" <<endl;
		cout <<"+++++++++++++++++++++++++++++++++++++++" <<endl;
		cout <<"+++++++++++++++++++++++++++++++++++++++"<<endl;*/
		//intermede->Afficher();

		bool retrait = false;
		for (unsigned int i = 0; i < intermede->Taille(); i++) {

			if (retrait)
				i = 0;
			retrait = false;

			//cout << "in for to see if corresponds --- i = " << i << endl;
			//cout << "size intermede = " << intermede->Taille() << endl;
			intermede->Afficher();
			//regarder si arrivee matche demande si oui => result


			if (strcmp(arr, (intermede->getTrajet(i))->Arrivee()) == 0) {
				//cout << "in if" << endl;
				result->Ajouter(intermede->getTrajet(i));
				intermede->Retirer(i);
				retrait = true;

				//cout << "good destination withdrawn" << endl;
			}

			//sinon regarder si arrivee matche qqch
			//et cr�er liste de tout ce qui matche pour ce trajet
			//=> ajouter � sa place tous ceux qui le contiennent augment�

			else {
				//cout << "in else" << endl;

				ListeTrajets * correspondent = new ListeTrajets;
				for (unsigned int j = 0; j < catalogue.Taille(); j++) {
					if (strcmp((catalogue.getTrajet(j))->Depart(),
							(intermede->getTrajet(i))->Arrivee()) == 0) {
						correspondent->Ajouter(catalogue.getTrajet(j));
					}
				}


				//cout << "taille de correspondent = " << correspondent->Taille()<< endl;

				if (correspondent->Taille() == 0) {
					intermede->Retirer(i);
					retrait = true; //on repart du début puisqu'on a changé le nombre d'éléments

				} else {
					//cout << "+++++ correspondent = ++++" << endl;
					correspondent->Afficher();


					for (unsigned int j = 0; j < correspondent->Taille(); j++) {

						ListeTrajets * aAjouter = new ListeTrajets;
						aAjouter->Ajouter(intermede->getTrajet(i));
						aAjouter->Ajouter(correspondent->getTrajet(j));
						TrajetCompose * t = new TrajetCompose(aAjouter);
						intermede->Ajouter(t);

						/*
						cout << "+++ aAjouter +++" << endl;
						aAjouter->Afficher();
						cout << "trajet trouvé" << endl;
						t->Afficher();
						cout << "intermede avec l'ajout" << endl;
						intermede->Afficher();
						*/
						//aAjouter->Retirer(1);

					}
					//cout << "trajet a retirer"<<endl;
					(intermede->getTrajet(i))->Afficher();
					intermede->Retirer(i);
					retrait = true; //on repart du début puisqu'on a changé le nombre d'éléments
					//cout << "etat d'intermede" << endl;
					intermede->Afficher();
				}
				//delete correspondent;
			}
			//sinon poubelle

		}

	}


	/*for (unsigned int i = 0; i < result->Taille(); i++) {
		(result->getTrajet(i))->Afficher();
		cout << "arrivée de" << i << " = " << (result->getTrajet(i))->Arrivee()
				<< endl;
		cout << "trajets de" << i << " = " << endl;
		//((result->getTrajet(i))->Trajets())->Afficher();

	}*/

	cout << "---------" << endl;
			result->Afficher();
			cout << "--------" << endl;
	//delete intermede;
	//delete result;
}

static void testListe()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{

	TrajetSimple *ts1 = new TrajetSimple("ty", "B", "MT");
	Trajet * ts2 = new TrajetSimple("B", "C", "MT2");

	TrajetSimple *ts3 = new TrajetSimple("ty", "C", "MT3");
	TrajetSimple *ts4 = new TrajetSimple("C", "K", "MT4");
	TrajetSimple *ts5 = new TrajetSimple("C", "E", "MT5");
	TrajetSimple *ts6 = new TrajetSimple("E", "K", "MT6");

	ListeTrajets * lt2 = new ListeTrajets;
	lt2->Ajouter(ts1);
	lt2->Ajouter(ts2);
	TrajetCompose * tc1 = new TrajetCompose(lt2);

	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts3);
	lt1->Ajouter(tc1);
	lt1->Ajouter(ts4);
	lt1->Ajouter(ts5);
	lt1->Ajouter(ts6);

	//cout << ts2->Depart()<<endl;

	//cout << lt1->DepartTrajet(1)<<endl;

	lt1->Afficher();

	rechercheAvancee(*lt1, "ty", "K");

	delete ts1;
	delete ts2;
	delete ts3;
	delete ts4;
	delete tc1;
	//delete lt1;
	//delete lt2;

}

static void testRetirer() {

	TrajetSimple *ts1 = new TrajetSimple("A", "B", "MT");
	Trajet * ts2 = new TrajetSimple("B", "C", "MT2");

	ListeTrajets * lt2 = new ListeTrajets;
	lt2->Ajouter(ts1);
	lt2->Ajouter(ts2);
	TrajetCompose * tc1 = new TrajetCompose(lt2);

	Trajet *ts3 = new TrajetSimple("A", "C", "MT3");
	TrajetSimple *ts4 = new TrajetSimple("C", "K", "MT4");

	ListeTrajets * lt1 = new ListeTrajets;
	lt1->Ajouter(ts3);
	lt1->Ajouter(tc1);
	lt1->Ajouter(ts4);

	/*ListeTrajets * lt3 = new ListeTrajets;
	lt3->Ajouter(ts3);
	cout << "++++lt3 au début"<<endl;
	lt3->Afficher();
	cout<<"++++retirer à i =0"<<endl;
	lt3->Retirer(0);
	lt3->Afficher();
	cout << "--taille--"<<lt3->Taille()<<endl;*/
	//=> marche q liste de taille 1

	//=> suppression en 0 ok, no matter the size is
	cout << "++++lt1 au début"<<endl;
	lt1->Afficher();
	cout<<"++++retirer à i =0"<<endl;
	lt1->Retirer(0);
	lt1->Afficher();
	cout << "--taille--"<<lt1->Taille()<<endl;
	cout<<"++++retirer à i =1"<<endl;
	lt1->Retirer(1);
	lt1->Afficher();
	cout << "--taille--"<<lt1->Taille()<<endl;
	delete ts1;
	delete ts2;
	delete ts3;
	delete ts4;
	delete tc1;
}

static void Menu(ListeTrajets & catalogue) {
	cout << "Veuillez choisir l'option: " << endl;
	cout << "1. Ajouter Trajet Simple " << endl;
	cout << "2. Ajouter Trajet Compose " << endl;
	cout << "3. Afficher le catalogue des trajets " << endl;
	cout << "4. Rechercher un parcours " << endl;
	cout << "5. Sortir" << endl;

	int action;
	cin >> action;

	while (action != 5
			&& (action == 1 || action == 2 || action == 3 || action == 4)) {
		switch (action) {
		//TS
		case 1: {
			
			char depart[1024];
			char arrivee[1024];
			char transport[1024];

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

			char arriveePrecedent[1024]; 			
			strcpy(arriveePrecedent, "no dest");

			while (i < n) {
				//while(arrivee d'avant != depart de maintenant) => sinon on peut le remplir pour lui
				cout << "Saisie du trajet num " << i + 1 << endl;
	
				char depart[1024];
				char arrivee[1024];
				char transport[1024];

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
			char depart[1024];
			char arrivee[1024];
			cout << "Quelle est votre ville de d�part ?" << endl;
			cin >> depart;
			cout << "Quelle est votre destination ?" << endl;
			cin >> arrivee;

			//RechercheSimple(catalogue, depart, arrivee);
			rechercheAvancee(catalogue, depart, arrivee);

			//recherche(depart,arrivee,catalogue); doit renvoyer liste => valeur

			break;
		}

		case 5:
			//fermer la fen�tre ?
			break;
		}

		cout << "Choisissez l'option: " << endl;
		cout << "1. Ajouter Trajet Simple " << endl;
		cout << "2. Ajouter Trajet Compose " << endl;
		cout << "3. Afficher le catalogue des trajets " << endl;
		cout << "4. Rechercher un parcours " << endl;
		cout << "5. Sortir" << endl;
		cin >> action;
	}

}

static void testMemoire(ListeTrajets &catalogue) {

	char depart[1024];
	char arrivee[1024];
	char transport[1024];

	cout << "Ville de d�part ?" << endl;
	cin >> depart;
	cout << "Ville d'ariv�e ?" << endl;
	cin >> arrivee;
	cout << "Moyen de transport ?" << endl;
	cin >> transport;

	catalogue.Ajouter(new TrajetSimple(depart, arrivee, transport));
	catalogue.Ajouter(new TrajetSimple(depart, arrivee, transport));


}


int main()
// Algorithme :
{

	ListeTrajets * catalogue = new ListeTrajets;

//testListe();
//testTC();


	//Menu(*catalogue);
//	testListe();
	//delete catalogue;
	testMemoire(*catalogue);
	delete catalogue;

//	Menu(*catalogue);
	testListe();
	//testRetirer();


	return 0;
}
