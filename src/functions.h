#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#ifndef functions_h
#define functions_h

void calcular(char *operador, Pilha *pilha){
    int b = pop(pilha);
    int a = pop(pilha);
    int res;
    switch (*operador) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
                return;
            }
            res = a / b;
            break;
        default:
            printf("Operador desconhecido: %s\n", operador);
            return;
    }
    push(pilha, res);

}

void lerValores(Pilha *pilha){
    char *str = NULL;
    int size = 0;
    int ch;

    printf("Insira sua expressão em RPN:\n");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        char *temp = realloc(str, size + 1);
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return;
        }

        str = temp;
        str[size] = ch;
        size++;
    }

    char *temp = realloc(str, size + 1);
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        free(str);
        return;
    }
    str = temp;
    str[size] = '\0';

    const char delimitador[] = " ";

    char *token = strtok(str, delimitador);

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            calcular(token, pilha);
        } else {
            char *endptr;
            int number = strtol(token, &endptr, 10);

            if (*endptr == '\0') {
                push(pilha, number);
            } else {
                printf("Invalid token: %s\n", token);
            }
        }

        token = strtok(NULL, delimitador);
    }

    free(str);
}

void mostrarResultadoFinal(Pilha *pilha){
    if (!estaVazia(pilha)) {
        printf("Resultado final: %d\n", pilha->elementos[pilha->topo]);
    } else {
        printf("A pilha está vazia. Nenhum resultado para mostrar.\n");
    }
}

#endif