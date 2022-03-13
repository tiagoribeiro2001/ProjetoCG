#include "structs.hpp"


using namespace structs;

// Cria um ponto dadas as coordenadas
void figure::addPoint(float a, float b, float c) {
    point p;
    p.x = a;
    p.y = b;
    p.z = c;
    pontos.push_back(p);
}
