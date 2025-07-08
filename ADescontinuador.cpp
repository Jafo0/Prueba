#include "ADescontinuador.h"

Tarea* ADescontinuador::accion(Tarea* tarea){
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
    //borro objeto
    mapa.erase(it);

    string etiquetaGenerada = "Borro juguete en <"+ to_string(id)+">";
    this->setEtiqueta(etiquetaGenerada);
    inv->agregarse(etiquetaGenerada);
    return inv;
} 