#include "Construction.h"
#include <algorithm>

Construction::~Construction(){
    
for (Node *n: this->ListaNodos){
    delete n;
  }
  this->ListaNodos.shrink_to_fit();
  this->ListaNodos.clear();
  
}

//Colocar en clase utilities
float Minimo(float a, float b){
  if (a < b){
    return a;
  } else {
    return b;
  }
}


bool Construction::ConstruirSolucionFact(Solution *sol){
  bool debug = false;

  //variables para guardar funciones objetivos
  float F1 = 0.0;
  float F2 = 0.0;
  int F3 = 0;
  int F4 = 0;

  //Se copia al vector de nodos
  for (Node *n: sol->getpi()->getTodosNodos()){
    if (n->getIDnodo() != sol->getpi()->getDeposito()->getIDnodo()){ // descarta el nodo deposito
      auto copy = new Node(*n);
      this->ListaNodos.push_back(copy);
    }
  }

  //Se ordenan los nodos según al preferencia del día 
  sort(this->ListaNodos.begin(), this->ListaNodos.end(), OrdenarCarga) ;

  sol->getpi()->imprimirProblemInstance();
  
  //partimos desde el nodo con mayor preferencia

  vector<Node *>::iterator it = this->ListaNodos.begin();   
  Node* temp = (*it); 

  if (debug) temp->imprimirNodo();
  if (debug) getchar();
  
  //Se guarda la cantidad escombros totales en el nodo 
  float EscDisponible = temp->getCantEsc();
  int contV = 0; //Se inicia un contador de vueltas.
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
        
        //Si el tiempo disponible es mayor a lo que se va a ocupar
        if (debug) cout << "Tiempo de viaje al nodo: " << (temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad()  << endl;
        
        if (Tdisponible > (temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad() ){
          if (debug) cout << "Tdisponible alcanza para ir y volver! " << endl;
          //Se calcula la carga factible del nodo ( t. disponible - tiempo transitado)/t. retiro )
          float CargaFactible = ( Tdisponible - ((temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad())) * sol->getpi()->getTiempoRetiroEsc() ;
          
          //cout << Tdisponible << "-" << ((temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad()) << "*" << sol->getpi()->getTiempoRetiroEsc() << endl ;
          //Se saca el minimo entre el tiempo disponible de camión y capacidad del camión)
          //cout << CargaFactible << endl ;
          CargaFactible = Minimo(CargaFactible, sol->getpi()->getCapacidad());
          if (debug) cout << "El camión puede recoger:  " << CargaFactible << endl;
          
          //Se elige el minimo entre los escombros disponibles en el nodo vs capacidad del camión ya ocupada) 
          float tempCarga = Minimo(EscDisponible,CargaFactible);
          if (debug) cout << "De acuerdo al camión y al nodo, se puede recoger:  " << tempCarga << endl;
          
          //Tiempo total de una vuelta (t. retiro escombros + t. desplazamiento)
          float Tvuelta = (temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad() + tempCarga * sol->getpi()->getTiempoRetiroEsc();
          if (debug) cout << "Tvuelta: " << Tvuelta << endl;
          
          F2 += tempCarga * sol->getpi()->getUnDia(d)->getPrefDia() ;
          if (debug) cout << "F2: " << F2 << endl;
          
          //Se construye una vuelta
          Round* tempVuelta = new Round(contV, temp->getIDnodo(), tempCarga, Tvuelta, sol->getpi()->getUnCamion(k), sol->getpi()->getUnDia(d)) ;
          sol->setVuelta(tempVuelta);

          //guardar el escombro disponible en el nodo
          sol->setEscRemanente(temp->getPosNodo(),sol->getEscRemanente(temp->getPosNodo())-tempCarga);

          sol->setTDisponibleCamion(k,d,sol->getTDisponibleCamion(k,d)-Tvuelta);

          if (debug) tempVuelta->imprimirVuelta();
          
          //Al tiempo disponible se le resta el tiempo de la vuelta.
          Tdisponible -= Tvuelta ;
          if (debug) cout << "Tdisponible actualizado " << Tdisponible << endl;
          
          //Se resta el total de escombros disponibles por el que llevó el camión
          EscDisponible -= tempCarga ;
          if (debug) cout << "EscDisponible actualizado " << EscDisponible << endl;

          //Si ya no quedan escombros disponibles, paso al siguiente nodo
          if (EscDisponible < 0.1){
                F1 += temp->getPrefNodo() * sol->getpi()->getUnDia(d)->getPrefDia() ;
                F3++ ;
                F4 += temp->getPrefNodo();
                if (debug) cout << "F1: " << F1 << endl;
                
                if (debug) cout << " --->Se acabaron los escombros en el nodo" << endl;
                it++ ;
                if(it == this->ListaNodos.end()){ //Cuando ya no quedan nodos
                    sol->setF1(F1);
                    sol->setF2(F2);
                    sol->setF3(F3);
                    sol->setF4(F4);
                    return true;
                }
                temp = (*it);

                EscDisponible = temp->getCantEsc();
                if (debug) temp->imprimirNodo();
                if (debug) getchar();
          }
          
          if (Tdisponible < 0.1){
              if (debug) cout << "Acá se acaba el tiempo" << endl;
              if (debug) getchar();
              contV++ ;
              break;
          }
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
  sol->setF1(F1);
  sol->setF2(F2);
  sol->setF3(F3);
  sol->setF4(F4);
}
