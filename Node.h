#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node{

  private:
    long int IDnodo;
    float CantEsc;
    int PrefNodo;

    float DesdeD;
    float HastaD;

  public:

    Node(){
      CantEsc = 0;
      PrefNodo = 0;
      DesdeD = 0;
      HastaD = 0;

    };//Constructor    
    Node(const Node &n2); //Otro constructor
    ~Node(){};   //Destructor

    void setIDnodo(long int IDnodo);
    void setCantEsc(float CantEsc);
    void setPrefNodo(int PrefNodo);
    void setDesdeD(float distancia);
    void setHastaD(float distancia);
    
    long int getIDnodo(void);
    float getCantEsc(void);
    int getPrefNodo(void);
    float getDesdeD(void);
    float getHastaD(void);

    void imprimirNodo(void);
};

bool OrdenarPref(const Node* n1, const Node* n2);

