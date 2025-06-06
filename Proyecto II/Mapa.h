#ifndef MAPA_H
#define MAPA_H

#include "Recurso.h"
#include "Criatura.h"
#include "IObservadorEvento.h"
#include <vector>
#include <memory>

class Mapa {
private:
    static Mapa* instancia;
    static const int ancho = 10;
    static const int alto = 10;

    vector<unique_ptr<Recurso>> recursos;
    vector<unique_ptr<Criatura>> criaturas;
    vector<IObservadorEvento*> observadores;

    Mapa();
    void generarRecursos();
    void generarCriaturas();

public:
    static Mapa* obtenerInstancia();
    const vector<unique_ptr<Criatura>>& getcriaturas()const ;
    const vector<unique_ptr<Recurso>>& getrecursos()const;
   // vector<unique_ptr<Criatura>>& getcriaturas();

    void generar();
    void mostrar() const;
    bool celdaLibre(int x, int y, const Criatura* quienPregunta) const;
    void actualizar();
    void agregarObservador(IObservadorEvento* obs);
    void notificarEvento(const std::string& mensaje);
    void agregarCriatura(unique_ptr<Criatura> criatura);
};

#endif // MAPA_H
