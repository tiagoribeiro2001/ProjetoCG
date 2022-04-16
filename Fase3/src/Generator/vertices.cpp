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

figure generate::createTorus(float radiusI, float radiusE, int slices, int stacks) {
    figure f;

    float radius = radiusI + ((radiusE - radiusI) / 2);
    float radiusCirc = (radiusE - radiusI) / 2;
    float sliceAng = (2 * M_PI) / slices;
    float stackAng = (2 * M_PI) / stacks;

    for (int i = 0; i < slices; i++) {
        float alpha = sliceAng * i;
        float nextAlpha = sliceAng * (i + 1);

        for (int j = 0; j < stacks; j++) {
            float beta = stackAng * j;
            float nextBeta = sliceAng * (j + 1);

            f.addPoint((radius + radiusCirc * cos(beta)) * cos(alpha), (radius + radiusCirc * cos(beta)) * sin(alpha), radiusCirc * sin(beta));
            f.addPoint((radius + radiusCirc * cos(beta)) * cos(nextAlpha), (radius + radiusCirc * cos(beta)) * sin(nextAlpha), radiusCirc * sin(beta));
            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(nextAlpha), (radius + radiusCirc * cos(nextBeta)) * sin(nextAlpha), radiusCirc * sin(nextBeta));

            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(nextAlpha), (radius + radiusCirc * cos(nextBeta)) * sin(nextAlpha), radiusCirc * sin(nextBeta));
            f.addPoint((radius + radiusCirc * cos(nextBeta)) * cos(alpha), (radius + radiusCirc * cos(nextBeta)) * sin(alpha), radiusCirc * sin(nextBeta));
            f.addPoint((radius + radiusCirc * cos(beta)) * cos(alpha), (radius + radiusCirc * cos(beta)) * sin(alpha), radiusCirc * sin(beta));
        }
    }
    return f;
}

void generate::multMatrixVector(float* m, float* v, float* res){
    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }
}

void generate::getPointBezier(float u, float v, float** matrixX, float** matrixY, float** matrixZ, float* pos) {
    float bezierMatrix[4][4] = { { -1.0f, 3.0f, -3.0f, 1.0f },
                                 { 3.0f, -6.0f, 3.0f, 0.0f },
                                 { -3.0f, 3.0f, 0.0f, 0.0f },
                                 { 1.0f,  0.0f, 0.0f, 0.0f } };

    float vetorU[4] = { u * u * u, u * u, u, 1 };
    float vetorV[4] = { v * v * v, v * v, v, 1 };

    float vetorAux[4];
    float px[4];
    float py[4];
    float pz[4];

    float mx[4];
    float my[4];
    float mz[4];

    multMatrixVector((float*)bezierMatrix, vetorV, vetorAux);
    multMatrixVector((float*)matrixX, vetorAux, px);
    multMatrixVector((float*)matrixY, vetorAux, py);
    multMatrixVector((float*)matrixZ, vetorAux, pz);

    multMatrixVector((float*)bezierMatrix, px, mx);
    multMatrixVector((float*)bezierMatrix, py, my);
    multMatrixVector((float*)bezierMatrix, pz, mz);


    pos[0] = (vetorU[0] * mx[0]) + (vetorU[1] * mx[1]) + (vetorU[2] * mx[2]) + (vetorU[3] * mx[3]);
    pos[1] = (vetorU[0] * my[0]) + (vetorU[1] * my[1]) + (vetorU[2] * my[2]) + (vetorU[3] * my[3]);
    pos[2] = (vetorU[0] * mz[0]) + (vetorU[1] * mz[1]) + (vetorU[2] * mz[2]) + (vetorU[3] * mz[3]);

}

figure generate::createBezier(figure points, std::vector<int> indices, int tesselation){
    figure f;

    float pos[4][3];
    float matrixX[4][4];
    float matrixY[4][4];
    float matrixZ[4][4];

    float u = 0;
    float v = 0;
    float inc = 1 / (float)tesselation;

    for (size_t p = 0; p < indices.size(); p += 16) {
        for (size_t i = 0; i < tesselation; i++) {
            for (size_t j = 0; j < tesselation; j++) {
                u = inc * i;
                v = inc * j;
                float u2 = inc * (i + 1);
                float v2 = inc * (j + 1);


                for (size_t a = 0; a < 4; a++) {
                    for (size_t b = 0; b < 4; b++) {

                        matrixX[a][b] = points.pontos.at(indices.at(p + a * 4 + b)).x;
                        matrixY[a][b] = points.pontos.at(indices.at(p + a * 4 + b)).y;
                        matrixZ[a][b] = points.pontos.at(indices.at(p + a * 4 + b)).z;

                    }
                }

                getPointBezier(u, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[0]);
                getPointBezier(u, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[1]);
                getPointBezier(u2, v, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[2]);
                getPointBezier(u2, v2, (float**)matrixX, (float**)matrixY, (float**)matrixZ, pos[3]);

                f.addPoint(pos[3][0], pos[3][1], pos[3][2]);
                f.addPoint(pos[2][0], pos[2][1], pos[2][2]);
                f.addPoint(pos[0][0], pos[0][1], pos[0][2]);

                f.addPoint(pos[0][0], pos[0][1], pos[0][2]);
                f.addPoint(pos[1][0], pos[1][1], pos[1][2]);
                f.addPoint(pos[3][0], pos[3][1], pos[3][2]);

            }
        }
    }
    return f;
}