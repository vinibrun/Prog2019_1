#include <stdio.h>
#include <stdlib.h>
#include <menu.h>
#include <func_vector.h>
#include <todos.h>

int funcao(int num);


int main()
{
    while(funcao(menu()) != FUNCOES_ENUM_END);
    return 0;
}

/*
int main()
{
    int aux;
    do
    {
        aux = menu();
        aux = funcao(aux);
    }while(aux != FUNCOES_ENUM_END);
    return 0;
}
*/

int funcao(int num){
    int aux, retorno;
    if(num >= 0 && num<FUNCOES_ENUM_END){
        retorno = (*FUNC_VECTOR[num])();
        input_int(&aux,SIM,NAO,"\nDeseja realizar outra operacao? 1=Sim, 2=Nao:  ");
        if(aux == SIM)
            return SIM;
        else
            return FUNCOES_ENUM_END;
    }
    return FUNCOES_ENUM_END;
};

//#include <stdio.h
