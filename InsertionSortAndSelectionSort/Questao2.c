// Selection Sort
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int indexMin(int l[], int ini, int tam){
  int im = ini;
  int maior = l[ini];

  for (int i = ini + 1 ; i < tam ; i++)
    if (l[i] > maior) {
      im = i;
      maior = l[i];
    }
  
  return im;
}

void selectionSort(int l[], int tam){
  for (int i = 0 ; i < tam - 1 ; i++) {
    int eleito = l[i];
    int im = indexMin(l, i+1, tam);
    if (l[im] > eleito)
      troca(&l[i],&l[im]);
  }
}

int main(void) {
  int l[] = {1,10,2,9,3,8,4,7,5,6}, tam = 10;

  selectionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}