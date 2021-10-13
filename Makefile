p03_strings: p03_strings.cc alfabeto.o cadena.o
	g++ -o p03_strings p03_strings.cc alfabeto.o cadena.o

p03_strings.o: alfabeto.cc alfabeto.h cadena.cc cadena.h
	g++ -c alfabeto.o alfabeto.cc cadena.o cadena.cc

clean: 
	rm *.o
	rm p02_strings


	