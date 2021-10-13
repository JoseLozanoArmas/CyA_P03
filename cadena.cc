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

#include "cadena.h"   
  
Cadena::Cadena(std::string lineas) {  //El constructor, se ubica en el final de una linea del fichero
  for(int i = lineas.length() - 1; i >= 0; --i) { //Y va desde el final hasta que encuentra un espacio almancenando la string
    if (lineas[i] != ' ') {
      lineas_ = lineas[i] + lineas_;
    }
    if (lineas[i] == ' ') {
      break;
    }
  }
}

std::string Cadena::GetLineas() { //Devuelve string, que sería la cadena
  return lineas_;
}

void Cadena::Longitud (std::string palabra, std::ofstream& texto_salida) { //Deguelve la longitud de la cadena
  texto_salida << palabra.length() << std::endl;
}

void Cadena::Inversa (std::string palabra, std::ofstream& texto_salida) { //Coge la string y le da la vuelta (recorriendo la misma del final al principio)
  std::string result = "";
  for(int i = palabra.length() -1 ; i >= 0; --i) {
   result = result + palabra[i];
  }
  texto_salida << result << std::endl;
}

void Cadena::Prefijo (std::string palabra, std::ofstream& texto_salida) { //Va mostrando cada una de las parte de la cadena haciendo el prefijo y concatenando un auxiliar;
  int limite = palabra.length();
  int i = 0;
  texto_salida << "& ";
  std::string concatenacion = " ";
  while(limite != i) {
    concatenacion = concatenacion + palabra[i];
    texto_salida << concatenacion << " ";
    i++;
  }
  texto_salida << std::endl;
}

void Cadena::Sufijo (std::string palabra, std::ofstream& texto_salida) { //Va mostrando cada una de las parte de la cadena haciendo el sufijo y concatenando un auxiliar;
  int limite = -1;
  int i = palabra.length() -1;
  texto_salida << "& ";
  std::string concatenacion = " ";

  while(limite != i) {
    concatenacion = palabra[i] + concatenacion;
    texto_salida << concatenacion << " ";
    i--;
  }
  texto_salida << std::endl;
}

void Cadena::Subcadena (std::string palabra, std::ofstream& texto_salida) { //Parte de la operación del prefijo y añade los simbolos para generar las subcadenas
  int limite = palabra.length();
  int i = 0;
  texto_salida << "& ";
  std::string concatenacion = " ";

  for(int i = 0; i < palabra.length(); ++i) { //Concatena los símbolos
    texto_salida << palabra[i] << " ";
  }

  while(limite != i) {
    concatenacion = concatenacion + palabra[i]; //Usando una cadena auxiliar se van formando las distintas cadenas
    texto_salida << concatenacion << " ";
    i++;
  }
  texto_salida << std::endl;
}

void Cadena::Menu(int numero, std::string lineas, std::ofstream& texto_salida) { //Se basa en un switch que en base al opcode usar una función o otra
  switch (numero) {
    case 1: Longitud(lineas, texto_salida); //Todos los resultados se aplican al fichero de salida, usando la cadena procesada
    break;
    case 2: Inversa(lineas, texto_salida);
    break;
    case 3: Prefijo(lineas, texto_salida);
    break;
    case 4: Sufijo(lineas, texto_salida);
    break;
    case 5: Subcadena(lineas, texto_salida);
    break;
 }
}

