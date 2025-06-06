#include <iostream>
#include <memory>
#include "CriaturaFactory.h"
#include "RecursoFactory.h"
using namespace std;
#include "Mapa.h"
#include "Persistencia.h"
int main() {
   /* // Crear un recurso de tipo 'C' (Carn�voro)
    unique_ptr<Recurso> recurso1 = RecursoFactory::crearRecursoDios(1, 2, 'C');

    // Mostrar informaci�n del recurso
    if (recurso1) {
        cout << "Recurso creado:" << endl;
        cout << "Tipo: " << recurso1->tipo()
            << ", S�mbolo: " << recurso1->obtenerSimbolo()
            << ", Energ�a: " << recurso1->energiaConsumible()
            << ", Posici�n: (" << recurso1->getX() << "," << recurso1->getY() << ")"
            << endl;
    }

    // Crear criatura carnivora
    int x = 0, y = 0;
    int edad = 5, energia = 10;
    string nombre = "CarnivoroPrueba";
    char tipo = 'C'; // Carn�vora

    unique_ptr<Criatura> criatura = CriaturaFactory().crearcriaturaDios(x, y, edad, energia, nombre, tipo);

    if (!criatura) {
        cout << "Error al crear la criatura." << endl;
        return 1;
    }

    // Mostrar energ�a antes de consumir
    cout << "\nEnerg�a antes de consumir: " << criatura->getenergia() << endl;

    // Intentar consumir el recurso
    bool consumido = criatura->puedeConsumir(recurso1.get());

    // Resultado del intento
    if (consumido) {
        cout << "La criatura consumi� el recurso correctamente." << endl;
    }
    else {
        cout << "La criatura NO pudo consumir el recurso." << endl;
    }

    // Mostrar energ�a despu�s de consumir
    cout << "Energ�a despu�s de consumir: " << criatura->getenergia() << endl;
    cout << criatura->getX() << endl;
    cout << criatura->getY() << endl;
    // Mostrar toda la informaci�n de la criatura
    cout << "\n=== Informaci�n de la criatura ===" << endl;
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
