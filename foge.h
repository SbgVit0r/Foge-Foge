#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd' 

void move(char direcao);
int acabou();
int direcaoheroi(char direcao);
void fantasmas();
int direcaofantasma(int xatual, int yatual, int* xdestino, int* ydestino);