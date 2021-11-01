// MergeSort com strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char **a, char **b) {
  char *t = *a;
  *a = *b;
  *b = t;
}

void intercala(char *l[],int ini, int fim, int meio) {
  char *aux[fim-ini+1], p_aux = 0;
  int ini1 = ini, ini2 = meio + 1;

  while( (ini1 <= meio) && (ini2 <= fim) ) {
    if (strcmp(l[ini1], l[ini2])<=0)
        troca(&aux[p_aux], &l[ini1++]);
    else
        troca(&aux[p_aux], &l[ini2++]);

    p_aux++;
  }

  for (int i = ini1 ; i <= meio ; i++)
    troca(&aux[p_aux++], &l[i]);
  
  for (int i = ini2 ; i <= fim ; i++)
    troca(&aux[p_aux++], &l[i]);
  
  for (int i = ini, j = 0 ; i <= fim ; i++,j++)
    troca(&l[i], &aux[j]);
}

void mergeSort(char *l[], int ini, int fim) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(l,ini,meio);
    mergeSort(l,meio+1,fim);
    intercala(l,ini,fim,meio);
  }
}

int main(void) {
  char *l[] = {"vaso","gato","planta","cachorro","mesa","cadeira"};
  mergeSort(l, 0, 5);

  printf("\n");
  for (int i = 0 ; i <= 5 ; i++)
    printf("%s\n",l[i]);

  return 0;
}