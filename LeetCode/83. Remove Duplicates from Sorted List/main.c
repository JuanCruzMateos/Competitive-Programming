/*   83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;
typedef nodo* TLista;

void cargarLista(TLista *L, char* fname);
void printLista(TLista L);
void elimiarDuplicados(TLista L);
TLista deleteDuplicates(TLista head);

int main() {
    TLista L;

    cargarLista(&L, "lista.txt");
    printLista(L);
    elimiarDuplicados(L);
    printLista(L);


    return 0;
}


void elimiarDuplicados(TLista L) {
    TLista ant, act;

    if (L != NULL) {
        ant = L;
        act = L->sig;
        while (act != NULL) {
            if (ant->dato == act->dato) {
                ant->sig = act->sig;
                free(act);
                act = ant->sig;
            } else {
                ant = act;
                act = act->sig;
            }
        }
    }
}


//void elimiarDuplicados(TLista L) {
//    TLista ant, act, elim;
//
//    if (L != NULL) {
//        ant = L;
//        act = L->sig;
//        while (act != NULL) {
//            while (act != NULL && ant->dato == act->dato) {
//                elim = act;
//                ant->sig = act->sig;
//                act = act->sig;
//                free(elim);
//            }
//            if (act != NULL) {
//                ant = act;
//                act = act->sig;
//            }
//        }
//    }
//}

TLista deleteDuplicates(TLista head) {
    TLista act, ant, elim;

    if (head == NULL)
        return NULL;
    else {
        ant = head;
        act = head->sig;
        while (act != NULL) {
            while (act != NULL && ant->dato == act->dato) {
                elim = act;
                ant->sig = act->sig;
                act = act->sig;
                free(elim);
            }
            if (act != NULL) {
                ant = act;
                act = act->sig;
            }
        }
        return head;
    }
}


void cargarLista(TLista *L, char* fname) {
    FILE* txt;
    TLista nodoNuevo;
    int x;

    txt = fopen(fname, "r");
    if (txt == NULL)
        printf("Error en la lectura del archivo: no existe");
    else { // existe el archivo
        *L = NULL;
        if (fscanf(txt, "%d", &x) == 1) { // si no esta vacio
            nodoNuevo = (TLista) malloc(sizeof(nodo));
            nodoNuevo->dato = x;
            *L = nodoNuevo;
            while (fscanf(txt, "%d", &x) == 1) {
                nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
                nodoNuevo = nodoNuevo->sig;
                nodoNuevo->dato = x;
            }
            nodoNuevo->sig = NULL;
        }
        fclose(txt);
    }
}

void printLista(TLista L) {

    while (L != NULL) {
        printf("%d ", L->dato);
        L = L->sig;
    }
    printf("\n");
}
