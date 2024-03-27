// Importando as bibliotecas necessárias e os header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "foge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int direcaofantasma(int xatual, int yatual, int* xdestino, int* ydestino){
    // Matriz que armazena as direções possiveis do fantasma
    int opcoes[4][2] = {
        { xatual, yatual +1},
        { xatual +1, yatual},
        { xatual, yatual -1},
        { xatual -1, yatual}
    };

    // Inicializa o gerador de numeros aleatorios
    srand(time(0));

    // loop for que se repete 10 vezes para encontrar uma direção para o fantasma
    for(int i = 0; i < 10; i++){
        
        // gera um numero aleatorio entre 0 e 3
        int posicao = rand() % 4;

        if(validadirecao(&m, opcoes[posicao][0], opcoes[posicao][1]) && direcaovazia(&m, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }
    return 0;
}

void fantasmas(){
    MAPA copia;

    copiamapa(&copia, &m);
    for (int i = 0; i < m.linhas; i++){
       for (int j = 0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){

                int xdestino;
                int ydestino;

                int encontrou = direcaofantasma(i, j, &xdestino, &ydestino);
                if(validadirecao(&m, i, j+1) && direcaovazia(&m, i, j+1)){
                    andanomapa(&m, i, j, i, j+1);
                }
            }     
       }  
    }

    liberamapa(&copia);

}

int acabou(){
    return 0;
}

int direcaoheroi(char direcao){
    return direcao == ESQUERDA || direcao == DIREITA || direcao == BAIXO || direcao == CIMA;

}

void move(char direcao){
    if(!direcaoheroi(direcao)){
        return;
    }

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
        case BAIXO:
            proximox++;
            break;
        case CIMA:
            proximox--;
            break;
        
    }

    if(!validadirecao(&m, proximox, proximoy)){
        return;
    }

    if(!direcaovazia(&m, proximox, proximoy)){
        return;
    }

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;

}



int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do{
       imprimemapa(&m);

       char comando;
       scanf(" %c", &comando);
       move(comando);
    }while(!acabou());

    liberamapa(&m);

}