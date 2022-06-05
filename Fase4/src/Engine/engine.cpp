#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <IL/il.h>
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "drawFunctions.hpp"
#include "../tinyXML/tinyxml.h"
#include "../Matrices/matrices.hpp"
#include "catmullRom.hpp"

#include <iostream>
#include <map>
#include <list>
#include <cmath>
#include <vector>

using namespace draw;
using namespace std;
using namespace structs;

std::vector<light> luzes;
int idLuz = 0;

group grupo;

bool wireframe = false;
bool orbitas = false;

float aux_y[3] = {0,1,0};

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

    for (timedTransform tt : g.getTimedTransformations()) {
        switch (tt.getTrans()) {
            case timedTransformation::rotate: {
                auto tempo = (float) glutGet(GLUT_ELAPSED_TIME);
                float angle = ((tempo / 1000) * 360) / (float)tt.getTime();
                glRotatef(angle, tt.getX(), tt.getY(), tt.getZ());
                break;
            }
            case timedTransformation::translate: {
                std::vector<structs::point> pontos = tt.getCurvePoints();

                // Desenhar a curva de CatmullRom
                if (orbitas) {
                    glPushMatrix();
                    draw::drawCatmullRomCurve(tt);
                    glPopMatrix();
                }

                float pos[3] = { 0.0, 0.0, 0.0 };
                float deriv[3] = { 0.0, 0.0, 0.0 };

                float timeT = ((float) glutGet(GLUT_ELAPSED_TIME) / 1000) / (float)(tt.getTime());
                catmull::getGlobalCatmullRomPoint(&tt, timeT, (float*)pos, (float*)deriv);

                glTranslatef(pos[0], pos[1], pos[2]);

                if (tt.isAligned()) {
                    float m[4][4];
                    float x[3], z[3];

                    matrices::cross(deriv, aux_y, z);
                    matrices::cross(z, deriv, aux_y);
                    matrices::normalize(deriv);
                    matrices::normalize(aux_y);
                    matrices::normalize(z);
                    matrices::buildRotMatrix(deriv, aux_y, z, *m);
                    glMultMatrixf(*m);
                }

                break;
            }
            default:
                break;
        }
    }

    for(model m : g.getModels()){

        glPushAttrib(GL_LIGHTING_BIT);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, m.diffuse);
        glMaterialfv(GL_FRONT, GL_AMBIENT, m.ambient);
        glMaterialfv(GL_FRONT, GL_SPECULAR, m.specular);
        glMaterialf(GL_FRONT, GL_SHININESS, m.shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, m.emissive);

        glBindBuffer(GL_ARRAY_BUFFER, m.verticesVBO);
        glVertexPointer(3, GL_FLOAT, 0, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.indicesVBO);

        glBindBuffer(GL_ARRAY_BUFFER, m.normaisVBO);
        glNormalPointer(GL_FLOAT, 0, 0);

        if (strcmp(m.getNameTex().c_str(), "") != 0) {

            glBindBuffer(GL_ARRAY_BUFFER, m.getTexCoords());
            glTexCoordPointer(2, GL_FLOAT, 0, 0);

            glBindTexture(GL_TEXTURE_2D, m.getTexID());
        }
        else {
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisable(GL_TEXTURE_2D);
        }

        glDrawElements(GL_TRIANGLES, m.getVerticesModel().size()/3, GL_UNSIGNED_INT,0);

        glBindTexture(GL_TEXTURE_2D, 0);

        glPopAttrib();
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



    for(light luz : luzes){
        glEnable(GL_LIGHT0 + luz.getID());
        float white[4] = {1, 1, 1, 1};
        float dark[4] = {0.1, 0.1, 0.1, 1};
        glLightfv(GL_LIGHT0 + luz.getID(), GL_DIFFUSE, white);
        glLightfv(GL_LIGHT0 + luz.getID(), GL_AMBIENT, dark);
        glLightfv(GL_LIGHT0 + luz.getID(), GL_SPECULAR, white);

        if (luz.getTipo() == typeLight::point){
            float posicao[4] = {luz.getPosX(), luz.getPosY(), luz.getPosZ(), 1};
            glLightfv(GL_LIGHT0 + luz.getID(), GL_POSITION, posicao);
        }

        else if (luz.getTipo() == typeLight::directional){
            float direcao[4] = {luz.getDirX(), luz.getDirY(), luz.getDirZ(), 0};
            glLightfv(GL_LIGHT0 + luz.getID(), GL_POSITION, direcao);
        }

        else if (luz.getTipo() == typeLight::spotlight){
            float pos[4] = {luz.getPosX(), luz.getPosY(), luz.getPosZ(), 1};
            float dir[4] = {luz.getDirX(), luz.getDirY(), luz.getDirZ(), 0};
            float cutoff = luz.getCutoff();
            glLightfv(GL_LIGHT0 + luz.getID(), GL_POSITION, pos);
            glLightfv(GL_LIGHT0 + luz.getID(), GL_SPOT_DIRECTION, dir);
            glLightf(GL_LIGHT0 + luz.getID(), GL_SPOT_CUTOFF, cutoff);
            glLightf(GL_LIGHT0 + luz.getID(), GL_SPOT_EXPONENT, 0.0);
        }
    }

    // drawReferencial();

    drawFigures(grupo);

    // End of frame
    glutSwapBuffers();
}

void loadTexture(model* modelo){
    unsigned int t,tw,th;
    unsigned char *texData;
    unsigned int texID, texCoords;

    // Colocar a origem da textura no canto inferior esquerdo
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

    // Carregar a textura para memória
    ilGenImages(1, &t);
    ilBindImage(t);
    ilLoadImage((ILstring) modelo->getNameTex().c_str());
    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);

    // Assegurar que a textura se encontra em RGBA (Red, Green, Blue, Alpha) com um byte (0 - 255) por componente
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    texData = ilGetData();

    // Gerar a textura para a placa gráfica
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Upload dos dados de imagem
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Store texture in GPU
    glGenBuffers(1, &texCoords);
    glBindBuffer(GL_ARRAY_BUFFER, texCoords);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * modelo->sizeCoordTex(), modelo->getCoordTexModel().data(), GL_STATIC_DRAW);

    modelo->setTexID(texID);
    modelo->setTexCoords(texCoords);
}

// Função que lâ um ficheiro .3d
void lerFich3D(string fileName, model* modelo) {
    ifstream fich;
    fich.open(fileName);
    if (fich.is_open()) {

        figure figura;
        string line;
        getline(fich, line);
        int numPontos = atoi(line.c_str());

        for (int i = 0; i < numPontos; i++) {
            getline(fich, line);
            float coord[3];

            size_t pos = 0;
            string delimitador = " ";
            string token;
            int j = 0;
            while ((pos = line.find(delimitador)) != std::string::npos) {
                token = line.substr(0, pos);
                coord[j] = std::stof(token);
                j++;
                line.erase(0, pos + delimitador.length());
            }
            modelo->addVerticeModel(coord[0]);
            modelo->addVerticeModel(coord[1]);
            modelo->addVerticeModel(coord[2]);
        }

        for (int i = 0; i < numPontos; i++) {
            getline(fich, line);
            float coord[3];

            size_t pos = 0;
            string delimitador = " ";
            string token;
            int j = 0;
            while ((pos = line.find(delimitador)) != std::string::npos) {
                token = line.substr(0, pos);
                coord[j] = std::stof(token);
                j++;
                line.erase(0, pos + delimitador.length());
            }
            modelo->addNormalModel(coord[0]);
            modelo->addNormalModel(coord[1]);
            modelo->addNormalModel(coord[2]);
        }

        for (int i = 0; i < numPontos; i++) {
            getline(fich, line);
            float coord[2];

            size_t pos = 0;
            string delimitador = " ";
            string token;
            int j = 0;
            while ((pos = line.find(delimitador)) != std::string::npos) {
                token = line.substr(0, pos);
                coord[j] = std::stof(token);
                j++;
                line.erase(0, pos + delimitador.length());
            }
            modelo->addCoordTexModel(coord[0]);
            modelo->addCoordTexModel(coord[1]);
        }
        fich.close();
    }

    else{
        printf("ERROR: Can't open .3d file: %s", fileName.c_str());
    }
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

void lerLights(TiXmlElement* lights){
    TiXmlElement *light = lights->FirstChildElement("light");

    while (light) {
        structs::light luz{};
        if (strcmp(light->Attribute("type"), "point") == 0){
            float posX = atof(light->Attribute("posx"));
            float posY = atof(light->Attribute("posy"));
            float posZ = atof(light->Attribute("posz"));
            luz.setPointLight(idLuz, posX, posY, posZ);
        }
        else if (strcmp(light->Attribute("type"), "directional") == 0){
            float dirX = atof(light->Attribute("dirx"));
            float dirY = atof(light->Attribute("diry"));
            float dirZ = atof(light->Attribute("dirz"));
            luz.setDirectionalLight(idLuz, dirX, dirY, dirZ);
        }
        else if (strcmp(light->Attribute("type"), "spot") == 0){
            float posX = atof(light->Attribute("posx"));
            float posY = atof(light->Attribute("posy"));
            float posZ = atof(light->Attribute("posz"));
            float dirX = atof(light->Attribute("dirx"));
            float dirY = atof(light->Attribute("diry"));
            float dirZ = atof(light->Attribute("dirz"));
            float cutoff = atof(light->Attribute("cutoff"));
            luz.setSpotlightLight(idLuz, posX, posY, posZ, dirX, dirY, dirZ, cutoff);
        }
        luzes.push_back(luz);
        idLuz++;

        light = light->NextSiblingElement("light");
    }
}

// Função que lê o grupo principal (e todos os seus filhos) do ficheiro XML
group lerGroup(TiXmlElement* gr, group g){
    float x, y, z, angle;
    int time;
    bool align;
    TiXmlElement* elem = gr->FirstChildElement();

    while (elem){
        // Primeiramente lê todas as transformações
        if(strcmp(elem->Value(),"transform")==0) {
            transform t{};
            timedTransform tt{};
            TiXmlElement* transChild = elem->FirstChildElement();
            while (transChild) {
                if (strcmp(transChild->Value(), "rotate") == 0) {
                    if (transChild->Attribute("time")) {
                        time = atoi(transChild->Attribute("time"));
                        x = atof(transChild->Attribute("x"));
                        y = atof(transChild->Attribute("y"));
                        z = atof(transChild->Attribute("z"));

                        tt.setTimedRotate(time, x, y, z);
                        g.addTimedTransformation(tt);
                    }
                    else {
                        angle = atof(transChild->Attribute("angle"));
                        x = atof(transChild->Attribute("x"));
                        y = atof(transChild->Attribute("y"));
                        z = atof(transChild->Attribute("z"));

                        t.setTransform(x, y, z, angle, transformation::rotate);
                        g.addTransform(t);
                    }
                }
                else if (strcmp(transChild->Value(), "translate") == 0) {
                    if (transChild->Attribute("time")) {
                        time = atoi(transChild->Attribute("time"));
                        align = !strcmp((transChild->Attribute("align")), "true");
                        TiXmlElement *point = transChild->FirstChildElement("point");
                        std::vector<structs::point> pontos;
                        while (point) {
                            structs::point p;
                            p.x = atof(point->Attribute("x"));
                            p.y = atof(point->Attribute("y"));
                            p.z = atof(point->Attribute("z"));
                            pontos.push_back(p);
                            //next sibling
                            point = point->NextSiblingElement("point");
                        }
                        tt.setTimedTranslate(time, align, pontos);

                        catmull::calculateCurvePoints(&tt);

                        g.addTimedTransformation(tt);
                    }
                    else {
                    x = atof(transChild->Attribute("x"));
                    y = atof(transChild->Attribute("y"));
                    z = atof(transChild->Attribute("z"));

                    t.setTransform(x, y, z, 0, transformation::translate);
                    g.addTransform(t);
                    }
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

                structs::model modelo{};
                // Lê o nome do ficheiro 3d
                const char *ficheiro = model->Attribute("file");
                lerFich3D(ficheiro, &modelo);

                // Lê o campo da textura
                TiXmlElement *texture = model->FirstChildElement("texture");
                if (texture != nullptr) {
                    const char *ficheiroTex = texture->Attribute("file");
                    modelo.setNameTex(ficheiroTex);
                }

                // Lê o campo da color
                TiXmlElement *color = model->FirstChildElement("color");
                TiXmlElement *colorChild = color == nullptr ? nullptr : color->FirstChildElement();
                while(colorChild){
                    if(strcmp(colorChild->Value(), "diffuse") == 0) {
                        float red = atof(colorChild->Attribute("R")) / 255;
                        float green = atof(colorChild->Attribute("G")) / 255;
                        float blue = atof(colorChild->Attribute("B")) / 255;
                        modelo.diffuse[0] = red;
                        modelo.diffuse[1] = green;
                        modelo.diffuse[2] = blue;

                    }
                    else if(strcmp(colorChild->Value(), "ambient") == 0){
                        float red = atof(colorChild->Attribute("R")) / 255;
                        float green = atof(colorChild->Attribute("G")) / 255;
                        float blue = atof(colorChild->Attribute("B")) / 255;
                        modelo.ambient[0] = red;
                        modelo.ambient[1] = green;
                        modelo.ambient[2] = blue;
                    }
                    else if(strcmp(colorChild->Value(), "specular") == 0){
                        float red = atof(colorChild->Attribute("R")) / 255;
                        float green = atof(colorChild->Attribute("G")) / 255;
                        float blue = atof(colorChild->Attribute("B")) / 255;
                        modelo.specular[0] = red;
                        modelo.specular[1] = green;
                        modelo.specular[2] = blue;
                    }
                    else if(strcmp(colorChild->Value(), "emissive") == 0){
                        float red = atof(colorChild->Attribute("R")) / 255;
                        float green = atof(colorChild->Attribute("G")) / 255;
                        float blue = atof(colorChild->Attribute("B")) / 255;
                        modelo.emissive[0] = red;
                        modelo.emissive[1] = green;
                        modelo.emissive[2] = blue;
                    }
                    else if(strcmp(colorChild->Value(), "shininess") == 0){
                        float value = atof(colorChild->Attribute("value"));
                        modelo.shininess = value;
                    }

                    colorChild = colorChild->NextSiblingElement();
                }

                // Copy vertices to GPU
                glGenBuffers(1, &modelo.verticesVBO);
                glBindBuffer(GL_ARRAY_BUFFER, modelo.verticesVBO);
                glBufferData(
                        GL_ARRAY_BUFFER,
                        sizeof(float) * modelo.getVerticesModel().size(),
                        modelo.getVerticesModel().data(),
                        GL_STATIC_DRAW);

                std::vector<unsigned int> arrayIndices;
                for(int i = 0; i < modelo.getVerticesModel().size(); i++){
                    arrayIndices.push_back(i);
                }

                // Copy indices to GPU
                glGenBuffers(1, &modelo.indicesVBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, modelo.indicesVBO);
                glBufferData(
                        GL_ELEMENT_ARRAY_BUFFER,
                        sizeof(unsigned int) * arrayIndices.size(),
                        arrayIndices.data(),
                        GL_STATIC_DRAW);

                // Copy normals to GPU
                glGenBuffers(1, &modelo.normaisVBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, modelo.normaisVBO);
                glBufferData(
                        GL_ELEMENT_ARRAY_BUFFER,
                        sizeof(unsigned int) * modelo.getNormaisModel().size(),
                        modelo.getNormaisModel().data(),
                        GL_STATIC_DRAW);

                if (strcmp(modelo.getNameTex().c_str(), "") != 0){
                    loadTexture(&modelo);
                }

                g.addModel(modelo);
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


        // Ler definições das luzes
        TiXmlElement* lightsElement = cameraElement->NextSiblingElement("lights");
        if (lightsElement != nullptr){
            lerLights(lightsElement);
        }


        // Ler o group principal
        TiXmlElement* groupElement = cameraElement->NextSiblingElement("group");
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
        case 'w':
            if (wireframe){
                glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
                wireframe = false;
            }
            else{
                glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                wireframe = true;
            }
            break;
        case 'o':
            orbitas = !orbitas;
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

        // put GLUT init here
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(800, 800);
        glutCreateWindow("Normals and Texture Coordinates G07");

        // vbo initialization
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        // some OpenGL settings
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glEnable(GL_NORMALIZE);
        glEnable(GL_RESCALE_NORMAL);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LIGHTING);
        float amb[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

        glewInit();
        ilInit();

        // put callback registry here
        glutDisplayFunc(renderScene);
        glutReshapeFunc(changeSize);
        glutIdleFunc(renderScene);

        glutKeyboardFunc(keyboardFunc);
        glutSpecialFunc(processSpecialKeys);

        if(lerFicheiroXML(argv[1])==0) {
            // enter GLUT's main cycle
            glutMainLoop();
        }
    }

    return 1;
}