#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node{

  private:
    long int IDnodo;
    float CantEsc;
    int PrefNodo;

  public:

    Node(){
      CantEsc = 0;
      PrefNodo = 0;
    };    //Constructor
    ~Node(){};   //Destructor

    void setIDnodo(long int IDnodo);
    void setCantEsc(float CantEsc);
    void setPrefNodo(int PrefNodo);

    long int getIDnodo(void);
    float getCantEsc(void);
    int getPrefNodo(void);

    void imprimirNodo(void);
};



