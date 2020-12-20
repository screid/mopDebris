#include "Solution.h"
#include <limits.h>
#include <math.h>

Solution::Solution(ProblemInstance* pi){
  this->pi = pi;

  for (Node* n: pi->getTodosNodos()){
    this->EscRemanente.push_back(n->getCantEsc());
  }

  this->F1 = 0 ;
  this->F2 = 0 ;
  this->F3 = 0 ;
  this->F4 = 0 ;

  for (Truck* n: pi->getTodosCamiones()){
    for (Day* d: pi->getTodosDias() ){

      this->TDisponibleCamion.push_back(pi->getTiempoMaxTrabajo());
    }
  }
}

Solution::~Solution(){
  this->EscRemanente.clear();
  this->EscRemanente.shrink_to_fit();

  this->TDisponibleCamion.clear();
  this->TDisponibleCamion.shrink_to_fit();
}


ProblemInstance* Solution::getpi(void){
  return this->pi ;
}

void Solution::setVuelta(Round* vuelta){
  this->Vueltas.push_back(vuelta); 
}

void Solution::ImprimirSolucion(){
  
  int vuelta = 0 ;
  for (Round* v: this->Vueltas){
    cout << "vuelta: " << vuelta << endl ;
    v->imprimirVuelta();

    vuelta++;
  } 
  cout << endl ;
  cout << "Objetivo 1: " << this->F1 << endl ;
  cout << "Objetivo 2: " << this->F2 << endl ;
  cout << "Objetivo 3: " << this->F3 << endl ;
  cout << "Objetivo 4: " << this->F4 << endl ;

  int h = 0 ;
  for (float i: this->EscRemanente){
    cout << h << "  " << this->getpi()->getUnNodo(h)->getIDnodo() << "  " << i << endl ;
    h ++;
  }
  
  h = 0 ;
  int d = 0 ;
  for (float i: this->TDisponibleCamion){

    cout << this->getpi()->getUnCamion(h)->getIDCamion() << " " << d << " " << i << endl ;

    d++;

    if (d % this->getpi()->getCantDias() == 0){
      h++;
      d=0;
    }
  }
}


void Solution::RevisarSolucion(){
    return;
    float F1=0.0, F2=0.0, F3=0.0, F4=0.0;
    int diatermino;
    vector <float> Escombros; 
    for (Node *n: this->getpi()->getTodosNodos()){
        Escombros.push_back(n->getCantEsc());
    }
        
    for (Round* v: this->Vueltas){
        int pos = this->getpi()->getUnNodo2(v->getIDNodo())->getPosNodo();
        Escombros.at(pos) -= v->getCargaRecogida();
        if(Escombros.at(pos) < -1){
            cout << "ERROR: Se recoge más cantidad de la disponible en el nodo " << v->getIDNodo() << endl;
            cout << "Escombros.at(pos):  " << Escombros.at(pos) << endl; 
            getchar();
        }
        
        if(Escombros.at(pos) < 0.1){
            diatermino = this->getDiaTermino(v->getIDNodo());
            F1 += this->getpi()->getUnNodo2(v->getIDNodo())->getPrefNodo() * this->getpi()->getUnDia(diatermino)->getPrefDia();
            F3 ++;
            F4 += this->getpi()->getUnNodo2(v->getIDNodo())->getPrefNodo();  
        }
        F2 += v->getCargaRecogida()*v->getDiaVuelta()->getPrefDia(); 
    
    }
    
    if(abs(F1 - this->F1) > 0.1){
        cout << "ERROR: El Objetivo 1 no corresponde! " << endl;
        cout << F1 << " vs " << this->F1 << endl;
        getchar();
    }
    
    if(abs(F2 - this->F2) > 0.1){
        cout << "ERROR: El Objetivo 2 no corresponde! " << endl;
        cout << F2 << " vs " << this->F2 << endl;
        getchar();
    }
    
    if(F3 != this->F3){
        cout << "ERROR: El Objetivo 3 no corresponde! " << endl;
        cout << F3 << " vs " << this->F3 << endl;
        getchar();
    }
    
    if(F4 != this->F4){
        cout << "ERROR: El Objetivo 4 no corresponde! " << endl;
        cout << F4 << " vs " << this->F4 << endl;
    }

/*
    int h = 0 ;
    for (float i: this->EscRemanente){
        cout << h << "  " << this->getpi()->getUnNodo(h)->getIDnodo() << "  " << i << endl ;
        h ++;
    }
    
    h = 0 ;
    int d = 0 ;
    for (float i: this->TDisponibleCamion){
    
        cout << this->getpi()->getUnCamion(h)->getIDCamion() << " " << d << " " << i << endl ;
    
        d++;
    
        if (d % this->getpi()->getCantDias() == 0){
        h++;
        d=0;
        }
    }*/
}
    


void Solution::setF1(float F1){
  this->F1 = F1;
}

void Solution::setF2(float F2){
  this->F2 = F2;
}

void Solution::setF3(int F3){
  this->F3 = F3;
}

void Solution::setF4(int F4){
  this->F4 = F4;
}

float Solution::getFo(int i){
  if (i == 0){
    return this->F1;
  } 
  if (i == 1){
    return this->F2;
  }
  if (i == 2){
    return this->F3;
  }
  if (i == 3){
    return this->F4;
  }
}

float Solution::getF1(void){
  return this->F1 ;
}

float Solution::getF2(void){
  return this->F2 ;
}  

int Solution::getF3(void){
  return this->F3 ;
} 

int Solution::getF4(void){
  return this->F4 ;
} 

float Solution::getEscRemanente(int posicion){
  return this->EscRemanente.at(posicion);
}

void Solution::setEscRemanente(int posicion, float cantidad){
  this->EscRemanente.at(posicion) = cantidad;
}


float Solution::getTDisponibleCamion(int camion, int dia){
  int pos =  camion*this->getpi()->getCantDias()+dia;
//   cout << "**camiondia: " << pos <<  ", camion: " << camion << ", dia: " << dia << endl;
  return this->TDisponibleCamion.at(pos);
}

void Solution::setTDisponibleCamion(int camion, int dia, float cantidad){
  this->TDisponibleCamion.at(camion*this->getpi()->getCantDias()+dia) = cantidad;
}


int Solution::getCantVueltas(void){
  return this->Vueltas.size();
}

Round* Solution::getUnaVuelta(int indice){
  return this->Vueltas.at(indice);
}

void Solution::EliminarVuelta(int posicion){
  int i=0;
  //cout << posicion << endl;
  for (auto it=this->Vueltas.begin(); it != this->Vueltas.end(); it++){
    if (i == posicion){
      //cout << i << endl;
      Round* temp = (*it) ;
      this->Vueltas.erase(this->Vueltas.begin()+posicion);
      delete temp;
      return ;
    }
    i++;
  }
}

void Solution::copiarSolucion(Solution *slt){

  //Copio los fi's
  this->setF1(slt->getF1());
  this->setF2(slt->getF2());
  this->setF3(slt->getF3());
  this->setF4(slt->getF4());

  //Copio las vueltas 
  for (Round* i: this->Vueltas){
    delete i;  //Primero se eliminan los que se tienen :c 
  }

  //Fijate que aun falta borrar espacio eh 
  this->Vueltas.shrink_to_fit();
  this->Vueltas.clear();

  for(Round* i: slt->Vueltas){
    auto CopiaVuelta = new Round(*i);
    this->Vueltas.push_back(CopiaVuelta);
  }

  //copiar la cantidad de escombros disponibles en el nodo
  this->EscRemanente.shrink_to_fit();
  this->EscRemanente.clear();

  
  for (float i: slt->EscRemanente){
    int copia = i ;
    this-> EscRemanente.push_back(copia) ;
  }
  
  //copiar los tiempos disponibles de los camiones
  this->TDisponibleCamion.shrink_to_fit();
  this->TDisponibleCamion.clear();

  for (float i: slt->TDisponibleCamion){
    int copia = i ;
    this-> TDisponibleCamion.push_back(copia) ;
  }
  
  //Copiar pi
  this->pi = slt->getpi();

}

int Solution::getSeleccionarCliente(){
  
  int nodo;
  int i = 0 ;
  
  do{
    nodo = this->getpi()->generarNAleat(0,this->EscRemanente.size()-1); // seleccionamos un cliente con escombros disponible de forma aleatoria
    i++;
    if ((i > this->EscRemanente.size()*2)){
      return this->EscRemanente.size() ; // señal para inidicar que no queda escombro disponible en un nodo
    }
  } while ((this->EscRemanente.at(nodo) < 0.1));

  return nodo;

}

int Solution::getSeleccionarCamionDia(){
    int camion;

    do{
      camion = this->getpi()->generarNAleat(0,this->TDisponibleCamion.size()-1);
    } while (this->TDisponibleCamion.at(camion) <= 0);

  return camion ;
}

int Solution::getCamionTdisponible(int camiondia){
  return camiondia/this->getpi()->getCantDias();
}

int Solution::getDiaTdisponible(int camiondia){
  return camiondia%this->getpi()->getCantDias();
}

//Colocar en clase utilities
float Solution::Minimo(float a, float b){
  if (a < b){
    return a;
  } else {
    return b;
  }
}

int Solution::getDiaTermino(long int cliente){
    int day = 0;
    for(Round * r: this->Vueltas){
        if(r->getIDNodo() == cliente){
            if (r->getDiaVuelta()->getIDDia() > day)
                day = r->getDiaVuelta()->getIDDia();
        }
    }
    return day;
}


//Método para evaluar la función de evaluación para SA MultiObjetivo
float Solution::probabilidadSolucionC(Solution *slt, int T, vector <float> Lambda){

  int max = INT_MIN;

  for (int i = 0; i < this->getpi()->getCantFO(); i++){
    float calculo = Lambda.at(i)*(slt->getFo(i) - this->getFo(i))/ T;
    if (calculo > max){
      max = calculo;
    }
  }

  max = exp(max);

  if (max < 1){
    return max;
  } else {
    return 1;
  }

}


void Solution::generarLambda(vector <float> Lambda){

  vector <float> numeros;
  float aux = 0;      //Me guarda la suma de los numeros 

  for (int i = 0; i < this->getpi()->getCantFO(); i++){
    //Genero un número aleatorio entre 0 y 10 y lo entrego al vector
    numeros.push_back(this->getpi()->generarNAleat(0, 10));
    aux = aux + numeros.at(i);
  }

  //Le voy modificando el valor a lambda
  for (int i = 0; i < this->getpi()->getCantFO(); i++){
    Lambda.at(i) = numeros.at(i)/aux;
    //cout << Lambda.at(i) << "\t";
  }
  //cout << endl;
}
