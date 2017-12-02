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
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
static void testConstructeur();
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
//
// Contrat :
//

static void testTS();
// Mode d'emploi :
//
// Contrat :
//

static void testTC();
// Mode d'emploi :
//
// Contrat :
//

static void Menu();

static void RechercheSimple(ListeTrajets & catalogue, char * dep,char * arr);

int main();
// Mode d'emploi :
//
// Contrat :
//

#endif // Test_H
