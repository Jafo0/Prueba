#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Inventario.h"
class AComprador : public Agente{
private:
    
public:
    AComprador()=default; 
    ~AComprador()=default;

    Tarea* accion(Tarea*) override;//accion 

};