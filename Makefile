p03_strings_operations: p03_strings_operations.cc alfabeto.o cadena.o simbolo.o
	g++ -o p03_strings_operations p03_strings_operations.cc alfabeto.o cadena.o simbolo.o

p03_strings_operations.o: alfabeto.cc alfabeto.h cadena.cc cadena.h simbolo.cc simbolo.h
	g++ -c alfabeto.o alfabeto.cc cadena.o cadena.cc simbolo.o simbolo.cc

clean: 
	rm *.o
	rm p03_strings_operations


	