#include "Mazo.h"

Mazo::Mazo(){
    vector<string> valores = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    vector<string> signos = {"c", "d", "t", "o"}; //corazon, diamante, trebol, oros
    for (const auto& val: valores){
        for(const auto& sig: signos){
            cartas.insert({val, sig});
        }
    }
}
Mazo::~Mazo(){}
multimap<string,string>& Mazo::getMap() {return this->cartas;}

void Mazo::agregarse(string& etiqueta) {
    this->getvectorEtiqueta().push_back(etiqueta);
}