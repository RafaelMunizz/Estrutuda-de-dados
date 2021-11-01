#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct controleAereo {
  int voo, quantPassageiros;
  char modelo[15], piloto[15];
  struct controleAereo  *prox;
};

struct controleAereo  *ini = NULL, *fim = NULL;

void adicionar(int voo, char *modelo, char *piloto, int quantPassageiros); //Adicionar aviao a fila
void quantAvioes(); // Exibir a quantidade de avioes em espera
void autorizar(); // Autorizar a decolagem do primeiro aviao
void listarAvioes(); // Listar todos os aviões
void infoAviao(); // Listar as informacoes do primeiro aviao
void limparFila(); // Limpar todos os avioes cadastrados

int main(void) {

    adicionar(1, "Comercial1", "Piloto1", 30);
    adicionar(2, "Comercial2", "Piloto2", 40);
    adicionar(3, "Comercial3", "Piloto3", 50);

    quantAvioes();
    listarAvioes();
    infoAviao();

    autorizar();

    quantAvioes();
    infoAviao();
    return 0;
}

void adicionar(int voo, char *modelo, char *piloto, int quantPassageiros) {
  struct controleAereo  *Aviao = (struct controleAereo *) malloc(sizeof(struct controleAereo ));
  Aviao->voo = voo;
  strcpy(Aviao->modelo, modelo);
  strcpy(Aviao->piloto, piloto);
  Aviao->quantPassageiros = quantPassageiros;
  Aviao->prox = NULL;

  if (!ini)
	ini = fim = Aviao;
  else{
	fim->prox = Aviao;
	fim = Aviao;
  }
}

void autorizar(){
  if (ini) {
	int voo = ini->voo;
	struct controleAereo  *tmp = ini;
    
	if (ini == fim)
  	   ini = fim = NULL;
	else
  	   ini = ini->prox;

	free(tmp);

	printf("\n\nVoo numero %d autorizado para voo", voo);

  } else {
	printf("\n\nNao ha avioes para autorizar. Fila vazia.");
	exit(1);
  }
}

void limparFila(){
  struct controleAereo  *aux = ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

void quantAvioes(){
  struct controleAereo  *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
    printf("\n\nQuantidade de avioes em espera: %d", tam);
}

void listarAvioes(){
  struct controleAereo  *aux = ini;
 
  while (aux){
	printf("\n\nNumero do voo: %d\nNome do piloto: %s", aux->voo, aux->piloto);
	aux = aux->prox;
  }
}

void infoAviao(){

    if (ini) {
        printf("\n\n# Proximo aviao a decolar:");
        printf("\nNumero do voo: %d\nModelo da aeronave: %s\nNome do piloto: %s\nNumero de passageiros: %d", ini->voo, ini->modelo, ini->piloto, ini->quantPassageiros);
    }
}