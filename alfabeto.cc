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


Alfabeto::Alfabeto(std::string lineas) { //Construye el alfabeto ignorando la cadena (último elemento de la string)
  std::string aux = "";
  for (int i = 0; i < lineas.length(); ++i) {
    if (lineas[i] != ' ') {
      aux = aux + lineas[i];
    } else if (i == lineas.length()) {
      std::cout << aux;
      alfabeto_.push_back(aux);
      aux = "";
    } else {
      alfabeto_.push_back(aux);
      aux = "";
    }
  }

}

std::vector<std::string> Alfabeto::GetAlfabeto() {  //Devuelve el alfabeto
  return alfabeto_;
}

void Alfabeto::SetDivision(std::vector<std::string>& alfabeto_, std::string lineas) { //Va mirando la cadena alfabeto, buscando elementos comunes que
  std::string aux_1, aux_2, eliminar;                                                 //se asemejen a la cadena, y los incluye
  for(int i = 0; i < alfabeto_.size(); ++i) {
    aux_1 = alfabeto_[i];
    for(int j = 0; j < lineas.length(); ++j) {
      for(int k = 0; k < aux_1.length(); ++k) {
        if(aux_1[k] == lineas[j]) {
          aux_2 = aux_2 + aux_1;     
        } else {
          break;
        }
        division_.push_back(aux_2);
        aux_2 = "";
      } 
    }
  }
}

void Alfabeto::PrintAlfabeto(std::ofstream& texto_salida) { //Función que desarrollé para comprobar que funcionaban los cálculos
  int espacio = alfabeto_.size() - 1;
  texto_salida << "{";
  for(int i = 0; i < alfabeto_.size(); i++) {
    texto_salida << alfabeto_[i];
    if(i != espacio) {
      texto_salida << " ";
    }
  }
  texto_salida << "}" << std::endl;
}

int Alfabeto::GetCardinalidad() { //Devuelve cantidad de simbolos
  return alfabeto_.size();
}
