#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void push(PILHA *pi, int dado);
int pop(PILHA *pi);
int tamanho(PILHA *pi);
void imprimir(PILHA *pi);
void apagar(PILHA *pi);

int main(void) {

    PILHA pilha1, pilha2, pilha3;

    criar(&pilha1, 5);
    criar(&pilha2, 2);

    push(&pilha1, 10);
    push(&pilha1, 11);
    push(&pilha1, 12);

    imprimir(&pilha1);

    push(&pilha2, 13);
    push(&pilha2, 14);
    push(&pilha2, 15);

    imprimir(&pilha2);

    printf("Pop em Pilha 1 -> %d\n", pop(&pilha1));
    printf("Pop em Pilha 2 -> %d\n", pop(&pilha2));

    imprimir(&pilha1);
    imprimir(&pilha2);

    apagar(&pilha1);
    apagar(&pilha2);

    return 0;
}

void criar(PILHA *pi, int tam_MAX) {
    pi->pos = 0;
    pi->arr = malloc(sizeof(struct sPILHA) * tam_MAX);
    pi->MAX = tam_MAX;
}

void push(PILHA *pi, int dado){
  if (pi->pos < pi->MAX)
	  pi->arr[pi->pos++] = dado;
  else
	  printf("Nao foi possivel inserir %d. Pilha cheia.\n", dado);
}

int pop(PILHA *pi) {

  if (pi->pos)
	  return pi->arr[--pi->pos];

  else {
    printf("Nao ha elementos. Pilha vazia.\n");
    exit(1);
  }
}

int tamanho(PILHA *pi){
  return pi->pos;
}

void imprimir(PILHA *pi){
  printf("P[ ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
	printf("%d ", pi->arr[i]);
  printf("]\n");
}

void apagar(PILHA *pi){
  pi->pos = 0;
  free(pi->arr);
}