#include "Interfaz.h"
#include <iostream>
#include <conio.h> // Para _kbhit() y _getch()

Interfaz::Interfaz() {
    mapa = Mapa::obtenerInstancia();
    mapa->agregarObservador(&logger);
    mapa->generar();
}

void Interfaz::ejecutarSimulacion() {
    int tick = 0;
    bool primerTick = true;

    while (continuar) {
        system("cls");
        std::cout << "Tick #" << tick << "\n\n";

        mapa->mostrar();

        if (!primerTick) {
            mapa->actualizar();
        }
        else {
            primerTick = false; // Después del primer tick
        }

        logger.mostrar();
        logger.limpiar();

        std::cout << "\nPresiona [SPACE] para pausar o cualquier otra tecla para avanzar...\n";

        // Esperar tecla sin Enter
        char tecla = _getch();
        if (tecla == ' ') {
            mostrarMenu();
        }

        ++tick;
    }
}

void Interfaz::mostrarMenu() {
    int opcion = 0;
    do {
        std::cout << "\n=== Menú ===\n";
        std::cout << "1. Continuar\n";
        std::cout << "2. Modo Dios: " << (modoDios ? "Activado" : "Desactivado") << "\n";
        std::cout << "3. Guardar (no implementado)\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        procesarOpcion(opcion);
    } while (opcion != 1 && continuar);
}

void Interfaz::procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        break;
    case 2:
        modoDios = !modoDios;
        std::cout << (modoDios ? "Modo Dios ACTIVADO\n" : "Modo Dios DESACTIVADO\n");
        break;
    case 3:
        guardarEstado();
        break;
    case 4:
        continuar = false;
        std::cout << "Saliendo de la simulación...\n";
        break;
    default:
        std::cout << "Opción inválida.\n";
        break;
    }
}

void Interfaz::guardarEstado() {
    std::cout << "Funcionalidad no implementada aún.\n";
}
