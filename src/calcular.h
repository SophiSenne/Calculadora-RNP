#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#ifndef calcular_H
#define calcular_H

void calcular(char *operador, Pilha *pilha){
    // Desempilha os dois operandos do topo da lista
    int b = pop(pilha);
    int a = pop(pilha);

    // Variável para armazenar o resultado da operação
    int res;

    // Realiza a operação de acordo com o operando
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

    // Empilha o resultado da operação
    push(pilha, res);

}

void lerValores(Pilha *pilha){
    char *str = NULL;
    int size = 0;
    int ch;

    // Lê a expressão inserida pelo usuário e a armazena em str
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

    // "Quebra" a expressão em valores de acordo com os espaços 
    const char delimitador[] = " ";
    char *token = strtok(str, delimitador);

    // Para cada um dos valores, verifica se é operando, número ou inválido
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