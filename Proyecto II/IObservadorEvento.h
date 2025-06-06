// IObservadorEvento.h
#pragma once
#include <string>

class IObservadorEvento {
public:
    virtual void onEvento(const std::string& mensaje) = 0;
    virtual ~IObservadorEvento() = default;
};
