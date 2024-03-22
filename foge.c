#include <stdio.h>
#include <stdlib.h>

int main(){
    // matriz de 5x10
    char mapa [5][10+1];
    char nome[20];

    mapa[0][0] = '|';
    mapa[4][9] = '@';

    printf("%c %c", mapa[0][0], mapa[4][9]);

    FILE* f;

    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("erro na leitura\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }

     for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);
}