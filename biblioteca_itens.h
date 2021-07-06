//Alcides Gomes Beato Neto 	19060987
//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon 		19243633

//pilha
typedef struct nop{
    char item[40], observacao[50];
    int quantidade;
    float valor_unidade, valor_total_tipo;
    struct nop *prox;
}Nop;

typedef struct itens{
    Nop *inicio;
}Itens;

//Criaçao da pilha de itens do pedido
Itens* Cria_itens(){
    Itens *novo = (Itens*)malloc(sizeof(Itens));
    if(!novo){ //Caso nao haja memoria
        printf("\nErro 404. Mem%cria da Pilha n%co encontrada",162, 198);
        exit(0); //encerra o programa
    }
    novo->inicio = NULL;
    return novo;
}

//Vericaçao se a pilha de itens esta vazia
int Vazia_Itens(Itens *unidade){
    if(unidade->inicio == NULL) return 1;
    return 0;
}

//Funçao auxiliar para push
Nop *Insere_Pilha(Nop *unidade, int quantidade, float valor_unidade, char item[], char obs[]){
    Nop *novo = (Nop*)malloc(sizeof(Nop));
    novo->prox = unidade;
    novo->quantidade = quantidade;
    novo->valor_unidade = valor_unidade;
    novo->valor_total_tipo = valor_unidade * quantidade;
    strcpy(novo->item,item);
    strcpy(novo->observacao,obs);
    return novo;
}

//Funçao push dos itens
void push(Itens *unidade, int quantidade, float valor_unidade, char item[], char obs[]){
    unidade->inicio = Insere_Pilha(unidade->inicio, quantidade, valor_unidade, item, obs);
	if(Vazia_Itens(unidade)){
		printf("Erro de alocamento");
		exit(0);
	}
}

//Calculo do tempo total de entrega(Tempo calculado na funçao anterior(fila) + o tempo dos itens do pedidos)
int calculo_temp_itens(Itens *itens_pedido, int tempo_ant, int exp){
    int quantidade = 0, tempo = 0;
    Nop *aux;
    for(aux = itens_pedido->inicio; aux != NULL; aux = aux->prox){
        quantidade += aux->quantidade;//Soma a quantidade total de item
    }
    switch(exp)
    {
        case 1: //Baixa
            tempo = quantidade * 5;
            break;
        case 2: //Media
            tempo = quantidade * 3;
            break;
        case 3://Alta
            tempo = quantidade * 2;
            break;
    }
    tempo += tempo_ant;//Somando o tempo calculado anteriormente(Tempo da fila)
    tempo += 20;//Tempo de fechamento = 5 e tempo de entrega = 15;
    return tempo;
}

//Calcula o valor total dos itens
float Calcula_valor_itens(Itens *Item){
    float valor = 0;
    Nop *aux;
    for(aux = Item->inicio; aux != NULL; aux = aux->prox){
        valor += aux->valor_total_tipo; //soma os subtotais de cada item da pilha
    }
    return valor;
}

//Funçao auxiliar para remoçao
Nop* Retira_Pilha(Nop *unidade_no){
    Nop *aux = unidade_no->prox;
    free(unidade_no);
    return aux;
}

//Funçao pop dos itens
void pop(Itens *unidade,int *quantidade,float *valor_item,float *valor_total_item,char desc[],char obs[]){
    if(Vazia_Itens(unidade)){
        printf("\n\tO pedido nao possui itens.\n");
        exit(1);
    }
	//passa os valores pelo parâmetro para emitir a nota fiscal
	*quantidade = unidade->inicio->quantidade;
	*valor_item = unidade->inicio->valor_unidade;
	*valor_total_item = unidade->inicio->valor_total_tipo;
	strcpy(desc,unidade->inicio->item);
	strcpy(obs,unidade->inicio->observacao);
    unidade->inicio = Retira_Pilha(unidade->inicio);
}

/*
//Impressao da nota fiscal - parte itens
void imprime_nota_pilha(Itens *pilha){
    printf("\n\tITEM\tQUANTIDADE\tVALOR UNIDADE\t\tSUBTOTAL");
    printf("\n\t");
    for(int i = 0; i < 60; i++)
        printf("-");
    for(Nop *aux = pilha->inicio; aux != NULL; aux = aux->prox){
        printf("\n\t%s",pilha->inicio->item);
        printf("\n\t\t\t%d\t\t%.2f\t\t%.2f",aux->quantidade,aux->valor_unidade,aux->valor_total_tipo);
        if(strcmp(pilha->inicio->observacao,"\0") != 0)
            printf("\n\t %s",pilha->inicio->observacao);
    }
}
*/

//impressao relatório com a fila
void impressao_relatorio_pilha(Nop *pilha){
	int i, n;
    printf("\n\t%cITEM\t QUANTIDADE \t VALOR UNIDADE \t\t SUBTOTAL    %c",179,179);
    for(Nop *aux = pilha; aux != NULL; aux = aux->prox){
		n = strlen(aux->item);
		n = 59 - n;
        printf("\n\t%c %s",179,aux->item);
		for(i = 0; i < n; i++)
			printf(" ");
        printf("%c",179);

        printf("\n\t%c",179);
		for(i = 0; i < 15; i++)
			printf(" ");
		printf("%3d",aux->quantidade);

		for(i = 0; i < 13; i++)
			printf(" ");

		printf("%6.2f",aux->valor_unidade);

		for(i = 0; i < 16; i++)
			printf(" ");


		printf("%6.2f %c",aux->valor_total_tipo,179);

        if(strcmp(aux->observacao,"\0") != 0){
            printf("\n\t%c %s",179,aux->observacao);
			n = strlen(aux->observacao);
			n = 60 - (n + 1);
			for(i = 0; i < n; i++)
				printf(" ");
            printf("%c",179);
		}
    }
}
 ///impressão simples
/*
//Impressao de todos os itens de um pedido
void Imprime_itens(Itens *unidade){
    if(Vazia_Pilha(unidade)){
        printf("\n\tO pedido nao possui itens.\n");
        exit(1);
    }
    else{
        printf("\n\tLista de itens:");
        for(Nop *aux = unidade->inicio; aux != NULL; aux = aux->prox){
            printf("\n\t%s",aux->item);
            printf("\t%3d",aux->quantidade);
            printf("\t%6.2f\t%6.2f",aux->valor_unidade, valor_total_tipo);
            printf("\n\t%s\n",aux->observacao);
        }
    }
}
*/

//Desalocamento
Itens* Libera_itens(Itens *unidade){
    Nop *aux = unidade->inicio, *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(unidade);
    return NULL;
}

















