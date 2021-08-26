/* 19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(TLista *L, char *fname);
void printLista(TLista L);
void elimiarDelFinal(TLista *L, int n);
void elimiarDelFinal_2P(TLista *L, int n);

int main(void) {
    TLista L;
    int x;


    cargarLista(&L, "lista.txt");
    printLista(L);
    printf("Ingrese posicion a borrar desde el final: ");
    scanf("%d", &x);
    elimiarDelFinal(&L, x);
    printLista(L);
    printf("Ingrese posicion a borrar desde el final: ");
    scanf("%d", &x);
    elimiarDelFinal_2P(&L, x);
    printLista(L);
    return 0;
}


void cargarLista(TLista *L, char *fname) {
    FILE *txt;
    TLista nodoNuevo;
    int x;

    txt = fopen(fname, "r");
    if (txt == NULL)
        printf("Error en la lectura del archivo: no existe");
    else {
        *L = NULL;
        if (fscanf(txt, "%d", &x) == 1) {
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


void elimiarDelFinal(TLista *L, int n) {
// OBS: - realizo dos pasadas sobre la lista
//      - O(N): lineal, (N = L = largo de la lista)
    TLista act, ant;
    int len = 0, i;

    if (*L != NULL) {
        act = *L;
        while (act != NULL) {   // busco el largo de la lista
            len++;
            act = act->sig;
        }
        if (len == n) {         // modifico la cabeza: el que quiero borrar coincide con len ==> es el primero
            act = *L;
            *L = (*L)->sig;
            free(act);
        } else if (n < len) {   // no modifico la cabeza: busco con ant y act y elimino. OBS: si n > len ==> n invalido
            act = *L;
            for (i=0; i<len-n; i++) {
                ant = act;
                act = act->sig;
            }
            ant->sig = act->sig;
            free(act);
        }
    }
}


void elimiarDelFinal_2P(TLista *L, int n) {
    TLista pri, ult, aux;
    int i;

    if (*L != NULL) {
        ult = *L;
        i = 0;
        while (ult != NULL && i < n) {
            i++;
            ult = ult->sig;
        }
        if (ult == NULL) {  // si ult == NULL => n invalido o modifico el primero
            if (i == n) {   // si i == n ==> modifico la cabeza
                aux = *L;
                *L = (*L)->sig;
                free(aux);
            }              // si i != n ==> llegue al final antes de la posicion indicada ==>  n no valido
        } else {
            pri = *L;
            while (ult != NULL) {
                aux = pri;
                pri = pri->sig;
                ult = ult->sig;
            }
            aux->sig = pri->sig;
            free(pri);
        }
    }
}


//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//    struct ListNode* act, *ant;
//    int len = 0, i;
//
//    if (head != NULL) {
//        act = head;
//        while (act != NULL) {
//            len++;
//            act = act->next;
//        }
//        if (len == n) {
//            act = head;
//            head = head->next;
//            free(act);
//        } else if (n < len) {
//            act = head;
//            for (i=0; i<len-n; i++) {
//                ant = act;
//                act = act->next;
//            }
//            ant->next = act->next;
//            free(act);
//        }
//    }
//    return head;
//}
