

struct alugueis_struct{
    int codigo;
    int codigo_cliente;
    int codigo_carro;
    int dia;
    int mes;
    int ano;
    int numero_diarias;
    float valor;
    char seguro;
    char status;
};

typedef struct alugueis_struct alugueis_t;

alugueis_t aluguel[100];


int leitura_alugueis_proc();
int info_aluguel_proc();
int novo_aluguel_proc();
int lista_alugueis_proc();
int grava_alugueis_proc();
