#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBin(char *l[], int tam, char *palavra) {
  int ini = 0, fim = tam -1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (!strcmp(l[meio], palavra))
      return meio;
    else {
      if (strcmp(palavra, l[meio]) < 0)
        fim = meio - 1;
      else
        ini = meio + 1;
      meio = (ini + fim) / 2;
    }
  }
  return -1;
}

int main() {
  char *l[] = {"cachorro","cadeira","gato","mesa","planta","vaso"}, tam = 6;

  printf("\nAchei vaso em %d \n",buscaBin(l, tam, "vaso"));
  printf("Achei cadeira em %d \n",buscaBin(l, tam, "cadeira"));
  
  return 0;
}