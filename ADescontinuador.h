#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Inventario.h"
class ADescontinuador : public Agente{
private:
    
public:
    ADescontinuador()=default; 
    ~ADescontinuador()=default;

    Tarea* accion(Tarea*) override;//accion 
    
};