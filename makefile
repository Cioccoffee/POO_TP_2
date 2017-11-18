#makefile pour compilation et reliure

#regle explicite pour la reliure de l'executable

executable : ListeTrajets.o Test.o
	g++ -o executable ListeTrajets.o Test.o -lm

#regle explicite pour la reliure de la classe

ListeTrajets.o : ListeTrajets.h ListeTrajets.cpp
	g++ -c -DMAP ListeTrajets.cpp

#regle explicite pour la reliure de le module de test

Test.o : Test.h Test.cpp
	g++ -c -DMAP Test.cpp
