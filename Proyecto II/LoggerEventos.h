// LoggerEventos.h
#pragma once
#include "IObservadorEvento.h"
#include <vector>
#include <string>

class LoggerEventos : public IObservadorEvento {
private:
    std::vector<std::string> eventos;
public:
    void onEvento(const std::string& mensaje) override;
    void mostrar() const;
    void limpiar();
};
