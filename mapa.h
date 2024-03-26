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


