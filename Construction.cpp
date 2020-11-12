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
  bool debug = true;

  //Se copia al vector de nodos
  vector <Node*> ListaNodos = sol->getpi()->getTodosNodos() ;

  //Se ordenan los nodos según al preferencia del día 
  sort(ListaNodos.begin(), ListaNodos.end(), OrdenarPref) ;

  sol->getpi()->imprimirProblemInstance();
  
  //partimos desde el nodo con mayor preferencia

  vector<Node *>::iterator it = ListaNodos.begin() + 1; // Descartar el depósito.  
  Node* temp = (*it); 
  
  if (debug) temp->imprimirNodo();
  if (debug) getchar();
  //Se guarda la cantidad escombros totales en el nodo 
  float EscDisponible = temp->getCantEsc();
  int contV = 0;
  for (int d=0 ; d < sol->getpi()->getCantDias() ; d++){
    if (debug) cout << "Día: " << d << endl ;

    for (int k=0 ; k < sol->getpi()->getCantCamiones() ; k++){
      if (debug) cout << "Camión: " << k << endl ;

      //Tiempo disponible  por cada camion cada dias (400 min)
      float Tdisponible = sol->getpi()->getTiempoMaxTrabajo();
      if (debug) cout << "Tdisponible: " << Tdisponible << endl;
      //Si le queda tiempo disponible:
      while (Tdisponible > 0){
        if (debug) cout << "Tdisponible > 0 !" << endl;
        //Se inicia un contador de vueltas.
        
        
        //Si el tiempo disponible es mayor a lo que se va a ocupar
        if (debug) cout << "Tiempo de viaje al nodo: " << (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad()  << endl;
        
        if (Tdisponible > (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad() ){
          if (debug) cout << "Tdisponible alcanza para ir y volver! " << endl;
          //Se calcula la carga factible del nodo ( t. disponible - tiempo transitado)/t. retiro )
          float CargaFactible = ( Tdisponible - (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad()) / sol->getpi()->getTiempoRetiroEsc() ;

          //Se saca el minimo entre el tiempo disponible de camión y capacidad del camión)
          CargaFactible = Minimo(CargaFactible, sol->getpi()->getCapacidad());
          if (debug) cout << "El camión puede recoger:  " << CargaFactible << endl;
          
          //Se elige el minimo entre los escombros disponibles en el nodo vs capacidad del camión ya ocupada) 
          float tempCarga = Minimo(EscDisponible,CargaFactible);
          if (debug) cout << "De acuerdo al camión y al nodo, se puede recoger:  " << tempCarga << endl;
          
          //Tiempo total de una vuelta (t. retiro escombros + t. desplazamiento)
          float Tvuelta = (temp->getDesdeD() + temp->getHastaD()) * sol->getpi()->getVelocidad() + tempCarga * sol->getpi()->getTiempoRetiroEsc();
          if (debug) cout << "Tvuelta: " << Tvuelta << endl;
          
          
          //Se construye una vuelta
          Round* tempVuelta = new Round(contV, temp->getIDnodo(), tempCarga, Tvuelta, sol->getpi()->getUnCamion(k), sol->getpi()->getUnDia(d)) ;
          sol->setVuelta(tempVuelta);
     
          if (debug) tempVuelta->imprimirVuelta();
          
          //Al tiempo disponible se le resta el tiempo de la vuelta.
          Tdisponible -= Tvuelta ;
          if (debug) cout << "Tdisponible actualizado " << Tdisponible << endl;
          
          //Se resta el total de escombros disponibles por el que llevó el camión
          EscDisponible -= tempCarga ;
          if (debug) cout << "EscDisponible actualizado " << EscDisponible << endl;

          //Si ya no quedan escombros disponibles, paso al siguiente nodo
          if (EscDisponible == 0){
                if (debug) cout << " --->Se acabaron los escombros en el nodo" << endl;
                it++ ;
                if(it == ListaNodos.end()) //Cuando ya no quedan nodos
                    return true;
                Node* temp = (*it); 
                EscDisponible = temp->getCantEsc();
                if (debug) temp->imprimirNodo();
                if (debug) getchar();
                
          }
          if (Tdisponible == 0)
              break;
          if (debug) getchar();
          //Se aumeta el contador de las vueltas
          contV++ ;
        }
        else{
            //Aunque le queda tiempo al camión, no alcanza a ir y volver al nodo analizado
            break;
        }
      }
    }
  }
}
