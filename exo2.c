#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MaxElem 10
#define MAX 99

void show2DTab(int T[MaxElem][MaxElem], int c, int r) {
    int count, numbers;
    for (int i = 0; i < r; i++) {
        printf("|");
        for (int j = 0; j < c; j++) {
            numbers = T[i][j];
            count = (numbers == 0)?1:log10(numbers)+1;
            printf(" %d", numbers);
            for (int i = count; i < 3; i++) printf(" ");
            printf("|");
        }
        printf("\n");
    } 
}

void getDiag(int T[MaxElem][MaxElem], int c, int r) {

    show2DTab(T, c, r);

    printf("\n----------------------------\n");

    printf("\nSa diagonale contient : ");
    for (int i = 0;i <= r - 1;i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                printf("[%d]", T[i][j]);
            }
        }
    }
}

void initTab(int T[MaxElem][MaxElem], int c, int r){
 	int i;
	srand(time(NULL));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[i][j] = rand()%MAX;
        }
    }
}


int main() {

    int nbCol = 10;
    int nbRow = 10;

    // A.

    int tab[10][10];

    // B.
    /*
    do {
        printf("Combien de colonnes : ");
        scanf("%d", &nbCol);
    } while (nbCol > 10);

    do {
        printf("Combien de lignes : ");
        scanf("%d", &nbRow);
    } while (nbRow > 10);

    */
    
    initTab(tab, nbCol, nbRow);

    getDiag(tab, nbCol, nbRow);


    return 0;
}