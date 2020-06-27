#include <stdio.h>
#include <stdlib.h>

void imprime_linha(){
    int i;
    printf("\n\t%c",195);
    for(i = 0; i < 5; i++)
        printf("%c",196);
    printf("%c",197);
    for(i = 0; i < 54; i++)
        printf("%c",196);
    printf("%c",180);
}

void imprime_menu(){
    int i;
    ///linha superior da tabela
    printf("\n\t%c",218);
    for(i = 0; i < 5; i++)
        printf("%c",196);
    printf("%c",194);
    for(i = 0; i < 54; i++)
        printf("%c",196);
    printf("%c",191);

    printf("\n\t%c  1  %c Cadastrar ponto.                                     %c",179,179,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  2  %c Pedido.                                              %c",179,179,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  3  %c Atender pedido.                                      %c",179,179,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  4  %c Cancelar pedido.                                     %c",179,179,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  5  %c Relat%crio dos pontos.                                %c",179,179,162,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  6  %c Relat%crio de pedidos de um ponto.                    %c",179,179,162,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  7  %c Relat%crio de um pedido.                              %c",179,179,162,179);

    ///linha de separação da tabela
    imprime_linha();

    printf("\n\t%c  8  %c Gerar dados.                                         %c",179,179,179);

    ///linha inferior da tabela
    printf("\n\t%c",192);
    for(i = 0; i < 5; i++)
        printf("%c",196);
    printf("%c",193);
    for(i = 0; i < 54; i++)
        printf("%c",196);
    printf("%c",217);

    printf("\n\n\t-> ");
}

int main(){
    imprime_menu();
    return 0;
}
