// Insertion Sort
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int l[], int tam){
  for (int i = 1 ; i < tam ; i++) {
    int eleito = l[i];
    int j = i - 1;

    while (j >= 0 && l[j] < eleito) {
      l[j+1] = l[j];
      j = j - 1;
    }
    l[j+1] = eleito;
  }
}

int main(void) {
  int l[] = {1,10,2,9,3,8,4,7,5,6}, tam = 10;

  insertionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}