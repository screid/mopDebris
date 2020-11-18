#pragma once
#include <iostream>
#include <vector>

#include "ProblemInstance.h"

using namespace std;

class Solution{
  private:
    vector <Round*> Vueltas ;
    ProblemInstance* pi;
    float F1 ;
    float F2 ;
    int F3 ;
    int F4 ;

    //vector <float*> EscDisponible ;
    //vector <float*> TiempoDisponible ;

  public:
    Solution(ProblemInstance* pi);
    ~Solution(){};

    ProblemInstance* getpi(void);

    void setVuelta(Round*);
    void setF1(float);
    void setF2(float);
    void setF3(int);
    void setF4(int);

    float getF1(void);
    float getF2(void);
    int getF3(void);
    int getF4(void);

    void ImprimirSolucion(void);
};