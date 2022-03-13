#include "../tinyXML/tinyxml.h"
#include "vertices.hpp"

using namespace std;
using namespace generate;

int createFile (vector<point> vertices, string name){

    ofstream file;

    file.open(name);
    for(point p : vertices){
        file << p.x << " ";
        file << p.y << " ";
        file << p.z << " ";
        file << "\n";
    }

    if(!file){
        cout<<"\nERROR: Couldn't create .3d file.\n";
        return -1;
    }
    cout<<".3d file created successfully.\n";
    file.close();
    return 0;
}

int main(int argc, char* argv[]) {
    figure f;

    if(argc<=1) cout << "\nERROR: Missing arguments.\n" << endl;
    else {

        // Receber os parâmetros e gerar o ficheiro 3d do plane
        if ((strcmp(argv[1], "plane") == 0) && (argc == 5)) {

            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);

            f = createPlane(units, divs);

            if (createFile(f.pontos, argv[4]) == 0) {
                std::cout << "Done.\n" << std::endl;
            }

        }

        // Receber os parâmetros e gerar o ficheiro 3d da box
        else if ((strcmp(argv[1], "box") == 0) && (argc == 5)) {
            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);

            f = createBox(units, divs);

            if (createFile(f.pontos, argv[4]) == 0) {
                std::cout << "Done.\n" << std::endl;
            }
        }

        // Receber os parâmetros e gerar o ficheiro 3d da sphere
        else if ((strcmp(argv[1], "sphere") == 0) && (argc == 6)) {
            float radius = std::stof(argv[2]);
            stringstream aux(argv[3]);
            int slices = 0;
            aux >> slices;
            stringstream aux2(argv[4]);
            int stacks = 0;
            aux2 >> stacks;

            f = createSphere(radius, stacks, slices);

            if (createFile(f.pontos, argv[5]) == 0) {
                std::cout << "Done.\n" << std::endl;
            }

        }

            // Receber os parâmetros e gerar o ficheiro 3d do cone
        else if ((strcmp(argv[1], "cone") == 0) && (argc == 7)) {
            float radius = std::stof(argv[2]);
            float height = std::stof(argv[3]);
            stringstream aux(argv[4]);
            int slices = 0;
            aux >> slices;
            stringstream aux2(argv[5]);
            int stacks = 0;
            aux2 >> stacks;

            f = createCone(radius, height, slices, stacks);

            if (createFile(f.pontos, argv[6]) == 0) {
                std::cout << "Done.\n" << std::endl;
            }
        }
        else {
            std::cout << "\nERROR: Missing arguments.\n" << std::endl;
        }
    }
}

