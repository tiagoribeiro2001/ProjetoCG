#ifndef FASE3_STRUCTS_HPP
#define FASE3_STRUCTS_HPP

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace structs{
    struct point {
        float x;
        float y;
        float z;
    };

    struct cameraSettings{
        float settings[12];
    };

    struct cameraPolar{
        double distance;
        double alpha;
        double beta;
    };

    class figure{

    public:
        std::vector<point> pontos;
        std::vector<point> normais;
        std::vector<point> coordTex;
        void addPoint(float, float, float);
        void addNormais(float, float, float);
        void addCoordTex(float, float, float);
    };

    enum class transformation {
        rotate,
        translate,
        scale,
        color};

    class transform{
        float x;
        float y;
        float z;
        float ang;
        transformation trans;

    public:
        void setTransform(float, float, float, float, transformation);
        float getX();
        float getY();
        float getZ();
        float getAng();
        transformation getTrans();
    };

    enum class timedTransformation {
        rotate,
        translate
    };

    class timedTransform {
        int time;
        float x;
        float y;
        float z;
        bool align;
        timedTransformation trans;
        std::vector<point> points;
        std::vector<point> curvePoints;

    public:
        void setTimedTranslate(int, bool, std::vector<point>);
        void setTimedRotate(int, float, float, float);
        int getTime();
        float getX();
        float getY();
        float getZ();
        bool isAligned();
        std::vector<point> getPoints();
        std::vector<point> getCurvePoints();
        timedTransformation getTrans();
        void addCurvePoints(point);
        // void setCurvePoints();
    };

    class model {
        std::vector<float> vertices;
        std::vector<float> normais;
        std::vector<float> coordTex;
        std::string nameTex = "";
        unsigned int texID;
        unsigned int texCoords;

    public:
        unsigned int verticesVBO;
        unsigned int indicesVBO;
        unsigned int normaisVBO;
        float diffuse[4] = {0.8, 0.8, 0.8, 1};
        float ambient[4] = {0.2, 0.2, 0.2, 1};
        float specular[4] = {0, 0, 0, 1};
        float emissive[4] = {0, 0, 0, 1};
        float shininess = 0;

    public:
        void addVerticeModel(float);
        void addNormalModel(float);
        void addCoordTexModel(float);
        void setNameTex(std::string);
        std::string getNameTex();
        int sizeCoordTex();
        std::vector<float> getCoordTexModel();
        std::vector<float> getVerticesModel();
        std::vector<float> getNormaisModel();
        unsigned int getTexID();
        unsigned int getTexCoords();
        void setTexID(unsigned int);
        void setTexCoords(unsigned int);
    };

    class group {
        int trianglesCount = 0;
        std::vector<model> models;
        std::vector<transform> transformations;
        std::vector<timedTransform> timedTransformations;
        std::vector<group> groups;

    public:
        void addTrianglesCount(int num);
        void addTransform(transform);
        void addTimedTransformation(timedTransform);
        void addModel(model);
        void addGroup(group);
        int getTrianglesCount();
        std::vector<model> getModels();
        std::vector<transform> getTransformations();
        std::vector<timedTransform> getTimedTransformations();
        std::vector<group> getGroups();
    };

    enum class typeLight {
        point,
        directional,
        spotlight
    };

    class light{
        typeLight tipo;
        int id;
        float posX;
        float posY;
        float posZ;
        float dirX;
        float dirY;
        float dirZ;
        float cutoff;

    public:
        void setPointLight(int, float, float, float);
        void setDirectionalLight(int, float, float, float);
        void setSpotlightLight(int, float, float, float, float, float, float, float);
        typeLight getTipo();
        int getID();
        float getPosX();
        float getPosY();
        float getPosZ();
        float getDirX();
        float getDirY();
        float getDirZ();
        float getCutoff();
    };

}

#endif