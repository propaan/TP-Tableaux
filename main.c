/*
Exercice 2

b. Demander la taille n*p souhaitées par l’utilisateur (n lignes, p colonnes avec n et p <=10)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 99
#define MaxElem 50

int c, r;

//rand()%MAX;

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

int main() {

    printf("\n----------Exercice 2----------");
    int row, collumn;

    do {
        printf("\nIndiquez combien de colonnes : ");
        scanf("%d", &collumn);
    } while (collumn > 10);

    do {
        printf("\nIndiquez combien de lignes : ");
        scanf("%d", &row);
    } while (row > 10);

    int tab[50][50];
    int tab2[50][50];

    initTab(tab, collumn, row);
    copyTab(tab, tab2, collumn, row);
    show2DTab(tab, collumn, row);

    printf("\n");

    show2DTab(tab2, collumn, row);
    return 0;
}

void create2T(int T[MaxElem][MaxElem], int ligne, int colonne){
    int  numbers, count; 

    printf("\nTableau 2T\n");

    for (int i=0;i<ligne;i++){
        printf("|");
        if ((i%2==0) || (i==0)){
            for (int j=0; j<colonne; j++){
                numbers = T[i][j];
                count = (numbers == 0)?1:log10(numbers)+1;
                printf(" %d", numbers);
                for (int k = count; k < 3; k++) printf(" ");
             printf("|");
            }
            printf("\n");
        }
    }
}