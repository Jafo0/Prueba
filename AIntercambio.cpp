#include "AIntercambio.h"
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>

using namespace std;

Tarea* AIntercambio::accion(Tarea* tarea) {
    Mazo* mazo = dynamic_cast<Mazo*>(tarea);
    if (mazo == nullptr) {
        return tarea;
    }

    multimap<string, string> cartasOriginales = mazo->getMap();
    vector<pair<string, string>> cartasVector;

    for (const auto& carta : cartasOriginales) {
        cartasVector.push_back(carta);
    }

    int totalCartas = cartasVector.size();
    if (totalCartas < 2) {
        return mazo;
    }

    random_device dispositivo;
    mt19937 generador(dispositivo());

    uniform_int_distribution<int> distribucion(0, totalCartas - 1);

    int indice1 = distribucion(generador);
    int indice2 = distribucion(generador);

    while (indice2 == indice1) {
        indice2 = distribucion(generador);
    }

    string carta1 = cartasVector[indice1].first + cartasVector[indice1].second;
    string carta2 = cartasVector[indice2].first + cartasVector[indice2].second;

    pair<string, string> temp = cartasVector[indice1];
    cartasVector[indice1] = cartasVector[indice2];
    cartasVector[indice2] = temp;

    multimap<string, string>& cartasDelMazo = mazo->getMap();
    cartasDelMazo.clear();

    for (int i = 0; i < cartasVector.size(); i++) {
        cartasDelMazo.insert(cartasVector[i]);
    }

    stringstream etiqueta;
    etiqueta << "intercambio " << carta1 << " y " << carta2;
    mazo->getvectorEtiqueta().push_back(etiqueta.str());

    return mazo;
}
