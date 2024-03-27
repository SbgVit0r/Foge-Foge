#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

//
void copiamapa(MAPA* origem, MAPA* destino){
    destino -> linhas = origem -> linhas;
    destino -> colunas = origem -> colunas;

    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    // Declara a posição inicial do nosso personagem
    char personagem = m->matriz[xorigem][yorigem];
    // Atribui a posição inicial
    m->matriz[xdestino][ydestino] = personagem;
    // Muda a posição 
    m->matriz[xorigem][yorigem] = VAZIO;
}

int validadirecao(MAPA* m, int x, int y){

    // Caso o heroi bater em uma das paredes horizontais, ele não se move
    if (x >= m->linhas){
        return 0;
    }

    // Caso o heroi bater em uma das paredes verticais, ele não se move
    if (y >= m->colunas){
        return 0;
    }

    return 1;

}

//
int direcaovazia(MAPA* m, int x, int y){
    return m->matriz[x][y] != VAZIO;
}

//
void encontramapa(MAPA* m, POSICAO* p, char c){
    
    //acha a posição do foge foge
    for (int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == HEROI){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }

}

void liberamapa(MAPA* m){

    for (int i = 0; i < m -> linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);

}

void alocamapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void lemapa(MAPA* m){

    // Ponteiro para a função FILE
    FILE* f;

    // Variavel que abre o arquivo e lê ele
    f = fopen("mapa.txt", "r");

    // Caso não esteja disponivel, o programa fecha
    if(f == 0){
        printf("erro na leitura\n");
        exit(1);
    }

    // Escaneia o arquivo txt do mapa e suas linhas e colunas
    fscanf(f, "%d %d", &m->linhas, &m->colunas);

    printf("linhas %d colunas %d\n", m->linhas, m->colunas);

    alocamapa(m);

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);

}

void imprimemapa(MAPA* m){

    // Imprime o arquivo escaneado na tela
    for(int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}
