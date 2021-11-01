#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int pos = 0;
char l[MAX][21];

void inserir(char *elemento);
void remover(char *elemento);
int buscar(char *elemento);

char *obter(int indice);
int tamanho();
void imprimir();
void apagar(); 

int main(void) {

    printf("\n");

    inserir("gato");
    inserir("tudo");
    inserir("maravilha");
    inserir("show");
    inserir("jacare");
    inserir("abacate");
    imprimir();
    remover("show");
    remover("mesa");
    remover("gato");
    inserir("programa");
    imprimir();

    return 0;
}

void inserir(char *elemento){

    int j = 0, p, i;

    if (pos < MAX){

        for (i = 0 ; i < pos ; i++)
  	        if (strcmp(l[i], elemento) > 0)
    	        break;

        for (p = pos ; p > i ; p--)
  	        strcpy(l[p], l[p-1]);
    
        strcpy(l[i], elemento);
        
        pos++;

    } else {
        printf("Nao foi possivel inserir '%s'. Lista cheia.\n",elemento);
    }
}

int buscar(char *elemento) {

    for (int i = 0; i < pos; i++) {
        
        if (!strcmp(l[i], elemento))
            return i; 
    }
    return -1;
}

void remover(char *elemento){

    int p = buscar(elemento);

    if (p == -1){
        printf("Elemento nao esta na lista\n");
        return;
    }

    for (int i = p ; i < pos -1; i++)

        strcpy(l[i], l[i+1]);

    pos--;

}

char *obter(int indice) {

    if (indice < 0 || indice >= pos) {

        printf("Indice %d fora dos limites da Lista.\n", indice);
        exit(1);
    }

    return &l[indice][0];
}

int tamanho() {
    return pos;
}

void imprimir() {
    printf("Lista atual = [");
    for (int i = 0; i<pos; i++)
        printf(" %s", l[i]);
    printf(" ]\n");
} 

void apagar() {
    pos = 0;
} 