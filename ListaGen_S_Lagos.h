/*
 * Modelo de lista generalizada conceitual por Silvio do Lago Pereira
 */

/* 
 * File:   ListaGen_S_Lagos.h
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

ListaGen *CriaNo() {

    ListaGen *Lst = (ListaGen*) malloc(sizeof (ListaGen));
    Lst->terminal = 0;
    return Lst;
};

char isNula(ListaGen *Lista) {
    return Lista == NULL;
};

char isAtomo(ListaGen *Lista) {
    
    if(!isNula(Lista))
        return Lista->terminal == 1;
    else
        return 0;
};

ListaGen *Head(ListaGen *Lista) {
    if (isNula(Lista) || isAtomo(Lista))
        return NULL; //Uma lista Nula ou Atomo não pode ser Head.

    return Lista->no.lista.head; //finalmente se passar pelo criterio de não
    //ser nula e não ser atomo, ela é Head
};

ListaGen *Tail(ListaGen *Lista) {

    return Lista->no.lista.tail;
}

ListaGen* Cons(ListaGen *head, ListaGen *tail) {
    if (!isAtomo(tail)) {
        ListaGen *L = (ListaGen*) malloc(sizeof (ListaGen));
        L->terminal = 0;
        L->no.lista.head = head;
        L->no.lista.tail = tail;
        return L;
    } else // caso o parametro tail tenha incorretamente recebido um atomo.       
        return NULL;
}

void destruir_recursivo(ListaGen **Lista) {
    if (!isNula(*Lista)) {
        if (isAtomo(*Lista))
            free(*Lista);
        else {
            destruir_recursivo(&(*Lista)->no.lista.head);
            destruir_recursivo(&(*Lista)->no.lista.tail);
            free(*Lista);
            *Lista = NULL;
        }
    }
};

void destruir_iterativo(ListaGen *Lista) {
    ListaGen *aux;
    Pilha *pilha;
    init(&pilha);
    Push(&pilha, Lista);
    while (!isEmpty(pilha)) {
        if (!isNula(Lista)) {
            Pop(&pilha, &Lista);
        }
        while (!isNula(Lista)&&!isAtomo(Lista)) {
            Push(&pilha, Lista);
            Lista = Head(Lista);
        }
        if (isAtomo(Lista))
            free(Lista);
        Pop(&pilha, &Lista);
        aux = Lista;
        Lista = Tail(Lista);
        if (isNula(Lista)) {
            Pop(&pilha, &Lista);
            free(aux);
        }
    }
}

int calcula_comprimento(ListaGen *Lista) {
    int Cont = 0;

    while (!isNula(Lista)) {
        Cont++;
        Lista = Tail(Lista);
    }

    return Cont;
}

int calcula_profundidade(ListaGen *List) {
    Pilha *pilha;
    init(&pilha);
    int Cont = 0, Andar = 0;
    Push(&pilha,List);
    while (!isEmpty(pilha)) {
        if (!isNula(List)) {
            Pop(&pilha, &List);
            while (!isNula(List) && !isAtomo(List)) {
                Push(&pilha, List);
                List = Head(List);
                Andar++;
                if (Cont < Andar)
                    Cont = Andar;
            }
        }
        Pop(&pilha, &List);
        Andar--;
        List = Tail(List);
        if (!isNula(List))
            Push(&pilha, List);
    }
    return Cont;
}

ListaGen *Duplica (ListaGen *Lista){
	if(isNula(Lista))
		return NULL;
	if(isAtomo(Lista))
		return (CriaAtomo(Lista->no.info));
		
	return Cons(Duplica(Head(Lista)),Duplica(Tail(Lista)));
}


char Compara(ListaGen *Lista, ListaGen *Lista2){
	if(isNula(Lista) && isNula(Lista2))
		return 1;
	if(isNula(Lista) || isNula(Lista2))
		return 0;
	if(isAtomo(Lista) && isAtomo(Lista2))
		return !strcmp(Lista->no.info,Lista2->no.info);
	
	if(isAtomo(Lista) || isAtomo(Lista2))
		return 0;
		
	return Compara(Head(Lista),Head(Lista2)) && Compara(Tail(Lista),Tail(Lista2));
}
#endif /* LISTAGEN_S_LAGOS_H */

