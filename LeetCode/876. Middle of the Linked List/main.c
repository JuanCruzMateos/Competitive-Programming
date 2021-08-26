/* Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node. */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void crearLista(TLista *L, int cantNodos);
void mostrarLista(TLista L);
void dividirLista(TLista L1, TLista *L2);

int main(void) {
    TLista L, L_med;

    crearLista(&L, 10);
    mostrarLista(L);
    dividirLista(L, &L_med);
    mostrarLista(L);
    mostrarLista(L_med);
    return 0;
}


void crearLista(TLista *L, int cantNodos) {
    TLista nodoNuevo, head;
    int i;

    head = (TLista) malloc(sizeof(nodo));
    head->sig = NULL;
    nodoNuevo = head;
    for (i=0; i<cantNodos; i++) {
        nodoNuevo->sig = (TLista) malloc (sizeof(nodo));
        nodoNuevo = nodoNuevo->sig;
        nodoNuevo->dato = i+1;
    }
    nodoNuevo->sig = NULL;
    *L = head->sig;
    free(head);            // MUY IMPORTANTE!!! ===> NO OLVIDAR ELIMINAR EL NODO AUXILIAR
}


void mostrarLista(TLista L) {
    while (L != NULL) {
        printf("%d ", L->dato);
        L = L->sig;
    }
    printf("\n");
}


void dividirLista(TLista L1, TLista *L2) {
    TLista ult, div;

    if (L1 != NULL) {
        div = L1;
        ult = L1->sig;
        while (ult != NULL) {
            ult = ult->sig;
            if (ult != NULL) {
                div = div->sig;
                ult = ult->sig;
            }
        }
        *L2 = div->sig;
        div->sig = NULL;
    }
}
