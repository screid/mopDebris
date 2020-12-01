#include "Solution.h"

Solution::Solution(ProblemInstance* pi){
  this->pi = pi;

  for (Node* n: pi->getTodosNodos()){
    this->EscRemanente.push_back(n->getCantEsc());
  }

  this->F1 = 0 ;
  this->F2 = 0 ;
  this->F3 = 0 ;
  this->F4 = 0 ;

  for (Truck* n: pi->getTodosCamiones()){
    for (Day* d: pi->getTodosDias() ){

      this->TDisponibleCamion.push_back(pi->getTiempoMaxTrabajo());
    }
  }
}

Solution::~Solution(){
  this->EscRemanente.clear();
  this->EscRemanente.shrink_to_fit();

  this->TDisponibleCamion.clear();
  this->TDisponibleCamion.shrink_to_fit();
}


ProblemInstance* Solution::getpi(void){
  return this->pi ;
}

void Solution::setVuelta(Round* vuelta){
  this->Vueltas.push_back(vuelta); 
}

void Solution::ImprimirSolucion(){
  
  for (Round* v: this->Vueltas){
    v->imprimirVuelta();
  } 
  cout << endl ;
  cout << "Objetivo 1: " << this->F1 << endl ;
  cout << "Objetivo 2: " << this->F2 << endl ;
  cout << "Objetivo 3: " << this->F3 << endl ;
  cout << "Objetivo 4: " << this->F4 << endl ;

  int h = 0 ;
  for (float i: this->EscRemanente){
    cout << h << "  " << this->getpi()->getUnNodo(h)->getIDnodo() << "  " << i << endl ;
    h ++;
  }
  
  h = 0 ;
  int d = 0 ;
  for (float i: this->TDisponibleCamion){

    cout << this->getpi()->getUnCamion(h)->getIDCamion() << " " << d << " " << i << endl ;

    d++;

    if (d % this->getpi()->getCantDias() == 0){
      h++;
      d=0;
    }
  }
}

void Solution::setF1(float F1){
  this->F1 = F1;
}

void Solution::setF2(float F2){
  this->F2 = F2;
}

void Solution::setF3(int F3){
  this->F3 = F3;
}

void Solution::setF4(int F4){
  this->F4 = F4;
}

float Solution::getFo(int i){
  if (i == 0){
    return this->F1;
  } else {
    return this->F2;
  }
}

float Solution::getF1(void){
  return this->F1 ;
}

float Solution::getF2(void){
  return this->F2 ;
}  

int Solution::getF3(void){
  return this->F3 ;
} 

int Solution::getF4(void){
  return this->F4 ;
} 

float Solution::getEscRemanente(int posicion){
  return this->EscRemanente.at(posicion);
}

void Solution::setEscRemanente(int posicion, float cantidad){
  this->EscRemanente.at(posicion) = cantidad;
}


float Solution::getTDisponibleCamion(int camion, int dia){
  return this->TDisponibleCamion.at( camion*this->getpi()->getCantDias()+dia );
}

void Solution::setTDisponibleCamion(int camion, int dia, float cantidad){
  this->TDisponibleCamion.at(camion*this->getpi()->getCantDias()+dia) = cantidad;
}


int Solution::getCantVueltas(void){
  return this->Vueltas.size();
}

Round* Solution::getUnaVuelta(int indice){
  return this->Vueltas.at(indice);
}

void Solution::EliminarVuelta(int posicion){
  int i=0;
  //cout << posicion << endl;
  for (auto it=this->Vueltas.begin(); it != this->Vueltas.end(); it++){
    if (i == posicion){
      //cout << i << endl;
      Round* temp = (*it) ;
      this->Vueltas.erase(this->Vueltas.begin()+posicion);
      delete temp;
      return ;
    }
    i++;
  }
}

void Solution::copiarSolucion(Solution *slt){

  //Copio los fi's
  this->setF1(slt->getF1());
  this->setF2(slt->getF2());
  this->setF3(slt->getF3());
  this->setF4(slt->getF4());

  //Copio las vueltas 
  for (Round* i: this->Vueltas){
    delete i;  //Primero se eliminan los que se tienen :c 
  }

  //Fijate que aun falta borrar espacio eh 
  this->Vueltas.shrink_to_fit();
  this->Vueltas.clear();

  for(Round* i: slt->Vueltas){
    auto CopiaVuelta = new Round(*i);
    this->Vueltas.push_back(CopiaVuelta);
  }

  //copiar la cantidad de escombros disponibles en el nodo
  this->EscRemanente.shrink_to_fit();
  this->EscRemanente.clear();

  for (float i: slt->EscRemanente){
    int copia = i ;
    this-> EscRemanente.push_back(copia) ;
  }

  //Copiar pi
  this->pi = slt->getpi();

}