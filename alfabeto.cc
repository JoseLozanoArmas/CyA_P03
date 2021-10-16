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
* - 15/10/21: Arreglo del fallo que existía cuando solo se le pasaba una cadena, ya adecua el alfabeto correctamente
* 05/10/2021 - Creación (primera versión) del código 
*/  

#include "alfabeto.h"

Alfabeto::Alfabeto(std::string lineas) { //Construye el alfabeto ignorando la cadena (último elemento de la string)
  std::string aux = "";  //Variable para concatenar la string
  bool unico = true;  //Variable que determina si solo está la cadena o si tambien contiene el alfabeto
  for (int i = 0; i < lineas.length(); ++i) {  //Recorre toda la cadena del fichero, en el caso de encontrar un espacio 
    if (lineas[i] == ' ') {                    //Asume que no existe solo la cadena y pasa al siguiente if
      unico = false;
    }

    if (lineas[i] != ' ') {  //En caso de no encontrar espacios va concatenando los elemetnos para luego guardarlos en el vector 
      aux = aux + lineas[i];
    } else if (i == lineas.length()) {
      alfabeto_.insert(aux);
      aux = "";  //Una vez guardado reinicia el auxiliar
    } else {
      alfabeto_.insert(aux);
      aux = "";
    }
  }

  if(unico == true) {  //En el caso de ser solo la cadena, asume que cada simbolo de la misma es el alfabeto
    for(int i = 0; i < lineas.length(); ++i) {
      aux = lineas[i]; //Los separa caracter por caracter y las va almacenando
      alfabeto_.insert(aux);
    }
  }

}

void Alfabeto::PrintAlfabeto(std::ofstream& texto_salida) { //Función que desarrollé para comprobar que funcionaban los cálculos
  std::set<std::string>::iterator indice = alfabeto_.begin();
  int espacio = alfabeto_.size() - 1; //El limite de la impresión
  int condicion = 0; //Esta variable sirve para controlar cuantas ',' imprimir
  texto_salida << "{"; //Comienza añadiendo el principio del conjunto
  while (indice != alfabeto_.end()) {  //Mientras que el indice no llega al final
    texto_salida << *indice; //Imprime el elemento en el texto
    if(condicion != espacio) { //Si no llega al limte, sigue imprimiendo ','
      texto_salida << ", ";
    }
    indice++; //Aunmmenta la condición y avanza en el índice
    condicion++;
  }
  texto_salida << "}" << std::endl; //Tras imprimir el conjunto lo cierra
}

int Alfabeto::GetCardinalidad() { //Devuelve cantidad de simbolos
  return alfabeto_.size();
}

void Alfabeto::Longitud(std::string palabra, std::ofstream& texto_salida) {
  texto_salida << GetCardinalidad() << std::endl;
}
