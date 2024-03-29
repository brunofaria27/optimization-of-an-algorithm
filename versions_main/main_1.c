#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592

/************************************************************************/
unsigned char ReadElement(FILE *p) {
  unsigned char element;
  if (1 != fread(&element, 1, 1, p)) {
    printf("Corrupt data file.\n");
    exit(-1);
  }
  else
    return (element);
}

/************************************************************************/

void DetSinCos(unsigned char element, float *sin_element, float *cos_element) {
  *sin_element = sin(2.0 * PI * element / 360.0);
  *cos_element = cos(2.0 * PI * element / 360.0);
}

/************************************************************************/

void DetOutput(unsigned char element, float *C, float *out_even, float *out_odd) {
  float sin_element, cos_element;
  DetSinCos(element, &sin_element, &cos_element);
  *out_even = 2.0 * sin_element + exp(cos_element);
  *out_odd = exp(sin_element) * C[element];
}

/************************************************************************/

int main(int argc, char **argv) {
  FILE *data_file;
  int rows, cols, i, j;
  double time_spent = 0.0;
  unsigned char element, *M;
  float out_even, out_odd, *Q, C[256];

  clock_t begin = clock();

  if (argc < 4) {
    printf("Sintaxe: %s file_name rows cols\n", argv[0]);
    exit(-1);
  }
  
  if (NULL == (data_file = fopen(argv[1], "rb"))) {
    printf("File not found.\n");
    exit(-1);
  }

  rows = atoi(argv[2]);
  cols = atoi(argv[3]);

  if (!(M = (unsigned char *)malloc((long)rows * cols))) {
    printf("Not enough memory to read file.\n");
    exit(-1);
  }

  for (j = 0; j < rows; j++)
    for (i = 0; i < cols; i++)
      *(M + j * cols + i) = ReadElement(data_file);
  fclose(data_file);

  if (!(Q = (float *)malloc((long)rows * cols * sizeof(float)))) {
    printf("Not enough memory for output matrix.\n");
    exit(-1);
  }

  for (i = 0; i < 256; i++)
    C[i] = 0.0;

  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      element = *(M + j * cols + i);
      C[element]++;
    }

  for (i = 0; i < 256; i++)
    C[i] = (C[i] > 0) ? log(C[i]) : 0.0;

  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      element = *(M + j * cols + i);
      DetOutput(element, C, &out_even, &out_odd);
      if ((element % 2) == 0)
        *(Q + j * cols + i) = pow(out_even, 2);
      else
        *(Q + j * cols + i) = out_odd;
    }

  clock_t end = clock();

  /**** Saída não deve ser medida ****/
  free(Q);
  free(M);

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f", time_spent);
}