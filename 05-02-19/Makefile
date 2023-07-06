OBJ = tipo.o liste.o compito.o 

compito: $(OBJ)
	g++ -o compito $(OBJ)

tipo.o: tipo.h
liste.o: tipo.h liste.h
compito.o: tipo.h liste.h

.PHONY: clean cleanall

clean:
	rm -f *.o 

cleanall:
	rm -f *.o compito