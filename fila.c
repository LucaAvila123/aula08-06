#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include "fila.h"
#include "pilha.h"

struct cel{
    tAluno* aluno;
    Celula* prox;
    int indice;
};

struct fila{
    Celula* prim;
    Celula* ult;
    int tamanhoMAX;
    int ondeEsta;
};

tFila* inicializaFila(int tamanhoMAX){
    tFila* fila = (tFila*) malloc ((tamanhoMAX+1)*sizeof(tFila));
    fila->prim = NULL;
    fila->ult = NULL;
    return fila;
}

void pushFila(tFila* fila, tAluno* aluno){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->aluno = aluno;
    //aqui temos uma condição de fila vazia
    if(fila->ult->indice == fila->tamanhoMAX && fila->prim != NULL){
        printf("A fila ta cheia, amigao\n");
        return;
    }
    if(fila->prim == NULL && fila->ult == NULL){
        fila->prim = nova;
        fila->ult = nova;
        fila->prim->indice = fila->ult->indice = 0;
    }
    //adicionando gente no final da fila
    else{
        fila->ult->prox = nova;
        fila->ult = nova;
        fila->ult->indice++;
        //quando a fila está chegando ao fim, mas tem espaço pra ela, a gente deixa circular
        if(fila->ult->indice > fila->tamanhoMAX && fila->prim == NULL){
            fila->ult->indice = 0;
            fila->prim = fila->ult;
        }
        fila->ult->prox = NULL;
    }
}
void popFila(tFila* fila);
int taVaziaFila(tFila* fila);
void imprimeFila(tFila* fila);
void liberaFila(tFila* fila);