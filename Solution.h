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

  public:
    Solution(ProblemInstance* pi){
      this->pi = pi;
    };
    ~Solution(){};

    ProblemInstance* getpi(void);

    void setVuelta(Round*);
    void setF1(float);
    void setF2(float);

    float getF1(void);
    float getF2(void);

    void ImprimirSolucion(void);
};