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

    vector <float> EscRemanente ;
    vector <float> TDisponibleCamion ;

  public:
  
    Solution(ProblemInstance* pi);
    ~Solution();

    ProblemInstance* getpi(void);
    void setVuelta(Round*);

    void setF1(float);
    void setF2(float);
    void setF3(int);
    void setF4(int);

    float getFo(int);

    float getF1(void);
    float getF2(void);
    int getF3(void);
    int getF4(void);

    void setEscRemanente(int posicion, float cantidad);
    float getEscRemanente(int posicion);

    void setTDisponibleCamion(int camion, int dia, float cantidad);
    float getTDisponibleCamion(int camion, int dia);

    int getCantVueltas(void);
    Round* getUnaVuelta(int indice);

    void EliminarVuelta(int posicion);

    int getSeleccionarCliente(void);
    int getSeleccionarCamionDia(void);

    int getCamionTdisponible(int camiondia);
    int getDiaTdisponible(int camiondia);
    
    int getDiaTermino(long int cliente);

    float Minimo(float a, float b);

    //Método para copiar una clase 
    void copiarSolucion(Solution *slt);

    //Método para evaluar la función de evaluación para SA MultiObjetivo
    float probabilidadSolucionC(Solution *slt, int T, vector <float> Lambda);

    //Función para generar valores para lambda
    void generarLambda(vector <float> Lambda);

    void ImprimirSolucion(void);
    void RevisarSolucion(void);
};
