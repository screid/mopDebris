#pragma once
#include <iostream>
#include <vector>

#include "ProblemInstance.h"

using namespace std;

class Solution{
  private:
    vector <Round*> Vueltas ;
    ProblemInstance* pi;

  public:
    Solution(ProblemInstance* pi){
      this->pi = pi;
    };
    ~Solution(){};

    ProblemInstance* getpi(void);

    void setVuelta(Round*);

    void ImprimirSolucion(void);
};