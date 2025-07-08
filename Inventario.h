#pragma once 
#include "Tarea.h"
#include <map>
//#include <vector>
using namespace std;

class Inventario: public Tarea{
private:
    map<int, int> juguetes; //almacena objetos unicos
public:
    Inventario();
    ~Inventario();
    map<int,int> getMap();
};

