#include "Solution.h"

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
  
  
}