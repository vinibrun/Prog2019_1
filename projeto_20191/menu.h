







enum funcoes_enum
{
    LEITURA_CLIENTES = 0,
    LEITURA_CARROS,
    LEITURA_ALUGUEIS,
    LEITURA_TODOS,

    INFO_CLIENTE,
    INFO_CARRO,
    INFO_ALUGUEL,

    NOVO_CLIENTE,
    NOVO_CARRO,
    NOVO_ALUGUEL,

    DEVOLUCAO,

    LISTA_CARROS,
    LISTA_CARROS_PRECO,
    LISTA_CLIENTES,
    LISTA_ALUGUEIS,
    LISTA_ATRASADOS,

    GRAVA_CLIENTES,
    GRAVA_CARROS,
    GRAVA_ALUGUEIS,
    GRAVA_TODOS,

    FUNCOES_ENUM_END
};

typedef enum funcoes_enum funcoes_t;

funcoes_t menu(void);

