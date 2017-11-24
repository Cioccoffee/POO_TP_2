#makefile pour compilation et reliure

#variables
RM = rm
COMP = g++
EDL = g++

INT = ListeTrajets.h Trajet.h TrajetSimple.h TrajetCompose.h Test.h

REAL =$(INT : .h  = .cpp)
OBJ = $(REAL : .cpp  = .o)

EXE = executable

RMFLAGS = -f
COMPFLAGS = -ansi -pedantic -Wall -std=c++11
EDLFLAGS = 

#useless
#$(REAL) : $(INT)
#$(OBJ) : $(REAL)

#realisation de l'executable
EXE : $(OBJ)
	$(COMP) -o EXE $(OBJ)

#patterns
%.o : %.cpp
	$(COMP) $(COMPFLAGS) -c $<


$(CLEAN):
$(RM) $(RMFLAGS) $(EXE) $(OBJ) core

#regle explicite pour la reliure de l'executable

executable : ListeTrajets.o Test.o Trajet.o TrajetSimple.o TrajetCompose.o
	g++ -o EXE ListeTrajets.o Test.o Trajet.o TrajetSimple.o TrajetCompose.o

#regle explicite pour la reliure de la classe

ListeTrajets.o : ListeTrajets.h ListeTrajets.cpp Trajet.h
	

#regle explicite pour la reliure de la classe Trajet

Trajet.o : Trajet.h Trajet.cpp
	

#regle explicite pour la reliure de la classe TrajetSimple

TrajetSimple.o : TrajetSimple.h TrajetSimple.cpp Trajet.h
	

#regle explicite pour la reliure de la classe TrajetCompose

TrajetCompose.o : TrajetCompose.h TrajetCompose.cpp Trajet.h ListeTrajets.h
	

#regle explicite pour la reliure de le module de test

Test.o : Test.h Test.cpp Trajet.h ListeTrajets.h TrajetSimple.h TrajetCompose.h
	


