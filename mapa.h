#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};

struct posicao{
    int x;
    int y;
};

typedef struct mapa MAPA;
typedef struct posicao POSICAO;

void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO* p, char c);
int validadirecao(MAPA* m, int x, int y);
int direcaovazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* origem, MAPA* destino);