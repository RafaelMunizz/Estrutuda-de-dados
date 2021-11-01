// Selection Sort
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

void inserir(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

struct sNODE* noMin(struct sNODE *ini) {
    struct sNODE* M = ini;
    while(ini) {
        if (ini->dado < M->dado)
            M->dado = ini->dado;
        ini = ini->prox;

    printf("%d", M->dado);
    return M;
    }
}

void selectionSort(LISTA *lst) {
  /* for (int i = 0 ; i < tam - 1 ; i++) {
        int eleito = l[i];
        int im = indexMin(l, i+1, tam);
        if (l[im] > eleito)
            troca(&l[i],&l[im]);
    } */
    struct sNODE *eleito = (struct sNODE*) malloc(sizeof(struct sNODE));

    for (int i = 0 ; i < tamanho(lst) - 1 ; i++) { 

        struct sNODE* menor = noMin(eleito);
        //printf("%d", menor->dado);

        if (eleito->dado > menor->dado)
            troca(&eleito->dado, &menor->dado);

        eleito = eleito->prox; 
    } 
}

int main(){
  LISTA lst;
  inicializar(&lst);
  
  inserir(&lst,1);
  inserir(&lst,10);
  inserir(&lst,2);
  inserir(&lst,9);
  inserir(&lst,3);
  inserir(&lst,8);
  inserir(&lst,4);
  inserir(&lst,7);
  inserir(&lst,5);
  inserir(&lst,6);

  imprimir(&lst);
  selectionSort(&lst);
  imprimir(&lst);

  apagar(&lst);
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = lst->fim = NULL;
}

void inserir(LISTA *lst, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!lst->ini)
    lst->ini = lst->fim = novo;
  else{
    lst->fim->prox = novo;
    lst->fim = novo;
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