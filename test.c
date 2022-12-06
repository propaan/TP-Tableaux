#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nbLines(FILE *fic) {
    int count = 0;
    char text[255];

    while (fgets(text, 254, fic) != NULL) count++;

    return count;
    
}

int main() {

    FILE* F = fopen("sae1.csv","r");
    char* fic = malloc(255);

    fread(fic,255,1,F);

    printf("%s", fic);

    fclose(F);

}