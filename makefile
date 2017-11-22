#makefile pour compilation et reliure

#regle explicite pour la reliure de l'executable

executable : ListeTrajets.o Test.o Trajet.o TrajetSimple.o TrajetCompose.o
	g++ -o executable ListeTrajets.o Test.o Trajet.o TrajetSimple.o TrajetCompose.o -lm

#regle explicite pour la reliure de la classe

ListeTrajets.o : ListeTrajets.h ListeTrajets.cpp
	g++ -c -DMAP ListeTrajets.cpp

#regle explicite pour la reliure de la classe Trajet

Trajet.o : Trajet.h Trajet.cpp
	g++ -c -DMAP Trajet.cpp

#regle explicite pour la reliure de la classe TrajetSimple

TrajetSimple.o : TrajetSimple.h TrajetSimple.cpp
	g++ -c -DMAP TrajetSimple.cpp

#regle explicite pour la reliure de la classe TrajetCompose

TrajetCompose.o : TrajetCompose.h TrajetCompose.cpp
	g++ -c -DMAP TrajetCompose.cpp

#regle explicite pour la reliure de le module de test

Test.o : Test.h Test.cpp
	g++ -c -DMAP Test.cpp


