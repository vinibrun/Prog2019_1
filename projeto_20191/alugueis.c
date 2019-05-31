#include <alugueis.h>
#include <clientes.h>
#include <carros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <todos.h>

extern alugueis_t aluguel[100];

int ler_alugueis_bin(FILE *arquivo_bin, alugueis_t *vetor)
{
    char linha[100], temp[100], *running_ptr;
    int alugueis_counter, char_counter;
    ler_linha(arquivo_bin, linha); // remove cabecalho
    alugueis_counter = 1;
    while(ler_linha(arquivo_bin, linha))
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
        vetor[alugueis_counter].codigo = atoi(temp);

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
        vetor[alugueis_counter].codigo_cliente = atoi(temp);

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
        vetor[alugueis_counter].codigo_carro = atoi(temp);

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
        vetor[alugueis_counter].dia= atoi(temp);

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
        vetor[alugueis_counter].mes = atoi(temp);

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
        vetor[alugueis_counter].ano = atoi(temp);

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
        vetor[alugueis_counter].numero_diarias = atoi(temp);

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
        vetor[alugueis_counter].valor = atof(temp);

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
        vetor[alugueis_counter].seguro = temp[0];

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
        vetor[alugueis_counter].status = temp[0];

        alugueis_counter++;
        printf(".");
    }
    printf("\nOK!\n");
    return alugueis_counter;
}

int leitura_alugueis_proc()
{
    FILE *alugueis_bin;
    printf("\nLendo alugueis do arquivo \"alugueis.bin\"\n");
    alugueis_bin = fopen("alugueis.bin", "r");
    if(alugueis_bin == NULL)
        printf("Erro ao abrir arquivo");
    qtd_alugueis_vetor = ler_alugueis_bin(alugueis_bin, aluguel);
    fclose(alugueis_bin);
    return OK;
}

void printa_aluguel(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes)
{
    printf("\nCodigo do aluguel:\t%d\n", v_alugueis[codigo].codigo);
    printf("Nome do cliente: \t%s  (cod: %d)\n",
            v_clientes[v_alugueis[codigo].codigo_cliente].nome,
            v_clientes[v_alugueis[codigo].codigo_cliente].codigo);
    printf("Carro: \t\t\t%s %s Ano %d (cod: %d)\n",
            v_carros[v_alugueis[codigo].codigo_carro].marca,
            v_carros[v_alugueis[codigo].codigo_carro].modelo,
            v_carros[v_alugueis[codigo].codigo_carro].ano,
            v_carros[v_alugueis[codigo].codigo_carro].codigo);
    printf("Data de retirada: \t%d/%d/%d\n"
           "Numero de diarias: \t%d\n"
           "Valor: \t\t\t%.2f\n"
           "Possui seguro: \t\t%c\n",
            v_alugueis[codigo].dia,
            v_alugueis[codigo].mes,
            v_alugueis[codigo].ano,
            v_alugueis[codigo].numero_diarias,
            v_alugueis[codigo].valor,
            v_alugueis[codigo].seguro);

    if(v_alugueis[codigo].status == 'L')
        printf("O carro esta locado\n");
    else
        printf("O carro foi entregue\n");

    return;
}

int encontrar_aluguel(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes)
{
    if(v_alugueis[codigo].codigo == codigo)
    {
        printf("Aluguel encontrado!\n");
        printa_aluguel(codigo, v_alugueis, v_carros, v_clientes);
        return OK;
    }
    else
    {
        printf("Aluguel nao encontrado!\n");
        return NOK;
    }
}

int info_aluguel_proc()
{
    int codigo_aluguel;
    input_int(&codigo_aluguel,1,qtd_alugueis_vetor, "Informe o codigo do aluguel:  ");
    return encontrar_aluguel(codigo_aluguel, aluguel, carro, cliente);
}


int cadastra_novo_aluguel(alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes)
{
    int go;
    alugueis_t temp;

    printf("Digite os dados do novo aluguel:\n");
    //flush_in();
    input_int(&temp.codigo_cliente, 1, qtd_clientes_vetor, "Codigo do cliente:  ");
    if(v_clientes[temp.codigo_cliente].codigo != temp.codigo_cliente)
    {
        do
        {
            printf("Cliente nao cadastrado");
            input_int(&temp.codigo_cliente, 1, qtd_clientes_vetor, "\nCodigo do cliente:  ");
        }while(v_clientes[temp.codigo_cliente].codigo != temp.codigo_cliente);
    }
    printf("Nome: %s\n", v_clientes[temp.codigo_cliente].nome);

    input_int(&temp.codigo_carro, 1, qtd_carros_vetor, "Codigo do carro:  ");
    if(v_carros[temp.codigo_carro].quantidade < 1)
    {
        do
        {
            printf("Carro indisponivel");
            input_int(&temp.codigo_carro, 1, qtd_carros_vetor, "Codigo do carro:  ");
        }while(v_carros[temp.codigo_carro].quantidade < 1);
    }
    printf("Carro: \t\t%s %s Ano %d\n",
    v_carros[temp.codigo_carro].marca,
    v_carros[temp.codigo_carro].modelo,
    v_carros[temp.codigo_carro].ano);

    input_int(&temp.dia, 1, 31, "Dia da reserva:  ");
    input_int(&temp.mes, 1, 12, "Mes da reserva:  ");
    input_int(&temp.ano, 2019, 2030, "Ano da reserva:  ");
    input_int(&temp.numero_diarias, 1, 99, "Numero de diarias:  ");

    printf("\nValor:\n"
           "Com seguro: R$%.2f\n"
           "Sem seguro: R$%.2f\n",
           (v_carros[temp.codigo_carro].valor_diaria *(float)temp.numero_diarias) + v_carros[temp.codigo_carro].valor_seguro,
           v_carros[temp.codigo_carro].valor_diaria *(float)temp.numero_diarias);

    input_int(&go,SIM,NAO,"Deseja incluir o seguro? 1=Sim, 2=Nao:  ");
    if(go == SIM)
    {
        temp.seguro = 'S';
        temp.valor = (v_carros[temp.codigo_carro].valor_diaria *(float)temp.numero_diarias) + v_carros[temp.codigo_carro].valor_seguro;
    }
    else
    {
        temp.seguro = 'N';
        temp.valor = v_carros[temp.codigo_carro].valor_diaria *(float)temp.numero_diarias;
    }

    input_int(&go,SIM,NAO,"\nDeseja confirmar a operacao? 1=Sim, 2=Nao:  ");
    if(go == NAO)
    {
        printf("Operacao cancelada");
        return  NOK;
    }
    else
    {
        v_alugueis[qtd_alugueis_vetor] = temp;
        v_alugueis[qtd_alugueis_vetor].codigo = qtd_alugueis_vetor;
        v_alugueis[qtd_alugueis_vetor].status = 'L';
        printf("Aluguel cadastrado. Codigo: %d\n", qtd_alugueis_vetor);
        qtd_alugueis_vetor++;
        return OK;
    }
}

int novo_aluguel_proc()
{
    cadastra_novo_aluguel(aluguel, carro, cliente);
    return OK;
}

int devolver(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes)
{
    int aux;
    if(encontrar_aluguel(codigo, v_alugueis, v_carros, v_clientes) == OK)
    {
        input_int(&aux,SIM,NAO,"\nDeseja finalizar esse aluguel? 1=Sim, 2=Nao:  ");
        if(aux == SIM)
        {
            v_alugueis[codigo].status = 'E';
            printf("Aluguel finalizado!");
        return OK;
        }
    }
    return NOK;
}
int devolucao_proc()
{
    int codigo_aluguel;
    input_int(&codigo_aluguel,1,qtd_alugueis_vetor, "Informe o codigo do aluguel:  ");
    return devolver(codigo_aluguel, aluguel, carro, cliente);
}


int lista_alugueis(int codigo, alugueis_t *v_alugueis, carros_t *v_carros, clientes_t *v_clientes)
{
    int counter, achei = NOK;

    for(counter = 1; counter < qtd_alugueis_vetor; counter++)
    {
        if(v_alugueis[counter].codigo_cliente == codigo)
        {
            printa_aluguel(counter, v_alugueis, v_carros, v_clientes);
            achei = OK;
        }
    }
    return achei;
}


int lista_alugueis_proc()
{
    int aux;
    input_int(&aux,1,qtd_alugueis_vetor, "Informe o codigo do cliente:  ");
    return lista_alugueis(aux, aluguel, carro, cliente);
}


int salvar_alugueis_bin(FILE *arquivo_bin, alugueis_t *vetor)
{
    int counter;
    fprintf(arquivo_bin, "cod_aluguel,cod_cliente,cod_carro,dia,mes,ano,diarias,valor,seguro,situacao\n");
    for(counter = 0; counter < qtd_alugueis_vetor; counter++)
    {
        fprintf(arquivo_bin, "%d", vetor[counter].codigo);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].codigo_cliente);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].codigo_carro);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].dia);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].mes);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].ano);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%d", vetor[counter].numero_diarias);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%.2f", vetor[counter].valor);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%c", vetor[counter].seguro);
        fprintf(arquivo_bin, ",");
        fprintf(arquivo_bin, "%c", vetor[counter].status);
        fprintf(arquivo_bin, "\n");
    }
    return OK;
}

int grava_alugueis_proc(){
    FILE *alugueis_bin;
    printf("\nSalvando alugueis no arquivo \"alugueis.bin\"\n");
    alugueis_bin = fopen("alugueis.bin", "w");
    if(alugueis_bin == NULL)
    {
        printf("Erro ao abrir arquivo");
        return NOK;
    }
    else
    {
        salvar_alugueis_bin(alugueis_bin, aluguel);
        fclose(alugueis_bin);
        return OK;
    }
}

int lista_atrasados_proc(){return 0;}
