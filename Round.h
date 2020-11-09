#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Round{
  private:
    int IDVuelta;

  public:

    Round(){};
    ~Round(){};

    void setIDVuelta(int IDVuelta);
    
    int getIDVuelta(void);

    void imprimirVuelta(void);
};