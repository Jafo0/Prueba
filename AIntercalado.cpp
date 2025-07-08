#include "AIntercalado.h"
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

Tarea* AIntercalado::accion(Tarea* tarea) {
    Mazo* mazo = dynamic_cast<Mazo*>(tarea);
    if(mazo == nullptr){
        return tarea;
    }

    multimap<string, string> cartasOriginales = mazo->getMap();
    vector<pair<string, string>> vectorCartas;

    for(const auto& carta : cartasOriginales){
        vectorCartas.push_back(carta);
    }

    random_device aleatorio;
    mt19937 generador(aleatorio());
    shuffle(vectorCartas.begin(), vectorCartas.end(), generador);

    int cantidadTotal = vectorCartas.size();
    int cantidadMitad = cantidadTotal / 2;

    vector<pair<string, string>> primeraMitad;
    vector<pair<string, string>> segundaMitad;

    for (int i = 0; i < cantidadMitad; i++) {
        primeraMitad.push_back(vectorCartas[i]);
    }

    for (int i = cantidadMitad; i < cantidadTotal; i++) {
        segundaMitad.push_back(vectorCartas[i]);
    }

    vector<pair<string, string>> cartasIntercaladas;
    int indice1 = 0;
    int indice2 = 0;

    while (indice1 < primeraMitad.size() || indice2 < segundaMitad.size()) {
        if (indice1 < primeraMitad.size()) {
            cartasIntercaladas.push_back(primeraMitad[indice1]);
            indice1++;
        }
        if (indice2 < segundaMitad.size()) {
            cartasIntercaladas.push_back(segundaMitad[indice2]);
            indice2++;
        }
    }

    multimap<string, string>& cartasDelMazo = mazo->getMap();
    cartasDelMazo.clear();

    for (int i = 0; i < cartasIntercaladas.size(); i++) {
        cartasDelMazo.insert(cartasIntercaladas[i]);
    }

    mazo->getvectorEtiqueta().push_back("intercalados");

    return mazo;
}
