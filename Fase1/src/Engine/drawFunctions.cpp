#include "drawFunctions.hpp"

// Desenha um triângulo dado 3 pontos
void drawTriangle(point p1, point p2, point p3) {

    glBegin(GL_TRIANGLES);

    // Cor branca
    glColor3ub(255, 255, 255);

    // Desenha o triângulo
    glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p3.x, p3.y, p3.z);

    glEnd();
}


// Desenha a figura a partir da struct figure
void draw::drawFigure(figure f) {
    int i;
    int n = f.pontos.size();
    for (i = 0; i+2 <= n; i+=3) {
        // Pega em 3 pontos e desenha um triângulo
        drawTriangle(f.pontos[i], f.pontos[i + 1], f.pontos[i + 2]);
    }
}

void draw::drawReferencial() {
    // Desenhar referencial
    glBegin(GL_LINES);

    // Eixo dos xx em vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);

    // Eixo dos yy em verde
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);

    // Eixo dos zz em azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);

    glEnd();
}