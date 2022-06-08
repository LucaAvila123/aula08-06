#ifndef FILA_H
#define FILA_H

#include "aluno.h"

typedef struct cel Celula;
typedef struct fila tFila;

tFila* inicializaFila(int tamanhoMAX);

void pushFila(tFila* fila, tAluno* aluno);
void popFila(tFila* fila);
int taVaziaFila(tFila* fila);
void imprimeFila(tFila* fila);
void liberaFila(tFila* fila);

#endif