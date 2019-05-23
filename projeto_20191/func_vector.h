#include <carros.h>
#include <clientes.h>
#include <alugueis.h>
#include <todos.h>

extern int leitura_clientes_proc();
extern int leitura_carros_proc();
extern int leitura_alugueis_proc();
extern int leitura_todos_proc();

extern int info_cliente_proc();
extern int info_carro_proc();
extern int info_aluguel_proc();

extern int novo_cliente_proc();
extern int novo_carro_proc();
extern int novo_aluguel_proc();

extern int devolucao_proc();

extern int lista_carros_proc();
extern int lista_carros_preco_proc();
extern int lista_clientes_proc();
extern int lista_alugueis_proc();
extern int lista_atrasados_proc();

extern int grava_clientes_proc();
extern int grava_carros_proc();
extern int grava_alugueis_proc();
extern int grava_todos_proc();

typedef int procedure_t();

procedure_t *FUNC_VECTOR[22] =
{
    leitura_clientes_proc,
    leitura_carros_proc,
    leitura_alugueis_proc,
    leitura_todos_proc,

    info_cliente_proc,
    info_carro_proc,
    info_aluguel_proc,

    novo_cliente_proc,
    novo_carro_proc,
    novo_aluguel_proc,

    devolucao_proc,

    lista_carros_proc,
    lista_carros_preco_proc,
    lista_clientes_proc,
    lista_alugueis_proc,
    lista_atrasados_proc,

    grava_clientes_proc,
    grava_carros_proc,
    grava_alugueis_proc,
    grava_todos_proc,
};
