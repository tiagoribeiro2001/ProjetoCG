#ifndef FASE3_DRAW_FUNCTIONS_HPP
#define FASE3_DRAW_FUNCTIONS_HPP


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../Structs/structs.hpp"

using namespace structs;

namespace draw {

    void drawFigure(structs::figure);
    void drawReferencial();

}

#endif