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

    struct cameraPolar {
        double distance;
        double alpha;
        double beta;
    };

    class figure {

    public:
        std::vector<point> pontos;
        void addPoint(float, float, float);
    };

    enum class transformation { none, translate, rotate, scale, color };

    class transform {
        float x;
        float y;
        float z;
        float ang;
        transformation trans;

    public:
        void setTransform();
        void setTransform(float, float, float, float, transformation);
        float getX();
        float getY();
        float getZ();
        float getAng();
        transformation getTrans();
    };

    class group {
        std::vector<figure> models;
        std::vector<transform> transformations;
        std::vector<group> groups;

    public:
        void addTransform(transform);
        void addFigure(figure);
        void addGroup(group);
        void deleteG();
        bool isEmptyG();
        std::vector<figure> getFiguras();
        std::vector<transform> getTransformations();
        std::vector<group> getFilhos();
    };

}