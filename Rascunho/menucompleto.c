#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_itens.h"
#include "biblioteca_pedidos.h"
#include "biblioteca_pontos.h"

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
    int numero_menu, numero_pedido=1, regiao_ponto=1, experiencia_ponto, total_pedidos, regiao_entrega, pedido_cancelamento;
    char pedido, itens_pedido;

do{ imprime_menu();
    printf("\n Digite o n%cmero para acesso do menu: ", 163);
    scanf("%d", &numero_menu);

switch(numero_menu){
    case 1: printf("\n\t\t Cadastro dos pontos");
    if (regiao_ponto<6){printf("\n O ponto fica localizado em: ", 198);
            printf("\n 1-centro; 2-zona sul; 3-zona leste; 4-zona norte; 5-zona oeste; ");
            printf("\n Qual a experi%cncia em preparo dos cachorros quentes? ", 136);
            printf("\n 1- baixa, 2- m%cdia, 3- alta ", 130);
            scanf("%d",&experiencia_ponto);}// if
            else printf("\n Todas as regi%ces j%c foram cadastradas ", 228,160 );
            break;

    case 2: printf("\n\t\t  Pedido");

            printf("\n N%cmero pedido: &d ", 163, numero_pedido);
            printf("\n Qual a regi%co de entrega?", 198 );
            printf("\n 1-centro; 2-zona sul; 3-zona leste; 4-zona norte; 5-zona oeste; ");
            scanf("%d",&regiao_entrega);
            do{printf("Itens do pedido: ");
                scanf("%c", &itens_pedido);
                }while(itens_pedido = 'sair');
            printf("\n Tempo de entrega: ");
            // funcao
            printf("\n Valor total pedido: ");
            // funcao
            numero_pedido++;
            break;

    case 3: printf("\n\t\t Atendimento do pedido ");
            break;

    case 4: printf("\n\t\t Cancelamento pedido" );
            printf("Qual o n%cmero do pedido? ", 163);
            scanf("%d",&pedido_cancelamento);
            break;

    case 5: printf("\n\t\t Relat%crio dos pontos" 162);
            break;

    case 6: printf("\n\t\t Relat%crio ponto ", 162);
            break;

    case 7: printf("\n\t\t Relat%crio pedido", 162);
            break;

    case 8: printf("\n\t\t Dados");
       break;

         }// switch
}while(numero_menu!=0);

    return 0;

}


