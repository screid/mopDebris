#pragma once
#include <iostream>
#include <vector>

#include "Truck.h"
#include "Day.h"

using namespace std;

class Round{
  private:
    int IDVuelta;
    long int IDNodo;
    float CargaRecogida;
    float TiempoVuelta;
    Truck* NombreCamion;
    Day* DiaVuelta;

  public:

    Round(int IDVuelta, long int IDNodo, float CargaRecogida, float TiempoVuelta, Truck* NombreCamion, Day* DiaVuelta);
    ~Round(){};

    void setIDVuelta(int IDVuelta);
    
    int getIDVuelta(void);

    void imprimirVuelta(void);
};
