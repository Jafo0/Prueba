#pragma once
#include <vector>
#include <deque>
#include <memory>
using namespace std;

template <typename T, typename A>
class Flujo {
private:
    deque<T> tareasPendientes;
    vector<A> agentes;
    deque<T> tareasProcesadas;

public:
    // Constructor
    Flujo(deque<T> tar, vector<A> ag)
        : tareasPendientes(tar), agentes(ag) {}

    // Ejecutar el flujo de procesamiento
    void ejecutarFlujo() {
        while (!tareasPendientes.empty()) {
            T tareaActual = tareasPendientes.front();
            tareasPendientes.pop_front();

            for (auto& agente : agentes) {
                if (tareaActual == nullptr) break;
                tareaActual = agente->accion(tareaActual);
            }

            if (tareaActual != nullptr) {
                tareasProcesadas.push_back(tareaActual);
            }
        }
    }

    // Obtener tareas procesadas
    deque<T> getTareasProcesadas() const {
        return tareasProcesadas;
    }
};