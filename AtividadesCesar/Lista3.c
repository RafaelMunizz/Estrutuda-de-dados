#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char *nome;
	int idade;
    float altura;
}TAluno;

TAluno* criarAluno (char *nome, int idade, float altura);
void liberarAluno (TAluno *var);
void imprimirDados (TAluno *var); 
void modificarDados (TAluno *var, char *novo_nome, int nova_idade, float nova_altura);

void main() {

    TAluno *primeiroAluno, *segundoAluno, *terceiroAluno;

    primeiroAluno = criarAluno("Rafael", 21, 1.75);
    segundoAluno = criarAluno("Maria", 18, 1.60);
    terceiroAluno = criarAluno("Gabriel", 16, 1.70);

    /* imprimirDados(primeiroAluno);
    imprimirDados(segundoAluno);
    imprimirDados(terceiroAluno); */

    modificarDados(primeiroAluno, "Victor", 22, 1.80);
    liberarAluno(segundoAluno);
    liberarAluno(terceiroAluno);

    printf("*******************************");

    imprimirDados(primeiroAluno);
    imprimirDados(segundoAluno);

    imprimirDados(terceiroAluno);
}

TAluno* criarAluno (char *nome, int idade, float altura){
    TAluno *aux = NULL;

    if( ( aux = (TAluno*) malloc( sizeof(TAluno) ) ) == NULL ) return NULL;

    aux -> nome = nome;
    aux -> idade = idade;
    aux -> altura = altura;

    return aux;
}

void liberarAluno (TAluno *var) { 

    if( var != NULL ){
        var -> nome = 0;
        var -> idade = 0;
        var -> altura = 0;
        free(var);
    }
}

void imprimirDados (TAluno *var){

    if(var->nome) {
        printf("\n");
        printf( "Nome: %s", var->nome );
        printf( "\nIdade: %d", var->idade );
        printf( "\nAltura: %.2f", var->altura );
        printf("\n");

    } else {
        printf( "\nO aluno nao existe\n" );
    }
} 

void modificarDados (TAluno *var, char *novo_nome, int nova_idade, float nova_altura) {

    var -> nome = novo_nome;
    var -> idade = nova_idade;
    var -> altura = nova_altura;
}