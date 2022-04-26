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

// ---------------------
// Transformações normais
// ---------------------

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

// ---------------------
// Transformações com tempo
// ---------------------

float timedTransform::getX() {
    return x;
}
float timedTransform::getY() {
    return y;
}
float timedTransform::getZ() {
    return z;
}
int timedTransform::getTime() {
    return time;
}
timedTransformation timedTransform::getTrans() {
    return trans;
}
std::vector<point> timedTransform::getPoints() {
    return points;
}

std::vector<point> timedTransform::getCurvePoints() {
    return curvePoints;
}

void timedTransform::setTimedTranslate(int timer, std::vector<point> p) {
    time = timer;
    x = 0;
    y = 0;
    z = 0;
    points = p;
    trans = timedTransformation::translate;
}

void timedTransform::setTimedRotate(int timer, float xr, float yr, float zr) {
    time = timer;
    x = xr;
    y = yr;
    z = zr;
    trans = timedTransformation::rotate;
}

void timedTransform::addCurvePoints(point p){
    curvePoints.push_back(p);
}

// ---------------------
// Grupos
// ---------------------

// Incrementa o valor de trianglesCount em num
void group::addTrianglesCount(int num) {
    trianglesCount += num;
}

// Adiciona um transform a um grupo
void group::addTransform(transform t) {
    transformations.push_back(t);
}

// Adiciona transformação com tempo a um grupo
void group::addTimedTransformation(timedTransform t) {
    timedTransformations.push_back(t);
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

int group::getTrianglesCount(){
    return trianglesCount;
}

std::vector<figure> group::getModels() {
    return models;
}

std::vector<transform> group::getTransformations() {
    return transformations;
}

std::vector<timedTransform> group::getTimedTransformations() {
    return timedTransformations;
}

std::vector<group> group::getGroups() {
    return groups;
}