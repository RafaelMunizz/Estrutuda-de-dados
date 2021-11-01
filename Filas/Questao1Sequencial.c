//Fila com base em Lista Sequencial

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

void enqueue(int elemento);
int dequeue();
int getFront();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    enqueue(100);
    enqueue(50);
    enqueue(75);

    imprimir();

    printf("Elemento inicial -> %d\n", getFront());

    printf("Dequeue -> %d\n", dequeue());
    printf("Dequeue -> %d\n", dequeue());

    printf("Elemento inicial -> %d\n", getFront());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    imprimir();

    printf("Dequeue -> %d\n", dequeue());
    return 0;
}

int getFront() {

    if (pos) {
        return l[0];

    } else {
        printf("Não há elementos. Pilha vazia.\n");
    }
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
}