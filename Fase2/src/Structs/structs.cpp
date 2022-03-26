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

void transform::setTransform() {
    x = 0;
    y = 0;
    z = 0;
    ang = 0;
    trans = transformation::none;
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

void group::deleteG() {
    for (size_t i = 0; i < models.size(); i++) {
        models.pop_back();
    }
    for (size_t i = 0; i < transformations.size(); i++) {
        transformations.pop_back();
    }
    for (size_t i = 0; i < groups.size(); i++) {
        groups.pop_back();
    }
    printf("lll: %zu %zu %zu\n", models.size(), transformations.size(), groups.size());
}

bool group::isEmptyG() {
    return models.size() == 0 && transformations.size() == 0 && groups.size() == 0;
}

std::vector<figure> group::getFiguras() {
    return models;
}
std::vector<transform> group::getTransformations() {
    return transformations;
}
std::vector<group> group::getFilhos() {
    return groups;
}