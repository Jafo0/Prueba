#include "AProveedor.h"

Tarea* AProveedor::accion(Tarea* tarea){
    Inventario* inv = dynamic_cast<Inventario*>(tarea);
    if (!inv){
        return nullptr;
    }
    auto& mapa = inv->getMap();
    
    //selecciono juguete
    int cont = rand()%mapa.size();
    auto it = mapa.begin();
    advance(it, cont);

    int id = it->first; //primer valor es el id segundo el valor
    int cantidadRan = rand()%5+1;

    mapa[id]+=cantidadRan;
    string etiquetaGenerada = "Entran "+to_string(cantidadRan)+" unidades de juguete" + to_string(id);
    this->setEtiqueta(etiquetaGenerada);
    inv->agregarse(etiquetaGenerada);
    return inv;
} 