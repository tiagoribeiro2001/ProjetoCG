#include "drawFunctions.hpp"
#include "../tinyXML/tinyxml.h"

#include <iostream>
#include <iterator>
#include <map>

using namespace draw;
using namespace std;
using namespace structs;

cameraSettings cam = {0,0,0,0,0,0,0,0,0,0,0,0};
map<int, figure> figurasMap;
int ativarFig = 0; //Vai buscar a chave/identificador da figura para desenha-la após obter permissão


void changeSize(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;
    // compute window's aspect ratio
    float ratio = w * 1.0f / h;
    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load the identity matrix
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    // Set the perspective
    gluPerspective(cam.settings[9], ratio, cam.settings[10], cam.settings[11]);
    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}



void renderScene(void){
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set camera
    glLoadIdentity();
    gluLookAt(cam.settings[0], cam.settings[1], cam.settings[2],
              cam.settings[3], cam.settings[4], cam.settings[5],
              cam.settings[6], cam.settings[7], cam.settings[8]);


    drawReferencial();
    auto pos = figurasMap.find(ativarFig);
    if (pos == figurasMap.end()) {
        cout << "Não existem mais figuras." << endl;
        glutDestroyWindow(0);
    } else {
        figure value = pos->second;
        drawFigure(value);
    }

    // End of frame
    glutSwapBuffers();
}

int lerFicheiroXML(std::string xml) {
    TiXmlDocument fich;
    //Load do ficheiro XML com o nome que foi passado como argumento

    if (fich.LoadFile(xml.c_str())) {
        TiXmlElement* worldElement =  fich.RootElement();
        TiXmlElement* cameraElement = worldElement->FirstChildElement();
        TiXmlElement* cameraChild = cameraElement->FirstChildElement();
        int i = 0;

        for (; cameraChild!= NULL; cameraChild = cameraChild->NextSiblingElement()) {
            TiXmlAttribute * attribute = cameraChild->FirstAttribute();

            for (; attribute != NULL; attribute = attribute->Next(), i++) {
                cam.settings[i] = std::stof(attribute->Value());
                std::cout << cam.settings[i] << std::endl;
            }
        }

        TiXmlElement* groupElement = cameraElement->NextSiblingElement();
        std::cout << groupElement->Value() << std::endl;
        TiXmlElement* modelsElement = groupElement->FirstChildElement();
        std::cout << modelsElement->Value() << std::endl;
        TiXmlElement* modelsChild = modelsElement->FirstChildElement();

        int j = 0;
        for (; modelsChild!= NULL; modelsChild = modelsChild->NextSiblingElement()) {
            TiXmlAttribute * attributeName = modelsChild->FirstAttribute();
            string fileName = attributeName->Value();
            std::cout << fileName << std::endl;

            ifstream file;
            file.open(fileName);

            if (file.is_open()){
                figure f;
                string line;

                float x1, y1, z1 = 0.0f; //Inicializa as coordenadas de cada ponto

                //Lê linha a linha do ficheiro, não esquecendo que cada linha é um vértice/ponto
                while (getline(file, line)) {
                    float cood[3]; //guarda num array as coordenadas de cada ponto

                    std::string delimiter = " ";
                    size_t pos = 0;
                    std::string token;
                    int k = 0;
                    while ((pos = line.find(delimiter)) != std::string::npos) {
                        token = line.substr(0, pos);
                        cood[k] = std::stof(token); //converte para float e guarda a coordenada
                        k++;
                        line.erase(0, pos + delimiter.length());
                    }
                    x1=cood[0],y1=cood[1],z1=cood[2];
                    f.addPoint(x1,y1,z1);
                }
                file.close();
                std::cout << f.pontos.size() << std::endl;
                figurasMap.insert(pair<int, figure>(j, f));
                j++;
            }
            else {
                std::cout << "Can't open file:" + fileName << std::endl;
                return -1;
            }
        }
    }
    else{
        std::cout <<"File does not exist!\n" << std::endl;
        return -1;
    }
    return 0;
}

void nextFigureKey (unsigned char key, int x, int y){

    switch (key) {
        case 'd':
            if(ativarFig<(figurasMap.size()-1)){
                ativarFig++;
                renderScene();
            }
            break;
        case 'a':
            if(ativarFig>0){
                ativarFig--;
                renderScene();
            }
            break;
        default:
            break;
    }
    //renderScene(); para mudar de cor :)
}

int main(int argc, char** argv){
    if (argc <=1) {
        std::cout << "\nMissing arguments\n" << std::endl;
    }
    else if(argc > 2){
        std::cout << "\nToo many arguments\n" << std::endl;
    }
    else {
        std::cout << "\nReading .... ..... ....\n" << std::endl;
        if(lerFicheiroXML(argv[1])==0) {

            // put GLUT init here
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
            glutInitWindowPosition(100, 100);
            glutInitWindowSize(800, 800);
            glutCreateWindow("Projeto-CG");



            // put callback registry here
            glutDisplayFunc(renderScene);
            glutReshapeFunc(changeSize);

            glutKeyboardFunc(nextFigureKey);

            // some OpenGL settings
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

            // enter GLUT�s main cycle
            glutMainLoop();
        }
    }

    return 1;
}