#include <clientes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <todos.h>

extern clientes_t cliente[100];

int ler_clientes_csv(FILE *arquivo_csv, clientes_t *vetor)
{
    char linha[100], temp[100], *running_ptr;
    int clientes_counter, char_counter;
    ler_linha(arquivo_csv, linha); // remove cabecalho
    clientes_counter = 1;
    while(ler_linha(arquivo_csv, linha))
    {
        char_counter = 0;
        running_ptr = linha;
        while(*running_ptr != ',')
        {
            temp[char_counter] = *running_ptr;
            //printf("%c", *running_ptr);
            char_counter++;
            running_ptr++;
        }
        temp[char_counter] = '\0';
        vetor[clientes_counter].codigo = atoi(temp);

        running_ptr++;
        char_counter = 0;
        while(*running_ptr != ',')
        {
            temp[char_counter] = *running_ptr;
            //printf("%c", temp[char_counter]);
            char_counter++;
            running_ptr++;
        }
        temp[char_counter] = '\0';
        strcpy(vetor[clientes_counter].nome, temp);

        running_ptr++;
        char_counter = 0;
        while(*running_ptr != ',')
        {
            temp[char_counter] = *running_ptr;
            //printf("%c", *running_ptr);
            char_counter++;
            running_ptr++;
        }
        temp[char_counter] = '\0';
        strcpy(vetor[clientes_counter].cnh, temp);

        running_ptr++;
        char_counter = 0;
        while(*running_ptr != ',')
        {
            temp[char_counter] = *running_ptr;
            //printf("%c", *running_ptr);
            char_counter++;
            running_ptr++;
        }
        temp[char_counter] = '\0';
        strcpy(vetor[clientes_counter].ddd, temp);

        running_ptr++;
        char_counter = 0;
        while(*running_ptr != '\0')
        {
            temp[char_counter] = *running_ptr;
            //printf("%c", *running_ptr);
            char_counter++;
            running_ptr++;
        }
        temp[char_counter] = '\0';
        strcpy(vetor[clientes_counter].telefone, temp);
        clientes_counter++;
        printf(".");
    }
    printf("\nOK!\n");
    return clientes_counter;
}

int leitura_clientes_proc()
{
    FILE *clientes_csv;
    printf("\nLendo clientes do arquivo \"clientes.csv\"\n");
    clientes_csv = fopen("clientes.csv", "r");
    if(clientes_csv == NULL)
        printf("Erro ao abrir arquivo");
    qtd_clientes_vetor = ler_clientes_csv(clientes_csv, cliente);
    fclose(clientes_csv);
    return OK;
}

int info_cliente_proc()
{
    int codigo_cliente;
    input_int(&codigo_cliente,1,qtd_clientes_vetor, "Informe o codigo do cliente:  ");
    return encontrar_cliente(codigo_cliente, cliente);
}

void printa_cliente(int codigo, clientes_t *vetor)
{
    printf("\nNome: \t\t%s\n"
           "Codigo: \t%d\n"
           "CNH: \t\t%s\n"
           "DDD: \t\t%s\n"
           "Telefone: \t%s\n",
            vetor[codigo].nome,
            vetor[codigo].codigo,
            vetor[codigo].cnh,
            vetor[codigo].ddd,
            vetor[codigo].telefone);
    return;
}
int encontrar_cliente(int codigo, clientes_t *vetor)
{
    if(vetor[codigo].codigo == codigo)
    {
        printf("Cliente encontrado!\n");
        printa_cliente(codigo, vetor);
        return OK;
    }
    else
    {
        printf("Cliente nao encontrado!\n");
        return NOK;
    }
}


int cadastra_novo_cliente(clientes_t *vetor)
{
    long int aux;
    printf("Digite os dados do novo cliente:\n");

    flush_in();
    input_string(vetor[qtd_clientes_vetor].nome, 0, "Nome:  ");
    input_string(vetor[qtd_clientes_vetor].cnh, 11, "CNH:  ");
    input_string(vetor[qtd_clientes_vetor].ddd, 2, "DDD:  ");
    input_string(vetor[qtd_clientes_vetor].telefone, 9, "Telefone:  ");
    vetor[qtd_clientes_vetor].codigo = qtd_clientes_vetor;
    printf("Usuario cadastrado. Codigo: %d\n", qtd_clientes_vetor);
    qtd_clientes_vetor++;

    return OK;
}

int novo_cliente_proc()
{
    cadastra_novo_cliente(cliente);
    return OK;


}

int lista_clientes_alfabetica(clientes_t *vetor)
{
    clientes_t copy[qtd_clientes_vetor];
    char temp_s[100];
    int ordem[qtd_clientes_vetor], counter1, counter2, temp_i;

    for(counter1 = 0; counter1 < qtd_clientes_vetor; counter1++)
    {
        strcpy(copy[counter1].nome, vetor[counter1].nome);
        ordem[counter1] = counter1;
    }

    for(counter1 = 1; counter1 < qtd_clientes_vetor; counter1++)
    {
        for(counter2 = 0; counter2 < qtd_clientes_vetor; counter2++)
        {
        if(strcmp(copy[counter2].nome,copy[counter2+1].nome) > 0)
            {
                strcpy(temp_s,copy[counter2].nome);
                strcpy(copy[counter2].nome,copy[counter2+1].nome);
                strcpy(copy[counter2+1].nome,temp_s);

                temp_i = ordem[counter2];
                ordem[counter2] = ordem[counter2+1];
                ordem[counter2+1] = temp_i;
                printf(".");
            }
            printf("-");
        }
        printf("\n");
    }

    printf("[a]");
    for(counter1 = 1; counter1 < qtd_clientes_vetor; counter1++)
    {
        printf("[b]");
        printa_cliente(ordem[counter1],vetor);


        printf("[c]");
    }

    return OK;
}


int lista_clientes_proc()
{
    lista_clientes_alfabetica(cliente);
    return OK;

}

int salvar_clientes_csv(FILE *arquivo_csv, clientes_t *vetor)
{
    int counter;
        fprintf(arquivo_csv, "codigo_cliente,nome,cnh,ddd,telefone\n");
    for(counter = 1; counter < qtd_clientes_vetor; counter++)
    {
        fprintf(arquivo_csv, "%d", vetor[counter].codigo);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].nome);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].cnh);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].ddd);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].telefone);
        fprintf(arquivo_csv, "\n");
    }
    return OK;
}

int grava_clientes_proc(){
    FILE *clientes_csv;
    printf("\nSalvando clientes no arquivo \"clientes.csv\"\n");
    clientes_csv = fopen("clientes.csv", "w");
    if(clientes_csv == NULL)
    {
        printf("Erro ao abrir arquivo");
        return NOK;
    }
    else
    {
        salvar_clientes_csv(clientes_csv, cliente);
        fclose(clientes_csv);
        return OK;
    }
}
