//Alcides Gomes Beato Neto 	19060987
//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon 		19243633

//Fila
typedef struct Nof{
    int numero_pedido, regiao_entrega /* centro ; zona sul ; zone leste ; zona norte ; zona oeste */ , tempo;
    float valor_total_pedido;
    Itens *Unidades;
    struct Nof *prox;
}Nof;

typedef struct requisicao{
    Nof *inicio, *fim;
}Requisicao;

//Se a fila de pedidos esta vazia
int Vazio_Pedidos(Requisicao *pedidos){
    if(pedidos->inicio == NULL) return 1;
    return 0;
}

//Criação da fila de pedidos
Requisicao* Cria_Pedido(){
    Requisicao *novo = (Requisicao*)malloc(sizeof(Requisicao));
    if(!novo){ //Caso nao haja memória
        printf("\nErro 404. Mem%cria da fila n%co encontrada", 162, 198);
        exit(0); //encerra o programa
    }
    novo->inicio = novo->fim = NULL;
    return novo;
}

//Retorna o tempo total
int Calcula_Tempo(Requisicao *pedidos, int exp){
    int tempo = 0;
    Nof *aux;
	if(pedidos->inicio != pedidos->fim){
		for(aux = pedidos->inicio ; aux->prox->prox != NULL ; aux = aux->prox)
			continue;
		tempo = (aux->tempo - 15); //pega o tempo do item anterior e retira 15(tempo de entrega)
	}
    tempo = calculo_temp_itens(pedidos->fim->Unidades, tempo, exp);//Retorna o tempo total(Tempo dos itens + o da fila)
    return tempo;
}

//Busca se o pedido existe e retorna a posição
int Busca_num_pedido(Requisicao *pedidos, int num_pedido){
    int posicao = 1;
    for(Nof *aux = pedidos->inicio; aux != NULL; posicao++, aux = aux->prox){
        if(aux->numero_pedido == num_pedido)
            return posicao;
    }
    return -1;
}

//Terceira parte da inserçao (valores totais)
void Insere_Totais(Requisicao *pedido, int exp){
    pedido->fim->tempo = Calcula_Tempo(pedido, exp);
    pedido->fim->valor_total_pedido = Calcula_valor_itens(pedido->fim->Unidades);
}

//Insere itens na pilha da fila
void Insere_os_Itens(Nof *pedido, int quantidade, float valor_unit, char desc_item[], char obs[]){
    push(pedido->Unidades, quantidade, valor_unit, desc_item, obs);
}

//Função auxiliar que aloca na memória a fila
Nof* Insere_Fila_fim(Nof *pedido, int num_pedido, int regiao){
    Nof *novo = (Nof*)malloc(sizeof(Nof));
    novo->Unidades = Cria_itens();
    novo->numero_pedido = num_pedido;
    novo->regiao_entrega = regiao;
	novo->prox = NULL;
	if(pedido != NULL)
		pedido->prox = novo;
    return novo;
}

//Funçao que insere no final da fila as informaçoes essenciais para criação de pedido
void Insere_Fila(Requisicao *pedidos, int num_pedido, int regiao){
    pedidos->fim = Insere_Fila_fim(pedidos->fim, num_pedido, regiao);
    if(pedidos->inicio == NULL) /* fila antes vazia? */
        pedidos->inicio = pedidos->fim;
	if(Vazio_Pedidos(pedidos)){
		printf("\n\tErro de alocamento.");
		exit(0);
	}
}

//Retira os pedidos da fila
void Retira_Pedidos(Requisicao *pedidos){
    Nof *aux = pedidos->inicio;
    pedidos->inicio = pedidos->inicio->prox;
	//pedidos->inicio->Unidades = Libera_itens(pedidos->inicio->Unidades); // itens do pedido ja desalocados no atendimento
    free(aux);
}

//Função que recalcula o tempo dos pedidos anteriores ao pedido cancelado
int Recalcula_Tempo(Nof *pedido, int tempo_ant, int xp){
    if(tempo_ant == 0)
        return calculo_temp_itens(pedido->Unidades, tempo_ant, xp);
    else
        return calculo_temp_itens(pedido->Unidades, (tempo_ant - 15), xp);
}

//Função que cancela o pedido
int Cancela_Pedido_Fila(Requisicao *pedidos, int num_pedido, int xp){
    Nof *aux = pedidos->inicio, *ant = NULL;
	int pos = Busca_num_pedido(pedidos, num_pedido), i;
	if(pos > 0){ //posição iniciando em 1
		if(pos == 1)//O primeiro pedido da fila será removido
		{
			pedidos->inicio = aux->prox;
			aux->Unidades = Libera_itens(aux->Unidades);//Libera a Pilha do pedido
			free(aux);
            aux = pedidos->inicio;
            while(aux != NULL){
                if(ant != NULL)
                    aux->tempo = Recalcula_Tempo(aux, (ant->tempo - 15), xp);
                else
                    aux->tempo = Recalcula_Tempo(aux, 0, xp);
                ant = aux;
                aux = aux->prox;
            }
            printf("\n\tPedido cancelado com sucesso!\n");
            return 1;
		}
		else{//É em outra posição qualquer
			for(ant = pedidos->inicio, aux = aux->prox, i = 2; aux != NULL; i++, ant = aux, aux = aux->prox){
				if(pos == i){//Achou o pedido que sera excluido
					if(aux->prox != NULL)
					{
						ant->prox = aux->prox;
						aux->Unidades = Libera_itens(aux->Unidades);//Libera a Pilha do pedido
						free(aux);
                        aux = ant->prox;
                        while(aux != NULL){
                            aux->tempo = Recalcula_Tempo(aux, (ant->tempo - 15), xp);
                            ant = aux;
                            aux = aux->prox;
                        }
					}
					else{//Se for o último da fila
						ant->prox = aux->prox;
						aux->Unidades = Libera_itens(aux->Unidades);//Libera a Pilha do pedido
						free(aux);
						pedidos->fim = ant;
					}
					printf("\n\tPedido cancelado com sucesso!\n");
                    return 1;
				}
			}
		}
	}
	else{
		printf("\n\tErro 404: pedido n%co encontrado!\n",198);
        return 0;
	}
}

//Impressao da nota fiscal - parte pedido
void imprime_nota_fila(Nof *aux){
    int i,quantidade;
	float valor_item,valor_total_item;
	char desc[40],obs[50];
    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\tN%c pedido: %d",167,aux->numero_pedido);
    printf("\n\tRegi%co de entrega: %d - ",198,aux->regiao_entrega);
    switch(aux->regiao_entrega){
        case 1:
            printf("Centro");
            break;
        case 2:
            printf("Zona Sul");
            break;
        case 3:
            printf("Zona Leste");
            break;
        case 4:
            printf("Zona Norte");
            break;
        case 5:
            printf("Zona Oeste");
            break;
    }
    printf("\n\tTempo de entrega: %d min",aux->tempo);
	printf("\n\tITEM\tQUANTIDADE\tVALOR UNIDADE\t\tSUBTOTAL");
    printf("\n\t");
    for(int i = 0; i < 60; i++)
        printf("-");

    while(!Vazia_Itens(aux->Unidades)){
		pop(aux->Unidades,&quantidade,&valor_item,&valor_total_item,desc,obs);
        printf("\n\t%s",desc);
        printf("\n\t\t\t%d\t\t%.2f\t\t%.2f",quantidade,valor_item,valor_total_item);
        if(strcmp(obs,"\0") != 0)
            printf("\n\t %s",obs);
    }

    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\tTOTAL:\t\t\t\t\t\t%.2f\n",aux->valor_total_pedido);

}

//impressão de pedidos em aberto (relatorio)
void Imprime_Relatorio_fila(Nof *Pedido){
    int i;
	for(Nof *aux = Pedido; aux != NULL; aux = aux->prox){
		printf("\n\t%c",218);
		for(i = 0; i < 60; i++)
			printf("%c",196);
		printf("%c",191);

		printf("\n\t%c N%c pedido: %4d Regi%co de entrega: %d - ",179,167,aux->numero_pedido,198,aux->regiao_entrega);
		switch(aux->regiao_entrega){
			case 1:
				printf("Centro");
				for(i = 0; i < 14; i++)
					printf(" ");
				printf("%c",179);
				break;
			case 2:
				printf("Zona Sul");
				for(i = 0; i < 12; i++)
					printf(" ");
				printf("%c",179);
				break;
			case 3:
				printf("Zona Leste");
				for(i = 0; i < 10; i++)
					printf(" ");
				printf("%c",179);
				break;
			case 4:
				printf("Zona Norte");
				for(i = 0; i < 10; i++)
					printf(" ");
				printf("%c",179);
				break;
			case 5:
				printf("Zona Oeste");
				for(i = 0; i < 10; i++)
					printf(" ");
				printf("%c",179);
				break;
		}
		printf("\n\t%cTempo de entrega: %3d min ",179,aux->tempo);
		for(i = 0; i < 34; i++)
			printf(" ");
		printf("%c",179);

		impressao_relatorio_pilha(aux->Unidades->inicio);

		printf("\n\t%c TOTAL:",179);
		for(i = 0; i < 46; i++)
			printf(" ");
		printf("%6.2f %c",aux->valor_total_pedido,179);

		printf("\n\t%c",192);
		for(i = 0; i < 60; i++)
			printf("%c",196);
		printf("%c\n\n",217);
	}
}

//impressao do relatorio Pilha
void Impressao_Fila_Itens(Nof *Fila, int Num){
    Nof *aux;
	int i;
    for(aux = Fila; aux != NULL; aux = aux->prox){
        if(aux->numero_pedido == Num){//Achou o pedido
			printf("\n\t%c",218);
			for(i = 0; i < 60; i++)
				printf("%c",196);
			printf("%c",191);

			printf("\n\t%c N%c pedido: %4d Regi%co de entrega: %d - ",179,167,aux->numero_pedido,198,aux->regiao_entrega);
			switch(aux->regiao_entrega){
				case 1:
					printf("Centro");
					for(i = 0; i < 14; i++)
						printf(" ");
					printf("%c",179);
					break;
				case 2:
					printf("Zona Sul");
					for(i = 0; i < 12; i++)
						printf(" ");
					printf("%c",179);
					break;
				case 3:
					printf("Zona Leste");
					for(i = 0; i < 10; i++)
						printf(" ");
					printf("%c",179);
					break;
				case 4:
					printf("Zona Norte");
					for(i = 0; i < 10; i++)
						printf(" ");
					printf("%c",179);
					break;
				case 5:
					printf("Zona Oeste");
					for(i = 0; i < 10; i++)
						printf(" ");
					printf("%c",179);
					break;
			}
			printf("\n\t%cTempo de entrega: %3d min ",179,aux->tempo);
			for(i = 0; i < 34; i++)
				printf(" ");
			printf("%c",179);

			impressao_relatorio_pilha(aux->Unidades->inicio);

			printf("\n\t%c TOTAL:",179);
			for(i = 0; i < 46; i++)
				printf(" ");
			printf("%6.2f %c",aux->valor_total_pedido,179);

			printf("\n\t%c",192);
			for(i = 0; i < 60; i++)
				printf("%c",196);
			printf("%c\n\n",217);
            break;
        }
    }
}

Requisicao* Desaloca_Pedidos(Requisicao *pedidos){
    Nof *aux = pedidos->inicio, *aux2;

    while(aux != NULL){
        aux2 = aux->prox;
        aux->Unidades = Libera_itens(aux->Unidades); //desaloca primeiro a pilha
        free(aux);
        aux = aux2;
    }
    free(pedidos);
    return NULL;
}

