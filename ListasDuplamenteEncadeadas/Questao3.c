#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

int main(){

    LISTA lst, lst2;

    inicializar(&lst);
    inicializar(&lst2);

    inserir_ord(&lst, 10);
    inserir_ord(&lst, 11);
    inserir_ord(&lst, 12);

    inserir_ord(&lst2, 13);
    inserir_ord(&lst2, 14);
    inserir_ord(&lst2, 15);

    imprimir(&lst);
    imprimir(&lst2);

    apagar(&lst);
    apagar(&lst2);

    return 0;
}

void inicializar(LISTA *lst) {

    lst->fim = lst->ini = NULL;
}


void inserir_ord(LISTA *lst, int dado){
    
    struct sNODE *aux = lst->ini;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;

    while(aux && dado > aux->dado)
        aux = aux->prox;

    if (!lst->ini)
        lst->ini = lst->fim = novo;
    else if (aux == lst->ini){
        novo->prox = lst->ini;
        lst->ini->ant = novo;
        lst->ini = novo;
    } else if (!aux){
        lst->fim->prox = novo;
        novo->ant = lst->fim;
        lst->fim = novo;
    } else {
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;
  }
}

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == lst->ini)
    	        lst->ini = lst->ini->prox;
  	    else if(aux == lst->fim){
    	        ant->prox = NULL;
    	        lst->fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  lst->ini = lst->fim = NULL;
}

int obter(struct sNODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
  struct sNODE *aux = lst->ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}