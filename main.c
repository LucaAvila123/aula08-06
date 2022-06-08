#include "pilha.h"
#include <stdio.h>
void main(){
    tPilha* pilha = inicializaPilha(10);

    tAluno* maria = inicializaAluno("Maria", 1);
    tAluno* jose  = inicializaAluno("Jose", 2);
    tAluno* zeca  = inicializaAluno("Zeca", 3);
    
    push(pilha, maria);
    push(pilha, jose);
    push(pilha, zeca);
    
    pop(pilha);

    imprime(pilha);

    libera(pilha);
}