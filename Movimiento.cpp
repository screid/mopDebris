#include "Movimiento.h"


bool Movimiento::modificarSolucion(Solution *sol){

  //eliminar getCantVueltas
  int veces = 2;
  int indice ;
  int cliente;
  int camion;
  int dia;

  sol->ImprimirSolucion();
  getchar();

  for (int i=0 ; i<veces ; i++){
    cout << "I: " << i << endl;
    indice = sol->getpi()->generarNAleat(0, sol->getCantVueltas()-1); //escoger vuelta aleatoria

    Round* EliminarV = sol->getUnaVuelta(indice); //tomamos la vuelta escogida
    cout <<"-----------------------------"<< endl;
    EliminarV->imprimirVuelta();
    cout <<"-----------------------------"<< endl;

    cliente = sol->getpi()->getUnNodo2(EliminarV->getIDNodo())->getPosNodo(); //nodo al que se le cambian las cosas
    camion = EliminarV->getNombreCamion()->getIDCamion();
    dia = EliminarV->getDiaVuelta()->getIDDia();

    sol->setEscRemanente(cliente, sol->getEscRemanente(cliente)+EliminarV->getCargaRecogida()); //le regresamos los escombros recogidos en esa vuelta al cliente  
    
    sol->setTDisponibleCamion(camion, dia, EliminarV->getTiempoVuelta()+ sol->getTDisponibleCamion(camion,dia));//le regresamos el tiempo disponible al camion en el dia correspondiente


    sol->EliminarVuelta(indice);

    sol->ImprimirSolucion();
    getchar();
  }

  //actualizar escombros remanente

  //seleccionar aleatorioamente un cliente al que le queden escombros

  //crear la vuelta

  //agregar vuelta al listado

  //actualizar escombros remanentes
  
  
  
  
  
  
  
  /*
  
  
  //cout << "Indice: " << indice << endl;
  
  sol->modificarObj(indice, 1-sol->getrepS(indice));

  //Verificamos si excede la capacidad de la mochila
  int peso_nuevo = sol->getpesoTotal();

  //Calculo del nuevo peso de la mochila 
  if (sol->getrepS(indice) == 1){
    //Significa que se agrego un objeto, por lo tanto se le suma el valor del peso:
    peso_nuevo = peso_nuevo + sol->getpi()->getObjetos(indice)->getPeso();
  }
  //Aquí se elimina un objeto de la mochila 
  else{
    peso_nuevo = peso_nuevo - sol->getpi()->getObjetos(indice)->getPeso(); 
  }

  //Verificamos si la solución es factible o no:
  if ( peso_nuevo <= sol->getpi()->getCapacidad() ){
    //cout << "Modificación factible" <<endl;
    
    //Aquí se actualiza el peso con el peso nuevo 
    sol->setpesoTotal(peso_nuevo);

    //Tengo que modificar las funciones objetivos.
    //Recorro todas las funciones objetivos
    for (int j = 0; j < sol->getpi()->getCantFO(); j++){
      
      if (sol->getrepS(indice) == 1){
        sol->modificarfo(j, sol->getfo(j) + sol->getpi()->getObjetos(indice)->getValor(j) );
      }
      else {
        sol->modificarfo(j, sol->getfo(j) - sol->getpi()->getObjetos(indice)->getValor(j) );
      }
    }
    return true;
  }
  else {
    //cout << "Modificación infactible" <<endl;
    //Vuelve al valor original
    sol->modificarObj(indice, 1-sol->getrepS(indice));

    return false;

  }
  */
}
