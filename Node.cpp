#include "Node.h"

Node::Node(const Node &n2){
    this->IDnodo = n2.IDnodo;
    this->CantEsc = n2.CantEsc;
    this->PrefNodo = n2.PrefNodo;
    this->DesdeD = n2.DesdeD;
    this->HastaD = n2.HastaD;
}

void Node::setIDnodo(long int IDnodo){
  this->IDnodo = IDnodo; 
}

void Node::setCantEsc(float CantEsc){
  this->CantEsc = CantEsc;
}

void Node::setPrefNodo(int PrefNodo){
  this->PrefNodo = PrefNodo;
}

//#########
void Node::setDesdeD(float distancia){
  this->DesdeD = distancia;
}

void Node::setHastaD(float distancia){
  this->HastaD = distancia;
}
//#########

long int Node::getIDnodo(void){
  return this->IDnodo;
}

float Node::getCantEsc(void){
  return this->CantEsc;
}

int Node::getPrefNodo(void){
  return this->PrefNodo;
}

//#########
float Node::getDesdeD(void){
  return this->DesdeD;
}
float Node::getHastaD(void){
  return this->HastaD;
}
//#########

void Node::imprimirNodo(void){
  cout << "ID:" << this->IDnodo << endl;
  cout << "Cant Esc:" << this->CantEsc << endl;
  cout << "Pref Nodo:" << this->PrefNodo << endl;
  
  //#########
  cout << "Dist Desde D. :" << this->DesdeD << endl;
  cout << "Dist Hasta D. :" << this->HastaD << endl;
  cout << " " << endl;
  //#########
}

bool OrdenarPref(const Node* n1, const Node* n2){
  return ((Node*)n1)->getPrefNodo() > ((Node*)n2)->getPrefNodo() ;
}

bool OrdenarCarga(const Node* n1, const Node* n2){
  return (((Node*)n1)->getCantEsc() / ((Node*)n1)->getPrefNodo()) < (((Node*)n2)->getCantEsc() / ((Node*)n2)->getPrefNodo()) ;
}
