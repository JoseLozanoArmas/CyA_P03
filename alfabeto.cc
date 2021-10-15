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
  bool unico = true;  //Variable que determina si solo está la cadena o si tambien contiene el abecedario
  for (int i = 0; i < lineas.length(); ++i) {  //Recorre toda la cadena del fichero, en el caso de encontrar un espacio 
    if (lineas[i] == ' ') {                    //Asume que no existe solo la cadena y pasa al siguiente if
      unico = false;
    }

    if (lineas[i] != ' ') {  //En caso de no encontrar espacios va concatenando los elemetnos para luego guardarlos en el vector 
      aux = aux + lineas[i];
    } else if (i == lineas.length()) {
      alfabeto_.push_back(aux);
      aux = "";  //Una vez guardado reinicia el auxiliar
    } else {
      alfabeto_.push_back(aux);
      aux = "";
    }
  }

  if(unico == true) {  //En el caso de ser solo la cadena, asume que cada simbolo de la misma es el alfabeto
    for(int i = 0; i < lineas.length(); ++i) {
      aux = lineas[i]; //Los separa caracter por caracter y las va almacenando
      alfabeto_.push_back(aux);
    }
  }

}

std::vector<std::string> Alfabeto::GetAlfabeto() {  //Devuelve el alfabeto
  return alfabeto_;
}



void Alfabeto::PrintAlfabeto(std::ofstream& texto_salida) { //Función que desarrollé para comprobar que funcionaban los cálculos
  int espacio = alfabeto_.size() - 1; //Para poder imprimir ',' es necesario un iterador
  texto_salida << "{"; //Comienza añadiendo el principio del conjunto
  for(int i = 0; i < alfabeto_.size(); i++) { //recorre todo el vector imprimiendo sus componetes y una coma para separarlos
    texto_salida << alfabeto_[i];
    if(i != espacio) {
      texto_salida << ", ";
    }
  }
  texto_salida << "}" << std::endl; //Tras imprimir el conjunto lo cierra
}

int Alfabeto::GetCardinalidad() { //Devuelve cantidad de simbolos
  return alfabeto_.size();
}
