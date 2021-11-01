// Fila Sequencial Circular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int l[MAX], ini = 0, fim = 0;

void inserir_ini (int dado);
void inserir_fim (int dado);
int remover_fim ();
int remover_ini();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    printf("\n");

    inserir_ini(1);
    inserir_ini(2);
    inserir_ini(3);
    inserir_fim(1);
    inserir_fim(2);
    inserir_fim(3);

    imprimir();

    printf("Removido do inicio -> %d\n", remover_ini());
    printf("Removido do fim -> %d\n", remover_fim());

    imprimir();

    printf("\n");
    return 0;
}

void inserir_ini (int dado){ // imcompleto
    if (((ini - 1) != fim) && (fim + 1 != MAX)) {
        ini--;
        l[ini] = dado;
    }
    else {
        printf("Não foi possível inserir %d. Fila cheia.\n",dado);
    }
}

void inserir_fim(int dado){
    if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
        l[fim] = dado;
        //fim = (fim + 1) % MAX;
        fim++;
        if (fim == MAX) fim = 0;
    }
    else
        printf("Não foi possível inserir %d. Fila cheia.\n",dado);
}

int remover_ini(){
    if (ini != fim) {
        int dado = l[ini];
        //ini = (ini + 1) % MAX;
        ini++;
        if (ini == MAX) ini = 0;
        return dado;
    }
    else {
        printf("Não há dados. Fila vazia.\n");
        exit(1);
    }
}

int remover_fim() {
    if (ini != fim) {
        int dado = l[fim-1];
        fim--;
        if (ini == MAX) ini = 0;
        return dado;
    }
    else {
        printf("Não há dados. Fila vazia.\n");
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
        if (l[i]) printf("%d ",l[i]);
    }
    printf("]\n");
}

void apagar(){
    ini = fim = 0;
}