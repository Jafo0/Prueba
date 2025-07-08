#pragma once
#include  <vector>
#include <deque>
#include <map>
#include <string>
class Tarea;
using namespace std;
class Agente
{
private:
    string etiqueta{};
    Tarea* tarea{nullptr};
public:
    Agente()=default;
    ~Agente()=default;
    void setEtiqueta(string et);
    string getEtiqueta();
    Tarea* getTarea(){return this->tarea;}

    
    virtual Tarea* accion(Tarea*) =0; //accion 
};


