// Insertion Sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char **a, char **b) {
  char *t = *a;
  *a = *b;
  *b = t;
}

void insertionSort(char *l[], int tam) {
  char *eleito;
  for (int i = 1 ; i < tam ; i++) {
    troca(&eleito, &l[i]);
    int j = i - 1;

    while (j >= 0 && strcmp(l[j], eleito) > 0) {
      l[j+1] = l[j];
      j = j - 1;
    }
    troca(&l[j+1], &eleito);
  }
}

void main() {
  char *l[] = {"vaso","gato","planta","cachorro","mesa","cadeira"}, tam = 6;

  insertionSort(l, tam);

  printf("\n");
  for (int i = 0 ; i < tam ; i++)
    printf("%s\n",l[i]);
}