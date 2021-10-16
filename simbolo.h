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
  Simbolo (std::string palabra); //Constructor de la clase
  std::string GetSimbolo(); //Devuelve los simbolos
  friend bool operator==(const Simbolo simbolo_1, const Simbolo simbolo_2); //Sobrecarga del operador == para 2 objetos simbolo
  friend bool operator<(const Simbolo simbolo_1, const Simbolo simbolo_2); //Sobrecarga del operador < para 2 objetos simbolo
  friend bool operator>(const Simbolo simbolo_1, const Simbolo simbolo_2); //Sobrecarga del operador > para 2 objetos simbolo
  void PrintSimbolo(std::ofstream& texto_salida); //Imprime en el fichero en un texto
  void Comparacion (std::string palabra, std::string nueva_linea, std::ofstream& texto_salida); //Compara 2 simbolos eh indica si son ==, <, >, !=
 private:
  std::string simbolo_; //El atributo símbolo
};











