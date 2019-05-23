#include <stdio.h>
#include <string.h>

int leitura_todos_proc(){return 0;}
int devolucao_proc(){return 0;}
int lista_atrasados_proc(){return 0;}
int grava_todos_proc(){return 0;}

int qtd_clientes_vetor = 0;

void input_int(long int *var, long int min, long int max, char *string)
{
    do
    {
        printf(string);
        scanf(" %d", var);
    }while(min>*var || *var>max);
    return;
}

void input_string(char *out, int tamanho, char *string)
{
    char aux[100];
    int aux2;
    do
    {
        printf(string);
        fgets(aux, 100, stdin);
        aux2 = strlen(aux);
        //printf("%d", aux2);
        if(aux[aux2] == '\n') {
			aux[aux2] = '\0';
        }
        //printf("%d", (aux2 != tamanho+1));
    }while((aux2 != tamanho+1) && tamanho);
    strcpy(out,aux);
}

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
