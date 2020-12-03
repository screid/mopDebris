#pragma once
#include <iostream>
#include <vector>

using namespace std;

#include "Solution.h"

class Pareto{
  private:

    vector <Solution*> Soluciones;   //Vector con soluciones

  public:

    //Constructor y destructor
    Pareto(){};
    ~Pareto(){};

    //Función dominancia
    int Dominancia(Solution* sol1, Solution* sol2);

    //Detectar soluciones iguales
    bool Iguales(Solution* sol1, Solution* sol2);
    
    //Función para modificar las soluciones al frente.
    void ModificarPareto(Solution* sol);

    //Función para imprimir frente
    void imprimirPareto();

    //Para imprimir un archivo 
    void imprimirParetoaArchivo(string nombre);

};
