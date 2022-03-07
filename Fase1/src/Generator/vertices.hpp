#ifndef FASE1_VERTICES_HPP
#define FASE1_VERTICES_HPP


#include "../Structs/structs.hpp"

using namespace structs;

namespace generate{

    figure createPlane(float, float);
    figure createBox(float, float, float, int);
    figure createSphere(float, int, int);
    figure createCone(float, float, int, int);
}


#endif //FASE1_VERTICES_HPP
