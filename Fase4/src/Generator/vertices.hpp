#include "../Structs/structs.hpp"

using namespace structs;

namespace generate{

    figure createPlane(float, float);
    figure createBox(float, float);
    figure createSphere(float, int, int);
    figure createCone(float, float, int, int);
    figure createTorus(float, float, int, int);
    void getBezierNormalPoint(float, float, float**, float**, float**, float*);
    void calculateBezierPoint(float, float, float**, float**, float**, float*);
    figure createBezier(std::vector<point>, std::vector<int>, int);
}
