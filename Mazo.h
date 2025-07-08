#pragma once 
#include "Tarea.h"
#include <map>
#include <vector>
using namespace std;

class Mazo:public Tarea{
private:
    multimap<string, string> cartas; //almacenar cartas
public:
    Mazo(/* args */);
    ~Mazo();
    multimap<string,string>& getMap();
    void agregarse(string& etiqueta) override;
};

