#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Sintaxe: %s file_name rows cols\n", argv[0]);
        exit(-1);
    }

    FILE *fp;
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);

    if ((fp = fopen(argv[1], "wb")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            unsigned char element = rand() % 256;
            fwrite(&element, 1, 1, fp);
        }
    }

    fclose(fp);
    return 0;
}