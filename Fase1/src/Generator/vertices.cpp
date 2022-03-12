#define _USE_MATH_DEFINES
#include <cmath>
#include "vertices.hpp"

figure generate::createPlane(float units, float divs) {

    figure f;

    float x1 = units / 2;
    float cdiv = units / divs;

    // Desenha uma fila a cada iteracao
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){

        // Desenha um quadrado virada para cima e para baixo a cada iteracao
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

figure generate::createSphere(float radius, int slices, int stacks) {
    figure f;

    float alpha = (2 * M_PI) / slices;
    float beta = (M_PI) / stacks;

    for (int i = 0; i < slices; i++) {
        for (int j = 0; j < stacks / 2; j++) {

            float atualAlpha = i * alpha;
            float atualBeta = j * beta;
            float nextAlpha = (i + 1) * alpha;
            float nextBeta = (j + 1) * beta;

            // Parte de cima da esfera
            f.addPoint(radius * cos(atualBeta) * sin(atualAlpha), radius * sin(atualBeta), radius * cos(atualBeta) * cos(atualAlpha));
            f.addPoint(radius * cos(nextBeta) * sin(nextAlpha), radius * sin(nextBeta), radius * cos(nextBeta) * cos(nextAlpha));
            f.addPoint(radius * cos(nextBeta) * sin(atualAlpha), radius * sin(nextBeta), radius * cos(nextBeta) * cos(atualAlpha));

            f.addPoint(radius * cos(nextBeta) * sin(nextAlpha), radius * sin(nextBeta), radius * cos(nextBeta) * cos(nextAlpha));
            f.addPoint(radius * cos(atualBeta) * sin(atualAlpha), radius * sin(atualBeta), radius * cos(atualBeta) * cos(atualAlpha));
            f.addPoint(radius * cos(atualBeta) * sin(nextAlpha), radius * sin(atualBeta), radius * cos(atualBeta) * cos(nextAlpha));


            // Parte de baixo da esfera
            f.addPoint(radius * cos(-atualBeta) * sin(nextAlpha), radius * sin(-atualBeta), radius * cos(-atualBeta) * cos(nextAlpha));
            f.addPoint(radius * cos(-atualBeta) * sin(atualAlpha), radius * sin(-atualBeta), radius * cos(-atualBeta) * cos(atualAlpha));
            f.addPoint(radius * cos(-nextBeta) * sin(atualAlpha), radius * sin(-nextBeta), radius * cos(-nextBeta) * cos(atualAlpha));

            f.addPoint(radius * cos(-nextBeta) * sin(atualAlpha), radius * sin(-nextBeta), radius * cos(-nextBeta) * cos(atualAlpha));
            f.addPoint(radius * cos(-nextBeta) * sin(nextAlpha), radius * sin(-nextBeta), radius * cos(-nextBeta) * cos(nextAlpha));
            f.addPoint(radius * cos(-atualBeta) * sin(nextAlpha), radius * sin(-atualBeta), radius * cos(-atualBeta) * cos(nextAlpha));

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