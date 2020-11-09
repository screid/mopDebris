#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Truck{

  private:
    int IDCamion;
    float CargaCamion;
    float TiempoCamion;

  public:

    Truck(){};    //Constructor
    ~Truck(){};   //Destructor

    void setIDCamion(int IDCamion);
    void setCargaCamion(float CargaCamion);
    void setTiempoCamion(float TiempoCamion);

    int getIDCamion(void);
    float getCargaCamion(void);
    float getTiempoCamion(void);

    void imprimirCamion(void);
};