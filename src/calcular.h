#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#ifndef calcular_H
#define calcular_H

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
                printf(RED "Erro: Divisão por zero\n" RESET);
                return;
            }
            res = a / b;
            break;
        default:
            printf(RED "Operador desconhecido: %s\n" RESET, operador);
            return;
    }
    push(pilha, res);

}

void lerValores(Pilha *pilha){
    char *str = NULL;
    int size = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        char *temp = realloc(str, size + 1);
        if (temp == NULL) {
            printf(RED "Falha na alocação da memória\n" RESET);
            free(str);
            return;
        }

        str = temp;
        str[size] = ch;
        size++;
    }

    char *temp = realloc(str, size + 1);
    if (temp == NULL) {
        printf(RED "Falha na alocação da memória\n" RESET);
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
                printf(RED "Entrada inválida: %s\n" RESET, token);
            }
        }

        token = strtok(NULL, delimitador);
    }

    free(str);
}

#endif