#include <clientes.h>
#include <stdio.h>
#include <string.h>
#include <todos.h>

extern clientes_t cliente[100];

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
    return 0;
}

int ler_clientes_csv(FILE *arquivo_csv, clientes_t *vetor)
{
    char linha[100], temp[100], *running_ptr;
    int clientes_counter, char_counter;
    ler_linha(arquivo_csv, linha); // remove cabecalho
    clientes_counter = 0;
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
}

int info_cliente_proc()
{
    int codigo_cliente;
    input_int(&codigo_cliente,1,qtd_clientes_vetor, "Informe o codigo do cliente:  ");
    return encontrar_cliente(codigo_cliente, cliente);
}

void printa_clinte(int codigo, clientes_t *vetor)
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
    if(vetor[codigo-1].codigo == codigo)
    {
        printf("Cliente encontrado!\n");
        printa_clinte(codigo-1, vetor);
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
    vetor[qtd_clientes_vetor].codigo = qtd_clientes_vetor+1;
    qtd_clientes_vetor++;
    printf("Usuario cadastrado. Codigo: %d\n", qtd_clientes_vetor);

    return OK;
}

int novo_cliente_proc()
{
    cadastra_novo_cliente(cliente);
    return 0;


}




int lista_clientes_alfabetica(clientes_t *vetor)
{
    char counter_char1, counter_char2, counter_char3;
    int counter_int1;
    for(counter_char1 = 'A'; counter_char1 <= 'Z'; counter_char1++)
        for(counter_char2 = 'a'; counter_char2 <= 'z'; counter_char2++)
            for(counter_char3 = 'a'; counter_char3 <= 'z'; counter_char3++)
                for(counter_int1 = 0; counter_int1 <= qtd_clientes_vetor; counter_int1++)
                    if((vetor[counter_int1].nome[0] == counter_char1) &&
                       (vetor[counter_int1].nome[1] == counter_char2) &&
                       (vetor[counter_int1].nome[2] == counter_char3))
                                printa_clinte(counter_int1, vetor);
    return OK;
}

int lista_clientes_proc()
{
    lista_clientes_alfabetica(cliente);
    return 0;

}

int grava_clientes_proc(){return 0;}
