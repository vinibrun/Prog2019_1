
#define SIM         1
#define NAO         2
#define OK          0
#define NOK         0xFF
#define CLIENTESMAX 100

extern int qtd_clientes_vetor;

int leitura_todos_proc();
int devolucao_proc();
int lista_atrasados_proc();
int grava_todos_proc();
int sair();
void input_int(int *var, int min, int max, char *string);
void input_string(char *out, int tamanho, char *string);
void flush_in(void);
