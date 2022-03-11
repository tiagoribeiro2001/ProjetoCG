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

    class figure {

    public:
        std::vector<point> pontos;
        void addPoint(float, float, float);
    };
}
