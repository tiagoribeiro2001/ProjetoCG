#include "drawFunctions.hpp"
#include "../tinyXML/tinyxml.h"

#include <iostream>
#include <map>
#include <list>
#include <cmath>

using namespace draw;
using namespace std;
using namespace structs;

group grupo;

cameraPolar camPol = {0,0,0};
cameraSettings cam = {0,0,0,0,0,0,0,0,0,0,0,0};

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

void drawFigures(group g) {
    glPushMatrix();

    // Aplica todas a transformações
    for (transform t : g.getTransformations()) {
        switch (t.getTrans()) {
            case transformation::rotate:
                glRotatef(t.getAng(),t.getX(), t.getY(), t.getZ());
                break;
            case transformation::translate:
                glTranslatef(t.getX(), t.getY(), t.getZ());
                break;
            case transformation::scale:
                glScalef(t.getX(), t.getY(), t.getZ());
                break;
            case transformation::color:
                glColor3f(t.getX(), t.getY(), t.getZ());
                break;
            default:
                break;
        }
    }

    // Desenha todos os models
    for (figure f : g.getModels()) {
        drawFigure(f);
    }

    // Passa para o grupo filho (recursividade), sendo aplicadas as transformações aplicadas a este (PopMatrix é feito no final)
    for (group gr : g.getGroups()) {
        drawFigures(gr);
    }
    glPopMatrix();
}

void renderScene(void){
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set camera
    glLoadIdentity();
    gluLookAt(polarX(camPol), polarY(camPol), polarZ(camPol),
              cam.settings[3], cam.settings[4], cam.settings[5],
              cam.settings[6], cam.settings[7], cam.settings[8]);


    // drawReferencial();

    drawFigures(grupo);

    // End of frame
    glutSwapBuffers();
}

// Função que lâ um ficheiro .3d
group lerFich3D(string fileName, group g) {
    ifstream fich;
    fich.open(fileName);
    if (fich.is_open()) {

        figure figura;
        string line;

        while (getline(fich, line)) {
            float coord[3];

            size_t pos = 0;
            string delimitador = " ";
            string token;
            int i = 0;
            while ((pos = line.find(delimitador)) != std::string::npos) {
                token = line.substr(0, pos);
                coord[i] = std::stof(token);
                i++;
                line.erase(0, pos + delimitador.length());
            }
            figura.addPoint(coord[0], coord[1], coord[2]);
        }
        g.addFigure(figura);
        fich.close();
    }

    else{
        printf("ERROR: Can't open .3d file: %s", fileName.c_str());
    }

    return g;
}

// Função que lâ os parâmetros da camera no ficheiro XML
void lerCamera(TiXmlElement* camera){
    TiXmlElement* cameraChild = camera->FirstChildElement();
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
}

// Função que lê o grupo principal (e todos os seus filhos) do ficheiro XML
group lerGroup(TiXmlElement* gr, group g){
    float x, y, z, angle;
    TiXmlElement* elem = gr->FirstChildElement();

    while (elem){

        // Primeiramente lê todas as transformações
        if(strcmp(elem->Value(),"transform")==0) {
            transform t{};
            TiXmlElement* transChild = elem->FirstChildElement();
            while (transChild) {
                if (strcmp(transChild->Value(), "rotate") == 0) {
                    angle = atof(transChild->Attribute("angle"));
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, angle, transformation::rotate);
                    g.addTransform(t);
                }
                else if (strcmp(transChild->Value(), "translate") == 0) {
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, 0, transformation::translate);
                    g.addTransform(t);
                }
                else if (strcmp(transChild->Value(), "scale") == 0) {
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, 0, transformation::scale);
                    g.addTransform(t);
                }
                else if (strcmp(transChild->Value(), "color") == 0) {
                    x = atof(transChild->Attribute("r"));
                    y = atof(transChild->Attribute("g"));
                    z = atof(transChild->Attribute("b"));

                    t.setTransform(x, y, z, 0, transformation::color);
                    g.addTransform(t);
                }

                transChild = transChild->NextSiblingElement();
            }
        }

        // Depois lê todos os ficheiros (models)
        else if (strcmp(elem->Value(), "models") == 0) {
            TiXmlElement *model = elem->FirstChildElement("model");

            // Lê todos os ficheiros .3d
            while (model) {
                const char *ficheiro = model->Attribute("file");
                g = lerFich3D(ficheiro, g);
                model = model->NextSiblingElement("model");
            }
        }

        // No fim lê todos os grupos filhos
        else if (strcmp(elem->Value(), "group") == 0){
            group childGr;
            childGr = lerGroup(elem, childGr);
            g.addGroup(childGr);
        }

        elem = elem->NextSiblingElement();
    }
    return g;
}

// Função que lê o ficheiro XML com o nome que foi passado como argumento
int lerFicheiroXML(std::string xml){
    TiXmlDocument fich;
    if (fich.LoadFile(xml.c_str())) {

        // Ler as definições da camera
        TiXmlElement* worldElement =  fich.RootElement();
        TiXmlElement* cameraElement = worldElement->FirstChildElement();
        lerCamera(cameraElement);

        // Ler o group principal
        TiXmlElement* groupElement = cameraElement->NextSiblingElement();
        grupo = lerGroup(groupElement, grupo);
    }
    else{
        printf("ERROR: File does not exist!\n");
        return -1;
    }
    return 0;
}

void keyboardFunc (unsigned char key, int x, int y){
    switch (key) {
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
        printf("ERROR: Missing arguments.\n");
    }
    else if(argc > 2){
        printf("ERROR: Too many arguments\n");
    }
    else {
        printf("Reading...\n");
        if(lerFicheiroXML(argv[1])==0) {

            // put GLUT init here
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
            glutInitWindowPosition(100, 100);
            glutInitWindowSize(800, 800);
            glutCreateWindow("Geometric Transforms G07");

            // put callback registry here
            glutDisplayFunc(renderScene);
            glutReshapeFunc(changeSize);

            glutKeyboardFunc(keyboardFunc);
            glutSpecialFunc(processSpecialKeys);

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