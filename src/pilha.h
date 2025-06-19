#include <stdio.h>

#ifndef pilha_h
#define pilha_h

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
        printf("Erro: Pilha cheia\n");
        return;
    }

    pilha->elementos[++pilha->topo] = valor;
}

int pop(Pilha *pilha){
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return 0;
    }

    int elemento = pilha->elementos[pilha->topo];
    pilha->topo--;
    return elemento;
}

#endif