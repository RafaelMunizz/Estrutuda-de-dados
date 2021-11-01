// Matrizes esparsas

#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  unsigned col;
  unsigned dado;
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);
int getMax();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    inicializar(20, 10);

    atribuir(3, 3, 4);
    atribuir(3, 2, 3);
    atribuir(1, 0, 7);
    atribuir(3, 3, 10);
    
    printf("Tamanho da matriz: %d \n", tamanho());
    printf(" Valor na pos %d %d eh %d\n", 0, 0, acessar(0, 0));
    printf(" Valor na pos %d %d eh %d\n", 3, 2, acessar(3, 2));

    imprimir();

    printf("O maior valor eh: %d", getMax());

    apagar();

    return 0;
}

int getMax() {

    int Max = 0;

    for (int i = 0 ; i < m.lin ; i++) {
        struct sNODE *aux = m.m[i];

        for (int j = 0 ; j < m.col ; j++) {
            if (aux && j == aux->col) {
                if ( Max < aux->dado){
                    Max = aux->dado;
                }
                aux = aux->prox;
            } 
        }
    }
    return Max;
}

void inicializar(unsigned t_lin, unsigned t_col){
  m.lin = t_lin;
  m.col = t_col;
  m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

  for (int i = 0 ; i < m.lin ; i++)
	m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, int dado) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin], *ant = NULL;

	while (aux && col > aux->col) {
  	ant = aux;
  	aux = aux->prox;
	}

	if (aux && aux->col == col){
  	   if (dado == 0) {
    	      if (ant == NULL) m.m[lin] = aux->prox;
    	      else ant->prox = aux->prox;

    	   free(aux);

  	} else aux->dado = dado;

	} else if (dado != 0) {
  	   struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
  	   novo->col = col;
  	   novo->dado = dado;
  	   novo->prox = aux;
  	   if (ant == NULL) m.m[lin] = novo;
  	   else ant->prox = novo;
	}

  } else {
	printf("Não é possível inserir elementos fora da Matriz.\n");
	exit(0);
  }
}

int acessar(unsigned lin, unsigned col) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin];

	while (aux && col > aux->col)
  	   aux = aux->prox;
    
	if (aux && col == aux->col)
  	return aux->dado;
    
	return 0;
  } else {
	printf("Não é possível acessar elementos fora da Matriz.\n");
	exit(0);
  }
}

int tamanho() {
  return m.lin * m.col;
}

void imprimir(){
    printf("M[\n");
    for (int i = 0 ; i < m.lin ; i++) {
        struct sNODE *aux = m.m[i];

        for (int j = 0 ; j < m.col ; j++) {
            if (aux && j == aux->col) {
                    printf("%4d ",aux->dado);
                    aux = aux->prox;
            } else printf("%4d ",0);
        }
        printf("\n");
    }
  printf("]\n");
}

void apagar(){
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i], *ant = NULL;

	while (aux) {
  	   ant = aux;
  	   aux = aux->prox;
  	   free(ant);
	}
  }
  free(m.m);
}
