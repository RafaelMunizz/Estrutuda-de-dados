#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

int getTopo();
void push(int elemento);
int pop();

int tamanho();
void imprimir();
void apagar();

int main(void) {

    push(100);    
    push(50);
    push(75);
    printf("Topo -> %d\n", getTopo());
    

    push(61);
    push(24);

    printf("Topo -> %d\n", getTopo());
    
    imprimir();
    printf("Pop -> %d\n", pop());
    imprimir();
    printf("Topo -> %d\n", getTopo());

    return 0;
}

int getTopo() {

    if (pos)
	    return l[pos-1];
    else 
        printf("Nao ha elementos. Pilha vazia.\n");
}

void push(int elemento){
  if (pos < MAX)
	  l[pos++] = elemento;
  else
	  printf("Nao foi possivel inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
  if (pos)
	  return l[--pos];

  else {
	  printf("Nao ha elementos. Pilha vazia.\n");
	  exit(1);

  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
	  printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}