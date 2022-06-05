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

void figure::addNormais(float a, float b, float c) {
    point p{};
    p.x = a;
    p.y = b;
    p.z = c;
    normais.push_back(p);
}

void figure::addCoordTex(float a, float b, float c) {
    point p{};
    p.x = a;
    p.y = b;
    p.z = c;
    coordTex.push_back(p);
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

bool timedTransform::isAligned(){
    return align;
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

void timedTransform::setTimedTranslate(int timer, bool aligned, std::vector<point> p) {
    time = timer;
    x = 0;
    y = 0;
    z = 0;
    align = aligned;
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
// Modelo
// ---------------------

void model::addVerticeModel(float a) {
    vertices.push_back(a);
}

void model::addNormalModel(float a) {
    normais.push_back(a);
}

void model::addCoordTexModel(float a) {
    coordTex.push_back(a);
}

void model::setNameTex(std::string nome) {
    nameTex = nome;
}

std::string model::getNameTex(){
    return nameTex;
}

int model::sizeCoordTex() {
    return coordTex.size();
}

std::vector<float> model::getCoordTexModel(){
    return coordTex;
}

std::vector<float> model::getVerticesModel(){
    return vertices;
}

std::vector<float> model::getNormaisModel(){
    return normais;
}

unsigned int model::getTexID(){
    return texID;
}

unsigned int model::getTexCoords(){
    return texCoords;
}

void model::setTexID(unsigned int i){
    texID = i;
}

void model::setTexCoords(unsigned int i){
    texCoords = i;
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
void group::addModel(model m) {
    models.push_back(m);
}

// Adiciona um grupo filho ao grupo
void group::addGroup(group g) {
    groups.push_back(g);
}

// Getters grupo

int group::getTrianglesCount(){
    return trianglesCount;
}

std::vector<model> group::getModels() {
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

// ---------------------
// Luzes
// ---------------------

void light::setPointLight(int i, float x, float y, float z){
    tipo = typeLight::point;
    id = i;
    posX = x;
    posY = y;
    posZ = z;
}

void light::setDirectionalLight(int i, float x, float y, float z){
    tipo = typeLight::directional;
    id = i;
    dirX = x;
    dirY = y;
    dirZ = z;
}

void light::setSpotlightLight(int i, float pX, float pY, float pZ, float dX, float dY, float dZ, float co){
    tipo = typeLight::spotlight;
    id = i;
    posX = pX;
    posY = pY;
    posZ = pZ;
    dirX = dX;
    dirY = dY;
    dirZ = dZ;
    cutoff = co;
}

typeLight light::getTipo(){
    return tipo;
}

int light::getID(){
    return id;
}

float light::getPosX(){
    return posX;
}

float light::getPosY(){
    return posY;
}

float light::getPosZ(){
    return posZ;
}

float light::getDirX(){
    return dirX;
}

float light::getDirY(){
    return dirY;
}

float light::getDirZ(){
    return dirZ;
}

float light::getCutoff(){
    return cutoff;
}