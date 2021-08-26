/*   82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.
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
void elimDuplicados_1(TLista L);
void elimDuplicados_2(TLista *L);


int main() {
    TLista L;

    cargarLista(&L, "lista.txt");
    printLista(L);
    elimDuplicados_2(&L);
    printLista(L);
    return 0;
}


void elimDuplicados_2(TLista *L) {
    TLista act, ant, aux, elim;
    int elimine;

    if (*L != NULL) {
        while (*L != NULL && (*L)->sig != NULL && (*L)->dato == (*L)->sig->dato) {
            while ((*L)->sig != NULL && (*L)->dato == (*L)->sig->dato) {
                elim = *L;
                *L = (*L)->sig;
                free(elim);
            }
            elim = *L;
            *L = (*L)->sig;
            free(elim);
        }
        if ( *L != NULL && (*L)->sig != NULL) {
            aux = *L;
            ant = (*L)->sig;
            act = ant->sig;
            while (act != NULL) {
                elimine = 0;
                while (act != NULL && ant->dato == act->dato) {
                    elimine = 1;
                    ant->sig = act->sig;
                    free(act);
                    act = ant->sig;
                }
                if (elimine) {
                    aux->sig = act;
                    free(ant);
                    ant = act;
                    if (act != NULL)
                        act = act->sig;
                } else {
                    aux = ant;
                    ant = act;
                    act = act->sig;
                }
            }
        }
    }
}


void elimDuplicados_1(TLista L) {
// Elimina los nodos repetidos, deja solo uno de los que se encuentran repetidos
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

    if (L != NULL) {
        printf("[ ");
        while (L != NULL) {
            printf("%d ", L->dato);
            L = L->sig;
        }
        printf("]\n");

    }
}
