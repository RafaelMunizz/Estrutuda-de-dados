#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
  char nome[31], ocupacao[31];
  float salario;
  struct funcionario *ant;
  struct funcionario *prox;
};

struct funcionario *ini = NULL, *fim = NULL;

int prioridade(char *ocupacao);
void inserir(char *nome, char *ocupacao, float salario);
void remover(float salario);
struct funcionario *buscar(float salario);

float obter(struct funcionario *node);
int tamanho(); 
void imprimir();
void apagar();

int main(){
    
    printf("\n");
    
    inserir("Funcionario 1", "Gerente", 4000);
    inserir("Funcionario 2", "Supervisor", 4000);
    inserir("Funcionario 3", "Peao", 4000);
    inserir("Funcionario 4", "Gerente", 3000);
    inserir("Funcionario 5", "Supervisor", 3000);
    inserir("Funcionario 6", "Peao", 3000);
    inserir("Funcionario 7", "Gerente", 2000);
    inserir("Funcionario 8", "Supervisor", 2000);
    inserir("Funcionario 9", "Peao", 2000);
    inserir("Funcionario 10", "Gerente", 1000);
    inserir("Funcionario 11", "Supervisor", 1000);
    inserir("Funcionario 12", "Peao", 1000);
    inserir("Funcionario 13", "Gerente", 5000);
    inserir("Funcionario 14", "Supervisor", 5000);
    inserir("Funcionario 15", "Peao", 5000);

    printf("%d funcionarios inseridos\n\n", tamanho());

    imprimir();

    return 0;
}

void inserir(char *nome, char *ocupacao, float salario){

    struct funcionario *aux = ini;
    struct funcionario *novo = (struct funcionario*) malloc(sizeof(struct funcionario ));
    strcpy(novo->nome, nome);
    strcpy(novo->ocupacao, ocupacao);
 
    novo->salario = salario;
    novo->ant = NULL;
    novo->prox = NULL;

    while (aux && prioridade(ocupacao) > prioridade(aux -> ocupacao)) {
        aux = aux->prox;
    }

    while (aux && salario < aux->salario && prioridade(ocupacao) == prioridade(aux -> ocupacao)) {
        aux = aux->prox;
    }

    if (!ini)
        ini = fim = novo;

    else if (aux == ini) {
        novo->prox = ini;
        ini->ant = novo;
        ini = novo;

    } else if (!aux) {
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;

    } else {
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;
    }
}

int prioridade(char *ocupacao) {

    int prioridade;

    if (!strcmp(ocupacao, "Gerente")){ prioridade = 1;
    } else if (!strcmp(ocupacao, "Supervisor")){ prioridade = 2;
    } else if (!strcmp(ocupacao, "Peao")){ prioridade = 3; }
    return prioridade;
}

struct funcionario *buscar(float salario){
  struct funcionario *aux = ini;

  while (aux){
	if (salario == aux->salario)
  	    return aux;
	aux = aux -> prox;
  }

  return NULL;
}

void remover(float salario){
    struct funcionario *aux = buscar(salario);

    if (!aux)
        return;

    if (!aux->ant && !aux->prox)
        ini = fim = NULL;

    else if (aux == ini) {
        ini = ini->prox;
        ini->ant = NULL;

    } else if (aux == fim) {
        fim = fim->ant;
        fim->prox = NULL;

    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free(aux);
}

void apagar() {

  struct funcionario *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }

  ini = fim = NULL;
}

float obter(struct funcionario *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->salario;
}

int tamanho(){
    struct funcionario *aux = ini;
    int tam = 0;
    
    while (aux){
        tam++;
        aux = aux->prox;
    }
    
    return tam;
} 

void imprimir(){
  struct funcionario *aux = ini;
 
  while (aux){
	printf("Nome do funcionario: %s\nOcupacao: %s\nSalario: %.2f\n\n", aux->nome, aux->ocupacao, aux->salario);
	aux = aux->prox;
  }
}