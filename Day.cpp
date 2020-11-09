#include "Day.h"

void Day::setIDDia(int IDDia){
  this->IDDia = IDDia;
}

void Day::setPrefDia(float PrefDia){
  this->PrefDia = PrefDia;
}

int Day::getIDDia(void){
  return this->IDDia;
}

float Day::getPrefDia(void){
  return this->PrefDia;
}

void Day::imprimirDia(void){
  cout << "ID:" << this->IDDia << endl;
  cout << "Pref:" << this->PrefDia << endl;
}