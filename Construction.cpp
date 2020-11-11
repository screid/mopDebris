#include "Construction.h"
#include <algorithm>


//Colocar en clase utilities
float Minimo(float a, float b){
  if (a < b){
    return a;
  } else {
    return b;
  }
}


bool Construction::ConstruirSolucionFact(Solution *sol){

  //Se copia al vector de nodos
  vector <Node*> ListaNodos = sol->getpi()->getTodosNodos() ;

  //Se ordenan los nodos según al preferencia del día 
  sort(ListaNodos.begin(), ListaNodos.end(), OrdenarPref) ;

  //partimos desde el nodo con mayor preferencia
  Node* temp = ListaNodos.at(0);
  temp->imprimirNodo();

  //Se guarda la cantidad escombros totales en el nodo 
  float EscDisponible = temp->getCantEsc();

  for (int d=0 ; d < sol->getpi()->getCantDias() ; d++){
    
    cout << "dia" << d << endl ;

    for (int k=0 ; k < sol->getpi()->getCantCamiones() ; k++){
      
      cout << "camion" << k << endl ;

      //Tiempo disponible  por cada camion cada dias (400 min)
      float Tdisponible = sol->getpi()->getTiempoMaxTrabajo();

      //Si le queda tiempo disponible:
      while (Tdisponible > 0){

        //Se inicia un contador de vueltas.
        int contV = 0;
        
        //Si el tiempo disponible es mayor a lo que se va a ocupar
        if (Tdisponible > (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad() ){
          
          //Se calcula la carga factible del nodo ( t. disponible - tiempo transitado)/t. retiro )
          float CargaFactible = ( Tdisponible - (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad()) / sol->getpi()->getTiempoRetiroEsc() ;

          //Se saca el minimo entre el tiempo disponible de camión y capacidad del camión)
          CargaFactible = Minimo(CargaFactible, sol->getpi()->getCapacidad());

          //Se elige el minimo entre los escombros disponibles en el nodo vs capacidad del camión ya ocupada) 
          float tempCarga = Minimo(EscDisponible,CargaFactible);

          //Tiempo total de una vuelta (t. retiro escombros + t. desplazamiento)
          float Tvuelta = (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad() + tempCarga * sol->getpi()->getTiempoRetiroEsc() ;

          //Se construye una vuelta
          Round* tempVuelta = new Round(contV, tempCarga, Tvuelta, sol->getpi()->getUnCamion(k), sol->getpi()->getUnDia(d)) ;

          //Al tiempo disponible se le resta el tiempo de la vuelta.
          Tdisponible -= Tvuelta ;
          
          //Se resta el total de escombros disponibles por el que llevó el camión
          EscDisponible -= tempCarga ;

          //Si ya no quedan escombros disponibles, paso al siguiente nodo
          if (EscDisponible == 0){
            temp++ ;
          }
          
          //Se aumeta el contador de las vueltas
          contV++ ;
        }
      }
    }
  }
}
