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
        printf("\nERROR: Couldn't create .3d file.\n");
        return -1;
    }
    printf(".3d file created successfully.\n");
    file.close();
    return 0;
}

// Funcao que le o ficheiro patch que contem os dados da figura a ser feita com superficies de bezier
figure readBezierFile(string fileName, int tesselation) {
    ifstream fich;
    fich.open(fileName);
    figure fig;
    if (fich.is_open()) {
        string line;
        int numPatches = 0;
        int lineNum = 0;

        std::vector<point> points;
        vector<int> indices;

        while (getline(fich, line)) {

            // Ler número de patches
            if (lineNum == 0) {
                numPatches = atoi(line.c_str());
            }

            // Ler indices dos pontos de controlo
            if (lineNum >= 1 && lineNum <= numPatches) {
                string token;
                istringstream tokenizer(line);
                for (int i = 0; i < 15; i++) {
                    getline(tokenizer, token, ',');
                    indices.push_back(stof(token));
                }
                getline(tokenizer, token);
                indices.push_back(stof(token));
            }

            // Ler pontos de controlo
            if (lineNum > numPatches + 1) {
                string token;
                string tokens[3];
                istringstream tokenizer(line);

                getline(tokenizer, tokens[0], ',');
                getline(tokenizer, tokens[1], ',');
                getline(tokenizer, tokens[2]);

                point ponto = {stof(tokens[0]), stof(tokens[1]), stof(tokens[2])};
                points.push_back(ponto);

            }
            lineNum++;
        }

        fig = createBezier(points, indices, tesselation);

    }
    else {
        printf("ERROR: Can't open .patch file: %s", fileName.c_str());
    }

    fich.close();

    return fig;
}

int main(int argc, char* argv[]) {
    figure f;

    if(argc<=1) {
        printf("\nERROR: Missing arguments.\n");
    }
    else {

        // Receber os parâmetros e gerar o ficheiro 3d do plane
        if ((strcmp(argv[1], "plane") == 0) && (argc == 5)) {

            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);

            f = createPlane(units, divs);

            if (createFile(f.pontos, argv[4]) == 0) {
                printf("Done.\n");
            }

        }

        // Receber os parâmetros e gerar o ficheiro 3d da box
        else if ((strcmp(argv[1], "box") == 0) && (argc == 5)) {
            float units = std::stof(argv[2]);
            float divs = std::stof(argv[3]);

            f = createBox(units, divs);

            if (createFile(f.pontos, argv[4]) == 0) {
                printf("Done.\n");
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
                printf("Done.\n");
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
                printf("Done.\n");
            }
        }

        // Receber os parâmetros e gerar o ficheiro 3d da torus
        else if ((strcmp(argv[1], "torus") == 0) && (argc == 7)) {
            float radiusI = std::stof(argv[2]);
            float radiusE = std::stof(argv[3]);
            stringstream aux(argv[4]);
            int slices = 0;
            aux >> slices;
            stringstream aux2(argv[5]);
            int rings = 0;
            aux2 >> rings;

            f = createTorus(radiusI, radiusE, slices, rings);

            if (createFile(f.pontos, argv[6]) == 0) {
                printf("Done.\n");
            }
        }

        // Receber os parâmetros e gerar o ficheiro 3d a partir de superficies de bezier
        else if ((strcmp(argv[1], "bezier") == 0) && (argc == 5)) {
            char* fileBezier = argv[2];
            stringstream aux(argv[3]);
            int tesselation = 0;
            aux >> tesselation;


            f = readBezierFile(fileBezier, tesselation);
            if (!f.pontos.empty()) {
                if (createFile(f.pontos, argv[4]) == 0) {
                    printf("Done\n");
                }
            }

        }

        else {
            printf("\nERROR: Missing arguments.\n");
        }
    }
}

