#include "structs.hpp"


using namespace structs;

// Cria um ponto dadas as coordenadas
void figure::addPoint(float a, float b, float c) {
    point p{};
    p.x = a;
    p.y = b;
    p.z = c;
    pontos.push_back(p);
}

// Altera os parâmetros de um objeto transform
void transform::setTransform(float xx, float yy, float zz, float a, transformation t) {
    x = xx;
    y = yy;
    z = zz;
    ang = a;
    trans = t;
}

// Getters transform

float transform::getX() {
    return x;
}
float transform::getY() {
    return y;
}
float transform::getZ() {
    return z;
}
float transform::getAng() {
    return ang;
}
transformation transform::getTrans() {
    return trans;
}

// Adiciona um transform a um grupo
void group::addTransform(transform t) {
    transformations.push_back(t);
}

// Adiciona uma figura a um grupo
void group::addFigure(figure f) {
    models.push_back(f);
}

// Adiciona um grupo filho ao grupo
void group::addGroup(group g) {
    groups.push_back(g);
}

// Getters grupo

std::vector<figure> group::getModels() {
    return models;
}
std::vector<transform> group::getTransformations() {
    return transformations;
}
std::vector<group> group::getGroups() {
    return groups;
}