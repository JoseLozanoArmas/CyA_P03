/*
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informatíca
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 2: Símbolos, alfabetos y cadenas
* Autor: José Lozano Armas
* Correo: alu0101392561@ull.es
* Fecha: 14/10/2021
* Archivo cya-P02-Strings.cc: programa cliente.
* Contiene la función main del proyecto que usa las clases X e Y
* que realizan el trabajo de leer el fichero de entrada
* identificando patrones en el texto que dan lugar
* al fichero de salida.
* Referencias: https://campusingenieriaytecnologia2122.ull.es/pluginfile.php/19541/mod_assign/introattachment/0/CyA_2021_2022_P2_Cadenas.pdf?forcedownload=1
* Enlaces de interés
* Historial de revisiones
* - 14/10/21: Desarrollo de la función Potencia y Concatenación. A su vez se modificó el main y la función Menú para poder usar estas mismas
* - 17/10/21: Creación del atributo palabra_fraccionada y modificación de las funciones Inversa y Longitud
* 05/10/2021 - Creación (primera versión) del código 
*/  

#include "cadena.h"
  
Cadena::Cadena(std::string lineas, Alfabeto alfabeto) {  //El constructor, se ubica en el final de una linea del fichero
  //Parte del constructor dedicada a desarrollar el atributo lineas_
  for(int i = lineas.length() - 1; i >= 0; --i) { //Y va desde el final hasta que encuentra un espacio almancenando la string
    if (lineas[i] != ' ') {
      lineas_ = lineas[i] + lineas_;
    }
    if (lineas[i] == ' ') {
      break;
    }
  }
  //Parte del constructor dedicada a desarrollar el atributo cadena_
  std::string aux = "";  //Variable para concatenar la string
  Simbolo simbolo(lineas);
  bool unico = true;  //Variable que determina si solo está la cadena o si tambien contiene el alfabeto
  for (int i = 0; i < lineas.length(); ++i) {  //Recorre toda la cadena del fichero, en el caso de encontrar un espacio 
    if (lineas[i] == ' ') {                    //Asume que no existe solo la cadena y pasa al siguiente if
      unico = false;
    }

    if (lineas[i] != ' ') {  //En caso de no encontrar espacios va concatenando los elemetnos para luego guardarlos en el vector 
      aux = aux + lineas[i];  
    } else if (i == lineas.length()) {
      cadena_.push_back(aux);
      aux = "";  //Una vez guardado reinicia el auxiliar
    } else {
      cadena_.push_back(aux);
      aux = "";
    }
  }

  if(unico == true) {  //En el caso de ser solo la cadena, asume que cada simbolo de la misma es el alfabeto
    for(int i = 0; i < lineas.length(); ++i) {
      aux = lineas[i]; //Los separa caracter por caracter y las va almacenando
      cadena_.push_back(aux);
    }
  }


  //Parte del constructor dedicada a desarrollar el atributo palabra_fraccionada_
  std::string auxiliar = ""; //Creamos un auxiliar que guarde el valor de los simbolos
  for(int i = 0; i < cadena_.size(); ++i) { //Recorre el vector con el alfabeto
    auxiliar = cadena_[i].GetSimbolo(); //Con el getter guardamos los distintos valores
    for(int j = 0; j < lineas.length(); ++j) { 
      for(int k = 0; k < auxiliar.length(); k++) {
        if(lineas[j] == auxiliar[k]) { //Va comparando varias strings 
          palabra_fraccionada_.push_back(auxiliar); //Almacena en el vector de palabras fraccionadas
          auxiliar = ""; //Y reinicia el auxiliar
        } 
      }
    }
  }

  //Parte del constructor dedicada a desarrollar el atributo alfabeto_
  Alfabeto construir(lineas); //Construimos un objeto Alfabeto, que tendrá el valor de lineas, para luego formar parte del atributo
  construir = lineas;
  alfabeto = construir;
}



std::string Cadena::GetLineas() { //Devuelve string, que sería la cadena
  return lineas_;
}

void Cadena::PrintCadenas(std::ofstream& texto_salida) {
  std::string aux; //Variable auxiliar que guarda el simbolo
  for(int i = 0; i < cadena_.size(); ++i) {
    aux = cadena_[i].GetSimbolo(); //Con un geter le asignamos dicho valor
    texto_salida << aux << " "; //Pasamos el simbolo al texto de salida
  }
  texto_salida << std::endl; //Al finalizar imprimis un endl para que dar lugar a la siguiente línea
}

void Cadena::PrintFraccion(std::ofstream& texto_salida) {
  std::string aux; //Variable auxiliar que guarda el simbolo
  for(int i = 0; i < palabra_fraccionada_.size(); ++i) {
    aux = palabra_fraccionada_[i].GetSimbolo(); //Con un geter le asignamos dicho valor
    texto_salida << aux << " "; //Pasamos el simbolo al texto de salida
  }
  texto_salida << std::endl; //Al finalizar imprimis un endl para que dar lugar a la siguiente línea
}


void Cadena::Longitud (std::string palabra, std::ofstream& texto_salida) { //Deguelve la longitud de la cadena
  texto_salida << palabra_fraccionada_.size() << std::endl; 
}

void Cadena::Inversa (std::string palabra, std::ofstream& texto_salida) { //Coge el vector palabra fracciona y le da la vuelta (recorriendo el mismo del final al principio)
  for(int i = palabra_fraccionada_.size() -1; i >= 0; --i) {
    texto_salida << palabra_fraccionada_[i].GetSimbolo() << " ";
  }
  texto_salida << std::endl;
}

void Cadena::Prefijo (std::string palabra, std::ofstream& texto_salida) { //Va mostrando cada una de las parte de la cadena haciendo el prefijo y concatenando un auxiliar;
  int limite = palabra.length(); //Se crea un limite y un iterador
  int i = 0;
  texto_salida << "& "; //Se muestra la cadena vacía y se van añadiendo las demás
  std::string concatenacion = " "; //Se crea un auxiliar para ir almacenando los datos
  while(limite != i) { //Estos se van imprimiendo mientras se va concatenando y aunmentando
    concatenacion = concatenacion + palabra[i];
    texto_salida << concatenacion << " ";
    i++;
  }
  texto_salida << std::endl;
}

void Cadena::Sufijo (std::string palabra, std::ofstream& texto_salida) { //Va mostrando cada una de las parte de la cadena haciendo el sufijo y concatenando un auxiliar;
  int limite = -1; //Se crea un limite y un iterador
  int i = palabra.length() -1;
  texto_salida << "& "; //Se muestra la cadena vacía y se van añadiendo las demás
  std::string concatenacion = " "; //Se crea un auxiliar para ir almacenando los datos
  while(limite != i) { //Estos se van imprimiendo mientras se va concatenando y aunmentando
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

void Cadena::Concatenacion(std::string lineas, std::string nueva_cadena, std::ofstream& texto_salida) { //Se encarga de concatenar la cadena con una nueva
  lineas = lineas + nueva_cadena; //Rescribe la cadena una vez sumada y la imprime
  texto_salida << lineas << std::endl;
}

void Cadena::Potencia(std::string lineas, int potencia, std::ofstream& texto_salida) { //Eleva a una potencia dada una cadena
  std::string aux = lineas; //crea un auxilar con el valor de lineas y un contador
  int contador = 0; 
  if(potencia == 0) { //Por definición si se eleva a la 0 el resultado es cadena vacía
    texto_salida << "&" << std::endl;
  } else {
    if(potencia == 1) { //Por definición si se eleva a la 1 el resultado es la misma cadena
      texto_salida << lineas << std::endl;
    } else {
      if(potencia >= 2) { //Por definición si se eleva a la 2 o mas el resultado es la cadena concatenada consigo misma n veces
        while (contador != (potencia - 1)) { //Se usa un contar que actua en base a la potencia y va uniendo
          lineas = lineas + aux;
          contador++;
        }
        texto_salida << lineas << std::endl;
      }
    }
  }
}


