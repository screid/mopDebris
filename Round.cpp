#include "Round.h"

Round::Round(long int IDNodo, float CargaRecogida, float TiempoVuelta, Truck* NombreCamion, Day* DiaVuelta){
  this->IDNodo = IDNodo;
  this->CargaRecogida = CargaRecogida;
  this->TiempoVuelta = TiempoVuelta;
  this->NombreCamion = NombreCamion;
  this->DiaVuelta = DiaVuelta;
}

Round::Round(const Round &r2){
  this->IDNodo = r2.IDNodo;
  this->CargaRecogida = r2.CargaRecogida;
  this->TiempoVuelta = r2.TiempoVuelta;
  this->NombreCamion = r2.NombreCamion;
  this->DiaVuelta = r2.DiaVuelta;
}


long int Round::getIDNodo(void){
  return this->IDNodo;
}
float Round::getCargaRecogida(void){
  return this->CargaRecogida;
}
float Round::getTiempoVuelta(void){
  return this->TiempoVuelta;
}
Truck* Round::getNombreCamion(void){
  return this->NombreCamion;
}
Day* Round::getDiaVuelta(void){
  return this->DiaVuelta;
}

/*void Round::imprimirVuelta(void){
  cout << "---------------^~^----------------" << endl;
  cout << "Nodo: " << this->IDNodo << endl;
  cout << "Carga: " << this->CargaRecogida << endl;
  cout << "Tiempo: " << this->TiempoVuelta << endl;
  cout << "Camión: " << this->NombreCamion->getIDCamion() << endl;
  cout << "Día: " << this->DiaVuelta->getIDDia() << endl;
  cout << "---------------^~^----------------" << endl;
}*/

void Round::imprimirVuelta(void){
  cout << " \tN: " << this->IDNodo;
  cout << " \tC: " << this->CargaRecogida;
  cout << " \tT: " << this->TiempoVuelta;
  cout << " \tC: " << this->NombreCamion->getIDCamion();
  cout << " \tD: " << this->DiaVuelta->getIDDia() << endl;
  
}
