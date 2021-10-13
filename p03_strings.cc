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
* 05/10/2021 - Creación (primera versión) del código 
*/     

#include "alfabeto.h"
#include "cadena.h"
 
int main(int argc, char* argv[]) {
  std::ifstream texto_entrada (argv[1]); //Los ficheros a analizar y operar
  std::ofstream texto_salida (argv[2]);
  std::string lineas;  //Variable que guardará el contenido del fichero
  std::string alfabeto; //Variable auxiliar para construir el vector división
  std::string convertir = argv[3];
  int numero = stoi(convertir); //El opcode de la operación

  if (numero >= 6) {
    std::cout << "Inserte de nuevo una opción en el intervalo de 1 - 5" << std::endl;
  }
  
  while (!texto_entrada.eof()) {  //Se lee el texto
    std::getline(texto_entrada,lineas); //se va guardando
    alfabeto = lineas;
    Cadena Texto(lineas); //Constructor de la clase cadena
    Alfabeto conjunto(alfabeto); //Constructor de la clase alfabeto
    lineas = Texto.GetLineas(); 
    Texto.Menu(numero,lineas,texto_salida); //Activa la función menú que administra el opcode
  }  

}
 