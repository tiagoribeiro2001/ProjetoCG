#include "../Structs/structs.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



using namespace structs;

namespace draw {

    void drawFigure(structs::figure);
    void drawReferencial();

}