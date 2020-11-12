#include "Round.h"

Round::Round(int IDVuelta, long int IDNodo, float CargaRecogida, float TiempoVuelta, Truck* NombreCamion, Day* DiaVuelta){
  this->IDVuelta = IDVuelta;
  this->IDNodo = IDNodo;
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
  cout << "---------------^~^----------------" << endl;
  cout << "Vuelta: " << this->IDVuelta << endl;
  cout << "Nodo: " << this->IDNodo << endl;
  cout << "Carga: " << this->CargaRecogida << endl;
  cout << "Tiempo: " << this->TiempoVuelta << endl;
  cout << "Camión: " << this->NombreCamion->getIDCamion() << endl;
  cout << "Día: " << this->DiaVuelta->getIDDia() << endl;
  cout << "---------------^~^----------------" << endl;
}

