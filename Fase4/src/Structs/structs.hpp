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
        int startX, startY, tracking;
    };

    class figure{

    public:
        std::vector<point> pontos;
        void addPoint(float, float, float);
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

    class group {
        int trianglesCount = 0;
        std::vector<figure> models;
        std::vector<transform> transformations;
        std::vector<timedTransform> timedTransformations;
        std::vector<group> groups;


    public:
        void addTrianglesCount(int num);
        void addTransform(transform);
        void addTimedTransformation(timedTransform);
        void addFigure(figure);
        void addGroup(group);
        int getTrianglesCount();
        std::vector<figure> getModels();
        std::vector<transform> getTransformations();
        std::vector<timedTransform> getTimedTransformations();
        std::vector<group> getGroups();
    };

}

#endif