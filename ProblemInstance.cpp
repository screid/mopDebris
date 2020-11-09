#include "ProblemInstance.h"


void ProblemInstance::agregarCamion(Truck* camion){
  this->Camiones.push_back(camion);
}

void ProblemInstance::modificarCamion(int indice, Truck* camion){
  this->Camiones.at(indice) = camion;
}

Truck* ProblemInstance::getUnCamion(int id){
  for (Truck* i: this->Camiones){
    if (i->getIDCamion() == id){
      return i;
    }
  }
}

vector <Truck*> ProblemInstance::getTodosCamiones(void){
  return this->Camiones;
}


void ProblemInstance::agregarNodo(Node* nodo){
  this->Nodos.push_back(nodo);
}

void ProblemInstance::modificarNodo(int indice, Node* nodo){
  this->Nodos.at(indice) = nodo;
}

Node* ProblemInstance::getUnNodo(int indice){

  if (indice < this->Nodos.size()){
    return this->Nodos.at(indice);
  } else {
    cout << "Error de dimensión" << endl; 
    return nullptr;
  }
}

vector <Node*> ProblemInstance::getTodosNodos(void){
  return this->Nodos;
}

void ProblemInstance::agregarDia(Day* dia){
  this->Dias.push_back(dia);
}

void ProblemInstance::modificarDia(int indice, Day* dia){
  this->Dias.at(indice) = dia;  
}

Day* ProblemInstance::getUnDia(int id){
  for (Day* i: this->Dias){
    if (i->getIDDia() == id){
      return i;
    }
  }
}

vector <Day*> ProblemInstance::getTodosDias(void){
  return this->Dias;
}

void ProblemInstance::agregarVuelta(Round* vueltas){
  this->Vueltas.push_back(vueltas);
}

void ProblemInstance::modificarVuelta(int indice, Round* vuelta){
  this->Vueltas.at(indice) = vuelta;
}

Round* ProblemInstance::getUnaVuelta(int id){
  for (Round* i: this->Vueltas){
    if (i->getIDVuelta() == id){
      return i;
    }
  }
}

vector <Round*> ProblemInstance::getTodosVueltas(void){
  return this->Vueltas;
}

void ProblemInstance::setCapacidad(float Capacidad){
  this->Capacidad = Capacidad;
}

void ProblemInstance::setVelocidad(float Velocidad){
  this->Velocidad = Velocidad;
}

void ProblemInstance::setTiempoRetiroEsc(float TiempoRetiroEsc){
  this->TiempoRetiroEsc = TiempoRetiroEsc;
}

void ProblemInstance::setTiempoMaxTrabajo(float TiempoMaxTrabajo){
  this->TiempoMaxTrabajo = TiempoMaxTrabajo;
}


void ProblemInstance::setCantCamiones(int CantCamiones){
  this->CantCamiones = CantCamiones;
}

void ProblemInstance::setCantNodos(int CantNodos){
  this->CantNodos = CantNodos;
}

void ProblemInstance::setCantDias(int CantDias){
  this->CantDias = CantDias;
}

void ProblemInstance::setCantVueltas(int CantVueltas){
  this->CantVueltas = CantVueltas;
}


int ProblemInstance::getCantCamiones(void){
  return this->CantCamiones;
}

int ProblemInstance::getCantNodos(void){
  return this->CantNodos;
}

int ProblemInstance::getCantDias(void){
  return this->CantDias;
}

int ProblemInstance::getCantVueltas(void){
  return this->CantVueltas;
}


float ProblemInstance::getCapacidad(void){
  return this->Capacidad;
}

float ProblemInstance::getVelocidad(void){
  return this->Velocidad;
}

float ProblemInstance::getTiempoRetiroEsc(void){
  return this->TiempoRetiroEsc;
}

float ProblemInstance::getTiempoMaxTrabajo(void){
  return this->TiempoMaxTrabajo;
}

//Matriz distancias
void ProblemInstance::setDesdeDeposito(float distancia){
  this->DesdeDeposito.push_back(distancia);
}
void ProblemInstance::setHaciaDeposito(float distancia){
  this->HastaDeposito.push_back(distancia);
}

float ProblemInstance::getDesdeDeposito(long int idnodo){
  
  int aux = 0;
  for (Node* i: this->Nodos){
    if (i->getIDnodo() == idnodo) {
      break;
    }
    aux++;
  }
  return this->DesdeDeposito.at(aux);

}

float ProblemInstance::getHaciaDeposito(long int idnodo){

  int aux = 0;
  for (Node* i: this->Nodos){
    if (i->getIDnodo() == idnodo) {
      break;
    }
    aux++;
  }
  return this->HastaDeposito.at(aux);
}


int ProblemInstance::generarNAleat(int min,int max){
  
  int numero = rand() % abs(max - min + 1) + min;
  return numero;
  
}

void ProblemInstance::imprimirProblemInstance(void){

  cout << "Cantidad de camiones:" << this->CantCamiones << endl;
  cout << "Cantidad de nodos: " << this->CantNodos << endl;
  cout << "Capacidad de dias: " << this->CantDias << endl;
  cout << "Capacidad de vueltas: " << this->CantVueltas << endl <<endl;

  cout << "Capacidad camiones:" << this->Capacidad << endl;
  cout << "Velocidad camiones : " << this->Velocidad << endl;
  cout << "Tiempo Recolec. Escombros: " << this->TiempoRetiroEsc << endl;
  cout << "Tiempo Max. trabajo: " << this->TiempoMaxTrabajo << endl << endl;

  for (Truck* i: this->Camiones){
    i->imprimirCamion();
  } cout << endl;

  for (Node* i: this->Nodos){
    i->imprimirNodo();
  } cout << endl;

  for (Day* i: this->Dias){
    i->imprimirDia();
  } cout << endl;

  for (Round* i: this->Vueltas){
    i->imprimirVuelta();
  } cout << endl;

  for (Node* i: this->Nodos){
    cout << getDesdeDeposito(i->getIDnodo()) << "\t" << getHaciaDeposito(i->getIDnodo())<< endl; 
  }

}