#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

int alturaArvore(struct sNODE *no);
struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);


int main() {
    raiz = inserir(raiz, 29);
    raiz = inserir(raiz, 19);
    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 34);
    raiz = inserir(raiz, 62);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 52);
    raiz = inserir(raiz, 69);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 70);

    printf("\n%d\n\n", alturaArvore(raiz));

	raiz = apagar(raiz);

    return 0;
}

int alturaArvore(struct sNODE *no) {

    if (no == NULL) return 0;

    else {
        int tamEsq = alturaArvore(no->esq), tamDir = alturaArvore(no->dir);;
        
        if (tamEsq > tamDir) 
            return tamEsq + 1;
        else 
            return tamDir + 1;
    }
}

struct sNODE *inserir(struct sNODE *no, int dado){
  if (!no) {
	no = (struct sNODE*) malloc(sizeof(struct sNODE));
	no->dado = dado;
	no->esq = no->dir = NULL;
  } else if (dado < no->dado)
	no->esq = inserir(no->esq,dado);
  else
	no->dir = inserir(no->dir,dado);

  return no;  
}

struct sNODE *remover(struct sNODE *no, int dado){
  struct sNODE *aux = NULL, *aux2 = NULL;

  if (no) {
	if (no->dado == dado) {
  	   if (no->esq == no->dir) {
    	      free(no);
    	      return NULL;
  	   }
  	   else if (!no->esq) {
    	      aux = no->dir;
    	      free(no);
    	      return aux;
  	   }
  	   else if (!no->dir) {
    	      aux = no->esq;
    	      free(no);
    	      return aux;
  	   } else {
    	      aux = aux2 = no->dir;
    	      while (aux->esq)
      	   aux = aux->esq;
    	      aux->esq = no->esq;
    	      free(no);
    	      return aux2;
  	   }
	}
	else {
  	   if (dado < no->dado)
    	      no->esq = remover(no->esq, dado);
  	   else
    	      no->dir = remover(no->dir, dado);
	}
  }
  return no;
}

void emOrdem(struct sNODE *no){
  if (no) {
	emOrdem(no->esq);
	printf("%d ",no->dado);
	emOrdem(no->dir);
  }
}

void preOrdem(struct sNODE *no){
  if (no) {
	printf("%d ",no->dado);
	preOrdem(no->esq);
	preOrdem(no->dir);
  }
}

void posOrdem(struct sNODE *no){
  if (no) {
	posOrdem(no->esq);
	posOrdem(no->dir);
	printf("%d ",no->dado);
  }
}

struct sNODE *buscar( struct sNODE *no, int dado){
  if (no) {
	if (no->dado == dado)
  	   return no;
	else if (dado < no->dado)
  	   return buscar(no->esq, dado);
	else
  	   return buscar(no->dir, dado);
  }
 
  return NULL;
}

int obter(struct sNODE *no) {
  if (no)
	return no->dado;
  else {
	printf("Nenhum dado para retornar.");
	exit(0);
  }
}

struct sNODE *apagar(struct sNODE *no){
  if (no) {
	no->esq = apagar(no->esq);
	no->dir = apagar(no->dir);
	free(no);
  }
  return NULL;
}