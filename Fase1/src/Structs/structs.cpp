#include "structs.hpp"


using namespace structs;

// cria um ponto com as dadas coordenadas, e adiciona-o à lista de pontos da figura
void figure::addPoint(float a, float b, float c) {
    point p;
    p.x = a;
    p.y = b;
    p.z = c;
    pontos.push_back(p);
}
