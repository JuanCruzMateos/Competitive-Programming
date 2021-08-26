/* 1431. Kids With the Greatest Number of Candies
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.
For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of
candies among them. Notice that multiple kids can have the greatest number of candies.
*/
/*
Success Details:
Runtime: 4 ms, faster than 87.13% of C online submissions for Kids With the Greatest Number of Candies.
Memory Usage: 6.2 MB, less than 65.98% of C online submissions for Kids With the Greatest Number of Candies.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 5

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);

int main()
{
    int candies[DIM] = {2,3,5,1,3};
    int candiesSize = 5;
    int extraCandies = 3;
    int returnSize;
    int i;
    bool* solution;

    solution = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    for (i=0; i<returnSize; i++) {
        printf("%d ", *(solution + i));
    }

    return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *check;
    int i, maxCandies = 0;

    // Para que funcione -> debe ser un tema de implementacion de la solucion
    *returnSize = candiesSize;
    // Obtengo el maximo
    for (i=0; i<candiesSize; i++) {
        if (candies[i] > maxCandies)
            maxCandies = candies[i];
    }
    // Creo el arreglo dinamico en el heap de tamaño del arreglo original
    check = (bool *) malloc(sizeof(bool)*candiesSize);
    // Lleno el arreglo
    for (i=0; i<candiesSize; i++) {
        check[i] = ((candies[i] + extraCandies >= maxCandies) ? true : false);
    }
    // Devuelvo el punto con malloc
    // malloc => la direccion de memoria pertenece al heap del programa
    // plt si bien cuando termina la ejecucion de la funcion las variables locales se pierden
    // al devolver la direccion pedida la conservo
    // la forma de perderla es unicamente hacer free()
    // evitar STATIC -> mala practica
    // USAR MALLOC PARA DEVOLVER PUNTEROS LOCALIZADOS EN EL HEAP
    return check;
}

/*
c++

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=*max_element(candies.begin(),candies.end());
        vector<bool>v;
        for(int i=0;i<candies.size();i++){
           if( candies[i]+extraCandies>=m)
                v.push_back(true);
            else
                v.push_back(false);
        }
        return v;
    }
};

*/
