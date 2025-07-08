#pragma once
#include "Agente.h"
#include "Tarea.h"
#include "Mazo.h"
class ACorte : public Agente{
private:
    
public:
    ACorte()=default; 
    ~ACorte()=default;

    Tarea* accion(Tarea*) override;//accion 
};