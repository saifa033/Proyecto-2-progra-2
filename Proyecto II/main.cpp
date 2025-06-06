#include <iostream>
#include <memory>
#include "CriaturaFactory.h"
#include "RecursoFactory.h"
using namespace std;
#include "Mapa.h"
#include "Persistencia.h"
int main() {
   /* // Crear un recurso de tipo 'C' (Carnívoro)
    unique_ptr<Recurso> recurso1 = RecursoFactory::crearRecursoDios(1, 2, 'C');

    // Mostrar información del recurso
    if (recurso1) {
        cout << "Recurso creado:" << endl;
        cout << "Tipo: " << recurso1->tipo()
            << ", Símbolo: " << recurso1->obtenerSimbolo()
            << ", Energía: " << recurso1->energiaConsumible()
            << ", Posición: (" << recurso1->getX() << "," << recurso1->getY() << ")"
            << endl;
    }

    // Crear criatura carnivora
    int x = 0, y = 0;
    int edad = 5, energia = 10;
    string nombre = "CarnivoroPrueba";
    char tipo = 'C'; // Carnívora

    unique_ptr<Criatura> criatura = CriaturaFactory().crearcriaturaDios(x, y, edad, energia, nombre, tipo);

    if (!criatura) {
        cout << "Error al crear la criatura." << endl;
        return 1;
    }

    // Mostrar energía antes de consumir
    cout << "\nEnergía antes de consumir: " << criatura->getenergia() << endl;

    // Intentar consumir el recurso
    bool consumido = criatura->puedeConsumir(recurso1.get());

    // Resultado del intento
    if (consumido) {
        cout << "La criatura consumió el recurso correctamente." << endl;
    }
    else {
        cout << "La criatura NO pudo consumir el recurso." << endl;
    }

    // Mostrar energía después de consumir
    cout << "Energía después de consumir: " << criatura->getenergia() << endl;
    cout << criatura->getX() << endl;
    cout << criatura->getY() << endl;
    // Mostrar toda la información de la criatura
    cout << "\n=== Información de la criatura ===" << endl;
    criatura->envejecer();
    cout << criatura->Tostring() << endl;
    */

    // Obtener instancia del mapa
    Mapa* mapa = Mapa::obtenerInstancia();

    // Generar recursos y criaturas (opcional)
    mapa->generar();

    // Mostrar el mapa
    mapa->mostrar();

    // Crear objeto de persistencia
    PersistenciaMapa persistencia;

    // Guardar recursos en archivo
    bool exito = persistencia.guardarrecurso(*mapa, "recursos.txt");

    if (exito) {
        std::cout << "Recursos guardados correctamente en recursos.txt\n";
    }
    else {
        std::cout << "Error al guardar recursos\n";
    } 

    return 0;
}
