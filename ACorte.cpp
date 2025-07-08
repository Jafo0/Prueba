#include "ACorte.h"
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

Tarea* ACorte::accion(Tarea* tarea) {
    Mazo* mazo = dynamic_cast<Mazo*>(tarea);
    if (mazo == nullptr) {
        return tarea;
    }

    multimap<string, string> cartasOriginales = mazo->getMap();
    vector<pair<string, string>> vectorCartas;

    for (const auto& carta : cartasOriginales) {
        vectorCartas.push_back(carta);
    }

    random_device aleatorio;
    mt19937 generador(aleatorio());
    shuffle(vectorCartas.begin(), vectorCartas.end(), generador);

    int totalCartas = vectorCartas.size();
    int mitad = totalCartas / 2;

    vector<pair<string, string>> primeraMitad;
    vector<pair<string, string>> segundaMitad;

    for (int i = 0; i < mitad; i++) {
        primeraMitad.push_back(vectorCartas[i]);
    }

    for (int i = mitad; i < totalCartas; i++) {
        segundaMitad.push_back(vectorCartas[i]);
    }

    vector<pair<string, string>> cartasCortadas;

    for (int i = 0; i < segundaMitad.size(); i++) {
        cartasCortadas.push_back(segundaMitad[i]);
    }

    for (int i = 0; i < primeraMitad.size(); i++) {
        cartasCortadas.push_back(primeraMitad[i]);
    }

    multimap<string, string>& cartasDelMazo = mazo->getMap();
    cartasDelMazo.clear();

    for (int i = 0; i < cartasCortadas.size(); i++) {
        cartasDelMazo.insert(cartasCortadas[i]);
    }

    mazo->getvectorEtiqueta().push_back("cortado");

    return mazo;
}