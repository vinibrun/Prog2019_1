

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

/*
int ler_alugueis_bin(FILE *arquivo_bin, alugueis_t *vetor);
void printa_aluguel(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes);
int encontrar_aluguel(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes);
int cadastra_novo_aluguel(alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes);
int devolver(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes);
*/

int leitura_alugueis_proc();
int info_aluguel_proc();
int novo_aluguel_proc();
int lista_alugueis_proc();
int grava_alugueis_proc();

int devolucao_proc();
