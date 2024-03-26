#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    m.matriz[heroi.x][heroi.y] = '.';

    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            heroi.y--;
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            heroi.y++;
            break;
        case 's':
            m.matriz [x+1][y] = '@';
            heroi.x++;
            break;
        case 'w':
            m.matriz[x-1][y] = '@';
            heroi.x--;
            break;
        
    }

    m.matriz[x][y] = '.';
}



int main(){

    lemapa(&m);
    
    do{
       imprimemapa(&m, &heroi, '@');

       char comando;
       scanf(" %c", &comando);
       move(comando);
    }while(!acabou());

    liberamapa(&m);

}