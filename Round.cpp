#include "Round.h"

Round::Round(int IDVuelta, float CargaRecogida, float TiempoVuelta, Truck* NombreCamion, Day* DiaVuelta){
  this->IDVuelta = IDVuelta;
  this->CargaRecogida = CargaRecogida;
  this->TiempoVuelta = TiempoVuelta;
  this->NombreCamion = NombreCamion;
  this->DiaVuelta = DiaVuelta;
}

void Round::setIDVuelta(int IDVuelta){
  this->IDVuelta = IDVuelta;
}

int Round::getIDVuelta(void){
  return this->IDVuelta;
}

void Round::imprimirVuelta(void){
  cout << "Vuelta:" << this->IDVuelta << endl;
  cout << "Carga:" << this->CargaRecogida << endl;
  cout << "Tiempo" << this->TiempoVuelta << endl;
  cout << "Camion" << this->NombreCamion->getIDCamion() << endl;
  cout << "Dia" << this->DiaVuelta->getIDDia() << endl;
  cout << "---------------^~^----------------" << endl;
}

