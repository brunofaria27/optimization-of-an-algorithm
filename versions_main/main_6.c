#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592

/************************************************************************/
void DetSinCos(unsigned char element, float *sin_element, float *cos_element) {
  static float sin_table[256], cos_table[256];
  static int initialized = 0;

  if (!initialized) {
    for (int i = 0; i < 256; i++) {
      sin_table[i] = sin(2.0 * PI * i / 360.0);
      cos_table[i] = cos(2.0 * PI * i / 360.0);
    }
    initialized = 1;
  }

  *sin_element = sin_table[element];
  *cos_element = cos_table[element];
}

/************************************************************************/

void DetOutputTable(float *C, float *out_even_table, float *out_odd_table) {
  float sin_element, cos_element;

  for (int i = 0; i < 256; i++) {
    DetSinCos(i, &sin_element, &cos_element);
    out_even_table[i] = 2.0 * sin_element + exp(cos_element);
    out_odd_table[i] = exp(sin_element) * C[i];
  }
}

/************************************************************************/

int main(int argc, char **argv) {
  FILE *data_file;
  int rows, cols, i, j;
  double time_spent = 0.0;
  unsigned char element, *M;
  float out_even, out_odd, *Q, C[256] = {0}, out_even_table[256], out_odd_table[256], pow_even_table[256], odd_table[256];

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

  if (cols * rows != fread(M, 1, cols * rows, data_file)) {
    printf("Error reading data file.\n");
    exit(-1);
  }
  fclose(data_file);

  if (!(Q = (float *)malloc((long)rows * cols * sizeof(float)))) {
    printf("Not enough memory for output matrix.\n");
    exit(-1);
  }

  for (i = 0; i < cols * rows; i++)
    C[M[i]]++;

  for (i = 0; i < 256; i++)
    C[i] = (C[i] > 0) ? log(C[i]) : 0.0;

  DetOutputTable(C, out_even_table, out_odd_table);
  for (i = 0; i < 256; i++) {
    if ((i % 2) == 0)
      pow_even_table[i] = pow(out_even_table[i], 2);
    else
      odd_table[i] = out_odd_table[i];
  }

  for (i = 0; i < cols * rows; i++) {
    element = M[i];
    if ((element % 2) == 0)
      Q[i] = pow_even_table[element];
    else
      Q[i] = odd_table[element];
  }

  clock_t end = clock();

  free(Q);
  free(M);

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("EXECUTION TIME: %f seconds", time_spent);
}