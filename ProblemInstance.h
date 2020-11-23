#pragma once
#include <iostream>
#include <vector>

#include "Truck.h"
#include "Node.h"
#include "Day.h"
#include "Round.h"

using namespace std;

class ProblemInstance{

  private:
    vector <Truck*> Camiones;
    vector <Node*> Nodos;
    vector <Day*> Dias;
    vector <Round*> Vueltas;
    Node* Deposito;

    //int CantFO default 2

    int CantCamiones;
    int CantNodos;
    int CantDias;
    int CantVueltas;

    float Capacidad;
    float Velocidad;
    float TiempoRetiroEsc;
    float TiempoMaxTrabajo;

    //Matriz Distancias <--- Falta esa!! 
    /* sami
    vector <float> DesdeDeposito;
    vector <float> HastaDeposito;
    */

    /* franco
    vector <float> Ida;
    vector <float> Regreso;
    */

  public:

    ProblemInstance(){};
    ~ProblemInstance(){};

    void agregarCamion(Truck* camion);
    void modificarCamion(int indice, Truck* camion);
    Truck* getUnCamion(int id);
    vector <Truck*> getTodosCamiones(void);
    
    void agregarNodo(Node*);
    void modificarNodo(int indice, Node* nodo);
    Node* getUnNodo(int indice);
    vector <Node*> getTodosNodos(void);

    void agregarDia(Day* dia);
    void modificarDia(int indice, Day* dia);
    Day* getUnDia(int id);
    vector <Day*> getTodosDias(void);

    void agregarVuelta(Round* vuelta);
    void modificarVuelta(int indice, Round* vuelta);
    Round* getUnaVuelta(int id);
    vector <Round*> getTodosVueltas(void);

    void setCantCamiones(int CantCamiones);
    void setCantNodos(int CantNodos);
    void setCantDias(int CantDias);
    void setCantVueltas(int CantVueltas);
    
    int getCantCamiones(void);
    int getCantNodos(void);
    int getCantDias(void);
    int getCantVueltas(void);
    int getCantFO(void);

    void setCapacidad(float Capacidad);
    void setVelocidad(float Velocidad);
    void setTiempoRetiroEsc(float TiempoRetiroEsc);
    void setTiempoMaxTrabajo(float TiempoMaxTrabajo);

    float getCapacidad(void);
    float getVelocidad(void);
    float getTiempoRetiroEsc(void);
    float getTiempoMaxTrabajo(void);

    void setDeposito(Node*);
    Node* getDeposito(void);

/* sami
    void setDesdeDeposito(float);
    void setHaciaDeposito(float);
    
    float getDesdeDeposito(long int idnodo);
    float getHaciaDeposito(long int idnodo);
*/

/* franco
    void setIda(float);
    void setRegreso(float);

    float getIda(int indice);
    float getRegreso(int indice);
*/

    //Función para generar el número de la semilla
    int generarNAleat(int,int);
    
    void imprimirProblemInstance(void);

};








