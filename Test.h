/*************************************************************************
 Test  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface du module <Test> (fichier Test.h) -------------------
#if ! defined ( Test_H )
#define Test_H

//------------------------------------------------------------------------
// Rôle du module <Test>
// classe utilisée pour tester les autres classes et leurs methodes,
// pour la création du catalogue, du menu avec les differentes options, pour la recherche des trajets
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

static void test();
// Mode d'emploi :
//
// Contrat :
//
static void testListe();
// Mode d'emploi :
// sert à tester les differentes méthodes de la classe ListeTrajets
// Contrat :
//

static void testTS();
// Mode d'emploi :
//sert à tester les differentes méthodes de la classe TrajetSimple
// Contrat :
//

static void testTC();
// Mode d'emploi :
//sert à tester les differentes méthodes de la classe TrajetCompose
// Contrat :
//

static void Menu(ListeTrajets & catalogue);
// Mode d'emploi :
// prend en paramètre la référence d'un objet de type ListeTrajets
// sert à creer le menu avec es differrentes options pour l'utilisateur
// Contrat :
//

static void RechercheSimple(ListeTrajets & catalogue,const char * dep,const char * arr);
// Mode d'emploi :
// paramètre 1 : la référence d'un objet de type ListeTrajets
// paramètre 2 : un pointeur vers un objet constant de type char (ville de départ d'un trajet)
// paramètre 3 : un pointeur vers un objet constant de type char (ville d'arrivée d'un trajet)
// sert à creer le menu avec es differrentes options pour l'utilisateur
// Contrat :
//

static ListeTrajets rechercheAvancee(ListeTrajets * catalogue, char * dep, char * arr);
int main();
// Mode d'emploi :
// création du catalogue et appel des méthodes décrites ci-dessus
// Contrat :
//

#endif // Test_H
