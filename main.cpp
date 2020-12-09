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

  //Inicio el reloj
  t_inicial = clock();

  //Crea una nueva solución y un constructor 
  Solution* solucion ;//= new Solution(pi) ;
  Construction* construccion ;//= new Construction();
  Movimiento* movimiento = new Movimiento();//se crea un movimiento

  //Creo frente de pareto
  auto fp = new Pareto();
  Solution* solucionactual;
  
  vector <float> Lambda(pi->getCantFO());     //Declaro el vector lambda
  float T = atoi(argv[5]);                           //Temperatura en valor alto
  bool debug = false;
  
  for (int it_ext= 0; it_ext < atoi(argv[3]); it_ext++){
    if (debug) cout << "It_ext -------------------------------------------------------> " << it_ext << endl;
    
    solucion = new Solution(pi) ;
    solucionactual = new Solution(pi) ;
    
    if (debug && it_ext == 1) solucion->ImprimirSolucion();
    if (debug && it_ext == 1) solucionactual->ImprimirSolucion();
    
    //Genero los numeros de lambda de manera aleatoria
    solucion->generarLambda(Lambda);
    
    construccion = new Construction();
    construccion->ConstruirSolucionFact(solucion);
    if (debug) cout << "CONSTRUCCION" << endl;
    solucion->RevisarSolucion();
    
    fp->ModificarPareto(solucion);

    solucionactual->copiarSolucion(solucion);
    
    if (debug && it_ext == 1) solucionactual->ImprimirSolucion();

    for (int it_int= 0; it_int<atoi(argv[4]) ; it_int++){
      if (debug) cout << "It_int -------------------------------------------------------> " << it_int << endl;
      
      movimiento->modificarSolucion(solucion);
      if (debug) cout << "MOVIMIENTO" << endl;
      solucion->RevisarSolucion();
      //Reemplazo el valor si es mejor segun lo siguiente:
      if (solucion->getpi()->generarNAleat(0, 10)/10.0 < solucionactual->probabilidadSolucionC(solucion,T,Lambda) ){
        solucionactual->copiarSolucion(solucion);

        //Se van agregando elementos al frente 
        fp->ModificarPareto(solucionactual);
      }
    }

    //Actualizar Temperatura:
    T = atof(argv[6])*T;
    //cout << "Temperatura:" << T << endl;
    if (T < 1){
      T = atoi(argv[5]);
    }
    
    //solucion->ImprimirSolucion();

    delete solucion ; 
    delete solucionactual;
    delete construccion;
  }

  //calcular tiempo de ejecucion
  t_final = clock();
  clock_t timeToBest = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
  cout << endl << "Tiempo de ejecución: " << timeToBest << endl << endl;

  fp->imprimirPareto(); cout << endl ;

  //imprimir solución 
  //solucion->ImprimirSolucion();

  string nombre = "Solucion.txt";
  
  fp->imprimirParetoaArchivo(nombre, timeToBest);
}
