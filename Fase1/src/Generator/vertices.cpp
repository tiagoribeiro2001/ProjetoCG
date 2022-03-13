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

    float theta = (2 * M_PI) / slices;
    float phi = (M_PI) / stacks;

    for (int i = 0; i < slices; i++) {
        for (int j = 0; j < stacks / 2; j++) {

            float atualTheta = i * theta;
            float atualPhi = j * phi;
            float nextTheta = (i + 1) * theta;
            float nextPhi = (j + 1) * phi;

            // Na parte superior e inferior da esfera (na ultima e primeira stack) apenas desenhamos um triangulo
            if (j != (stacks / 2) - 1) {

                // Parte de cima da esfera
                f.addPoint(radius * cos(atualPhi) * sin(atualTheta), radius * sin(atualPhi), radius * cos(atualPhi) * cos(atualTheta));
                f.addPoint(radius * cos(nextPhi) * sin(nextTheta), radius * sin(nextPhi), radius * cos(nextPhi) * cos(nextTheta));
                f.addPoint(radius * cos(nextPhi) * sin(atualTheta), radius * sin(nextPhi), radius * cos(nextPhi) * cos(atualTheta));

                // Parte de baixo da esfera
                f.addPoint(radius * cos(-nextPhi) * sin(atualTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(atualTheta));
                f.addPoint(radius * cos(-nextPhi) * sin(nextTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(nextTheta));
                f.addPoint(radius * cos(-atualPhi) * sin(nextTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(nextTheta));

            }

            // Parte de cima da esfera
            f.addPoint(radius * cos(nextPhi) * sin(nextTheta), radius * sin(nextPhi), radius * cos(nextPhi) * cos(nextTheta));
            f.addPoint(radius * cos(atualPhi) * sin(atualTheta), radius * sin(atualPhi), radius * cos(atualPhi) * cos(atualTheta));
            f.addPoint(radius * cos(atualPhi) * sin(nextTheta), radius * sin(atualPhi), radius * cos(atualPhi) * cos(nextTheta));

            // Parte de baixo da esfera
            f.addPoint(radius * cos(-atualPhi) * sin(nextTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(nextTheta));
            f.addPoint(radius * cos(-atualPhi) * sin(atualTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(atualTheta));
            f.addPoint(radius * cos(-nextPhi) * sin(atualTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(atualTheta));

        }
    }
    return f;
}

figure generate::createCone(float radius, float height, int slices, int stacks) {
    figure f;

    float delta = (2 * M_PI) / slices;
    float raio = radius / stacks;
    float alturas = height / stacks;

    for (int i = 0; i < slices; i++) {

        float atualTheta = i * delta;
        float nextTheta = (i + 1) * delta;

        // Desenha base
        f.addPoint(0, 0, 0);
        f.addPoint(radius * sin(nextTheta), 0, radius * cos(nextTheta));
        f.addPoint(radius * sin(atualTheta), 0, cos(atualTheta));

        for (int j = 0; j < stacks; j++) {

            // Desenha as faces laterais
            float atualRad = (stacks - j) * raio;
            float nextRad = (stacks - j - 1) * raio;
            float atualAlt = j * alturas;
            float nextAlt = (j + 1) * alturas;

            // Na ultima stack so desenha um triangulo
            if (j != (stacks - 1)) {
                f.addPoint(nextRad * sin(nextTheta), nextAlt, nextRad * cos(nextTheta));
                f.addPoint(nextRad * sin(atualTheta), nextAlt, nextRad * cos(atualTheta));
                f.addPoint(atualRad * sin(atualTheta), atualAlt, atualRad * cos(atualTheta));
            }

            f.addPoint(atualRad * sin(nextTheta), atualAlt, atualRad * cos(nextTheta));
            f.addPoint(nextRad * sin(nextTheta), nextAlt, nextRad * cos(nextTheta));
            f.addPoint(atualRad * sin(atualTheta), atualAlt, atualRad * cos(atualTheta));
        }
    }
    return f;
}