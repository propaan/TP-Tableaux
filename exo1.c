#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 99
#define MaxElem 50

void initTab(int T[MaxElem][MaxElem], int c, int r){
 	int i;
	srand(time(NULL));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[i][j] = rand()%MAX;
        }
    }
}

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

int pairRow(int t[MaxElem][MaxElem], int t2[MaxElem][MaxElem], int c, int r) {

    int nbRows = (r % 2 == 1)?((r/2) + 1):(r/2);
    
    int count, numbers, c2 = 0;
    for (int i = 0; i < r; i++) {

        if(i % 2 == 0) {
            for (int j = 0; j < c; j++) {
                numbers = t[i][j];
                t2[c2][j] = numbers;
            }
        c2++;
        }
    }
    return nbRows;
}

int impairCollumn(int t[MaxElem][MaxElem], int t2[MaxElem][MaxElem], int c, int r) {

    int nbCollumns = (c % 2 == 0)?(c/2):((c/2) + 1);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j % 2 == 1) {
                t2[i][j - (j/2) - 1] = t[i][j];
            }
        }
    }

    return nbCollumns;
}

int main() {
    system("cls");

    int c = 10, r = 10;
    
    int tab[MaxElem][MaxElem];
    int tab2[MaxElem][MaxElem];

    initTab(tab, c, r);
    show2DTab(tab, c, r);

    printf("\n-------------------------------Récupérer les lignes d'indices paires -------------------------------\n\n");

    int nbROw = pairRow(tab, tab2, 10, 10);

    show2DTab(tab2, 10, nbROw);


    printf("\n-------------------------------Récupérer les colonnes d'indices impaires -------------------------------\n\n");


    int nbCol = impairCollumn(tab, tab2, 10, 10);

    show2DTab(tab2, nbCol, 10);
}