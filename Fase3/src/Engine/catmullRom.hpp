#ifndef FASE3_CATMULLROM_HPP
#define FASE3_CATMULLROM_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../Structs/structs.hpp"
#include "../Matrices/matrices.hpp"

namespace catmull{
    void getCatmullRomPoint(float, structs::point[], float*, float*);
    void getGlobalCatmullRomPoint(structs::timedTransform*, float , float* , float*);
    void calculateCurvePoints(structs::timedTransform*);
}

#endif //FASE3_CATMULLROM_HPP
