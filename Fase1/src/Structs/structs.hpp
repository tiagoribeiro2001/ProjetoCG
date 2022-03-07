#ifndef FASE1_STRUCTS_HPP
#define FASE1_STRUCTS_HPP

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

    class figure {

    public:
        std::vector<point> pontos;
        void addPoint(float, float, float);
    };

    std::string getPath();

}

#endif //FASE1_STRUCTS_HPP
