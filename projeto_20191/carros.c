

#include <carros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <todos.h>

extern carros_t carro[100];

int ler_carros_csv(FILE *arquivo_csv, carros_t *vetor)
{
    char linha[100], temp[100], *running_ptr;
    int carros_counter, char_counter;
    ler_linha(arquivo_csv, linha); // remove cabecalho
    carros_counter = 1;
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
        vetor[carros_counter].codigo = atoi(temp);

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
        strcpy(vetor[carros_counter].marca, temp);

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
        strcpy(vetor[carros_counter].modelo, temp);

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
        vetor[carros_counter].ano = atoi(temp);

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
        strcpy(vetor[carros_counter].placa, temp);

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
        vetor[carros_counter].valor_diaria = atof(temp);

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
        vetor[carros_counter].valor_seguro = atof(temp);

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
        vetor[carros_counter].quantidade = atoi(temp);
        carros_counter++;
        printf(".");
    }
    printf("\nOK!\n");
    return carros_counter;
}

int leitura_carros_proc()
{
    FILE *carros_csv;
    printf("\nLendo carros do arquivo \"carros.csv\"\n");
    carros_csv = fopen("carros.csv", "r");
    if(carros_csv == NULL)
        printf("Erro ao abrir arquivo");
    qtd_carros_vetor = ler_carros_csv(carros_csv, carro);
    fclose(carros_csv);
}

int info_carro_proc()
{
    int codigo_carro;
    input_int(&codigo_carro,1,qtd_carros_vetor, "Informe o codigo do carro:  ");
    return encontrar_carro(codigo_carro, carro);
}

void printa_carro(int codigo, carros_t *vetor)
{
    printf("\nCodigo: \t\t%d\n"
           "Marca: \t\t\t%s\n"
           "Modelo: \t\t%s\n"
           "Ano: \t\t\t%d\n"
           "Placa: \t\t\t%s\n"
           "Valor da diaria: \t%.2f\n"
           "Valor do seguro: \t%.2f\n"
           "Quantidade: \t\t%d\n",
            vetor[codigo].codigo,
            vetor[codigo].marca,
            vetor[codigo].modelo,
            vetor[codigo].ano,
            vetor[codigo].placa,
            vetor[codigo].valor_diaria,
            vetor[codigo].valor_seguro,
            vetor[codigo].quantidade);
    return;
}
int encontrar_carro(int codigo, carros_t *vetor)
{
    if(vetor[codigo].codigo == codigo)
    {
        printf("Carro encontrado!\n");
        printa_carro(codigo, vetor);
        return OK;
    }
    else
    {
        printf("Carro nao encontrado!\n");
        return NOK;
    }
}


int cadastra_novo_carro(carros_t *vetor)
{
    long int aux;
    printf("Digite os dados do novo carro:\n");

    flush_in();
    input_string(vetor[qtd_carros_vetor].marca, 0, "Marca:  ");
    input_string(vetor[qtd_carros_vetor].modelo, 0, "Modelo:  ");
    input_int(&vetor[qtd_carros_vetor].ano, 1800, 2030, "Ano:  ");
    flush_in();
    input_string(vetor[qtd_carros_vetor].placa, 7, "Placa:  ");
    input_float(&vetor[qtd_carros_vetor].valor_diaria, (1), (999.9), "Valor da diaria [xx.xx]:  R$");
    input_float(&vetor[qtd_carros_vetor].valor_seguro, 1.1, 999.9, "Valor do seguro [xx.xx]:  R$");
    input_int(&vetor[qtd_carros_vetor].quantidade, 1, 999, "Quantidade:  ");
    vetor[qtd_carros_vetor].codigo = qtd_carros_vetor;
    printf("Carro cadastrado. Codigo: %d\n", qtd_carros_vetor);
    qtd_carros_vetor++;

    return OK;
}

int novo_carro_proc()
{
    cadastra_novo_carro(carro);
    return OK;
}

int salvar_carros_csv(FILE *arquivo_csv, carros_t *vetor)
{
    int counter;
        fprintf(arquivo_csv, "codigo_carro,nome,cnh,ddd,telefone\n");
    for(counter = 0; counter < qtd_carros_vetor; counter++)
    {
        fprintf(arquivo_csv, "%d", vetor[counter].codigo);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].marca);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].modelo);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, "%d", vetor[counter].ano);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, vetor[counter].placa);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, "%.2f", vetor[counter].valor_diaria);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, "%.2f", vetor[counter].valor_seguro);
        fprintf(arquivo_csv, ",");
        fprintf(arquivo_csv, "%d", vetor[counter].quantidade);
        fprintf(arquivo_csv, "\n");
    }
    return OK;
}

int grava_carros_proc(){
    FILE *carros_csv;
    printf("\nSalvando carros no arquivo \"carros.csv\"\n");
    carros_csv = fopen("carros.csv", "w");
    if(carros_csv == NULL)
    {
        printf("Erro ao abrir arquivo");
        return NOK;
    }
    else
    {
        salvar_carros_csv(carros_csv, carro);
        fclose(carros_csv);
        return OK;
    }
}

int lista_carros_marca(carros_t *vetor, char *marca)
{
    int counter, achei = 0;
    for(counter = 0; counter < qtd_carros_vetor; counter++)
        if(!strcmp(vetor[counter].marca, marca))
        {
            achei = 1;
            printa_carro(counter, vetor);
        }
    if(achei)
        return OK;
    else
        return NOK;
}


int lista_carros_marca_preco(carros_t *vetor, char *marca)
{
    int counter, counter2, achei = 0;
    float precos[qtd_carros_vetor], aux_f;
    int ordem[qtd_carros_vetor], aux_i;

    for(counter = 0; counter < qtd_carros_vetor; counter++)
    {
        precos[counter] = vetor[counter].valor_diaria;
        ordem[counter] = counter;
    }

    //Insercion Sort
    for(counter = 1; counter < qtd_carros_vetor; counter++){
        counter2 = counter;
        while((counter2 != 0) && (precos[counter2] > precos[counter2 - 1])) {

            aux_f = precos[counter2];
            precos[counter2] = precos[counter2 - 1];
            precos[counter2 - 1] = aux_f;

            aux_i = ordem[counter2];
            ordem[counter2] = ordem[counter2 - 1];
            ordem[counter2 - 1] = aux_i;

            counter2--;
        }
    }

    for(counter = 0; counter < qtd_carros_vetor; counter++)
        if(!strcmp(vetor[ordem[counter]].marca, marca))
        {
            achei = 1;
            printa_carro(ordem[counter], vetor);
        }
    if(achei)
        return OK;
    else
        return NOK;
}

int lista_carros_proc_aux(int preco)
{
    int counter, retorno;
    char marca[30];
    flush_in();
    do{
        printf("\nMarcas disponiveis: ");
        for(counter = 0; counter < qtd_carros_vetor; counter++)
            printf("%s, ", carro[counter].marca);
        printf("\n");
        input_string(marca, 0, "Digite a marca desejada:  ");
        if (preco == SIM)
            retorno = lista_carros_marca_preco(carro, marca);
        else
            retorno = lista_carros_marca(carro, marca);
    }while(retorno);
    return OK;
}

int lista_carros_proc()
{
    return lista_carros_proc_aux(NAO);
}

int lista_carros_preco_proc()
{
    return lista_carros_proc_aux(SIM);
}


