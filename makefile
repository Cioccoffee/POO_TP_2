#makefile pour compilation et reliure

#regle explicite pour la reliure de l'executable

executable : Ensemble.o Test.o
	g++ -o executable Ensemble.o Test.o -lm

#regle explicite pour la reliure de la classe

Ensemble.o : Ensemble.h Ensemble.cpp
	g++ -c -DMAP Ensemble.cpp

#regle explicite pour la reliure de le module de test

Test.o : Test.h Test.cpp
	g++ -c -DMAP Test.cpp
