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

void transform::setTransform(float xx, float yy, float zz, float a, transformation t) {
    x = xx;
    y = yy;
    z = zz;
    ang = a;
    trans = t;
}

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

void group::addTransform(transform t) {
    transformations.push_back(t);
}
void group::addFigure(figure f) {
    models.push_back(f);
}
void group::addGroup(group g) {
    groups.push_back(g);
}

std::vector<figure> group::getModels() {
    return models;
}
std::vector<transform> group::getTransformations() {
    return transformations;
}
std::vector<group> group::getGroups() {
    return groups;
}