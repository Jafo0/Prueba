#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Inventario.h"
class AProveedor : public Agente{
private:
    
public:
    AProveedor()=default; 
    ~AProveedor()=default;

    Tarea* accion(Tarea*) override;//accion 
};
