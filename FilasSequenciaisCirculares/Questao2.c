// Fila Sequencial Circular (Versão melhorada)
#include <stdio.h>
#include <stdlib.h>

struct sFILA{
  int *arr, ini, fim;
  int MAX;
};

typedef struct sFILA FILA;

void criar(FILA *fi, int tam_MAX);
void apagar(FILA *fi);

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(void) {

    printf("\n");
    FILA Fila1, Fila2, Fila3;

    criar(&Fila1, 10); criar(&Fila2, 10); criar(&Fila3, 10);

    enqueue(&Fila1, 10); enqueue(&Fila1, 20); enqueue(&Fila1, 30);
    enqueue(&Fila2, 40); enqueue(&Fila2, 50); enqueue(&Fila2, 60);
    enqueue(&Fila3, 70); enqueue(&Fila3, 80); enqueue(&Fila3, 90);

    imprimir(&Fila1);
    imprimir(&Fila2);
    imprimir(&Fila3);

    printf("\nDequeue em Fila1 -> %d\n", dequeue(&Fila1));
    printf("Dequeue em Fila2 -> %d\n", dequeue(&Fila2));
    printf("Dequeue em Fila3 -> %d\n", dequeue(&Fila3));
    printf("Dequeue em Fila1 -> %d\n", dequeue(&Fila1));

    apagar(&Fila3);

    imprimir(&Fila1);
    imprimir(&Fila2);
    imprimir(&Fila3);
    printf("\n");
    return 0;
}

void criar(FILA *fi, int tam_MAX) {
    fi->fim = fi->ini = 0;
    fi->arr = malloc(sizeof(struct sFILA) * tam_MAX);
    fi->MAX = tam_MAX;
}


void apagar(FILA *fi) {
  fi->ini = fi->fim = 0;
}

void enqueue(FILA *fi, int dado) {
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini) ){
	fi->arr[fi->fim] = dado;
	//fi->fim = (fi->fim + 1) % fi->MAX;
	fi->fim++;
	if (fi->fim == fi->MAX) fi->fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",dado);
}

int dequeue(FILA *fi) {
  if (fi->ini != fi->fim) {
	int dado = fi->arr[fi->ini];
	//fi->ini = (fi->ini + 1) % fi->MAX;
	fi->ini++;
	if (fi->ini == fi->MAX) fi->ini = 0;
	return dado;
  }
  else {
	printf("Não há dados. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(FILA *fi){
  if (fi->ini <= fi->fim)
	return fi->fim - fi->ini;
  else
	return fi->MAX - (fi->ini - fi->fim);
}

void imprimir(FILA *fi) {
  printf("F[ ");
  for (int i = fi->ini ;  ; i++) {
	if (i == fi->MAX) i = 0;
	if (i == fi->fim) break;
	printf("%d ",fi->arr[i]);
  }
  printf("]\n");
}
