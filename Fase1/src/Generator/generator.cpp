#include "../tinyXML/tinyxml.h"
#include "calculaVertices.hpp"

using namespace std;
using namespace generate;

int createFileType (vector<point> vertices, string name){

    fstream file;

    // in out(write) mode
    // ios::out Open for output operations.
    file.open(getPath() + name, ios::out);
    for(point p : vertices){
        file << p.x << " ";
        file << p.y << " ";
        file << p.z << " ";
        file << "\n";
    }

    if(!file){
        cout<<"\n       Error in creating file!!!\n";
        return -1;
    }
    cout<<"File created successfully.";
    file.close();
    return 0;
}

int main(int argc, char* argv[]) {
    figure f;

    if(argc<=1) cout << "Missing Arguments" << endl;
    else {

        //Gerar os vértices para o desenho do plano e transcrever para o ficheiro .3d
        if ((strcmp(argv[1], "Plane") == 0) && (argc == 5)) {

            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);

            f = createPlane(units, divs);

            if (createFileType(f.pontos, argv[4]) == 0) {
                std::cout << "Done\n" << std::endl;
            }

        }

            //Gerar os vértices para o desenho do cubo/caixa e transcrever para o ficheiro .3d
        else if ((strcmp(argv[1], "Box") == 0) && (argc == 5)) {
            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);
            float z = std::stof(argv[4]);

            f = createBox(units, divs);

            if (createFileType(f.pontos, argv[4]) == 0) {
                std::cout << "Done\n" << std::endl;
            }
        }

            //Gerar os vértices para o desenho da esfera e transcrever para o ficheiro .3d
        else if ((strcmp(argv[1], "Sphere") == 0) && (argc == 6)) {
            float radius = std::stof(argv[2]);
            stringstream aux(argv[3]);
            int slices = 0;
            aux >> slices;
            stringstream aux2(argv[4]);
            int stacks = 0;
            aux2 >> stacks;

            f = createSphere(radius, stacks, slices);

            if (createFileType(f.pontos, argv[5]) == 0) {
                std::cout << "Done\n" << std::endl;
            }

        }

            //Gerar os vértices para o desenho do cone e transcrever para o ficheiro .3d
        else if ((strcmp(argv[1], "Cone") == 0) && (argc == 7)) {
            float radius = std::stof(argv[2]);
            float height = std::stof(argv[3]);
            stringstream aux(argv[4]);
            int slices = 0;
            aux >> slices;
            stringstream aux2(argv[5]);
            int stacks = 0;
            aux2 >> stacks;

            f = createCone(radius, height, stacks, slices);

            if (createFileType(f.pontos, argv[6]) == 0) {
                std::cout << "Done\n" << std::endl;
            }
        }
        else {
            std::cout << "\nMissing arguments\n" << std::endl;
        }
    }
}

