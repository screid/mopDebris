#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Day{
  private:
    int IDDia;
    float PrefDia;
  
  public:

    Day(){};
    ~Day(){};

    void setIDDia(int IDDia);
    void setPrefDia(float PrefDia);

    int getIDDia(void);
    float getPrefDia(void);

    void imprimirDia(void);
};