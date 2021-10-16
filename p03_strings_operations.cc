/*
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informatíca
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 2: Símbolos, alfabetos y cadenas
* Autor: José Lozano Armas
* Correo: alu0101392561@ull.es
* Fecha: 05/10/2021
* Archivo cya-P02-Strings.cc: programa cliente.
* Contiene la función main del proyecto que usa las clases X e Y
* que realizan el trabajo de leer el fichero de entrada
* identificando patrones en el texto que dan lugar
* al fichero de salida.
* Referencias: https://campusingenieriaytecnologia2122.ull.es/pluginfile.php/19541/mod_assign/introattachment/0/CyA_2021_2022_P2_Cadenas.pdf?forcedownload=1
* Enlaces de interés
* Historial de revisiones
* - 14/10/21: Desarrollo de la función Potencia y Concatenación. A su vez se modificó el main y la función Menú para poder usar estas mismas
* 05/10/2021 - Creación (primera versión) del código 
*/     

#include "alfabeto.h"
#include "cadena.h"
#include "simbolo.h"
 
int main(int argc, char* argv[]) {
  std::ifstream texto_entrada (argv[1]); //Los ficheros a analizar y operar
  std::ofstream texto_salida (argv[2]);
  std::string lineas;  //Variable que guardará el contenido del fichero
  std::string alfabeto; //Variable auxiliar para construir el vector del alfabeto
  std::string caracter;
  std::string nueva_cadena; //Variable para concatenar 
  std::string convertir = argv[3];
  int numero = stoi(convertir); //El opcode de la operación
  int potencia; //Variable que guarda la potencia a elevar

  if (numero == 6 || numero == 7) { //En el caso del número ser igual a 6 o 7 solicita que se inserte una cadena
    std::cout << "Introduzca una cadena: ";
    std::cin >> nueva_cadena;
  }

  if (numero == 8) {
    std::cout << "Inserte potencia a elevar: ";
    std::cin >> potencia; 
    if(potencia <= -1) {
      std::cout << "Error: Inserte una potencia mayor o igual a 0 " << std::endl;
    }
  }

  if (numero >= 9 || numero <= 0) {
    std::cout << "Inserte de nuevo una opción en el intervalo de [1 - 8]" << std::endl;
  }
     
  while (!texto_entrada.eof()) {  //Se lee el texto
    std::getline(texto_entrada,lineas); //se va guardando
    alfabeto = lineas; //Hace una copia de lineas para el constructor de alfabeto
    caracter = lineas; //Hace una copia de lineas para el constructor de simbolo
    Alfabeto conjunto(alfabeto); //Constructor de la clase alfabeto
    Cadena Texto(lineas, conjunto); //Constructor de la clase cadena
    Simbolo Simbolo (caracter); //Constructor de la calse simbolo
    caracter = Simbolo.GetSimbolo(); //Guarda el contenido en sus respectivas variables
    lineas = Texto.GetLineas(); 

        
    switch (numero) {
     case 1: Texto.Longitud(lineas, texto_salida); //Todos los resultados se aplican al fichero de salida, usando la cadena procesada, alfabeto, etc...
      break;
     case 2: Texto.Inversa(lineas, texto_salida);
      break;
     case 3: Texto.Prefijo(lineas, texto_salida);
      break;
     case 4: Texto.Sufijo(lineas, texto_salida);
      break;
     case 5: Texto.Subcadena(lineas, texto_salida);
      break;
     case 6: Simbolo.Comparacion(lineas, nueva_cadena, texto_salida);
      break;
     case 7: Texto.Concatenacion(lineas, nueva_cadena, texto_salida);
      break;
     case 8: Texto.Potencia(lineas, potencia, texto_salida);
      break;
    }
        

  //Texto.PrintCadenas(texto_salida);
  //Simbolo.PrintSimbolo(texto_salida);
  //conjunto.PrintAlfabeto(texto_salida);
 
  }

}
 