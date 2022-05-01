#include "../Structs/structs.hpp"

using namespace structs;

namespace generate{

    figure createPlane(float, float);
    figure createBox(float, float);
    figure createSphere(float, int, int);
    figure createCone(float, float, int, int);
    figure createTorus(float, float, int, int);
    void calculateBezierPoint(float u, float v, float** matrixX, float** matrixY, float** matrixZ, float* pos);
    figure createBezier(std::vector<point> points, std::vector<int> indices, int tesselation);
}
