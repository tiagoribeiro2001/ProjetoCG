#define _USE_MATH_DEFINES
#include <cmath>
#include "vertices.hpp"

figure generate::createPlane(float units, float divs) {

    figure f;

    float x1 = units / 2;
    float cdiv = units / divs;

    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){
        for(float auxX = -x1; auxX < x1; auxX += cdiv){

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX, 0, auxZ + cdiv);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);
            f.addPoint(auxX + cdiv, 0, auxZ);

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);
            f.addPoint(auxX, 0, auxZ + cdiv);

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX + cdiv, 0, auxZ);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);
        }
    }

    return f;
}

figure generate::createBox(float units, float divs) {
    figure f;

    float x1 = units / 2;
    float cdiv = units / divs;

    // Desenhar os dois planos no eixo dos yy's
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){
        for(float auxX = -x1; auxX < x1; auxX += cdiv){

            f.addPoint(auxX, x1, auxZ);
            f.addPoint(auxX, x1, auxZ + cdiv);
            f.addPoint(auxX + cdiv, x1, auxZ + cdiv);

            f.addPoint(auxX, x1, auxZ);
            f.addPoint(auxX + cdiv, x1, auxZ + cdiv);
            f.addPoint(auxX + cdiv, x1, auxZ);

            f.addPoint(auxX, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ + cdiv);
            f.addPoint(auxX, -x1, auxZ + cdiv);

            f.addPoint(auxX, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ + cdiv);
        }
    }

    // Desenhar os dois planos no eixos dos xx's
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){
        for(float auxY = -x1; auxY < x1; auxY += cdiv){

            f.addPoint(x1, auxY, auxZ);
            f.addPoint(x1, auxY + cdiv, auxZ);
            f.addPoint(x1, auxY, auxZ + cdiv);

            f.addPoint(x1, auxY + cdiv, auxZ + cdiv);
            f.addPoint(x1, auxY, auxZ + cdiv);
            f.addPoint(x1, auxY + cdiv, auxZ);

            f.addPoint(-x1, auxY, auxZ);
            f.addPoint(-x1, auxY, auxZ + cdiv);
            f.addPoint(-x1, auxY + cdiv, auxZ);

            f.addPoint(-x1, auxY + cdiv, auxZ + cdiv);
            f.addPoint(-x1, auxY + cdiv, auxZ);
            f.addPoint(-x1, auxY, auxZ + cdiv);

        }
    }

    // Desenhar os dois planos no eixos dos zz's
    for(float auxY = -x1; auxY < x1; auxY += cdiv){
        for(float auxX = -x1; auxX < x1; auxX += cdiv){

            f.addPoint(auxX, auxY, x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, x1);
            f.addPoint(auxX , auxY + cdiv, x1);

            f.addPoint(auxX, auxY, x1);
            f.addPoint(auxX + cdiv, auxY, x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, x1);

            f.addPoint(auxX, auxY, -x1);
            f.addPoint(auxX , auxY + cdiv, -x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, -x1);

            f.addPoint(auxX, auxY, -x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, -x1);
            f.addPoint(auxX + cdiv, auxY, -x1);
        }
    }

    return f;
}

figure generate::createSphere(float radius, int slices, int stacks){
    figure f;

    float delta1 = M_PI / stacks;
    float delta2 = 2 * M_PI / slices;

    for (float i = -M_PI / 2; i < M_PI / 2; i += delta1) {

        float aux1 = i + delta1;


        for (float j = 0; j < 2 * M_PI - delta2; j += delta2) {

            float aux2 = j + delta2;

            //Triângulo 1
            f.addPoint(cos(aux1) * sin(j) * radius, sin(aux1) * radius, cos(aux1)* cos(j)* radius);
            f.addPoint(cos(i) * sin(j) * radius, sin(i) * radius, cos(i) * cos(j) * radius);
            f.addPoint(cos(i) * sin(aux2) * radius,sin(i) * radius, cos(i) * cos(aux2) * radius);

            //Triângulo 2
            f.addPoint(cos(aux1) * sin(j) * radius, sin(aux1) * radius, cos(aux1)* cos(j)* radius);
            f.addPoint(cos(i) * sin(aux2) * radius, sin(i) * radius, cos(i)* cos(aux2)* radius);
            f.addPoint(cos(aux1) * sin(aux2) * radius, sin(aux1) * radius, cos(aux1)* cos(aux2)* radius);

        }
    }

    return f;
}

figure generate::createCone(float radius, float height, int slices, int stacks) {
    figure f;

    float theta = 0;
    float nextTheta = 0;
    float delta = (2 * M_PI) / slices;
    float raio = radius / stacks;
    float alturas = height / stacks;
    int i, j;

    //fazer a circunferência da base
    for (i = 0; i < slices; i++) {

        nextTheta = theta + delta;

        f.addPoint(0, 0, 0);
        f.addPoint(radius * sin(nextTheta), 0, radius * cos(nextTheta));
        f.addPoint(radius * sin(theta), 0, cos(theta));

        theta = nextTheta;
    }

    // Fazer as laterais
    float r1 = radius;
    float r2 = radius - raio;
    float alt1 = 0;
    float alt2 = alturas;
    theta = 0;
    nextTheta = 0;

    for (i = 0; i < slices; i++) {

        nextTheta += delta;

        for (j = 0; j < stacks; j++) {

            f.addPoint(r1 * sin(nextTheta), alt1, r1 * cos(nextTheta));
            f.addPoint(r2 * sin(nextTheta), alt2, r2 * cos(nextTheta));
            f.addPoint(r1 * sin(theta), alt1, r1 * cos(theta));

            f.addPoint(r2 * sin(nextTheta), alt2, r2 * cos(nextTheta));
            f.addPoint(r2 * sin(theta), alt2, r2 * cos(theta));
            f.addPoint(r1 * sin(theta), alt1, r1 * cos(theta));

            r1 -= raio;
            r2 -= raio;
            alt1 += alturas;
            alt2 += alturas;
        }
        r1 = radius;
        r2 = radius - raio;
        alt1 = 0;
        alt2 = alturas;
        theta = nextTheta;
    }
    return f;
}