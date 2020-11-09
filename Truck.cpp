#include "Truck.h"

void Truck::setIDCamion(int IDCamion){
 this->IDCamion = IDCamion; 
}

void Truck::setCargaCamion(float CargaCamion){
  this->CargaCamion = CargaCamion;
}

void Truck::setTiempoCamion(float TiempoCamion){
  this->TiempoCamion = TiempoCamion;
}

int Truck::getIDCamion(void){
  return this->IDCamion;
}

float Truck::getCargaCamion(void){
  return this->CargaCamion;
}

float Truck::getTiempoCamion(void){
  return this->TiempoCamion;
}

void Truck::imprimirCamion(void){
  cout << "ID:" << this->IDCamion << endl;
  //cout << "Carga:" << this->CargaCamion << endl;
  // cout << "Tiempo:" << this->TiempoCamion << endl;
}