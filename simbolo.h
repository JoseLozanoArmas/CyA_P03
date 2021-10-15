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
* 15/10/2021 - Creación (primera versión) del código 
*/  

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class Simbolo {
 public:
  Simbolo (std::string palabra);
  std::string GetSimbolo();
  //friend bool operator==(const Simbolo& simbolo_1, const Simbolo& simbolo_2); 
  //friend bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2);
  //friend bool operator>(const Simbolo& simbolo1, const Simbolo& simbolo2);
  void PrintSimbolo(std::ofstream& texto_salida);
  
 private:
  std::string simbolo_; 
};

/*

bool operator==(const Simbolo& simbolo_1, const Simbolo& simbolo_2) {
  return (simbolo_1.simbolo_ == simbolo_2.simbolo_);
}

*/


/*
bool operator<(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return (simbolo1.simbolo_ < simbolo2.simbolo_);
}

bool operator>(const Simbolo& simbolo1, const Simbolo& simbolo2) {
  return (simbolo1.simbolo_ > simbolo2.simbolo_);
}
*/




