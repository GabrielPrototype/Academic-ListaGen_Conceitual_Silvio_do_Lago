/*
 * Pilha para o modelo conceitual de lista gen de Silvio do Lago Pereira.
 */

/* 
 * File:   Pilha_ListaGen_S_Lagos.h
 */

#ifndef PILHA_LISTAGEN_S_LAGOS_H
#define PILHA_LISTAGEN_S_LAGOS_H

#include <stddef.h>
#include "Pilha_ListaGen_S_Lagos.h"

struct pilha {
    ListaGen *Lista;
    struct pilha *ant;
};

typedef struct pilha Pilha;

void init(Pilha **P) {
    *P = NULL;
}

char isEmpty(Pilha *P) {
    return P == NULL;
}

ListaGen* Top(Pilha *P) {
    if (!isEmpty(P))
        return P->Lista;
    return NULL;
}

void Push(Pilha **P, ListaGen *L) {
    Pilha *nova = (Pilha*) malloc(sizeof (Pilha));
    nova->Lista = L;
    nova->ant = *P;
    *P = nova;
}

void Pop(Pilha **P, ListaGen **L) {
    Pilha *aux;
    if (!isEmpty(*P)) {
        aux = *P;
        *L = (*P)->Lista;
        *P = (*P)->ant;
        free(aux);
    } else *L = NULL;
}

#endif /* PILHA_LISTAGEN_S_LAGOS_H */

