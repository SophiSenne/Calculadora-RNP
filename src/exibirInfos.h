#include <stdio.h>
#include "pilha.h"

#ifndef exibirInfos_H
#define exibirInfos_H

#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void iniciar() {
    printf(CYAN "========================================\n");
    printf("            CALCULADORA RPN           \n");
    printf("========================================\n" RESET);
    printf("Esta aplicação resolve expressões na notação\n");
    printf("polonesa reversa (RPN - Reverse Polish Notation).\n\n");
    printf(GREEN "Instruções:\n" RESET);
    printf(" - Digite os números e operadores separados por espaços\n");
    printf(" - Os operadores disponíveis são: +  -  *  /\n");
    printf(" - Exemplo: 5 3 + 2 *    (resultado = 16)\n\n");
    printf(CYAN "----------------------------------------\n" RESET);
    printf("Digite sua expressão abaixo e pressione ENTER:\n");
}


void mostrarResultadoFinal(Pilha *pilha){
    if (!estaVazia(pilha)) {
        printf("Resultado final: %d\n", pilha->elementos[pilha->topo]);
    } else {
        printf("A pilha está vazia. Nenhum resultado para mostrar.\n");
    }
}

#endif