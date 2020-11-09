#include <iostream>
#include <random>
#include <vector>
#include <time.h>

#include "ProblemInstance.h"
#include "FileHandler.h"

using namespace std;

int main(int argc, char **argv) {

  //Defino tiempo inicial y tiempo final
  clock_t t_inicial;
  clock_t t_final;
  
  //Leo el archivo que tengo que leer xD
  string instancia = argv[1];
  
  //Creo la semilla
  int seed = atoi(argv[2]);

  //Inicio generador de números aleatorios
  srand(seed);

  //Aquí defino fh 
  FileHandler fh(instancia);

  //Se llama al método para leer al documento
  ProblemInstance* pi = fh.readInputFile();

  //Método para imprimir todo resumido y bonito
  pi-> imprimirProblemInstance();

}