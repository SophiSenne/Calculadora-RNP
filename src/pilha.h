#include <stdio.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#ifndef pilha_H
#define pilha_H

#define MAX 100

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *pilha){
    pilha->topo = -1;    
}

int estaVazia(Pilha *pilha){
    if (pilha->topo < 0)
        return 1;
    return 0;
}

void push(Pilha *pilha, int valor){
    if (pilha->topo >= MAX - 1){
        printf(RED "Erro: Pilha cheia\n" RESET);
        return;
    }

    pilha->elementos[++pilha->topo] = valor;
}

int pop(Pilha *pilha){
    if (estaVazia(pilha)) {
        printf(RED "Erro: Pilha vazia\n" RESET);
        return 0;
    }

    int elemento = pilha->elementos[pilha->topo];
    pilha->topo--;
    return elemento;
}

#endif