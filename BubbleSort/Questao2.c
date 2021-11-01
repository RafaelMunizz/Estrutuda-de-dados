#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linha 5
#define coluna 10

char l[linha][coluna] = {"gato","planta","cachorro","mesa","cadeira"};

void bubbleSort();
void imprimir();

void main() {

  bubbleSort();
  imprimir();
}

void bubbleSort(){

  char aux[25];
  for(int i=1; i <= linha; i++)
    for(int j=0; j <= linha -i -1; j++)
      if(strcmp(l[j], l[j+1])>0) {
        strcpy(aux, l[j]);
        strcpy(l[j], l[j+1]);
        strcpy(l[j+1], aux);
      }
}

void imprimir() {
  printf("\n");
    for (int i = 0 ; i < linha; i++) {
      for (int j=0; j < strlen(l[i]); j++) {
        printf("%c",l[i][j]);
      }
      printf("\n");
    } 
}