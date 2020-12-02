#include <iostream>
#include <random>
#include <vector>
#include <time.h>

#include "FileHandler.h"
#include "ProblemInstance.h"
#include "Solution.h"
#include "Construction.h"
#include "Pareto.h"
#include "Movimiento.h"

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
  Solution* solucion ;//= new Solution(pi) ;
  Construction* construccion ;//= new Construction();
  Movimiento* movimiento = new Movimiento();//se crea un movimiento


  //Creo frente de pareto
  auto fp = new Pareto();
  Solution* solucionactual = new Solution(pi);
  vector <float> Lambda(pi->getCantFO());     //Declaro el vector lambda
  float T = 100;                           //Temperatura en valor alto

  for (int it_ext= 0; it_ext < atoi(argv[3]); it_ext++){

    //Genero los numeros de lambda de manera aleatoria
    solucion->generarLambda(Lambda);
    
    solucion = new Solution(pi) ;

    construccion = new Construction();

    construccion->ConstruirSolucionFact(solucion);
  
    fp->ModificarPareto(solucion);

    solucionactual->copiarSolucion(solucion);

    for (int it_int= 0; it_int<20 ; it_int++){
      movimiento->modificarSolucion(solucion);

      //Reemplazo el valor si es mejor segun lo siguiente:
      if (solucion->getpi()->generarNAleat(0, 10)/10.0 < solucionactual->probabilidadSolucionC(solucion,T,Lambda) ){
        solucionactual->copiarSolucion(solucion);

        //Se van agregando elementos al frente 
        fp->ModificarPareto(solucionactual);
      }
    }

    //Actualizar Temperatura:
    T = 0.9*T;
    //cout << "Temperatura:" << T << endl;
    if (T < 1){
      T = 100;
    }

    solucion->ImprimirSolucion();

    delete solucion ; 
    delete construccion;

  }

  fp->imprimirPareto();

  //imprimir solución 
  //solucion->ImprimirSolucion();

}
