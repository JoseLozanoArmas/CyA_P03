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

#include "simbolo.h"

Simbolo::Simbolo(std::string palabra) {
  simbolo_ = palabra;
}

std::string Simbolo::GetSimbolo() {
  return simbolo_;
}

void Simbolo::PrintSimbolo(std::ofstream& texto_salida) {
  texto_salida << simbolo_ << std::endl;
}



