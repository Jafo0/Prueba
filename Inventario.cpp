#include "Inventario.h"
Inventario::Inventario(){
    for(int id=1;id<=40;id++){
        juguetes[id]=10; 
        //para cada id todos empiezan con cantidad 10
    }
}
Inventario::~Inventario(){}
map<int,int>& Inventario::getMap(){return this->juguetes;}

void Inventario::agregarse(string& etiqueta) {
    this->getvectorEtiqueta().push_back(etiqueta);
}