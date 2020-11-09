#include "Round.h"

void Round::setIDVuelta(int IDVuelta){
  this->IDVuelta = IDVuelta;
}

int Round::getIDVuelta(void){
  return this->IDVuelta;
}

void Round::imprimirVuelta(void){
  cout << "Vuelta:" << this->IDVuelta << endl;
}