#include <menu.h>
#include <stdio.h>

funcoes_t menu (void)
{
    int aux;
    printf( "* * * * * * * * * * * LocAU * * * * * * * * * * * * * *\n"
            "* 1.  Carregar clientes do arquivo                    *\n"
            "* 2.  Carregar carros do arquivo                      *\n"
            "* 3.  Carregar alugueis do arquivo                    *\n"
            "* 4.  Carregar todos os dados dos arquivos            *\n"
            "*                                                     *\n"
            "* 5.  Exibir dados de um cliente                      *\n"
            "* 6.  Exibir dados de um carro                        *\n"
            "* 7.  Exibir dados de um aluguel                      *\n"
            "*                                                     *\n"
            "* 8.  Cadastrar novo cliente                          *\n"
            "* 9.  Cadastrar novo carro                            *\n"
            "* 10. Cadastrar novo aluguel                          *\n"
            "*                                                     *\n"
            "* 11. Finalizar aluguel                               *\n"
            "*                                                     *\n"
            "* 12. Exibir carros de uma marca                      *\n"
            "* 13. Exibir carros de uma marca (por ordem de preco) *\n"
            "* 14. Exibir clientes                                 *\n"
            "* 15. Exibir alugueis                                 *\n"
            "* 16. Exibir atrasados                                *\n"
            "*                                                     *\n"
            "* 17. Salvar clientes no arquivo                      *\n"
            "* 18. Salvar carros no arquivo                        *\n"
            "* 19. Salvar alugueis no arquivo                      *\n"
            "* 20. Salvar todos os dados nos arquivos              *\n"
            "*                                                     *\n"
            "* 21. Sair                                            *\n"
            "* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    input_int(&aux,1, FUNCOES_ENUM_END+1, "Digite a opcao desejada: ");

    aux--; // para usar valor como indice no vetor de funcoes
    return aux;
}

