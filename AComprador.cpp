#include "AComprador.h"
Tarea* AComprador::accion(Tarea* tarea){
    string etiquetaGenerada;
    Inventario* inv = dynamic_cast<Inventario*>(tarea);
    if (!inv){
        return nullptr;
    }
    auto& mapa = inv->getMap();

    //selecciono random
    int cont = rand()%mapa.size(); 
    auto it = mapa.begin();
    advance(it, cont);

    int id = it->first;
    if (mapa[id]>=1){
        mapa[id] -=1;
        etiquetaGenerada = "Compra juguete <"+to_string(id)+">";
    }else{
        etiquetaGenerada = "No hay mas<"+to_string(id)+">";
    }
    this->setEtiqueta(etiquetaGenerada);
    inv->agregarse(etiquetaGenerada);
    return inv;
}