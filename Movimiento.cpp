#include "Movimiento.h"

bool Movimiento::modificarSolucion(Solution *sol){

  //eliminar getCantVueltas
  int veces = 2;
  int indice ;
  int cliente;
  int camion;
  int dia;
  
  bool debug = false;

  if (debug) sol->ImprimirSolucion();
  //if (debug) getchar();

  for (int i=0 ; i<veces ; i++){
    if (debug) cout << "I: " << i << endl;
    indice = sol->getpi()->generarNAleat(0, sol->getCantVueltas()-1); //escoger vuelta aleatoria

    Round* EliminarV = sol->getUnaVuelta(indice); //tomamos la vuelta escogida
    if (debug) cout <<"----------------------------------------------------------------"<< endl;
    if (debug) EliminarV->imprimirVuelta();
    if (debug) cout <<"-----------------------------------------------------------------"<< endl;

    cliente = sol->getpi()->getUnNodo2(EliminarV->getIDNodo())->getPosNodo(); //nodo al que se le cambian las cosas
    camion = EliminarV->getNombreCamion()->getIDCamion();
    dia = EliminarV->getDiaVuelta()->getIDDia();

    // si antes de eliminar la vuelta la cant de escombros remante era casi cero significa que el nodo se consideraba limpio completo
    if (sol->getEscRemanente(cliente) < 0.01){      
      
      int diatermino = sol->getDiaTermino(EliminarV->getIDNodo()); //Se debe bucar el día de la última recoleccion para actualizar las FO (especialmente la preferencia asociada a ese día)
      
      sol->setF1(sol->getF1() - sol->getpi()->getUnDia(diatermino)->getPrefDia()*sol->getpi()->getUnNodo(cliente)->getPrefNodo());

      //se actualizan las otras cosas
      sol->setF3(sol->getF3() - 1);
      sol->setF4(sol->getF4() - sol->getpi()->getUnNodo(cliente)->getPrefNodo());
    }

    sol->setEscRemanente(cliente, sol->getEscRemanente(cliente) + EliminarV->getCargaRecogida()); //le regresamos los escombros recogidos en esa vuelta al cliente  
    
    sol->setTDisponibleCamion(camion, dia, EliminarV->getTiempoVuelta() + sol->getTDisponibleCamion(camion, dia));//le regresamos el tiempo disponible al camion en el dia correspondiente

    sol->setF2(sol->getF2() - EliminarV->getCargaRecogida()*sol->getpi()->getUnDia(dia)->getPrefDia());

    sol->EliminarVuelta(indice);

    if (debug) sol->ImprimirSolucion();
    if (debug) sol->RevisarSolucion();
  }

  int intentos = 0, maxintentos = 6 ;
  int camiondia;
  float Tdisponible ;
  float EscDisponible;

  while (intentos < maxintentos){
    cliente = sol->getSeleccionarCliente(); // se seleciona un cliente

    Node* temp = sol->getpi()->getUnNodo(cliente) ;

    // se selecciona un camion en un deteminado dia
    camiondia = sol->getSeleccionarCamionDia();
    camion = sol->getCamionTdisponible(camiondia);
    dia = sol->getDiaTdisponible(camiondia);
    
//     cout << "camiondia: " << camiondia <<  ", camion: " << camion << ", dia: " << dia << endl;

    if (debug) cout << "cliente:" << cliente << ", camion: " << camion << ", dia: " << dia << endl;

    Tdisponible = sol->getTDisponibleCamion(camion,dia) ;
    EscDisponible = sol->getEscRemanente(cliente);

    if (Tdisponible > (temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad()){

      if (debug) cout << "cliente:" << cliente << ", camion: " << camion << ", dia: " << dia << endl;
      
      float CargaFactible = ( Tdisponible - ((temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad())) * sol->getpi()->getTiempoRetiroEsc() ;
          
        //Se saca el minimo entre el tiempo disponible de camión y capacidad del camión)
        //cout << CargaFactible << endl ;
        CargaFactible = sol->Minimo(CargaFactible, sol->getpi()->getCapacidad());
        if (debug) cout << "El camión puede recoger:  " << CargaFactible << endl;
        
        //Se elige el minimo entre los escombros disponibles en el nodo vs capacidad del camión ya ocupada) 
        float tempCarga = sol->Minimo(EscDisponible, CargaFactible);
        if (debug) cout << "De acuerdo al camión y al nodo, se puede recoger:  " << tempCarga << endl;
        
        if(tempCarga > 0.01) {
        
            //Tiempo total de una vuelta (t. retiro escombros + t. desplazamiento)
            float Tvuelta = (temp->getDesdeD() + temp->getHastaD()) / sol->getpi()->getVelocidad() + tempCarga * sol->getpi()->getTiempoRetiroEsc();
            if (debug) cout << "Tvuelta: " << Tvuelta << endl;
        
            sol->setF2(sol->getF2() + tempCarga * sol->getpi()->getUnDia(dia)->getPrefDia());
            if (debug) cout << "F2: " << sol->getF2() << endl;
        
            //Se construye una vuelta
            Round* tempVuelta = new Round( temp->getIDnodo(), tempCarga, Tvuelta, sol->getpi()->getUnCamion(camion), sol->getpi()->getUnDia(dia)) ;
            sol->setVuelta(tempVuelta);
  
            //guardar el escombro disponible en el nodo
            sol->setEscRemanente(temp->getPosNodo(), sol->getEscRemanente(temp->getPosNodo()) - tempCarga);

//             // si al eliminar la vuelta la cant de escombros remante es casi cero significa que el nodo se consideraba limpio completo
            if (sol->getEscRemanente(cliente) <= 0.01){
                int diatermino = sol->getDiaTermino(temp->getIDnodo()); //Se debe bucar el día de la última recoleccion para actualizar las FO (especialmente la preferencia asociada a ese día)
                if (diatermino < dia)
                    diatermino = dia;
                sol->setF1(sol->getF1() + sol->getpi()->getUnDia(diatermino)->getPrefDia()*sol->getpi()->getUnNodo(cliente)->getPrefNodo());

                //se actualizan las otras cosas
                sol->setF3(sol->getF3() + 1);
                sol->setF4(sol->getF4() + sol->getpi()->getUnNodo(cliente)->getPrefNodo());
            }

            sol->setTDisponibleCamion(camion, dia, sol->getTDisponibleCamion(camion,dia) - Tvuelta);

            if (debug) tempVuelta->imprimirVuelta();
        }


    }
    if (debug) sol->ImprimirSolucion();
    //if (debug) getchar();
    intentos++;
  }


  //agregar vuelta al listado

  //actualizar escombros remanentes
  
}
