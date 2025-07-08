#pragma once
#include  <vector>
#include <deque>
#include <map>
#include <string>
#include "Tarea.h"
using namespace std;
class Agente
{
private:
    string etiqueta{};
    Tarea* tarea{nullptr};
public:
    Agente(Tarea*);
    ~Agente()=default;
    void setEtiqueta(string et);
    string getEtiqueta();

    virtual void agregarse(vector<string>)=0;//etiqueta
    virtual Tarea* accion() =0; //accion 
};


