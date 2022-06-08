#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"
#include "aluno.h"

struct pilha{
    tAluno** elementos;
    int tamanhoMAX;
    int topo;
};

tPilha* inicializaPilha(int tamanhoMAX){
    tPilha* pilha = (tPilha*) malloc (sizeof(tPilha));
    pilha->elementos = (tAluno**) malloc ((tamanhoMAX+1)*sizeof(tAluno*));
    pilha->tamanhoMAX = tamanhoMAX;
    pilha->topo = 0;

    return pilha;
}

void push(tPilha* pilha, tAluno* aluno){
    if(!pilha || pilha->topo > pilha->tamanhoMAX) return;

    pilha->elementos[pilha->topo] = aluno;
    pilha->topo++;

}
void pop(tPilha* pilha){
    if(taVazia(pilha)) return;
    
    //int retorno = pilha->elementos[pilha->topo-1];
    pilha->topo--;

    //return retorno;
}
int taVazia(tPilha* pilha){
    if(pilha->topo == -1) return 1;
    else return 0;
}
void imprime(tPilha* pilha){
    for(int i=pilha->topo-1; i>=0; i--){
        imprimeAluno(pilha->elementos[i]);
    }
}
void libera(tPilha* pilha){
    for(int i=pilha->topo-1; i>=0; i--){
        larga(pilha->elementos[i]);
    };
    free(pilha);
}
