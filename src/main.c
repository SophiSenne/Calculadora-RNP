#include "calcular.h"
#include "pilha.h"
#include "exibirInfos.h"

int main(){

    iniciar();

    Pilha pilha;
    inicializaPilha(&pilha);

    lerValores(&pilha);

    mostrarResultadoFinal(&pilha);

    return 0;
}