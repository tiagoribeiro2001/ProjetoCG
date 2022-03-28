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
    for (transform t : g.getTransformations()) {
        switch (t.getTrans()) {
            case transformation::translate:
                glTranslatef(t.getX(), t.getY(), t.getZ());
                break;
            case transformation::rotate:
                glRotatef(t.getAng(),t.getX(), t.getY(), t.getZ());
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
    for (figure f : g.getFiguras()) {
        drawFigure(f);
    }
    for (group gr : g.getFilhos()) {
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


    drawReferencial();

    drawFigures(grupo);

    // End of frame
    glutSwapBuffers();
}

group lerFicheiro3D(string fileName, group g) {
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        figure figura;
        string line;
        float x1, y1, z1 = 0.0f;

        while (getline(file, line)) {
            float cood[3];

            std::string delimiter = " ";
            size_t pos = 0;
            std::string token;
            int i = 0;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                cood[i] = std::stof(token);
                i++;
                line.erase(0, pos + delimiter.length());
            }
            x1=cood[0],y1=cood[1],z1=cood[2];
            figura.addPoint(x1,y1,z1);
        }
        g.addFigure(figura);
        file.close();
    }

    else{
        std::cout << "ERROR: Can't open .3d file:" + fileName << std::endl;
    }

    return g;
}

group parseGroupXML(TiXmlElement* gr, group g){
    float x, y, z, angle;

    //Anda por cada elemento filho do <group>
    for (TiXmlElement* elem = gr->FirstChildElement(); elem!=nullptr;elem = elem->NextSiblingElement()){
        //Caso o filho seja <transform>
        if(strcmp(elem->Value(),"transform")==0) {
            transform t{};
            TiXmlElement* transChild = elem->FirstChildElement();
            while (transChild) {
                if (strcmp(transChild->Value(), "translate") == 0) {
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, 0, transformation::translate);
                    g.addTransform(t);
                } else if (strcmp(transChild->Value(), "rotate") == 0) {
                    angle = atof(transChild->Attribute("angle"));
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, angle, transformation::rotate);
                    g.addTransform(t);
                } else if (strcmp(transChild->Value(), "scale") == 0) {
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, 0, transformation::scale);
                    g.addTransform(t);
                } else if (strcmp(transChild->Value(), "color") == 0) {
                    x = atof(transChild->Attribute("r"));
                    y = atof(transChild->Attribute("g"));
                    z = atof(transChild->Attribute("b"));

                    t.setTransform(x, y, z, 0, transformation::color);
                    g.addTransform(t);
                }
                transChild = transChild->NextSiblingElement();
            }
        }
        else if (strcmp(elem->Value(), "models") == 0) {
            TiXmlElement *model = elem->FirstChildElement("model");

            while (model) {
                const char *ficheiro = model->Attribute("file");

                //Abre o ficheiro .3d
                g = lerFicheiro3D(ficheiro, g);

                //next sibling
                model = model->NextSiblingElement("model");
            }
        }
        else if (strcmp(elem->Value(), "group") == 0){ //caso encontre uma tag de grupo dentro deste grupo
            group childGr;
            childGr = parseGroupXML(elem, childGr);
            g.addGroup(childGr);
        }
    }
    return g;
}

int lerFicheiroXML(std::string xml){
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
                if (i == 2) { //Já temos o x,y,z -> Convertemos para coordenadas polares e guardamos.
                    camPol.distance = getDistance(cam.settings[0], cam.settings[1], cam.settings[2]); //Obtemos a distancia da camara
                    camPol.beta = getBeta(cam.settings[1]);
                    camPol.alpha = getAlpha(cam.settings[0]);
                }
            }
        }

        // Lê os ficheiros a desenhar
        TiXmlElement* groupElement = cameraElement->NextSiblingElement();
        grupo = parseGroupXML(groupElement, grupo);
    }
    else{
        std::cout <<"File does not exist!\n" << std::endl;
        return -1;
    }
    return 0;
}

/*
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
}*/

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
            glutCreateWindow("Geometric Transforms  G07");

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