/*
 * Modelo de lista generalizada conceitual por Silvio do Lago Pereira
 */

/* 
 * File:   ListaGen_S_Lagos.h
 * Author: titan
 *
 * Created on 27 de Março de 2017, 06:50
 */

#ifndef LISTAGEN_S_LAGOS_H
#define LISTAGEN_S_LAGOS_H

#include <string.h>


#define INFO_SIZE 8

struct reg_lista {
    struct listaGen *head;
    struct listaGen *tail;
};

union info_lista {
    char info[INFO_SIZE];
    struct reg_lista lista;
};

struct listaGen {
    char terminal;
    union info_lista no;

};

typedef struct listaGen ListaGen;

#include "Pilha_ListaGen_S_Lagos.h"

ListaGen *CriaAtomo(char *info) {

    ListaGen *Lst = (ListaGen*) malloc(sizeof (ListaGen));
    Lst->terminal = 1;
    strncpy(Lst->no.info, info, INFO_SIZE);
    return Lst;
};


char isNula(ListaGen *Lista){
    return Lista == NULL;
};

char isAtomo(ListaGen *Lista) {

    return Lista->terminal == 1;
};

ListaGen *Head(ListaGen *Lista) {
    if(isNula(Lista) || isAtomo(Lista))
        return NULL; //Uma lista Nula ou Atomo não pode ser Head.
    
    return Lista->no.lista.head;  //finalmente se passar pelo criterio de não
                                    //ser nula e não ser atomo, ela é Head
};

ListaGen *Tail(ListaGen *Lista) {

    return Lista->no.lista.tail;
}

void destruir_iterativo(ListaGen *Lista) {
    ListaGen *aux;
    Pilha *pilha;
    init(&pilha);
    Push(&pilha, Lista);
    while (!isEmpty(pilha)) {
        if (!isNula(Lista)) {
            Pop(&pilha, Lista);
        }
        while (!isNula(Lista)&&!isAtomo(Lista)) {
            Push(&pilha, Lista);
            Lista = Head(Lista);
        }
        if (isAtomo(Lista))
            free(Lista);
        Pop(&pilha, Lista);
        aux = Lista;
        Lista = Tail(Lista);
        if (isNula(Lista)) {
            Pop(&pilha, Lista);
            free(aux);
        }
    }
}

#endif /* LISTAGEN_S_LAGOS_H */

