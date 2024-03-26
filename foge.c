#include <stdio.h>
#include <stdlib.h>
#include "foge.h"

void liberamapa(){

    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

}

void alocamapa(){
    matriz = malloc(sizeof(char*) * linhas);

    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void lemapa(){

    FILE* f;

    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("erro na leitura\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("linhas %d colunas %d\n", linhas, colunas);

    alocamapa();

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", matriz[i]);
    }

    fclose(f);

}

void imprimemapa(){

    for(int i = 0; i < 5; i++){
        printf("%s\n", matriz[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    //acha a posição do foge foge
    for (int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a':
            matriz[x][y-1] = '@';
            break;
        case 's':
            matriz [x+1][y] = '@';
            break;
        case 'w':
            matriz[x-1][y] = '@';
            break;
        case 'd':
            matriz[x][y+1] = '@';
            break;
    }

    matriz[x][y] = '.';
}



int main(){

    lemapa();
    
    do{
       imprimemapa();

       char comando;
       scanf(" %c", &comando);
       move(comando);
    }while(!acabou());

    liberamapa();

}