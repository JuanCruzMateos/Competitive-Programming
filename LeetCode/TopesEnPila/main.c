#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pila.h"

void mostrarPila(TPila *P);
void ordenar_rec(TPila *P);
void ordenar(TPila* P);
void esAscendente(TPila* P, int* as);
void minimoPila(TPila* P, TElementoP* min);
void minimo(TPila* P, TElementoP* min);
void retornarTopes(TPila* P, int cantTopes, int vec[], int* n);
void elimiarTodos(TPila* P, TElementoP elim, int* cantElim);

int main() {
    TPila P;
    int as;
    int min = INT_MAX;
    int topes[30], n;
    int eliminados;

    iniciaP(&P);
    poneP(&P, 12);
    poneP(&P, 9);
    poneP(&P, 7);
    poneP(&P, 22);
    poneP(&P, 7);
    poneP(&P, 1);
    poneP(&P, 7);

    mostrarPila(&P);
//    ordenar_rec(&P);
//    ordenar(&P);
//    printf("\n");
//    mostrarPila(&P);
    esAscendente(&P, &as);
    if (as == 1)
        printf("\nEs ascendente\n");
    else
        printf("\nNo es ascendente\n");
    mostrarPila(&P);
    minimoPila(&P, &min);
    printf("\nmin = %d\n", min);
    mostrarPila(&P);
    minimo(&P, &min);
    printf("\nmin = %d\n", min);
    mostrarPila(&P);
    printf("\n");

//    n = 0;
    retornarTopes(&P, 3, topes, &n);
    for (int i=0; i<n; i++)
        printf("%d ", topes[i]);
    printf("\n");
    mostrarPila(&P);
    printf("\n");

    elimiarTodos(&P, 7, &eliminados);
    mostrarPila(&P);
    printf("\nCant elim = %d", eliminados);
    return 0;
}

void elimiarTodos(TPila* P, TElementoP elim, int* cantElim) {
    TElementoP x;

    if (!vaciaP(*P)) {
        sacaP(P, &x);
        elimiarTodos(P, elim, cantElim);
        if (x != elim)
            poneP(P, x);
        else
            *cantElim += 1;
    } else
        *cantElim = 0;
}

void retornarTopes(TPila* P, int cantTopes, int vec[], int* n) {
    TElementoP x;

    if (!vaciaP(*P) && cantTopes > 0) {
        sacaP(P, &x);
        retornarTopes(P, cantTopes - 1, vec, n);
        vec[(*n)++] = x;
        poneP(P, x);
    } else {
        *n = 0;
    }
}

void minimoPila(TPila* P, TElementoP* min) {
    TElementoP x;

    if (!vaciaP(*P)) {
        sacaP(P, &x);
        if (x < *min)
            *min = x;
        minimoPila(P, min);
        if (x != *min)
            poneP(P, x);
    }
}

void minimo(TPila* P, TElementoP* min) {
    TElementoP x;

    if (vaciaP(*P))
        *min = INT_MAX;
    else {
        sacaP(P, &x);
        minimo(P, min);
        if (x < *min)
            *min = x;
        poneP(P, x);
    }
}

void esAscendente(TPila* P, int* as) {
    TElementoP tope, sig;

    if (!vaciaP(*P)) {
        sacaP(P, &tope);
        if (!vaciaP(*P)) {
            sig = consultaP(*P);
            if (tope < sig)
                esAscendente(P, as);
            else
                *as = 0;
        } else {
            *as = 1;
        }
        poneP(P, tope);
    }
}


void ordenar_rec(TPila *P) {
    TElementoP x, y;

    if (!vaciaP(*P)) {
        sacaP(P, &x);
        ordenar_rec(P);
        if (!vaciaP(*P) && consultaP(*P) < x) {
            sacaP(P, &y);
            poneP(P, x);
            ordenar_rec(P);
            poneP(P, y);
        } else
            poneP(P, x);
    }
}

void ordenar(TPila* P) {
    TPila P_aux;
    TElementoP x, y;

    iniciaP(&P_aux);
    while (!vaciaP(*P)) {
        sacaP(P, &x);
        while (!vaciaP(P_aux) && x < consultaP(P_aux)) {
            sacaP(&P_aux, &y);
            poneP(P, y);
        }
        poneP(&P_aux, x);
    }
    while (!vaciaP(P_aux)) {
        sacaP(&P_aux, &x);
        poneP(P, x);
    }
}

void mostrarPila(TPila *P) {
    TElementoP x;

    if (!vaciaP(*P)) {
        sacaP(P, &x);
        printf("%d ", x);
        mostrarPila(P);
        poneP(P, x);
    }
}
