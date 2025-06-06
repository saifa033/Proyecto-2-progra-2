// LoggerEventos.cpp
#include "LoggerEventos.h"
#include <iostream>

void LoggerEventos::onEvento(const std::string& mensaje) {
    eventos.push_back(mensaje);
}

void LoggerEventos::mostrar() const {
    std::cout << "\nEventos:\n";
    for (const auto& e : eventos) {
        std::cout << "- " << e << "\n";
    }
}

void LoggerEventos::limpiar() {
    eventos.clear();
}
