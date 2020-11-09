#include "Node.h"

void Node::setIDnodo(long int IDnodo){
  this->IDnodo = IDnodo; 
}

void Node::setCantEsc(float CantEsc){
  this->CantEsc = CantEsc;
}

void Node::setPrefNodo(int PrefNodo){
  this->PrefNodo = PrefNodo;
}

long int Node::getIDnodo(void){
  return this->IDnodo;
}

float Node::getCantEsc(void){
  return this->CantEsc;
}

int Node::getPrefNodo(void){
  return this->PrefNodo;
}

void Node::imprimirNodo(void){
  cout << "ID:" << this->IDnodo << endl;
  cout << "Cant Esc:" << this->CantEsc << endl;
  cout << "Pref Nodo:" << this->PrefNodo << endl;
}



