
OBJS=ej1nuevo.o ej2.o ej3.o
MAIN= ejercicio1 ejercicio2 ejercicio3

main:  ejercicio ejercicio2 ejercicio3

ejercicio:  ej1nuevo.o
	g++  -std=c++11 ej1nuevo.o -o ejercicio1

ejercicio2: ej2.o
	g++ -std=c++11 ej2.o -o ejercicio2	

ejercicio3: ej3.o
	g++ -std=c++11 ej3.o -o ejercicio3	

ej1nuevo.o: ej1nuevo.cpp  representador.h aux.h
	g++ -std=c++11 -c ej1nuevo.cpp 

ej2.o: ej2.cpp aux2.cpp aux2.h 
	g++ -std=c++11 -c ej2.cpp


ej3.o: ej3.cpp representador.h aux.h
	g++ -std=c++11 -c ej3.cpp 	

clean:
	rm -f $(OBJS) $(MAIN)
