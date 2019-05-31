#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <todos.h>
#include <carros.h>
#include <clientes.h>
#include <alugueis.h>

int qtd_clientes_vetor = 0;
int qtd_carros_vetor = 0;
int qtd_alugueis_vetor = 0;

int leitura_todos_proc()
{
    leitura_carros_proc();
    leitura_clientes_proc();
    leitura_alugueis_proc();
    return OK;
}


int grava_todos_proc()
{
    grava_clientes_proc();
    grava_carros_proc();
    grava_alugueis_proc();
    return OK;
}


void input_int(int *var, int min, int max, char *string)
{
    do
    {
        printf(string);
        scanf(" %d", var);
    }while(min>*var || *var>max);
    return;
}

void input_float(float *var, float min, float max, char *string)
{
    do
    {
        printf(string);
        scanf("%f", var);
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
        aux2 = strlen(aux)-1;
        //printf("%d", aux2);
        if(aux[aux2] == '\n') {
			aux[aux2] = '\0';
        }
        //printf("%d", (aux2 != tamanho+1));
    }while((aux2 != tamanho) && tamanho);
    strcpy(out,aux);
}

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int ler_linha(FILE *arquivo, char *temp)
{
    if(fgets(temp, 100, arquivo))
    {
        if(temp[strlen(temp)-1] == '\n') {
			temp[strlen(temp)-1] = '\0';
        }
        printf("\n|:");
        printf(temp);
        printf(":|");
        return 1;
    }
    return OK;
}
