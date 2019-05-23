

struct carros_struct{
    int     codigo;
    char    marca[30];
    char    modelo[100];
    int     ano;
    char    placa[8];
    float   valor_diaria;
    float   valor_seguro;
    int     quantidade;
};

typedef struct carros_struct carros_t;

carros_t carro[100];


int leitura_carros_proc();
int info_carro_proc();
int novo_carro_proc();
int lista_carros_proc();
int lista_carros_preco_proc();
int grava_carros_proc();
