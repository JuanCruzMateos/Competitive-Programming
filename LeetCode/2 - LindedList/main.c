/* 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of
their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;
typedef nodo* TLista;

TLista addTwoNumbers_1(TLista l1, TLista l2);
TLista addTwoNumbers_2(TLista l1, TLista l2);
void copyList(TLista L, TLista *LC);
void cargarLista(TLista *L, char* nomArch);
void printLista(TLista L);


int main() {
    TLista L1, L2, L3;

    cargarLista(&L1, "n1.txt");
    cargarLista(&L2, "n2.txt");
    printLista(L1);
    printLista(L2);

    L3 = addTwoNumbers_1(L1, L2);
    printLista(L3);
    return 0;
}

TLista addTwoNumbers_1(TLista l1, TLista l2) {
    TLista L3, nodoNuevo;
    int suma, resto = 0;

    if (l1 == NULL && l2 == NULL)
        return NULL;
    else {
        if (l1 == NULL)
            copyList(l2, &L3);
        else if (l2 == NULL)
            copyList(l1, &L3);
        else {
            nodoNuevo = (TLista) malloc(sizeof(nodo));
            L3 = nodoNuevo;
            suma = l1->dato + l2->dato + resto;
            nodoNuevo->dato = suma % 10;
            resto = suma / 10;
            l1 = l1->sig;
            l2 = l2->sig;
            while (l1 != NULL && l2 != NULL) {
                nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
                nodoNuevo = nodoNuevo->sig;
                suma = l1->dato + l2->dato + resto;
                nodoNuevo->dato = suma % 10;
                resto = suma / 10;
                l1 = l1->sig;
                l2 = l2->sig;
            }
            if (l1 == NULL)
                l1 = l2;
            while (l1 != NULL ) {
                nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
                nodoNuevo = nodoNuevo->sig;
                suma = l1->dato + resto;
                nodoNuevo->dato = suma % 10;
                resto = suma / 10;
                l1 = l1->sig;
            }
            if (resto != 0) {
                nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
                nodoNuevo = nodoNuevo->sig;
                nodoNuevo->dato = resto;
            }
            nodoNuevo->sig = NULL;
        }
        return L3;
    }
}


TLista addTwoNumbers_2(TLista l1, TLista l2) {
    TLista L3, nodoNuevo;
    int suma, resto = 0;

    if (l1 == NULL && l2 == NULL)
        return NULL;
    else {
        nodoNuevo = (TLista) malloc(sizeof(nodo));
        L3 = nodoNuevo;
        suma = l1->dato + l2->dato + resto;
        nodoNuevo->dato = suma % 10;
        resto = suma / 10;
        l1 = l1->sig;
        l2 = l2->sig;
        while (l1 != NULL || l2 != NULL) {
            nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
            nodoNuevo = nodoNuevo->sig;
            if (l1 != NULL && l2 != NULL) {
                suma = l1->dato + l2->dato + resto;
                l1 = l1->sig;
                l2 = l2->sig;
            } else if (l1 != NULL) {
                suma = l1->dato + resto;
                l1 = l1->sig;
            } else {
                suma = l2->dato + resto;
                l2 = l2->sig;
            }
            nodoNuevo->dato = suma % 10;
            resto = suma / 10;
        }
        if (resto != 0) {
            nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
            nodoNuevo = nodoNuevo->sig;
            nodoNuevo->dato = resto;
        }
        nodoNuevo->sig = NULL;
        return L3;
    }
}

void copyList(TLista L, TLista *LC) {
    TLista nodoNuevo;

    if (L == NULL)
        *LC = NULL;
    else {
        nodoNuevo = (TLista) malloc(sizeof(nodo));
        nodoNuevo->dato = L->dato;
        *LC = nodoNuevo;
        L = L->sig;
        while (L != NULL) {
            nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
            nodoNuevo = nodoNuevo->sig;
            nodoNuevo->dato = L->dato;
            L = L->sig;
        }
        nodoNuevo->sig = NULL;
    }
}

void cargarLista(TLista *L, char* nomArch) {
    FILE* txt;
    int num;
    TLista nodoNuevo;

    *L = NULL;
    txt = fopen(nomArch, "r");
    if (txt == NULL)
        printf("Error en la lectura del arhcivo: no existe");
    else {
        while (fscanf(txt, "%d", &num) == 1) {
            nodoNuevo = (TLista) malloc(sizeof(nodo));
            nodoNuevo->dato = num;
            nodoNuevo->sig = *L;
            *L = nodoNuevo;
        }
        fclose(txt);
    }
}


void printLista(TLista L) {

    while (L != NULL) {
        printf("%d ",L->dato);
        L = L->sig;
    }
    printf("\n");
}
