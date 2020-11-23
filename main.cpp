#include <iostream>
#include <random>
#include <vector>
#include <time.h>

#include "FileHandler.h"
#include "ProblemInstance.h"
#include "Solution.h"
#include "Construction.h"
#include "Pareto.h"

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
  // pi-> imprimirProblemInstance();

  //Crea una nueva solución y un constructor 
  Solution* solucion = new Solution(pi) ;
  Construction* construccion = new Construction();

  //Creo frente de pareto
  auto fp = new Pareto();

  for (int it_ext= 0; it_ext < atoi(argv[3]); it_ext++){

    construccion->ConstruirSolucionFact(solucion);
  
    fp->ModificarPareto(solucion);
  
  }

  fp->imprimirPareto();

  //imprimir solución 
  //solucion->ImprimirSolucion();

}
