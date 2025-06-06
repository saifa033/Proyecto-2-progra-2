#pragma once
#include "Mapa.h"
#include "LoggerEventos.h"

class Interfaz {
private:
    Mapa* mapa;
    LoggerEventos logger;
    bool modoDios = false;
    bool continuar = true;

    void mostrarMenu();
    void procesarOpcion(int opcion);
    void guardarEstado(); // a futuro
public:
    Interfaz();

    void ejecutarSimulacion();
};
