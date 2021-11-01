#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
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

    LISTA lst, lst2, lst3;

    inicializar(&lst);
    inicializar(&lst2);
    inicializar(&lst3);

    inserir_ord(&lst, 100);
    inserir_ord(&lst, 101);
    inserir_ord(&lst, 102);

    inserir_ord(&lst2, 103);
    inserir_ord(&lst2, 104);
    inserir_ord(&lst2, 105);

    inserir_ord(&lst3, 106);
    inserir_ord(&lst3, 107);
    inserir_ord(&lst3, 108);

    imprimir(&lst);
    imprimir(&lst2);
    imprimir(&lst3);

    apagar(&lst);
    apagar(&lst2);
    apagar(&lst3);

    return 0;
}

void inicializar(LISTA *lst) {

    lst->fim = lst->ini = NULL;
}


void inserir_ord(LISTA *lst, int dado) {

    struct sNODE *aux = lst->ini, *ant = NULL;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
    novo->dado = dado;
    novo->prox = NULL;

    while(aux && dado > aux->dado){
        ant = aux;
        aux = aux->prox;
    }

    if (!lst->ini)
        lst->ini = lst->fim = novo;
    else if (aux == lst->ini){
        novo->prox = lst->ini;
        lst->ini = novo;
    } else if (!aux){
        lst->fim->prox = novo;
        lst->fim = novo;
    } else {
        ant->prox = novo;
        novo->prox = aux;
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