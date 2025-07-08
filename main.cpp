#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

#include "Flujo.tpp"
#include "Tarea.h"
#include "Inventario.h"
#include "Mazo.h"

#include "AProveedor.h"
#include "AComprador.h"
#include "ADescontinuador.h"
#include "AIntercambio.h"
#include "AIntercalado.h"
#include "ACorte.h"

using namespace std;

int main() {
    srand(time(0));

    int tipo;
    cout << "Seleccione tipo de tarea:\n";
    cout << "1. Inventario\n";
    cout << "2. Mazo\n";
    cin >> tipo;

    int cantidadTareas, cantidadAgentes;
    cout << "Cantidad de tareas: ";
    cin >> cantidadTareas;
    cout << "Cantidad de agentes: ";
    cin >> cantidadAgentes;

    if (tipo == 1) {
        deque<Tarea*> tareas;
        vector<Agente*> agentes;

        for (int i = 0; i < cantidadTareas; i++) {
            tareas.push_back(new Inventario());
        }

        for (int i = 0; i < cantidadAgentes; i++) {
            int aleatorio = rand() % 3;
            if (aleatorio == 0) {
                agentes.push_back(new AProveedor());
            } else if (aleatorio == 1) {
                agentes.push_back(new AComprador());
            } else {
                agentes.push_back(new ADescontinuador());
            }
        }

        Flujo<Tarea*, Agente*> flujo(tareas, agentes);
        flujo.ejecutarFlujo();

        cout << "\nProceso de inventario finalizado.\nTareas procesadas:\n";
        deque<Tarea*> resultado = flujo.getTareasProcesadas();
        for (size_t i = 0; i < resultado.size(); i++) {
            cout << "Tarea #" << (i + 1) << " - Etiquetas:\n";
            vector<string> etiquetas = resultado[i]->getvectorEtiqueta();
            for (const auto& etiqueta : etiquetas) {
                cout << "  - " << etiqueta << endl;
            }
            cout << "---------------------------" << endl;
        }

    } else if (tipo == 2) {
        deque<Tarea*> tareas;
        vector<Agente*> agentes;

        for (int i = 0; i < cantidadTareas; i++) {
            tareas.push_back(new Mazo());
        }

        for (int i = 0; i < cantidadAgentes; i++) {
            int aleatorio = rand() % 3;
            if (aleatorio == 0) {
                agentes.push_back(new AIntercambio());
            } else if (aleatorio == 1) {
                agentes.push_back(new AIntercalado());
            } else {
                agentes.push_back(new ACorte());
            }
        }

        Flujo<Tarea*, Agente*> flujo(tareas, agentes);
        flujo.ejecutarFlujo();

        cout << "\nProceso de mazo finalizado.\nTareas procesadas:\n";
        deque<Tarea*> resultado = flujo.getTareasProcesadas();
        for (size_t i = 0; i < resultado.size(); i++) {
            cout << "Tarea #" << (i + 1) << " - Etiquetas:\n";
            vector<string> etiquetas = resultado[i]->getvectorEtiqueta();
            for (const auto& etiqueta : etiquetas) {
                cout << "  - " << etiqueta << endl;
            }
            cout << "---------------------------" << endl;
        }

    } else {
        cout << "Opcion invalida." << endl;
    }

    return 0;
}
