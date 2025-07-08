#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Mazo.h"
class AIntercambio : public Agente{
private:
    
public:
    AIntercambio()=default; 
    ~AIntercambio()=default;

    Tarea* accion(Tarea*) override;//accion 
};