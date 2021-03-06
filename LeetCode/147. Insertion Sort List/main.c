/* 147. Insertion Sort List
Sort a linked list using insertion sort. */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void crearLista(TLista *L, char* fname);
void crearListaNoArch(TLista *L);
void printList(TLista L);

void selectionSortList(TLista L);
void insertionSortList(TLista *L);
void insercion(TLista *L);

TLista insercionLista(TLista head);

void insercion(TLista *L);
void insertarOrdenado(TLista *L, TLista nodoNuevo);

void merge(TLista L1, TLista L2, TLista *L3);
//void merge(TLista *L1, TLista *L2, TLista *L3);
//void merge(TLista *L1, TLista *L2);
void separar(TLista L1, TLista *L2);
void merge_sort(TLista *L);

int main(void) {
    TLista L, L2, L3;

    crearLista(&L, "lista.txt");
    printList(L);
//    insertionSortList(&L);
//    selectionSortList(L);
//    L = insercionLista(L);
//    insercion(&L);
//    merge_sort(&L);
//    printList(L);
    separar(L, &L2);
    printList(L);
    printList(L2);

//    merge(&L, &L2, &L3);
    merge(L, L2, &L3);
    printf("\n");
    printList(L);
    printList(L2);
    printList(L3);
    return 0;
}


void separar(TLista L1, TLista *L2) {
// Dividir la lista en dos en un solo recorrido -> O(N)
// IDEA: uso dos punteros => inicio) me posiciono en L y L->sig,  iter) avanzo ultimo, si != NULL ==> avanzo con los dos
// Por lo tanto => avanzo con el ultimo dos posiciones por cada posicion que avanza el primero
    TLista aux, ult;

    if (L1 != NULL) {
       if (L1->sig == NULL) {
            *L2 = NULL;
       } else {
            aux = L1;
            ult = L1->sig;
            while (ult != NULL) {
                ult = ult->sig;
                if (ult != NULL) {
                    ult = ult->sig;
                    aux = aux->sig;
                }
            }
            *L2 = aux->sig;
            aux->sig = NULL;
       }
    }
}


//void merge(TLista *L1, TLista *L2, TLista *L3) {
//    TLista aux;
//
//    if (*L1 != NULL && *L2 != NULL) {
//        if ((*L1)->dato < (*L2)->dato) {
//            aux = *L1;
//            *L1 = (*L1)->sig;
//        } else {
//            aux = *L2;
//            *L2 = (*L2)->sig;
//        }
//        *L3 = aux;
//        aux->sig = NULL;
//        while (*L1 != NULL && *L2 != NULL) {
//            if ((*L1)->dato < (*L2)->dato) {
//                aux->sig = *L1;
//                *L1 = (*L1)->sig;
//            } else {
//                aux->sig = *L2;
//                *L2 = (*L2)->sig;
//            }
//            aux = aux->sig;
//        }
//        if (*L1 != NULL) {
//            aux->sig = *L1;
//            *L1 = NULL;
//        }
//        if (*L2 != NULL){
//            aux->sig = *L2;
//            *L2 = NULL;
//        }
//    } else if (*L1 == NULL && *L2 != NULL) {
//        *L3 = *L2;
//        *L2 = NULL;
//    } else if (*L1 != NULL && *L2 == NULL) {
//        *L3 = *L1;
//        *L1 = NULL;
//    }
//}

void merge(TLista L1, TLista L2, TLista *L3) {
    TLista pri, ult;

    pri = (TLista) malloc(sizeof(nodo));  // uso un nodo auxiliar para evitar repeticion de codigo
    pri->sig = NULL;                      // en caso de que sean los dos NULL devuelvo NULL
    ult = pri;
    while (L1 != NULL && L2 != NULL) {
        if (L1->dato < L2->dato) {
            ult->sig = L1;
            L1 = L1->sig;
        } else {
            ult->sig = L2;
            L2 = L2->sig;
        }
        ult = ult->sig;
    }
    if (L1 != NULL)
        ult->sig = L1;
    if (L2 != NULL)
        ult->sig = L2;
    *L3 = pri->sig;
    free(pri);
}

void merge_sort(TLista *L) {
    TLista L2;//, L3;

    if (*L != NULL && (*L)->sig != NULL) {
        separar(*L, &L2);
        merge_sort(L);
        merge_sort(&L2);
        merge(*L, L2, L);
    }
}


// Inserion V1: mas complejo, voy analizando e insertando sobre la misma lista -> necesito mas ounteros
void insertionSortList(TLista *L) {
    TLista act, aux, antAct, antAux;
    int datoAux;

    if (*L != NULL && (*L)->sig != NULL) {   // si esta vacia o si tiene solo un nodo no hago nada
        antAct = *L;
        act = (*L)->sig;
        while (act != NULL) {
            aux = *L;
            while (aux != act && aux->dato < act->dato) {
                antAux = aux;
                aux = aux->sig;
            }
            if (aux != act) {
                if (aux->sig == act) {       // si son adyacentes intercambio los datos -> no se modifica la cabeza
                    datoAux= aux->dato;
                    aux->dato = act->dato;
                    act->dato = datoAux;
                } else {
                    antAct->sig = act->sig;
                    act->sig = aux;
                    if (aux == *L)
                        *L = act;
                    else
                        antAux->sig = act;
                    act = antAct;
                }
            }
            antAct = act;
            act = act->sig;
        }
    }
}


// Insercion V2: voy tomando nodos de la lista y los acomomodo en una lista nueva. al final asigno la lista original a esa nueva lista
void insercion(TLista *L) {
    TLista L_ord, nodo;

    L_ord = NULL;
    if (*L != NULL && (*L)->sig != NULL) {      // si tiene un nodo o niguno ==> ordenada
        while (*L != NULL) {                    // mientras que no se anule
            nodo = *L;                          // tomo el nodo de la cabeza
            *L = (*L)->sig;                     // avanzo con la lista (hasta que se haga NULL)
            insertarOrdenado(&L_ord, nodo);     // inseto el nodo en la lista auxiliar
        }
        *L = L_ord;                             // devuelvo la lista ordenada
    }
}


void insertarOrdenado(TLista *L, TLista nodoNuevo) {
    TLista ant, act;

    if (*L == NULL || (*L)->dato > nodoNuevo->dato) {      // caso I: modifico la cabeza
        nodoNuevo->sig = *L;
        *L = nodoNuevo;
    } else {                                               // caso II: no modifico la cabeza
        ant = *L;
        act = (*L)->sig;
        while (act != NULL && act->dato < nodoNuevo->dato) {
            ant = act;
            act = act->sig;
        }
        nodoNuevo->sig = act;
        ant->sig = nodoNuevo;
    }
}


TLista insercionLista(TLista head) {
/* Success Details:
Runtime: 36 ms, faster than 89.29% of C online submissions for Insertion Sort List.
Memory Usage: 6.6 MB, less than 77.38% of C online submissions for Insertion Sort List.
*/
    TLista act, aux, antAct, antAux;
    int datoAux;

    if (head != NULL && head->sig != NULL) {
        antAct = head;
        act = head->sig;
        while (act != NULL) {
            aux = head;
            while (aux != act && aux->dato < act->dato) {
                antAux = aux;
                aux = aux->sig;
            }
            if (aux != act) {
                if (aux->sig == act) {
                    datoAux = aux->dato;
                    aux->dato = act->dato;
                    act->dato = datoAux;
                } else {
                    antAct->sig = act->sig;
                    act->sig = aux;
                    if (aux == head)
                        head = act;
                    else
                        antAux->sig = act;
                    act = antAct;
                }
            }
            antAct = act;
            act = act->sig;
        }
    }
    return head;
}

// Seleccion; mas sensillo de todos -> no implica reacomodar punteros
void selectionSortList(TLista L) {
    TLista act, aux, min;
    int x;

    if (L != NULL && L->sig != NULL) {
        act = L;
        while (act != NULL) {
            min = act;
            aux = act->sig;
            while (aux != NULL) {
                if (aux->dato < min->dato)
                    min = aux;
                aux = aux->sig;
            }
            if (min != act) {
                x = act->dato;
                act->dato = min->dato;
                min->dato = x;
            }
            act = act->sig;
        }
    }
}


void crearLista(TLista *L, char* fname) {
    FILE *arch;
    TLista nodoNuevo;
    int x;

    arch = fopen(fname, "r");
    if (arch == NULL)
        printf("Error en la lectura del archivo: no existe");
    else {
        *L = NULL;
        if (fscanf(arch, "%d", &x) == 1) {
            nodoNuevo = (TLista) malloc(sizeof(nodo));
            nodoNuevo->dato = x;
            *L = nodoNuevo;
            while (fscanf(arch, "%d", &x) == 1) {
                nodoNuevo->sig = (TLista) malloc(sizeof(nodo));
                nodoNuevo = nodoNuevo->sig;
                nodoNuevo->dato = x;
            }
            nodoNuevo->sig = NULL;
        }
        fclose(arch);
    }
}

void crearListaNoArch(TLista *L) {
    int i;
    TLista nodoNuevo;

    *L = NULL;
    for (i=0; i<5; i++) {
        nodoNuevo = (TLista) malloc(sizeof(nodo));
        nodoNuevo->dato = 5-i;
        nodoNuevo->sig = *L;
        *L = nodoNuevo;
    }
}

void printList(TLista L) {

    while (L != NULL) {
        printf("%d ", L->dato);
        L = L->sig;
    }
    printf("\n");
}
