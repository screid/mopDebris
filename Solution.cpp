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
  cout << endl ;
  cout << "Objetivo 1: " << this->F1 << endl ;
  cout << "Objetivo 2: " << this->F2 << endl ;

}

void Solution::setF1(float F1){
  this->F1 = F1;
}

void Solution::setF2(float F2){
  this->F2 = F2;
}

float Solution::getF1(void){
  return this->F1 ;
}

float Solution::getF2(void){
  return this->F2 ;
}  
 