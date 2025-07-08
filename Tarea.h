#pragma once
#include  <vector>
#include <string>
#include "Agente.h"
using namespace std;
class Tarea{
private:
    vector<string> etiquetas;//mensajes de agentes

public:
    Tarea();
    ~Tarea();
    //virtual void registrarAgente(Agente*)=0;
    virtual void agregarse(string&)=0;
    vector<string> getvectorEtiqueta();
};
