//Alcides Gomes Beato Neto	19060987
//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon		19243633

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "biblioteca_itens.h"
#include "biblioteca_pedidos.h"
#include "biblioteca_pontos.h"

void tela_inicial(int n);
void imprime_linha();
void imprime_linha_acima(int N);
void imprime_linha_abaixo(int N);
void imprime_menu();
void gerar_pontos(Pontos **ponto, int *numeropedido, int *regiao_pont);

int main(){
    system("color 0F");

	Pontos *Carrinhos = Cria_Ponto();
    int numero_menu, numero_pedido = 1, regiao_ponto = 1,
    experiencia, regiao, quantidade, aux, pedido, verificacao,opcao;
    float valor;
    char descricao[40], obs[50];
	srand(time (NULL));

	system("cls");
	tela_inicial(15);
	system("cls");
	tela_inicial(25);
	system("cls");
	tela_inicial(40);
	system("cls");
	tela_inicial(50);

    do{
        system("cls");
        imprime_menu();///impressao do menu
        scanf("%d", &numero_menu);

        switch(numero_menu){
        case 1:
            system("cls");

            imprime_linha_acima(21);

            printf("\n\t\t%c Cadastro dos pontos %c",179,179);

            imprime_linha_abaixo(21);

            if(regiao_ponto < 6){
                printf("\n\n\t Ponto - ");
                switch(regiao_ponto){
                    case 1:
                        printf("Centro.");
                        break;
                    case 2:
                        printf("Zona Sul.");
                        break;
                    case 3:
                        printf("Zona Leste.");
                        break;
                    case 4:
                        printf("Zona Norte.");
                        break;
                    case 5:
                        printf("Zona Oeste.");
                        break;
                }
                do{
                    printf("\n\n\t Qual a experi%cncia em preparo dos cachorros quentes? ", 136);
                    printf("\n\t 1 - Baixa.\n\t 2 - M%cdia.\n\t 3 - Alta.\n\t-> ", 130);
                    scanf("%d",&experiencia);
                    if(experiencia < 1 || experiencia > 3){
                        system("cls");

						imprime_linha_acima(21);
						printf("\n\t\t%c Cadastro dos pontos %c",179,179);
						imprime_linha_abaixo(21);

						printf("\n\tErro! Insira o valor dentro do intervalo.\n");
                    }
                }while(experiencia < 1 || experiencia > 3);
                Insere_Ponto(&Carrinhos,regiao_ponto,experiencia);
                regiao_ponto++;
                system("cls");
                printf("\n\tPonto cadastrado com sucesso\n\n");
            }
            else
                printf("\n\t Todas as regi%ces j%c foram cadastradas.\n", 228, 160);
            system("pause");
            break;

        case 2:
            system("cls");
            if(!Vazia_Lista_Pontos(Carrinhos)){
                imprime_linha_acima(8);

                printf("\n\t\t%c Pedido %c",179,179);

                imprime_linha_abaixo(8);

                printf("\n\t N%cmero pedido: %d ", 163, numero_pedido);
                do{
                    printf("\n\t Qual a regi%co de entrega?", 198);
                    printf("\n\t 1 - centro.\n\t 2 - zona sul.\n\t 3 - zona leste.\n\t 4 - zona norte.\n\t 5 - zona oeste.\n\t-> ");
                    scanf("%d",&regiao);
                }while(regiao < 1 || regiao > 5);
                aux = Busca_Ponto(Carrinhos, regiao);
                if(aux != -1)///conferencia ponto em funcionamento
                    Insere_Pedidos(Carrinhos, numero_pedido,regiao,aux);
                else///senao redireciona para o centro
                    Insere_Pedidos(Carrinhos, numero_pedido,regiao,1);
                do{
                    fflush(stdin);
                    printf("\n\t Insira o nome do item: ");
                    gets(descricao);
                    printf("\n\t Insira o valor unit%crio: ", 160);
                    scanf("%f",&valor);
                    printf("\n\t Insira a quantidade de itens: ");
                    scanf("%d",&quantidade);
                    fflush(stdin);
                    printf("\n\t Insira uma observa%c%co ou digite <enter>: ", 135, 198);
                    gets(obs);
                    if(aux != -1)///conferencia ponto em funcionamento
                        Insere_Itens(Carrinhos, quantidade, aux, valor, descricao, obs);
                    else///senao redireciona para o centro
                        Insere_Itens(Carrinhos, quantidade, 1, valor, descricao, obs);
                    do{
                        printf("\n\t Deseja inserir mais um item?\n\t0 - N%co.\n\t1 - Sim.\n\t -> ",198);
                        scanf("%d",&opcao);
                        system("cls");
                    }while(opcao < 0 || opcao > 1);
                }while(opcao == 1);
                if(aux != -1)///conferencia ponto em funcionamento
                    Insere_Valor_totais(Carrinhos,aux);
                else ///senao redireciona para o centro
                    Insere_Valor_totais(Carrinhos,1);
                printf("\n\tPedido cadastrado com sucesso.\n");
                numero_pedido++;
            }
            else
                printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
            system("pause");
            break;

        case 3:
            system("cls");

			imprime_linha_acima(23);
            printf("\n\t\t%c Atendimento do pedido %c",179,179);
            imprime_linha_abaixo(23);

			if(!Vazia_Lista_Pontos(Carrinhos)){
                do{
                    printf("\n\t 1 - Centro.\n\t 2 - Zona sul.\n\t 3 - Zona leste.\n\t 4 - Zona norte.\n\t 5 - Zona oeste.\n\t");
                    printf("\n\t Insira a regi%co a ser atendida: ",198);
                    scanf("%d",&regiao);
					if(regiao > 5 || regiao < 1){
						system("cls");

						imprime_linha_acima(23);
						printf("\n\t\t%c Atendimento do pedido %c",179,179);
						imprime_linha_abaixo(23);

						printf("\n\tInsira uma regi%co v%clida\n", 198, 160);
					}
                }while(regiao > 5 || regiao < 1);
                aux = Busca_Ponto(Carrinhos, regiao);
                system("color E0");
                system("cls");
                if(aux != -1)
                    Atendimento_Pedido(Carrinhos, aux);
                else
                    Atendimento_Pedido(Carrinhos, 1);
                system("pause");
                system("color 0F");
            }
            else{
                printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
                system("pause");
            }
            break;

        case 4:
            system("cls");

			imprime_linha_acima(21);
            printf("\n\t\t%c Cancelamento pedido %c", 179,179);
			imprime_linha_abaixo(21);

			if(!Vazia_Lista_Pontos(Carrinhos)){
                do{
					printf("\n\t 1 - Centro.\n\t 2 - Zona sul.\n\t 3 - Zona leste.\n\t 4 - Zona norte.\n\t 5 - Zona oeste.\n\t");
                    printf("\n\tInsira a regi%co do pedido:",198);
                    scanf("%d",&regiao);
					if(regiao > 5 || regiao < 1){
						system("cls");

						imprime_linha_acima(21);
						printf("\n\t\t%c Cancelamento pedido %c", 179,179);
						imprime_linha_abaixo(21);

						printf("\n\tInsira uma regi%co v%clida\n", 198, 160);
					}
                }while(regiao > 5 || regiao < 1);

                printf("\n\tQual o n%cmero do pedido?\n\t->", 163);
                scanf("%d",&pedido);

                aux = Busca_Ponto(Carrinhos,regiao);
                if(aux != -1)
                    Cancela_Pedido_Ponto(Carrinhos,pedido,aux);
                else
                    Cancela_Pedido_Ponto(Carrinhos,pedido,1);
            }
            else
                printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
            system("pause");
            break;

        case 5:
            system("cls");

			imprime_linha_acima(22);
            printf("\n\t\t%c Relat%crio dos pontos %c",179 , 162, 179);
            imprime_linha_abaixo(22);

			if(!Vazia_Lista_Pontos(Carrinhos)){
                Imprime_Pontos(Carrinhos);
            }
			else
                printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
            system("pause");
            break;

        case 6:
            system("cls");

			imprime_linha_acima(19);
            printf("\n\t\t%c Relat%crio pedidos %c",179, 162, 179);
            imprime_linha_abaixo(19);

            if(!Vazia_Lista_Pontos(Carrinhos)){
                do{
                    printf("\n\tInsira a regi%co do pedido:",198);
                    scanf("%d",&regiao);
                    if(regiao > 5 || regiao < 1){
                        printf("\n\tRegi%co inv%clida.", 198, 160);
                        system("pause");
                        system("cls");

						imprime_linha_acima(19);
						printf("\n\t\t%c Relat%crio pedidos %c",179, 162, 179);
						imprime_linha_abaixo(19);
                    }
                }while(regiao > 5 || regiao < 1);

                aux = Busca_Ponto(Carrinhos,regiao);
                if(aux != -1)
                    Imprime_Pedidos_Pontos(Carrinhos, aux);
                else
                    Imprime_Pedidos_Pontos(Carrinhos, 1);

            }else
                 printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
            system("pause");
            break;

        case 7:
            system("cls");

            imprime_linha_acima(30);
            printf("\n\t\t%c Relat%crio de itens do pedido %c", 179, 162, 179);
            imprime_linha_abaixo(30);

            if(!Vazia_Lista_Pontos(Carrinhos)){
				if(Carrinhos->pedidos->inicio == NULL) //Verifica se existe pedidos
					printf("\n\tInsira Pedidos!");
				else{
					printf("\n\tInsira o n%cmero do pedido:", 163);
                    scanf("%d", &pedido);
                    verificacao = Busca_Num_Pedidos(Carrinhos, pedido);//Retorna a posiçao do ponto na lista e retorna 0 se o pedido não existe
                    if(verificacao == 0){//Nao achou
                        system("cls");
                        printf("\n\tInsira um n%cmero de pedido v%clido\n", 163, 160);
                    }
					else
						Imprime_Itens_Pontos(Carrinhos, verificacao, pedido);
				}
			}
			else
                printf("\n\tInsira um ponto para realizar essa op%c%co.\n",135,198);
            system("pause");
            break;

        case 8:
            system("cls");
            if(Vazia_Lista_Pontos(Carrinhos)){
                imprime_linha_acima(7);

                printf("\n\t\t%c Dados %c",179,179);

                imprime_linha_abaixo(7);
                gerar_pontos(&Carrinhos, &numero_pedido, &regiao_ponto);
				printf("\n\tDado cadastrados com sucesso!\n");
            }else
                 printf("\n\tH%c carrinhos cadastrados.\n",160);
            system("pause");
            break;

        }
    }while(numero_menu != 0);

    Arquivo_Ponto(Carrinhos); //gera um arquivo com os dados dos pontos em um .txt
	Carrinhos = Desaloca_Pontos(Carrinhos);
    return 0;

}

void tela_inicial(int n){
	int i;

	printf("\n\t\t\t\t    %c%c%c %c%c%c",219,219,187,219,219,187);
	printf("\n\t\t\t\t  %c%c%c%c%c%c%c%c%c",219,219,201,205,219,219,201,205,188);
	printf("\n\t\t\t\t  %c%c%c %c%c%c  ",200,205,188,200,205,188);

	//linha 1/6
	printf("\n\t");

	for(i = 0; i < 6; i++) printf("%c",219); printf("%c ",187); //D
	printf(" ");for(i = 0; i < 6; i++) printf("%c",219); printf("%c",187); //O
	printf("  "); for(i = 0; i < 7;i ++){printf("%c", 219);} printf("%c", 187); //G
	printf(" ");for(i = 0; i < 5; i++) printf("%c",219); printf("%c ",187); //Ã
	printf(" ");for(i = 0; i < 6; i++) printf("%c",219); printf("%c",187); //O

	//linha 2/6
	printf("\n\t");

	printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187); //D
	printf("%c%c%c%c%c%c%c%c%c",219,219,201,205,205,205,219,219,187); //O
	printf("%c%c%c", 219,219,201); for(i = 0; i < 5; i++){printf("%c", 205);} printf("%c",188 ); //G
	printf("%c%c",219,219);printf("%c",201);printf("%c%c",205,205);printf("%c%c",219,219);printf("%c",187); //Ã
	printf("%c%c%c%c%c%c%c%c%c",219,219,201,205,205,205,219,219,187); //O

	//linha 3/6
	printf("\n\t");

	printf("%c%c%c  %c%c%c",219,219,186,219,219,186); //D
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186); //O
	printf("%c%c%c", 219,219,186); printf("  "); printf("%c%c%c%c", 219,219,219,187);// G
	for(i = 0; i < 7; i++) printf("%c",219); printf("%c",186);//Ã
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186);//O

	//linha 4/6
	printf("\n\t");

	printf("%c%c%c  %c%c%c",219,219,186,219,219,186);
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186);
	printf("%c%c%c", 219,219,186); printf("   "); printf("%c%c%c", 219,219,186);
	printf("%c%c",219,219);printf("%c",201);printf("%c%c",205,205);printf("%c%c",219,219);printf("%c",186);
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186);

	//linha 5/6
	printf("\n\t");

	for(i = 0; i < 6; i++) printf("%c",219);printf("%c%c",201,188);
	printf("%c",200);for(i = 0; i < 6; i++) printf("%c",219);printf("%c%c",201,188);
	printf("%c", 200); for(i = 0; i < 6; i++){printf("%c", 219);} printf("%c%c",201,188 );
	printf("%c%c",219,219);printf("%c  ",186);printf("%c%c",219,219);printf("%c",186);
	printf("%c",200);for(i = 0; i < 6; i++) printf("%c",219);printf("%c%c",201,188);

	//linha 6/6
	printf("\n\t");

	printf("%c",200);for(i = 0; i < 5; i++) printf("%c",205);printf("%c ",188);
	printf(" ");printf("%c",200);for(i = 0; i < 5; i++) printf("%c",205);printf("%c ",188);
	printf(" %c",200); for(i = 0; i < 5; i++){printf("%c", 205);} printf("%c ",188);
	printf("%c%c%c  %c%c%c",200,205,188,200,205,188);
	printf(" ");printf("%c",200);for(i = 0; i < 5; i++) printf("%c",205);printf("%c ",188);



	printf("\n\n\t\t");

	for(i = 0; i < 6; i++) printf("%c",219); printf("%c ",187);
	printf(" ");for(i = 0; i < 6; i++) printf("%c",219); printf("%c ",187);

	printf("\n\t\t");

	printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
	printf("%c%c%c%c%c%c%c%c%c",219,219,201,205,205,205,219,219,187);

	printf("\n\t\t");

	printf("%c%c%c  %c%c%c",219,219,186,219,219,186);
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186);

	printf("\n\t\t");

	printf("%c%c%c  %c%c%c",219,219,186,219,219,186);
	printf("%c%c%c   %c%c%c",219,219,186,219,219,186);

	printf("\n\t\t");

	for(i = 0; i < 6; i++) printf("%c",219);printf("%c%c",201,188);
	printf("%c",200);for(i = 0; i < 6; i++) printf("%c",219);printf("%c%c",201,188);
	printf("     %c%c%c",219,219,187);

	printf("\n\t\t");

	printf("%c",200);for(i = 0; i < 5; i++) printf("%c",205);printf("%c ",188);
	printf(" ");printf("%c",200);for(i=0;i<5;i++) printf("%c",205);printf("%c ",188);
	printf("   %c%c%c%c%c",219,219,201,205,188);

	printf("\n\t\t\t\t ");

	printf("   %c%c%c  ",200,205,188);

	printf("\n\t\t\t");

	printf(" "); for(i = 0; i < 7; i++){printf("%c", 219);} printf("%c", 187);
	for(i = 0; i < 7; i++) printf("%c",219); printf("%c",187);

	printf("\n\t\t\t");

	printf(" %c", 200); printf("%c%c",205,205); printf("%c%c%c",219,219,219); printf("%c%c",201,188);
	printf("%c%c",219,219); printf("%c",201);for(i = 0; i < 4; i++) printf("%c",205);printf("%c",188);

	printf("\n\t\t\t");

	printf("   "); printf("%c%c%c",219,219,219); printf("%c%c ",201,188);
	for(i = 0; i < 5; i++) printf("%c",219); printf("%c  ",187);

	printf("\n\t\t\t");

	printf("  "); printf("%c%c%c",219,219,219); printf("%c%c  ",201,188);
	printf("%c%c",219,219); printf("%c",201); printf("%c%c",205,205); printf("%c  ",188);

	printf("\n\t\t\t");

	printf(" "); for(i = 0; i < 7; i++){printf("%c", 219);} printf("%c", 187);
	for(i = 0; i < 7; i++) printf("%c",219); printf("%c",187);

	printf("\n\t\t\t");

	printf(" %c",200); for(i = 0; i < 6; i++){printf("%c", 205);} printf("%c",188);
	printf("%c",200); for(i = 0; i < 6; i++) printf("%c",205); printf("%c",188);

	printf("\n\n\t%c",218);
	for(i = 0; i < 50; i++)
		printf("%c",196);
	printf("%c",191);

	printf("\n\t%c",179);
	for(i = 0; i < n; i++)
		printf("%c",219);
	for(i = 0; i < (50 - n); i++)
		printf(" ");
	printf("%c  %.d%%",179,n*2);

	printf("\n\t%c",192);
	for(i = 0; i < 50; i++)
		printf("%c",196);
	printf("%c",217);

	Sleep(1000);

}

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

void imprime_linha_acima(int N){
    printf("\n\t\t%c",218);
    for(int i = 0; i < N; i++)
        printf("%c",196);
    printf("%c",191);
}

void imprime_linha_abaixo(int N){
     printf("\n\t\t%c",192);
     for(int i = 0; i < N; i++)
        printf("%c",196);
     printf("%c",217);
}

void imprime_menu(){
    int i;
    ///linha superior da tabela
    printf("\n\t%c",218);
    for(i = 0; i < 60; i++)
        printf("%c",196);
    printf("%c",191);

    printf("\n\t%c",179);
    for(i = 0; i < 28; i++)
        printf(" ");
    printf("MENU");
    for(i = 0; i < 28; i++)
        printf(" ");
    printf("%c",179);

    printf("\n\t%c",195);
    for(i = 0; i < 5; i++)
        printf("%c",196);
    printf("%c",194);
    for(i = 0; i < 54; i++)
        printf("%c",196);
    printf("%c",180);


    printf("\n\t%c  0  %c Sair.                                                %c",179,179,179);

    ///linha de separação da tabela
    imprime_linha();

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

void gerar_pontos(Pontos **ponto, int *numeropedido, int *regiao_pont){
	int i, j, k, pnts, xp, pedidos, entrega, quantidade, itens;
	float valor;

	pnts = rand()%5+1;//geração de nº aleatório dos pontos
	while(pnts < 3)
        pnts = rand()%5+1;
	for(i = 0; i < pnts;i++){ // cadastra cada ponto
		xp = rand()%3+1; // escolhe o nível de experiência
        Insere_Ponto(&(*ponto),(*regiao_pont),xp);

		pedidos = rand()%15+1; // sorteia o nº de pedidos
		while(pedidos < 5)
			pedidos = rand()%15+1;
		for(j = 0; j < pedidos; j++){ // cadastra os pedidos
			entrega = rand()%5+1; // sorteia a região de entrega
			Insere_Pedidos((*ponto), (*numeropedido), entrega, (*regiao_pont));
			(*numeropedido)++;
			quantidade = rand()%5+1; // sorteia a quantidade de itens
			for(k = 0; k < quantidade; k++){ // cadastro dos itens
				itens = rand()%5+1; // sorteia a quantidade de cada item
				valor = rand()%1500; // sorteia o preço
				while(valor < 999)
					valor = rand()%1500;
				valor /= 100;
				Insere_Itens(*ponto,itens,(*regiao_pont),valor,"cachorro quente","\0");
			}
			Insere_Valor_totais(*ponto,(*regiao_pont));
		}

		(*regiao_pont)++;//Atualizando a região
	}
}





