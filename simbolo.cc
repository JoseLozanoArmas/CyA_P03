/*
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informatíca
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 2: Símbolos, alfabetos y cadenas
* Autor: José Lozano Armas
* Correo: alu0101392561@ull.es
* Fecha: 15/10/2021
* Archivo cya-P02-Strings.cc: programa cliente.
* Contiene la función main del proyecto que usa las clases X e Y
* que realizan el trabajo de leer el fichero de entrada
* identificando patrones en el texto que dan lugar
* al fichero de salida.
* Referencias: https://campusingenieriaytecnologia2122.ull.es/pluginfile.php/19541/mod_assign/introattachment/0/CyA_2021_2022_P2_Cadenas.pdf?forcedownload=1
* Enlaces de interés
* Historial de revisiones
* - 15/10/21: Creación de las sobrecargas de los operadores y del getter que devuelve el simbolo
* 15/10/2021 - Creación (primera versión) del código 
*/  

#include "simbolo.h"

Simbolo::Simbolo(std::string palabra) { //Le da al simbolo el valor de la string que se le pasa
  simbolo_ = palabra;
}

std::string Simbolo::GetSimbolo() { //Devuelve el simbolo
  return simbolo_;
}

void Simbolo::PrintSimbolo(std::ofstream& texto_salida) { //Imprime en un fichero el símbolo
  texto_salida << simbolo_ << std::endl;
}

bool operator==(const Simbolo simbolo_1, const Simbolo simbolo_2) { //Devuelve si 2 objetos son iguales
  return (simbolo_1.simbolo_ == simbolo_2.simbolo_);
}
  

bool operator<(const Simbolo simbolo_1, const Simbolo simbolo_2) { //Devuelve si un objeto es menor que otro
  return (simbolo_1.simbolo_ < simbolo_2.simbolo_);
}

bool operator>(const Simbolo simbolo_1, const Simbolo simbolo_2) { //Devuelve si un objeto es mayor que otro
  return (simbolo_1.simbolo_ > simbolo_2.simbolo_);
}

void Simbolo::Comparacion(std::string lineas, std::string nueva_cadena,std::ofstream& texto_salida) {
  int contar_coincidencias = 0;
  for (int i = 0; i < lineas.length(); ++i) {
    for (int j = 0; j < nueva_cadena.length(); ++j) {
      if(lineas[i] == nueva_cadena[j]) {
        contar_coincidencias++;
      }
    }
  }
  if(contar_coincidencias == lineas.length()) {
    texto_salida << lineas << " == " << nueva_cadena << std::endl;
  } else if (contar_coincidencias == 0) {
    texto_salida << lineas << " != " << nueva_cadena << std::endl;
  }

  if(contar_coincidencias != lineas.length() && contar_coincidencias != 0) {
    if (lineas.length() > nueva_cadena.length()) {
      texto_salida << lineas << " > " << nueva_cadena << std::endl;
    } else {
      texto_salida << lineas << " < " << nueva_cadena << std::endl;
    }
  }

}