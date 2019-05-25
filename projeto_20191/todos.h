
#define SIM         1
#define NAO         2
#define OK          0
#define NOK         0xFF
#define CLIENTESMAX 100

extern int qtd_clientes_vetor;
extern int qtd_carros_vetor;

int leitura_todos_proc();
int devolucao_proc();
int lista_atrasados_proc();
int grava_todos_proc();
int sair();
void input_int(long int *var, long int min, long int max, char *string);
void input_float(float *var, float min, float max, char *string);
void input_string(char *out, int tamanho, char *string);
void flush_in(void);
int ler_linha(FILE *arquivo, char *temp);
