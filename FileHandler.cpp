#include "FileHandler.h"

ProblemInstance* FileHandler::readInputFile(){

  //Creamos un espacio para pi (que es de tipo problemInstance)
  ProblemInstance* pi = new ProblemInstance();

  //Ejecuta la lectura para la variable fs
  this->fs = fstream( this->instanceFilename );

  //Error por si uno el da mal la ruta
  if ( ! this->fs ) // Si la dirección está vacía, tira error 
	{
		cerr << "No se puede abrir archivo: "<< this-> instanceFilename << endl;
		exit(0);
	}

  //Aquí empieza la lectura
	string linea;
  getline(this->fs,linea);
  int n_camiones = atoi(linea.c_str());
  pi->setCantCamiones(n_camiones);

  //Le asigno ID a los camiones 
  for (int i = 0; i < n_camiones; i++){
    Truck* temp = new Truck();
    temp->setIDCamion(i);
    pi->agregarCamion(temp);
  }

  //Se corre una linea
  getline(this->fs,linea);
  int n_nodos = atoi(linea.c_str());
  pi->setCantNodos(n_nodos);

  //Se corre una linea
  getline(this->fs,linea);
  int n_dias = atoi(linea.c_str());
  pi->setCantDias(n_dias);

  //Le asigno ID a los dias 
  for (int i = 0; i < n_dias; i++){
    Day* temp = new Day();
    temp->setIDDia(i);
    pi->agregarDia(temp);
  }

  //Se corre una linea
  getline(this->fs,linea);
  int n_vueltas = atoi(linea.c_str());
  pi->setCantVueltas(n_vueltas);

  //Le asigno ID a las vueltas 
  for (int i = 0; i < n_vueltas; i++){
    Round* temp = new Round();
    temp->setIDVuelta(i);
    pi->agregarVuelta(temp);
  }

  //Se corre una linea
  getline(this->fs,linea);
  pi->setCapacidad(atoi(linea.c_str()));

  //Se corre una linea
  getline(this->fs,linea);
  pi->setVelocidad(atof(linea.c_str()));

  //Se corre una linea
  getline(this->fs,linea);
  pi->setTiempoRetiroEsc(atof(linea.c_str()));

  //Se corre una linea
  getline(this->fs,linea);
  pi->setTiempoMaxTrabajo(atof(linea.c_str()));

  //Para asignar ID a cada uno
  for (int i= 0; i < n_nodos; i++){
    this->fs >> this->read;

    Node* temp = new Node();
    temp->setIDnodo(stol(read.c_str()));
    pi->agregarNodo(temp);
  }

  //Cantidad de escombros para cada nodo
  for (int i= 1; i < n_nodos; i++){
    this->fs >> this->read;

    Node* temp = pi->getUnNodo(i);
    temp->setCantEsc(atoi(read.c_str()));
  }

  //Preferencia para cada nodo
  for (int i= 1; i < n_nodos; i++){
    this->fs >> this->read;

    Node* temp = pi->getUnNodo(i);
    temp->setPrefNodo(atoi(read.c_str()));
  }

  //Preferencia de cada dia
  for (int i= 0; i < n_dias; i++){
    this->fs >> this->read;

    Day* temp = pi->getUnDia(i);
    temp->setPrefDia(atoi(read.c_str()));
  }

  /*
  //Matriz distancia :c (desde el deposito hasta los nodos)
  for (int i = 0; i < n_nodos; i++){
    this->fs >> this->read >> this->read2 >> this->read3;

    //Se asume que los datos están ordenados y el franco no se equivoco
    pi->setDesdeDeposito(atof(read3.c_str()));
  }

    //Matriz distancia :c (desde los nodos hacia el depósito)
  for (int i = 0; i < n_nodos; i++){
    this->fs >> this->read >> this->read2 >> this->read3;

    //Se asume que los datos están ordenados y el franco no se equivoco
    pi->setHaciaDeposito(atof(read3.c_str()));
  }
*/
  return pi;

}