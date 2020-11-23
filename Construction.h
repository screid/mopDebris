#pragma once
#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

class Construction{

  private:
    vector<Node *> ListaNodos;
  public:

    //Método constructor
    Construction(){};

    //Método destructor
    ~Construction();

    //Detecta si la solución es factible o no
    bool ConstruirSolucionFact(Solution *sol);

};
