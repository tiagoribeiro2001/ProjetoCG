#include "drawFunctions.hpp"
#include "../tinyXML/tinyxml.h"

#include <iostream>
#include <map>
#include <cmath>

using namespace draw;
using namespace std;
using namespace structs;

cameraPolar camPol = {0,0,0};
cameraSettings cam = {0,0,0,0,0,0,0,0,0,0,0,0};
map<int, figure> figurasMap;
int ativarFig = 0; //Vai buscar a chave/identificador da figura para desenha-la após obter permissão

double getDistance (int x, int y, int z) {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double getBeta(int y) {
    return asin(y/camPol.distance);
}

double getAlpha(int x) {
    return asin((x/camPol.distance) * cos(camPol.beta));
}

double polarX (cameraPolar post) {
    return post.distance * cos(post.beta) * sin(post.alpha);
}
double polarY(cameraPolar post) {
    return post.distance * sin(post.beta);
}

double polarZ(cameraPolar post) {
    return post.distance * cos(post.beta) * cos(post.alpha);
}

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
    gluLookAt(polarX(camPol), polarY(camPol), polarZ(camPol),
              cam.settings[3], cam.settings[4], cam.settings[5],
              cam.settings[6], cam.settings[7], cam.settings[8]);


    drawReferencial();
    auto pos = figurasMap.find(ativarFig);
    if (pos == figurasMap.end()) {
        cout << "ERROR: No more figures." << endl;
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

        // Lê as definições da camera
        TiXmlElement* worldElement =  fich.RootElement();
        TiXmlElement* cameraElement = worldElement->FirstChildElement();
        TiXmlElement* cameraChild = cameraElement->FirstChildElement();
        int i = 0;

        for (; cameraChild!= NULL; cameraChild = cameraChild->NextSiblingElement()) {
            TiXmlAttribute * attribute = cameraChild->FirstAttribute();

            for (; attribute != NULL; attribute = attribute->Next(), i++) {
                cam.settings[i] = std::stof(attribute->Value());
                if (i == 2) { //Já temos o x,y,z -> Convertemos para coordenadas polares e guardamos.
                    camPol.distance = getDistance(cam.settings[0], cam.settings[1], cam.settings[2]); //Obtemos a distancia da camara
                    camPol.beta = getBeta(cam.settings[1]);
                    camPol.alpha = getAlpha(cam.settings[0]);
                }
            }
        }

        // Lê os ficheiros a desenhar
        TiXmlElement* groupElement = cameraElement->NextSiblingElement();
        TiXmlElement* modelsElement = groupElement->FirstChildElement();
        TiXmlElement* modelsChild = modelsElement->FirstChildElement();

        int j = 0;
        for (; modelsChild!= NULL; modelsChild = modelsChild->NextSiblingElement()) {
            TiXmlAttribute * attributeName = modelsChild->FirstAttribute();
            string fileName = attributeName->Value();

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
                figurasMap.insert(pair<int, figure>(j, f));
                j++;
            }
            else {
                std::cout << "ERROR: Can't open .3d file:" + fileName << std::endl;
                return -1;
            }
        }
    }
    else{
        std::cout <<"ERROR: XML file does not exist.\n" << std::endl;
        return -1;
    }
    return 0;
}

void keyboardFunc (unsigned char key, int x, int y){

    switch (key) {
        case 'd':
            if(ativarFig < (figurasMap.size() - 1)){
                ativarFig++;
                glutPostRedisplay();
            }
            break;
        case 'a':
            if(ativarFig > 0){
                ativarFig--;
                glutPostRedisplay();
            }
            break;
        case '+':
            camPol.distance -= 1;
            glutPostRedisplay();
            break;
        case '-':
            camPol.distance += 1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
    //renderScene(); para mudar de cor :)
}

void processSpecialKeys(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_UP:
            camPol.beta += M_PI/16;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            camPol.beta -= M_PI/16;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            camPol.alpha -= M_PI/16;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            camPol.alpha += M_PI/16;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv){
    if (argc <=1) {
        std::cout << "\nERROR: Missing arguments.\n" << std::endl;
    }
    else if(argc > 2){
        std::cout << "\nERROR: Too many arguments\n" << std::endl;
    }
    else {
        std::cout << "\nReading...\n" << std::endl;
        if(lerFicheiroXML(argv[1])==0) {

            // put GLUT init here
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
            glutInitWindowPosition(100, 100);
            glutInitWindowSize(800, 800);
            glutCreateWindow("Graphical primitives G07");

            // put callback registry here
            glutDisplayFunc(renderScene);
            glutReshapeFunc(changeSize);

            glutKeyboardFunc(keyboardFunc);
            glutSpecialFunc(processSpecialKeys);

            // some OpenGL settings
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

            // enter GLUT�s main cycle
            glutMainLoop();
        }
    }

    return 1;
}