#pragma once
#include "Agente.h"
#include "Tarea.h"
class AProveedor : public Agente{
private:
    
public:
    AProveedor(Tarea* tar);
    ~AProveedor();

    void agregarse(vector<string>) override;//etiquetas
    Tarea* accion() override;//accion 
};
