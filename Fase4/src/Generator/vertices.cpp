#include <cmath>
#include "vertices.hpp"
#include "../Matrices/matrices.hpp"

figure generate::createPlane(float units, float divs) {

    figure f;

    float x1 = units / 2;
    float cdiv = units / divs;

    float tamDivTex = 1.0 / divs;
    float tamDivTexAtualX = 0;
    float tamDivTexAtualY = 1;

    // Desenha uma fila a cada iteracao
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){

        // Desenha um quadrado  a cada iteracao
        for(float auxX = -x1; auxX < x1; auxX += cdiv){


            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX, 0, auxZ + cdiv);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);

            f.addNormais(0,1,0);
            f.addNormais(0,1,0);
            f.addNormais(0,1,0);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY - tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY - tamDivTex, 0);

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX + cdiv, 0, auxZ + cdiv);
            f.addPoint(auxX + cdiv, 0, auxZ);

            f.addNormais(0,1,0);
            f.addNormais(0,1,0);
            f.addNormais(0,1,0);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY - tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY, 0);

            tamDivTexAtualX += tamDivTex;
        }
        tamDivTexAtualX = 0;
        tamDivTexAtualY -= tamDivTex;
    }

    return f;
}

figure generate::createBox(float units, float divs) {
    figure f;

    float x1 = units / 2;
    float cdiv = units / divs;

    float tamDivTex = 1 / divs;
    float tamDivTexAtualX = 0;
    float tamDivTexAtualY = 1;

    // Desenhar os dois planos no eixo dos yy's
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){
        for(float auxX = -x1; auxX < x1; auxX += cdiv){

            // Triângulos virados para cima
            f.addPoint(auxX, x1, auxZ);
            f.addPoint(auxX, x1, auxZ + cdiv);
            f.addPoint(auxX + cdiv, x1, auxZ + cdiv);

            f.addNormais(0,1,0);
            f.addNormais(0,1,0);
            f.addNormais(0,1,0);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY - tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY - tamDivTex, 0);

            f.addPoint(auxX, x1, auxZ);
            f.addPoint(auxX + cdiv, x1, auxZ + cdiv);
            f.addPoint(auxX + cdiv, x1, auxZ);

            f.addNormais(0,1,0);
            f.addNormais(0,1,0);
            f.addNormais(0,1,0);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY - tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY, 0);

            // Triângulos virados para baixo
            f.addPoint(auxX, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ + cdiv);
            f.addPoint(auxX, -x1, auxZ + cdiv);

            f.addNormais(0,-1,0);
            f.addNormais(0,-1,0);
            f.addNormais(0,-1,0);

            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY - tamDivTex, 0);
            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY - tamDivTex, 0);

            f.addPoint(auxX, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ);
            f.addPoint(auxX + cdiv, -x1, auxZ + cdiv);

            f.addNormais(0,-1,0);
            f.addNormais(0,-1,0);
            f.addNormais(0,-1,0);

            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY - tamDivTex, 0);

            tamDivTexAtualX += tamDivTex;
        }
        tamDivTexAtualX = 0;
        tamDivTexAtualY -= tamDivTex;
    }

    tamDivTexAtualX = 1;
    tamDivTexAtualY = 0;

    // Desenhar os dois planos no eixos dos xx's
    for(float auxZ = -x1; auxZ < x1; auxZ += cdiv){
        for(float auxY = -x1; auxY < x1; auxY += cdiv){

            // Triângulos virados para a direita
            f.addPoint(x1, auxY, auxZ);
            f.addPoint(x1, auxY + cdiv, auxZ);
            f.addPoint(x1, auxY, auxZ + cdiv);

            f.addNormais(1,0,0);
            f.addNormais(1,0,0);
            f.addNormais(1,0,0);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX - tamDivTex, tamDivTexAtualY, 0);

            f.addPoint(x1, auxY + cdiv, auxZ + cdiv);
            f.addPoint(x1, auxY, auxZ + cdiv);
            f.addPoint(x1, auxY + cdiv, auxZ);

            f.addNormais(1,0,0);
            f.addNormais(1,0,0);
            f.addNormais(1,0,0);

            f.addCoordTex(tamDivTexAtualX - tamDivTex, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX - tamDivTex, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY + tamDivTex, 0);

            // Triângulos virados para a esquerda
            f.addPoint(-x1, auxY, auxZ);
            f.addPoint(-x1, auxY, auxZ + cdiv);
            f.addPoint(-x1, auxY + cdiv, auxZ);

            f.addNormais(-1,0,0);
            f.addNormais(-1,0,0);
            f.addNormais(-1,0,0);

            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX + tamDivTex, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY  + tamDivTex, 0);

            f.addPoint(-x1, auxY + cdiv, auxZ + cdiv);
            f.addPoint(-x1, auxY + cdiv, auxZ);
            f.addPoint(-x1, auxY, auxZ + cdiv);

            f.addNormais(-1,0,0);
            f.addNormais(-1,0,0);
            f.addNormais(-1,0,0);

            f.addCoordTex(1 - tamDivTexAtualX + tamDivTex, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(1 - tamDivTexAtualX + tamDivTex, tamDivTexAtualY, 0);

            tamDivTexAtualY += tamDivTex;
        }

        tamDivTexAtualY = 0;
        tamDivTexAtualX -= tamDivTex;
    }

    tamDivTexAtualX = 0;
    tamDivTexAtualY = 0;

    // Desenhar os dois planos no eixos dos zz's
    for(float auxY = -x1; auxY < x1; auxY += cdiv){
        for(float auxX = -x1; auxX < x1; auxX += cdiv){

            // Triângulos virados para a frente
            f.addPoint(auxX, auxY, x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, x1);
            f.addPoint(auxX , auxY + cdiv, x1);

            f.addNormais(0,0,1);
            f.addNormais(0,0,1);
            f.addNormais(0,0,1);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY + tamDivTex, 0);

            f.addPoint(auxX, auxY, x1);
            f.addPoint(auxX + cdiv, auxY, x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, x1);

            f.addNormais(0,0,1);
            f.addNormais(0,0,1);
            f.addNormais(0,0,1);

            f.addCoordTex(tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY, 0);
            f.addCoordTex(tamDivTexAtualX + tamDivTex, tamDivTexAtualY + tamDivTex, 0);

            // Triângulos virados para trás
            f.addPoint(auxX, auxY, -x1);
            f.addPoint(auxX , auxY + cdiv, -x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, -x1);

            f.addNormais(0,0,-1);
            f.addNormais(0,0,-1);
            f.addNormais(0,0,-1);

            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY + tamDivTex, 0);

            f.addPoint(auxX, auxY, -x1);
            f.addPoint(auxX + cdiv, auxY + cdiv, -x1);
            f.addPoint(auxX + cdiv, auxY, -x1);

            f.addNormais(0,0,-1);
            f.addNormais(0,0,-1);
            f.addNormais(0,0,-1);

            f.addCoordTex(1 - tamDivTexAtualX, tamDivTexAtualY, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY + tamDivTex, 0);
            f.addCoordTex(1 - tamDivTexAtualX - tamDivTex, tamDivTexAtualY, 0);

            tamDivTexAtualX += tamDivTex;
        }
        tamDivTexAtualX = 0;
        tamDivTexAtualY += tamDivTex;
    }

    return f;
}

figure generate::createSphere(float radius, int slices, int stacks) {
    figure f;

    float theta = (2 * M_PI) / slices;
    float phi = (M_PI) / stacks;

    float tamSlice = 1 / (float) slices;
    float tamStack = 1 / (float) stacks;


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

                f.addNormais(cos(atualPhi) * sin(atualTheta), sin(atualPhi), cos(atualPhi) * cos(atualTheta));
                f.addNormais(cos(nextPhi) * sin(nextTheta), sin(nextPhi), cos(nextPhi) * cos(nextTheta));
                f.addNormais(cos(nextPhi) * sin(atualTheta), sin(nextPhi), cos(nextPhi) * cos(atualTheta));

                f.addCoordTex(i * tamSlice, 0.5 + j * tamStack, 0);
                f.addCoordTex(i * tamSlice + tamSlice, 0.5 + j * tamStack + tamStack, 0);
                f.addCoordTex(i * tamSlice, 0.5 + j * tamStack + tamStack, 0);

                // Parte de baixo da esfera
                f.addPoint(radius * cos(-nextPhi) * sin(atualTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(atualTheta));
                f.addPoint(radius * cos(-nextPhi) * sin(nextTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(nextTheta));
                f.addPoint(radius * cos(-atualPhi) * sin(nextTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(nextTheta));

                f.addNormais(cos(-nextPhi) * sin(atualTheta), sin(-nextPhi), cos(-nextPhi) * cos(atualTheta));
                f.addNormais(cos(-nextPhi) * sin(nextTheta), sin(-nextPhi), cos(-nextPhi) * cos(nextTheta));
                f.addNormais(cos(-atualPhi) * sin(nextTheta), sin(-atualPhi), cos(-atualPhi) * cos(nextTheta));

                f.addCoordTex(i * tamSlice, 0.5 + (-j * tamStack) - tamStack, 0);
                f.addCoordTex(i * tamSlice + tamSlice, 0.5 + (-j * tamStack) - tamStack, 0);
                f.addCoordTex(i * tamSlice + tamSlice, 0.5 + (-j * tamStack), 0);

            }

            // Parte de cima da esfera
            f.addPoint(radius * cos(nextPhi) * sin(nextTheta), radius * sin(nextPhi), radius * cos(nextPhi) * cos(nextTheta));
            f.addPoint(radius * cos(atualPhi) * sin(atualTheta), radius * sin(atualPhi), radius * cos(atualPhi) * cos(atualTheta));
            f.addPoint(radius * cos(atualPhi) * sin(nextTheta), radius * sin(atualPhi), radius * cos(atualPhi) * cos(nextTheta));

            f.addNormais(cos(nextPhi) * sin(nextTheta), sin(nextPhi), cos(nextPhi) * cos(nextTheta));
            f.addNormais(cos(atualPhi) * sin(atualTheta), sin(atualPhi), cos(atualPhi) * cos(atualTheta));
            f.addNormais(cos(atualPhi) * sin(nextTheta), sin(atualPhi), cos(atualPhi) * cos(nextTheta));

            f.addCoordTex(i * tamSlice + tamSlice, 0.5 + j * tamStack + tamStack, 0);
            f.addCoordTex(i * tamSlice, 0.5 + j * tamStack, 0);
            f.addCoordTex(i * tamSlice + tamSlice, 0.5 + j * tamStack, 0);

            // Parte de baixo da esfera
            f.addPoint(radius * cos(-atualPhi) * sin(nextTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(nextTheta));
            f.addPoint(radius * cos(-atualPhi) * sin(atualTheta), radius * sin(-atualPhi), radius * cos(-atualPhi) * cos(atualTheta));
            f.addPoint(radius * cos(-nextPhi) * sin(atualTheta), radius * sin(-nextPhi), radius * cos(-nextPhi) * cos(atualTheta));

            f.addNormais(cos(-atualPhi) * sin(nextTheta), sin(-atualPhi), cos(-atualPhi) * cos(nextTheta));
            f.addNormais(cos(-atualPhi) * sin(atualTheta), sin(-atualPhi), cos(-atualPhi) * cos(atualTheta));
            f.addNormais(cos(-nextPhi) * sin(atualTheta), sin(-nextPhi), cos(-nextPhi) * cos(atualTheta));

            f.addCoordTex(i * tamSlice + tamSlice, 0.5 + (-j * tamStack), 0);
            f.addCoordTex(i * tamSlice, 0.5 + (-j * tamStack), 0);
            f.addCoordTex(i * tamSlice, 0.5 + (-j * tamStack) - tamStack, 0);
        }
    }
    return f;
}

figure generate::createCone(float radius, float height, int slices, int stacks) {
    figure f;

    float delta = (2 * M_PI) / slices;
    float raio = radius / stacks;
    float alturas = height / stacks;
    float yNormal = cos(atan(height / radius));

    float tamSlice = 1 / (float) slices;
    float tamStack = 1 / (float) stacks;

    for (int i = 0; i < slices; i++) {

        float atualTheta = i * delta;
        float nextTheta = (i + 1) * delta;

        // Desenha base
        f.addPoint(0, 0, 0);
        f.addPoint(radius * sin(nextTheta), 0, radius * cos(nextTheta));
        f.addPoint(radius * sin(atualTheta), 0, cos(atualTheta));

        f.addNormais(0,-1,0);
        f.addNormais(0,-1,0);
        f.addNormais(0,-1,0);

        f.addCoordTex(i * tamSlice + (tamSlice / 2), 1, 0);
        f.addCoordTex(i * tamSlice + tamSlice, 0, 0);
        f.addCoordTex(i * tamSlice, 0, 0);

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

                f.addNormais(sin(nextTheta), yNormal, cos(nextTheta));
                f.addNormais(sin(atualTheta), yNormal, cos(atualTheta));
                f.addNormais(sin(atualTheta), yNormal, cos(atualTheta));

                f.addCoordTex(i * tamStack + tamStack, j * tamSlice + tamSlice, 0);
                f.addCoordTex(i * tamStack, j * tamSlice + tamSlice, 0);
                f.addCoordTex(i * tamStack, j * tamSlice, 0);
            }

            f.addPoint(atualRad * sin(nextTheta), atualAlt, atualRad * cos(nextTheta));
            f.addPoint(nextRad * sin(nextTheta), nextAlt, nextRad * cos(nextTheta));
            f.addPoint(atualRad * sin(atualTheta), atualAlt, atualRad * cos(atualTheta));

            f.addNormais(sin(nextTheta), yNormal, cos(nextTheta));
            f.addNormais(sin(nextTheta), yNormal, cos(nextTheta));
            f.addNormais(sin(atualTheta), yNormal, cos(atualTheta));

            f.addCoordTex(i * tamStack + tamStack, j * tamSlice, 0);
            f.addCoordTex(i * tamStack + tamStack, j * tamSlice + tamSlice, 0);
            f.addCoordTex(i * tamStack, j * tamSlice, 0);
        }
    }
    return f;
}

figure generate::createTorus(float radiusI, float radiusE, int slices, int stacks) {
    figure f;

    float radius = radiusI + ((radiusE - radiusI) / 2);
    float radiusCirc = (radiusE - radiusI) / 2;
    float sliceAng = (2 * M_PI) / slices;
    float stackAng = (2 * M_PI) / stacks;

    float tamSlice = 1 / (float) slices;
    float tamStack = 1 / (float) stacks;

    for (int i = 0; i < slices; i++) {
        float alpha = sliceAng * i;
        float nextAlpha = sliceAng * (i + 1);

        for (int j = 0; j < stacks; j++) {
            float beta = stackAng * j;
            float nextBeta = sliceAng * (j + 1);

            f.addPoint((radius + radiusCirc * cos(beta)) * cos(alpha), (radius + radiusCirc * cos(beta)) * sin(alpha), radiusCirc * sin(beta));
            f.addPoint((radius + radiusCirc * cos(beta)) * cos(nextAlpha), (radius + radiusCirc * cos(beta)) * sin(nextAlpha), radiusCirc * sin(beta));
            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(nextAlpha), (radius + radiusCirc * cos(nextBeta)) * sin(nextAlpha), radiusCirc * sin(nextBeta));

            f.addNormais(cos(beta) * cos(alpha), cos(beta) * sin(alpha), sin(beta));
            f.addNormais(cos(beta) * cos(nextAlpha), cos(beta) * sin(nextAlpha), sin(beta));
            f.addNormais(cos(nextBeta) * cos(nextAlpha), cos(nextBeta) * sin(nextAlpha), sin(nextBeta));

            f.addCoordTex(j * tamStack, i * tamSlice, 0);
            f.addCoordTex(j * tamStack, i * tamSlice + tamSlice, 0);
            f.addCoordTex(j * tamStack + tamStack, i * tamSlice + tamSlice, 0);

            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(nextAlpha), (radius + radiusCirc * cos(nextBeta)) * sin(nextAlpha), radiusCirc * sin(nextBeta));
            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(alpha), (radius + radiusCirc * cos(nextBeta)) * sin(alpha), radiusCirc * sin(nextBeta));
            f.addPoint((radius + radiusCirc * cos(beta)) * cos(alpha), (radius + radiusCirc * cos(beta)) * sin(alpha), radiusCirc * sin(beta));

            f.addNormais(cos(nextBeta) * cos(nextAlpha), cos(nextBeta) * sin(nextAlpha), sin(nextBeta));
            f.addNormais(cos(nextBeta) * cos(alpha), cos(nextBeta) * sin(alpha), sin(nextBeta));
            f.addNormais(cos(beta) * cos(alpha), cos(beta) * sin(alpha), sin(beta));

            f.addCoordTex(j * tamStack + tamStack, i * tamSlice + tamSlice, 0);
            f.addCoordTex(j * tamStack + tamStack, i * tamSlice, 0);
            f.addCoordTex(j * tamStack, i * tamSlice, 0);
        }
    }
    return f;
}

void generate::getBezierNormalPoint(float u, float v, float** matrixX, float** matrixY, float** matrixZ, float* pos) {
    float bezierMatrix[4][4] = { { -1.0f, 3.0f, -3.0f, 1.0f },
                                 { 3.0f, -6.0f, 3.0f, 0.0f },
                                 { -3.0f, 3.0f, 0.0f, 0.0f },
                                 { 1.0f,  0.0f, 0.0f, 0.0f } };

    float vetorU[4] = { u * u * u, u * u, u, 1 };
    float vetorV[4] = { v * v * v, v * v, v, 1 };

    float vetorDerivU[4] = { 3 * u * u, 2 * u, 1, 0 };
    float vetorDerivV[4] = { 3 * v * v, 2 * v, 1, 0 };

    float vetorAux[4];
    float px[4];
    float py[4];
    float pz[4];

    float mxAux[4];
    float myAux[4];
    float mzAux[4];

    float uRes[3];

    //Calcular u


    matrices::multMatrixVector((float*)bezierMatrix, vetorDerivV, vetorAux);
    matrices::multMatrixVector((float*)matrixX, vetorAux, px);
    matrices::multMatrixVector((float*)matrixY, vetorAux, py);
    matrices::multMatrixVector((float*)matrixZ, vetorAux, pz);

    matrices::multMatrixVector((float*)bezierMatrix, px, mxAux);
    matrices::multMatrixVector((float*)bezierMatrix, py, myAux);
    matrices::multMatrixVector((float*)bezierMatrix, pz, mzAux);

    uRes[0] = (mxAux[0] * vetorU[0]) + (mxAux[1] * vetorU[1]) + (mxAux[2] * vetorU[2]) + (mxAux[3] * vetorU[3]);
    uRes[2] = (mzAux[0] * vetorU[0]) + (mzAux[1] * vetorU[1]) + (mzAux[2] * vetorU[2]) + (mzAux[3] * vetorU[3]);
    uRes[1] = (myAux[0] * vetorU[0]) + (myAux[1] * vetorU[1]) + (myAux[2] * vetorU[2]) + (myAux[3] * vetorU[3]);


    //Calcular v
    float vetorAux2[4];
    float px2[4];
    float py2[4];
    float pz2[4];

    float mxAux2[4];
    float myAux2[4];
    float mzAux2[4];

    float vRes[3];

    matrices::multMatrixVector((float*)bezierMatrix, vetorV, vetorAux2);
    matrices::multMatrixVector((float*)matrixX, vetorAux2, px2);
    matrices::multMatrixVector((float*)matrixY, vetorAux2, py2);
    matrices::multMatrixVector((float*)matrixZ, vetorAux2, pz2);

    matrices::multMatrixVector((float*)bezierMatrix, px2, mxAux2);
    matrices::multMatrixVector((float*)bezierMatrix, py2, myAux2);
    matrices::multMatrixVector((float*)bezierMatrix, pz2, mzAux2);

    vRes[0] = (mxAux2[0] * vetorDerivU[0]) + (mxAux2[1] * vetorDerivU[1]) + (mxAux2[2] * vetorDerivU[2]) + (mxAux2[3] * vetorDerivU[3]);
    vRes[1] = (myAux2[0] * vetorDerivU[0]) + (myAux2[1] * vetorDerivU[1]) + (myAux2[2] * vetorDerivU[2]) + (myAux2[3] * vetorDerivU[3]);
    vRes[2] = (mzAux2[0] * vetorDerivU[0]) + (mzAux2[1] * vetorDerivU[1]) + (mzAux2[2] * vetorDerivU[2]) + (mzAux2[3] * vetorDerivU[3]);

    //normalize(uRes);
    //normalize(vRes);

    matrices::cross(uRes, vRes, pos);
    matrices::normalize(pos);

}

void generate::calculateBezierPoint(float u, float v, float** matrixX, float** matrixY, float** matrixZ, float* pos) {
    float bezierMatrix[4][4] = { { -1.0f, 3.0f, -3.0f, 1.0f },
                                 { 3.0f, -6.0f, 3.0f, 0.0f },
                                 { -3.0f, 3.0f, 0.0f, 0.0f },
                                 { 1.0f,  0.0f, 0.0f, 0.0f } };

    float vetorU[4] = { powf(u, 3), powf(u, 2), u, 1 };
    float vetorV[4] = { powf(v, 3), powf(v, 2), v, 1 };

    float vetorAux[4];
    float px[4];
    float py[4];
    float pz[4];

    float mx[4];
    float my[4];
    float mz[4];

    matrices::multMatrixVector((float*)bezierMatrix, vetorV, vetorAux);
    matrices::multMatrixVector((float*)matrixX, vetorAux, px);
    matrices::multMatrixVector((float*)matrixY, vetorAux, py);
    matrices::multMatrixVector((float*)matrixZ, vetorAux, pz);

    matrices::multMatrixVector((float*)bezierMatrix, px, mx);
    matrices::multMatrixVector((float*)bezierMatrix, py, my);
    matrices::multMatrixVector((float*)bezierMatrix, pz, mz);


    pos[0] = (vetorU[0] * mx[0]) + (vetorU[1] * mx[1]) + (vetorU[2] * mx[2]) + (vetorU[3] * mx[3]);
    pos[1] = (vetorU[0] * my[0]) + (vetorU[1] * my[1]) + (vetorU[2] * my[2]) + (vetorU[3] * my[3]);
    pos[2] = (vetorU[0] * mz[0]) + (vetorU[1] * mz[1]) + (vetorU[2] * mz[2]) + (vetorU[3] * mz[3]);

}

figure generate::createBezier(std::vector<point> points, std::vector<int> indices, int tesselation){
    figure f;

    float pos[4][3];
    float matrixX[4][4];
    float matrixY[4][4];
    float matrixZ[4][4];

    float u = 0;
    float v = 0;
    float inc = 1 / (float)tesselation;

    for (int p = 0; p < indices.size(); p += 16) {
        for (int i = 0; i < tesselation; i++) {
            for (int j = 0; j < tesselation; j++) {
                u = inc * i;
                v = inc * j;
                float u2 = inc * (i + 1);
                float v2 = inc * (j + 1);


                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < 4; b++) {

                        matrixX[a][b] = points.at(indices.at(p + a * 4 + b)).x;
                        matrixY[a][b] = points.at(indices.at(p + a * 4 + b)).y;
                        matrixZ[a][b] = points.at(indices.at(p + a * 4 + b)).z;

                    }
                }

                calculateBezierPoint(u, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[0]);
                calculateBezierPoint(u, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[1]);
                calculateBezierPoint(u2, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[2]);
                calculateBezierPoint(u2, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[3]);

                f.addPoint(pos[3][0], pos[3][1], pos[3][2]);
                f.addPoint(pos[2][0], pos[2][1], pos[2][2]);
                f.addPoint(pos[0][0], pos[0][1], pos[0][2]);

                f.addCoordTex(u2, v2, 0);
                f.addCoordTex(u2, v, 0);
                f.addCoordTex(u, v, 0);

                f.addPoint(pos[0][0], pos[0][1], pos[0][2]);
                f.addPoint(pos[1][0], pos[1][1], pos[1][2]);
                f.addPoint(pos[3][0], pos[3][1], pos[3][2]);

                f.addCoordTex(u, v, 0);
                f.addCoordTex(u, v2, 0);
                f.addCoordTex(u2, v2, 0);

                getBezierNormalPoint(u, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[0]);
                getBezierNormalPoint(u, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[1]);
                getBezierNormalPoint(u2, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[2]);
                getBezierNormalPoint(u2, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[3]);

                f.addNormais(pos[3][0], pos[3][1], pos[3][2]);
                f.addNormais(pos[2][0], pos[2][1], pos[2][2]);
                f.addNormais(pos[0][0], pos[0][1], pos[0][2]);

                f.addNormais(pos[0][0], pos[0][1], pos[0][2]);
                f.addNormais(pos[1][0], pos[1][1], pos[1][2]);
                f.addNormais(pos[3][0], pos[3][1], pos[3][2]);
            }
        }
    }
    return f;
}