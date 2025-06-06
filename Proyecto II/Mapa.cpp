#include "Mapa.h"
#include "RecursoFactory.h"
#include "CriaturaFactory.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Mapa* Mapa::instancia = nullptr;

Mapa::Mapa() {
    srand(time(nullptr));
}

Mapa* Mapa::obtenerInstancia() {
    if (!instancia) {
        instancia = new Mapa();
    }
    return instancia;
}

 const vector<unique_ptr<Criatura>>& Mapa::getcriaturas() const 
{
    return criaturas;
}

 const vector<unique_ptr<Recurso>>& Mapa::getrecursos() const
 {
     return recursos;
 }




void Mapa::generar() {
    generarRecursos();
    generarCriaturas();
}

void Mapa::generarRecursos() {
    recursos.clear();
    for (int i = 0; i < 10; ++i) {
        int x = rand() % ancho;
        int y = rand() % alto;
        auto r = RecursoFactory::crearRecursoAleatorio(x, y);

        if (celdaLibre(r->getX(), r->getY(), nullptr)) {
            notificarEvento("Ha aparecido un nuevo recurso en (" + std::to_string(r->getX()) +
                ", " + to_string(r->getY()) + ")");
            recursos.push_back(std::move(r));
        }
    }
}

void Mapa::generarCriaturas() {
    criaturas.clear();
    for (int i = 0; i < 3; ++i) {
        int x = rand() % ancho;
        int y = rand() % alto;
        auto c = CriaturaFactory::crearCriaturaAleatoria(x, y);

        if (celdaLibre(c->getX(), c->getY(), nullptr)) {
            notificarEvento("Ha aparecido una nueva criatura en (" + to_string(c->getX()) +
                ", " + to_string(c->getY()) + ")");
            criaturas.push_back(std::move(c));
        }
    }
}

void Mapa::mostrar() const {
    char matriz[alto][ancho];

    // Rellenar con espacios
    for (int i = 0; i < alto; ++i)
        for (int j = 0; j < ancho; ++j)
            matriz[i][j] = '.';

    // Insertar recursos
    for (const auto& r : recursos)
        matriz[r->getY()][r->getX()] = r->obtenerSimbolo();

    // Insertar criaturas
    for (const auto& c : criaturas)
        matriz[c->getY()][c->getX()] = c->tipo();

    // Imprimir matriz
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j)
            std::cout << matriz[i][j] << ' ';
        std::cout << '\n';
    }
}

void Mapa::actualizar() {
    for (auto& c : criaturas) {
        int dx = 0, dy = 0;
        switch (rand() % 4) {
        case 0: dy = -1; break; // arriba (w)
        case 1: dy = 1; break;  // abajo (s)
        case 2: dx = -1; break; // izquierda (a)
        case 3: dx = 1; break;  // derecha (d)
        }

        int nuevaX = c->getX() + dx;
        int nuevaY = c->getY() + dy;

        // Verifica límites
        if (nuevaX < 0 || nuevaX >= ancho || nuevaY < 0 || nuevaY >= alto)
            continue;

        // Solo mover si la celda está libre
        if (celdaLibre(nuevaX, nuevaY, c.get())) {
            c->movimiento(dx, dy, ancho, alto);
            notificarEvento("La criatura se ha movido a (" + std::to_string(c->getX()) + "," + std::to_string(c->getY()) + ")");
        }
    }
}


bool Mapa::celdaLibre(int x, int y, const Criatura* quienPregunta) const {
    // Verifica si hay algún recurso en la celda
    for (const auto& r : recursos) {
        if (r->getX() == x && r->getY() == y) return false;
    }

    // Verifica si hay otra criatura en la celda
    for (const auto& c : criaturas) {
        if (c.get() != quienPregunta && c->getX() == x && c->getY() == y)
            return false;
    }

    return true;
}

void Mapa::agregarObservador(IObservadorEvento* obs) {
    observadores.push_back(obs);
}

void Mapa::notificarEvento(const std::string& mensaje) {
    for (auto* obs : observadores) {
        obs->onEvento(mensaje);
    }
}

void Mapa::agregarCriatura(unique_ptr<Criatura> criatura)
{
    criaturas.push_back(move(criatura));
}
