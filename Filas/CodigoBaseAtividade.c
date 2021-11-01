/* 
//Fila com base em Lista Sequencial

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    enqueue(100);
    enqueue(50);
    enqueue(75);

    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    return 0;
}

void enqueue(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Nao foi possivel inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (pos) {
	int dado = l[0];
	for (int i = 0 ; i < pos -1 ; i++)
  	l[i] = l[i+1];
	pos--;
	return dado;
  }
  else {
	printf("Nao ha elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){

    printf("\n");
    printf("F[ ");
    for (int i = 0 ; i < pos ; i++)
        printf("%d ",l[i]);
    printf("]\n");
}

void apagar(){
  pos = 0;
} */

// Fila com base em Lista Simplesmente Encadeada

#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void enqueue(int dado);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    enqueue(100);
    enqueue(50);
    enqueue(75);

    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    return 0;
}

void enqueue(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	fim = novo;
  }
}

int dequeue(){
  if (ini) {
	int dado = ini->dado;
	struct sNODE *tmp = ini;
    
	if (ini == fim)
  	   ini = fim = NULL;
	else
  	   ini = ini->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

void apagar(){
  struct sNODE *aux = ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("F[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}