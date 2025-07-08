#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Mazo.h"
class AIntercalado : public Agente{
private:
    
public:
    AIntercalado()=default; 
    ~AIntercalado()=default;

    Tarea* accion(Tarea*) override;//accion 
};