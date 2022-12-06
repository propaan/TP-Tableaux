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

void pair(int t[MaxElem][MaxElem], int t2[MaxElem][MaxElem], int c, int r) {
    
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
}

int main() {
    system("cls");

    int c = 10, r = 10;
    
    int tab[MaxElem][MaxElem];
    int tab2[MaxElem][MaxElem];

    initTab(tab, c, r);
    show2DTab(tab, c, r);

    printf("\n------------------------------------------------------------------------------\n\n");

    pair(tab, tab2, c, r);

    int howManyLines = (r % 2 == 0)?(r/2):((r/2) + 1);

    show2DTab(tab2, r, howManyLines);
}