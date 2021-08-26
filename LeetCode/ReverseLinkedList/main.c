#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;
typedef nodo* TLista;

void cargarLista(TLista *L, char *nomArch);
void mostrarLista(TLista L);
void mostrarOrdenInv(TLista L);
void reverse_copy(TLista L, TLista *LR);
void reverse_iter(TLista *L);
void reverse_rec(TLista *L, TLista act, TLista ant);
void selectionSort(TLista *L);

int main() {
    TLista L;
//    TLista LR;

    cargarLista(&L, "lista.txt");
    mostrarLista(L);
//    reverse_iter(&L);
    reverse_rec(&L, L, NULL);
    mostrarLista(L);
//    mostrarOrdenInv(L);
//    reverse_copy(L, &LR);
//    mostrarLista(LR);
    return 0;
}

void selectionSort(TLista *L) {


}


//void reverse_iter(TLista *L) {
// VERSION 1
//    TLista ant, act, aux;
//
//    if (*L != NULL) {
//        ant = *L;
//        act = (*L)->sig;
//        while (act != NULL) {
//            aux = act->sig;
//            act->sig = ant;
//            ant = act;
//            act = aux;
//        }
//        // reacomodo la cabeza y hago que la cola apunte a NULL
//        (*L)->sig = NULL;
//        *L = ant;
//    }
//}

void reverse_iter(TLista *L) {
    TLista ant, act, aux;

    ant = NULL;
    act = *L;
    while (act != NULL) {
        aux = act->sig;
        act->sig = ant;
        ant = act;
        act = aux;
    }
    *L = ant;
}


void reverse_rec(TLista *L, TLista act, TLista ant) {

    if (act != NULL) {
        if (act->sig == NULL)
            *L = act;
        else {
            reverse_rec(L, act->sig, act);
        }
        act->sig = ant;
    }
}


void reverse_copy(TLista L, TLista *LR) {
//crea una copia de la lista pero invertida
    TLista nodoNuevo;

    *LR = NULL;
    while (L != NULL) {
        nodoNuevo = (TLista) malloc(sizeof(nodo));
        nodoNuevo->dato = L->dato;
        nodoNuevo->sig = *LR;
        *LR = nodoNuevo;
        L = L->sig;
    }
}


void cargarLista(TLista *L, char *nomArch) {
    FILE *txt;
    TLista nodoNuevo;
    int cant, i, num;

    txt = fopen(nomArch, "r");
    if (txt == NULL)
        printf("Error en la lectura del archivo: no existe.\n");
    else {
        fscanf(txt, "%d", &cant);
        *L = NULL;
        for (i=0; i<cant; i++) {
            fscanf(txt, "%d", &num);
            nodoNuevo = (TLista) malloc(sizeof(nodo));
            nodoNuevo->dato = num;
            nodoNuevo->sig = *L;
            *L = nodoNuevo;
        }
        fclose(txt);
    }
}

void mostrarLista(TLista L) {

    while (L != NULL) {
        printf("%d ", L->dato);
        L = L->sig;
    }
    printf("\n");
}

void mostrarOrdenInv(TLista L) {

    if (L != NULL) {
        mostrarOrdenInv(L->sig);
        printf("%d ", L->dato);
    }
}
