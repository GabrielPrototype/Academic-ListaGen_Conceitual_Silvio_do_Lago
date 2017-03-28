/*
 * Exibição e outras funções para demostrar Lista Generalizadas de
 * Silvio do Lago Pereira.
 */

/* 
 * File:   Display_ListaGen_S_Lagos.h
 */

#ifndef DISPLAY_LISTAGEN_S_LAGOS_H
#define DISPLAY_LISTAGEN_S_LAGOS_H

#include <stdio.h>

#include "ListaGen_S_Lagos.h"
#include "Pilha_ListaGen_S_Lagos.h"

void Exibe_Atomo(ListaGen *Lista) {

    if (!isNula(Lista)) {
        if (isAtomo(Lista))
            printf("%s", Lista->no.info);
        else {
            Exibe_Atomo(Head(Lista));
            Exibe_Atomo(Tail(Lista));
        }
    }
};

void Exibe(ListaGen *Lista) {

    if (!isNula(Lista)) {
        if (isAtomo(Lista))
            printf("%s", Lista->no.info);
        else {
            printf("[");
            while (!isNula(Lista)) {
                Exibe(Head(Lista));
                Lista = Tail(Lista);
                if (!isNula(Lista))
                    printf(",");
            }
            printf("]");
        }
    }
};


#endif /* DISPLAY_LISTAGEN_S_LAGOS_H */

