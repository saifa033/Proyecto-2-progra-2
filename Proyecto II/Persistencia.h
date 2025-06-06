using namespace std;
#include "Mapa.h"
#include <fstream>
#include <vector>
#include <memory>
#include <string>

class PersistenciaMapa {
public:
    bool guardarcriaturas(const Mapa& mapa, const string& archivo);
    static bool cargar(Mapa& mapa, string& archivo);
    bool guardarrecurso(const Mapa& mapa, const string& archivo);
};
