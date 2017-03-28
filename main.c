/*
 * Exemplos com lista generalizada conceitual de Silvio do Lago Pereira
 */

/* 
 * File:   main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "ListaGen_S_Lagos.h"
#include "Pilha_ListaGen_S_Lagos.h"
#include "Display_ListaGen_S_Lagos.h"
/*
 * 
 */

int main(int argc, char** argv) {

    teste_listaGen();
    return (EXIT_SUCCESS);
}

void insere(ListaGen **Lista) {
    char str[200];
    gets(str);
    
    

};

void insere_seq_vazia(ListaGen **Lista) {

    ListaGen *aux;
    
    
    *Lista =    Cons(
                    Cons(
                        CriaAtomo("A"),
                        NULL
                    ),
                    Cons(
                        CriaAtomo("B"),
                        NULL
                    )
                );
    

    
    printf("\n\n\n");
    
    Exibe(*Lista);
    
    printf("\n\n\n");
   
    Exibe_Atomo(*Lista);
};

void teste_listaGen(){

    ListaGen *Lista01;
    
    insere_seq_vazia(&Lista01);


}