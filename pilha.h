#ifndef PILHA_H
#define PILHA_H

#include "aluno.h"

typedef struct pilha tPilha;

tPilha* inicializaPilha(int tamanhoMAX);

void push(tPilha* pilha, tAluno* aluno);
void pop(tPilha* pilha);
int taVazia(tPilha* pilha);
void imprime(tPilha* pilha);
void libera(tPilha* pilha);

#endif