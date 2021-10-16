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
#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include "simbolo.h"

class Alfabeto {
 public:
  Alfabeto(std::string lineas); //Constructor
  Alfabeto(); //Constructor por defecto
  void PrintAlfabeto(std::ofstream& texto_salida); //Función que desarrollé para comprobar que funcionaban los cálculos
  int GetCardinalidad(); //Devuelve cardinalidad
  void Longitud (std::string palabra, std::ofstream& texto_salida); //Pasa a un fichero la longitud de la cadena
 private:
  int cardinalidad_; //Cantidad de simbolos
  std::set<Simbolo> alfabeto_; //Alfabeto en sí
};