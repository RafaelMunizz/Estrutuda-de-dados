#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
  char nome[15];
  float nota1, nota2, media;
  struct aluno *prox;
};

struct aluno *ini = NULL, *fim = NULL;

void inserir(char *nome, float nota1, float nota2);
struct aluno *buscar(float media);
void remover(float media);

void apagar();
float obter(struct aluno *node);
int tamanho(); 
void imprimir();

int main(){
    
    printf("\n");
    
    inserir("Rafael", 10.0, 8.0);
    inserir("Ana", 3.0, 7.0);
    inserir("Gabriel", 5.0, 8.0); 

    printf("%d alunos inseridos\n\n", tamanho());

    imprimir();

    return 0;
}

void inserir(char *nome, float nota1, float nota2){

    float media = (nota1 + nota2) / 2;

    struct aluno *aux = ini, *ant = NULL;
    struct aluno *novo = (struct aluno*) malloc(sizeof(struct aluno ));
    strcpy(novo->nome, nome);
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->media = media;
    novo->prox = NULL;

    while(aux && media > aux->media){
        ant = aux;
        aux = aux->prox;
    }

    if (!ini)
        ini = fim = novo;

    else if (aux == ini){
        fim->prox = novo;
        fim = novo;
        
    } else if (!aux){
        novo->prox = ini;
        ini = novo;

    } else {
        ant->prox = novo;
        novo->prox = aux;
    }
}

struct aluno *buscar(float media){
  struct aluno *aux = ini;

  while (aux){
	if (media == aux->media)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(float media){
  struct aluno *aux = ini, *ant = NULL;

  while (aux){
	if (media == aux->media){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        ant->prox = NULL;
    	        fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(){
  struct aluno *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

float obter(struct aluno *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->media;
}

int tamanho(){
    struct aluno *aux = ini;
    int tam = 0;
    
    while (aux){
        tam++;
        aux = aux->prox;
    }
    
    return tam;
} 

void imprimir(){
  struct aluno *aux = ini;
 
  while (aux){
	printf("Nome do aluno: %s\nNota 1: %.1f\nNota 2: %.1f\nMedia: %.1f\n\n", aux->nome, aux->nota1, aux->nota2, aux->media);
	aux = aux->prox;
  }
}