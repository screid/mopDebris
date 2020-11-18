#include "Solution.h"

Solution::Solution(ProblemInstance* pi){
  this->pi = pi;

  //for (Node* n: pi->getTodosNodos()){
  //  this->EscDisponible.push_back(n->getCantEsc());
  //}

  //for (Truck* n: pi->getTodosCamiones()){
  //  this->TiempoDisponible.push_back(n->getTiempoCamion());
  //}
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