#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "genann.h"

// rede neural baseada na biblioteca genann que treina sobre porta logicas, AND, OR , XOR
// cmc com pesos aleatorios
// 2 neuronios (burra)

void imprimir_saida(genann *rede, const double entrada[2]) {
    const double *resultado = genann_run(rede, entrada);
    printf("Saída para [%1.f, %1.f] é %1.f.\n", entrada[0], entrada[1], *resultado);
}

int xor(int argc, char *argv[]) {
    printf("Teste de XOR\n");
    printf("Treinamento de 700x\n");

    srand(time(0));

    const double entrada_xor[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    const double saida_xor[4] = {0, 1, 1, 0};

    genann *sabido_xor = genann_init(2, 1, 2, 1);

    for (int i = 0; i < 700; ++i) {
        for (int j = 0; j < 4; ++j) {
            genann_train(sabido_xor, entrada_xor[j], &saida_xor[j], 3);
        }
    }

    for (int i = 0; i < 4; ++i) {
        imprimir_saida(sabido_xor, entrada_xor[i]);
    }

    genann_free(sabido_xor);
    return 0;
}

int and(int argc, char *argv[]) {
    printf("Teste de AND\n");
    printf("Treinamento de 80x\n");

    srand(time(0));

    const double entrada_and[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    const double saida_and[4] = {0, 0, 0, 1};

    genann *sabido_and = genann_init(2, 1, 2, 1);

    for (int i = 0; i <  80; ++i) {
        for (int j = 0; j < 4; ++j) {
            genann_train(sabido_and, entrada_and[j], &saida_and[j], 3);
        }
    }

    for (int i = 0; i < 4; ++i) {
        imprimir_saida(sabido_and, entrada_and[i]);
    }

    genann_free(sabido_and);
    return 0;
}

int or(int argc, char *argv[]) {
    printf("Teste de OR\n");
    printf("Treinamento de 100x\n");

    srand(time(0));

    const double entrada_or[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    const double saida_or[4] = {0, 1, 1, 1};

    genann *sabido_or = genann_init(2, 1, 2, 1);

    for (int i = 0; i <  100; ++i) {
        for (int j = 0; j < 4; ++j) {
            genann_train(sabido_or, entrada_or[j], &saida_or[j], 3);
        }
    }

    for (int i = 0; i < 4; ++i) {
        imprimir_saida(sabido_or, entrada_or[i]);
    }

    genann_free(sabido_or);
    return 0;
}
int main(int argc, char *argv[]) {
    xor(argc, argv);
    and(argc, argv);
    or (argc, argv);
    return 0;
}