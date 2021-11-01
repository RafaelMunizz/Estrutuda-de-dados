#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, int dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(){
  char str[101];
  printf("Entre com a string: ");
  gets(str);
  
  if (validar(str))
    printf("Balanceada\n");
  else
    printf("Não Balanceada\n");

  return 0;
}

//Validação

int validarAF(char *str, char a, char f){
  char *s = str;
  PILHA p;
  criar(&p,100);
  while(*s){
    if (*s == a)
      push(&p,*s);
    s++;
  }
  s = str;
  while(*s){
    if (*s == f)
      if (tamanho(&p))
        pop(&p);
      else {
        apagar(&p);
        return 0;
      }
    s++;
  }
  if (tamanho(&p)){
    apagar(&p);
    return 0;
  } else {
    apagar(&p);
    return 1;
  }
}

int validar(char *str){
  if (validarAF(str, '(',')') && validarAF(str, '[',']') && validarAF(str, '{','}'))
    return 1;
  else
    return 0;
}


void criar(PILHA *pi, int tam_MAX){
  pi->pos = 0;
  pi->MAX = tam_MAX;
  pi->arr = (int*) malloc(sizeof(int) * tam_MAX);
}

void apagar(PILHA *pi){
  free(pi->arr);
  pi->pos = 0;
  pi->MAX = 0;
}

void push(PILHA *pi, int elemento){
  if (pi->pos < pi->MAX)
    pi->arr[pi->pos++] = elemento;
  else
    printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(PILHA *pi){
  if (pi->pos)
    return pi->arr[--pi->pos];
  else {
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
  }
}

int tamanho(PILHA *pi){
  return pi->pos;
}

void imprimir(PILHA *pi){
  printf("P[ ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
    printf("%d ",pi->arr[i]);
  printf("]\n");
}