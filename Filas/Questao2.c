#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(void) {

    FILA Fila1, Fila2, Fila3;

    criar(&Fila1); criar(&Fila2); criar(&Fila3);

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
    return 0;
}

void criar(FILA *fi){
    fi -> ini = fi -> fim = NULL;
}

void apagar(FILA *fi) {
  struct sNODE *aux = fi->ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  fi -> ini = fi -> fim = NULL;
}

void enqueue(FILA *fi, int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi -> ini)
	fi -> ini = fi -> fim = novo;
  else{
	fi -> fim->prox = novo;
	fi -> fim = novo;
  }
}

int dequeue(FILA *fi) {
  if (fi -> ini) {
	int dado = fi -> ini -> dado;
	struct sNODE *tmp = fi -> ini;
    
	if (fi -> ini == fi -> fim)
  	   fi -> ini = fi -> fim = NULL;
	else
  	   fi -> ini = fi -> ini->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(FILA *fi) {
  struct sNODE *aux = fi -> ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(FILA *fi) {
  struct sNODE *aux = fi -> ini;
 
  printf("F[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}