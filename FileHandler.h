#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "ProblemInstance.h"

using namespace std;

class FileHandler{

  private:
    //Para leer el nombre de la instancia 
    string instanceFilename;
    //Tipo de puntero para leer archivos
	  fstream fs;
    //Lee string's desde el archivo 
	  string read;
    string read2;
    string read3;

  public:
    //Método constructor
    FileHandler(string instanceFilename): instanceFilename(instanceFilename) {};
    ~FileHandler() { cout<< "Eliminando FileHandler" << endl; }

    //Función que lee cositas
    ProblemInstance* readInputFile();

};