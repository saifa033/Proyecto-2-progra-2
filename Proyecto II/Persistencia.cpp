#include "Persistencia.h"



bool PersistenciaMapa::guardarcriaturas(const Mapa& mapa, const string& archivo)
{
    ofstream archivoG(archivo);
    if (!archivoG.is_open()) {
        return false;
    }
    const auto& criaturas = mapa.getcriaturas();
    archivoG << criaturas.size() << endl;
    for (const auto& c : criaturas)
    {
        archivoG << c->tipo() << ' '
            << c->getX() << ' '
            << c->getY() << ' '
            << c->getenergia() << ' '
            << c->getnombre() << ' '
            << c->getenergia() << ' '
            << c->getnombre() << '\n';
    }
    archivoG.close();
    return true;
}

bool PersistenciaMapa::cargar(Mapa& mapa, string& archivo)
{
    return false;
}

bool PersistenciaMapa::guardarrecurso(const Mapa& mapa, const string& archivo)
{
    ofstream archivoG(archivo);
    if (!archivoG.is_open()) {
        return false;
    }
    const auto& recursos = mapa.getrecursos();
    archivoG << recursos.size() << endl;
    for (const auto& r : recursos)
    {
        archivoG << r->obtenerSimbolo() << ' '
            << r->getX() << ' '
            << r->getY() << ' ' << '\n';
            
    }
    archivoG.close();
    return true;
}

/*bool PersistenciaMapa::cargarRecursos(Mapa& mapa, const string& archivo)
{
    ifstream archivoL(archivo);
    if (!archivoL.is_open()) {
        return false;
    }

    int cantidad;
    archivoL >> cantidad;
    for (int i = 0; i < cantidad; ++i) {
        char tipo;
        int x, y;
        archivoL >> tipo >> x >> y;

        // Crear recurso con fábrica
        auto recurso = RecursoFactory::crearRecursoDios(x, y, tipo);
        if (recurso) {
            mapa.agregarRecurso(std::move(recurso));
        } else {
            // Error: tipo desconocido
            return false;
        }
    }
    return true;
}
*/
