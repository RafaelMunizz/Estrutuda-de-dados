// Fila Sequencial Circular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int l[MAX], ini = 0, fim = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    printf("\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);

    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());

    enqueue(10); enqueue(11); enqueue(12);

    imprimir();
    printf("Tam: %d\n", tamanho());

    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());

    imprimir();

    printf("Dequeue -> %d\n", dequeue());

    imprimir();

    printf("Dequeue -> %d\n", dequeue());

    imprimir();

    enqueue(13);
    enqueue(14);
    enqueue(15);

    imprimir();
    printf("\n");
    return 0;
}

void enqueue(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
	l[fim] = elemento;
	//fim = (fim + 1) % MAX;
	fim++;
	if (fim == MAX) fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (ini != fim) {
	int dado = l[ini];
	//ini = (ini + 1) % MAX;
	ini++;
	if (ini == MAX) ini = 0;
	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(){
  if (ini <= fim)
	return fim - ini;
  else
	return MAX - (ini - fim);
}

void imprimir(){
  printf("F[ ");
  for (int i = ini ;  ; i++) {
	if (i == MAX) i = 0;
	if (i == fim) break;
	printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}