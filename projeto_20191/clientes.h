

struct clientes_struct{
    int codigo;
    char nome[100];
    char cnh[12];
    char ddd[3];
    char telefone[10];
};

typedef struct clientes_struct clientes_t;

clientes_t cliente[100];

int leitura_clientes_proc();
int info_cliente_proc();
int novo_cliente_proc();
int lista_clientes_proc();
int grava_clientes_proc();
int encontrar_cliente(int codigo, clientes_t *vetor);
