#include "Agente.h"
Agente::Agente(Tarea* tar):tarea(tar){}

    
void Agente::setEtiqueta(string et ){ this->etiqueta = et;}
string Agente::getEtiqueta(){return this->etiqueta;}