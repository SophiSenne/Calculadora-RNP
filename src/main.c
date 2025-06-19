#include "functions.h"
#include "pilha.h"

int main(){

    Pilha pilha;
    inicializaPilha(&pilha);

    lerValores(&pilha);

    mostrarResultadoFinal(&pilha);

    return 0;
}