//Alcides Gomes Beato Neto	19060987
//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon		19243633

//lista
typedef struct pontos{
    int regiao /* centro ; zona sul ; zone leste ; zona norte ; zona oeste */, experiencia, total_pedidos; /* baixa = 5 ; media = 3 ; alta = 2 */
    float valor_total_vendas;
    Requisicao *pedidos;
	struct pontos *prox;
}Pontos;

Pontos* Cria_Ponto(void){
	return NULL;
}

//Verifica se a lista está vazia
int Vazia_Lista_Pontos(Pontos *ponto){
	if(ponto == NULL)
		return 1;
	return 0;
}

//Insere pontos na lista
void Insere_Ponto(Pontos **ponto, int regiao, int exp){
	Pontos* novo = (Pontos*)malloc(sizeof(Pontos)), *aux;
	if(Vazia_Lista_Pontos(novo)){
		printf("Erro de alocamento");
		exit(0);//Encerra o programa
	}
	novo->regiao = regiao;
	novo->valor_total_vendas = 0;
	novo->experiencia = exp;
	novo->total_pedidos = 0;
	novo->pedidos = Cria_Pedido();
	novo->prox = NULL;
    if((*ponto) == NULL)//Insere no inicio
        (*ponto) = novo;
    else{//Insere no final
        for(aux = (*ponto); aux->prox != NULL; aux = aux->prox)
            continue;
        aux->prox = novo;
    }
}

//Insere os pedidos primeira parte(Informações essenciais: Região de entrega, num. pedido e num.ponto)
void Insere_Pedidos(Pontos *ponto, int numero_pedido, int reg_entrega, int Nponto){
	Pontos *aux = ponto;
	while(aux != NULL){
		if(aux->regiao == Nponto){
			Insere_Fila(aux->pedidos, numero_pedido, reg_entrega);
			break;
		}
		aux = aux->prox;
	}
}

//Insere os pedidos parte 2(Inserção do itens da Pilha)
void Insere_Itens(Pontos *ponto, int qtdade, int Nponto, float valor_unid, char desc[], char obs[]){
	Pontos *aux = ponto;
	while(aux != NULL){
		if(aux->regiao == Nponto){
			Insere_os_Itens(aux->pedidos->fim, qtdade, valor_unid, desc, obs);
			break;
		}
		aux = aux->prox;
	}
}

//Insere os pedidos parte 3(Calculo dos valores totais e tempo e inserção destes valores)
void Insere_Valor_totais(Pontos *ponto, int Nponto){
	Pontos *aux = ponto;
	while(aux != NULL){
		if(aux->regiao == Nponto){
			Insere_Totais(aux->pedidos, aux->experiencia);
			break;
		}
		aux = aux->prox;
	}
	(aux->total_pedidos)++;
}

//Impressão Relatório
void Imprime_Pontos(Pontos *ponto){
	Pontos *aux;
	int i;
	//Inicio
	printf("\n\n\t%c",218);
	for(i = 0; i < 60; i++)
		printf("%c",196);
	printf("%c",191);
	for(aux = ponto; !Vazia_Lista_Pontos(aux); aux = aux->prox){
		printf("\n\t%c Regi%co: %d - ", 179,198, aux->regiao);
		switch(aux->regiao){
        case 1:
            printf("Centro");
            for(i = 0; i < 41; i++)
                printf(" ");
            printf("%c",179);
            break;
        case 2:
            printf("Zona Sul");
            for(i = 0; i < 39; i++)
                printf(" ");
            printf("%c",179);
            break;
        case 3:
            printf("Zona Leste");
            for(i = 0; i < 37; i++)
                printf(" ");
            printf("%c",179);
            break;
        case 4:
            printf("Zona Norte");
            for(i = 0; i < 37; i++)
                printf(" ");
            printf("%c",179);
            break;
        case 5:
            printf("Zona Oeste");
            for(i = 0; i < 37; i++)
                printf(" ");
            printf("%c",179);
            break;
		}
		printf("\n\t%c Total Pedidos: %4d", 179, aux->total_pedidos);
		for(i = 0; i < 40; i++)
             printf(" ");
        printf("%c",179);
		printf("\n\t%c Valor total vendido: R$%7.2f", 179, aux->valor_total_vendas);
		for(i = 0; i < 29; i++)
             printf(" ");
        printf("%c",179);
		if(aux->prox == NULL){
			printf("\n\t%c",192);
			for(i = 0; i < 60; i++)
				printf("%c",196);
			printf("%c\n",217);

		}else{
			printf("\n\t%c", 195);
			for(i = 0; i < 60; i++)
				printf("%c",196);
			printf("%c",180);
		}
	}
}

//Imprime Relatorio pedidos
void Imprime_Pedidos_Pontos(Pontos *Carrinho, int Num){
    Pontos *aux;
	int flag = 0;
    for(aux = Carrinho; !Vazia_Lista_Pontos(aux); aux = aux->prox){
        if(aux->regiao == Num && aux->pedidos->inicio != NULL){//Achou o carrinho
            Imprime_Relatorio_fila(aux->pedidos->inicio);
			flag = 1;
            break;
        }
    }
	if(!flag)
		printf("\n\tN%co h%c pedidos cadastrados.\n", 198, 160);
}

//Imprime Relatorio itens do pedido
void Imprime_Itens_Pontos(Pontos *Carrinho, int Num, int Num_Pedi){
    Pontos *aux;
    for(aux = Carrinho; !Vazia_Lista_Pontos(aux); aux = aux->prox){
        if(aux->regiao == Num){//Achou o carrinho
            Impressao_Fila_Itens(aux->pedidos->inicio, Num_Pedi);
            break;
        }
    }
}

//Busca Lista retorna posição do ponto na lista
int Busca_Ponto(Pontos *ponto, int regiao){
	Pontos *aux;
	int i = 1;
	for(aux = ponto; !Vazia_Lista_Pontos(aux); i++, aux = aux->prox)
	{
		if(aux->regiao == regiao)
			return i;
	}
	return -1; //A conferencia será feita na main antes de chamar a função
}

//Busca o numero pedido
int Busca_Num_Pedidos(Pontos *Carrinhos, int num_pedidos){
    Pontos *aux;
    int i = 1;
    for(aux = Carrinhos; !Vazia_Lista_Pontos(aux); aux = aux->prox){
        if(Busca_num_pedido(aux->pedidos, num_pedidos) != -1)//Achou
            return i;//retorna a posição do carrinho em que o pedido está
        i++;
    }
    return 0;//Nao achou o pedido
}

//Imprime nota fiscal
void imprime_nota_lista(Pontos *ponto){
    int i;
    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\t\tDog%co do Z%c\t-\tPonto %d ",198,130,ponto->regiao);
    switch(ponto->regiao){
        case 1:
            printf("CENTRO");
            break;
        case 2:
            printf("ZONA SUL");
            break;
        case 3:
            printf("ZONA LESTE");
            break;
        case 4:
            printf("ZONA NORTE");
            break;
        case 5:
            printf("ZONA OESTE");
            break;
    }///lista
    imprime_nota_fila(ponto->pedidos->inicio);
}

//Atendimento
void Atendimento_Pedido(Pontos *ponto, int Nponto){//Nponto: num do ponto //Verificar na main o ponto
	Pontos *aux = ponto;
	while(aux != NULL){
		if(aux->regiao == Nponto){//Achou o ponto
			aux->valor_total_vendas += aux->pedidos->inicio->valor_total_pedido;
			//Imprime a nota fiscal
			imprime_nota_lista(aux);
			//Retira da fila
			Retira_Pedidos(aux->pedidos);
			break;
		}
		aux = aux->prox;
	}
}

//Cancela o pedido
void Cancela_Pedido_Ponto(Pontos *ponto, int num_pedido, int Nponto){
	Pontos *aux = ponto;
	while(aux != NULL){
		if(aux->regiao == Nponto){//Achou o ponto
            if(Cancela_Pedido_Fila(aux->pedidos, num_pedido, aux->experiencia))
                (aux->total_pedidos)--;
			break;
		}
		aux = aux->prox;
	}
}

//Função que gera o arquivo dos pontos
void Arquivo_Ponto(Pontos *ponto){
	FILE *arquivo_pontos;
	Pontos *aux;
	arquivo_pontos = fopen("Dados_Pontos.txt", "a+");
	int i;
	if(arquivo_pontos != NULL){
			fprintf(arquivo_pontos,"\n\n\t");
		for(i = 0; i < 62; i++)
			fprintf(arquivo_pontos,"_");
		fprintf(arquivo_pontos,"\n");
		for(aux = ponto; !Vazia_Lista_Pontos(aux); aux = aux->prox){
			fprintf(arquivo_pontos,"\t| Regi%co: %d - ", 227, aux->regiao);
			switch(aux->regiao){
			case 1:
				fprintf(arquivo_pontos,"Centro");
				for(i = 0; i < 41; i++)
					fprintf(arquivo_pontos," ");
				fprintf(arquivo_pontos,"|");
				break;
			case 2:
				fprintf(arquivo_pontos,"Zona Sul");
				for(i = 0; i < 39; i++)
					fprintf(arquivo_pontos," ");
				fprintf(arquivo_pontos,"|");
				break;
			case 3:
				fprintf(arquivo_pontos,"Zona Leste");
				for(i = 0; i < 37; i++)
					fprintf(arquivo_pontos," ");
				fprintf(arquivo_pontos,"|");
				break;
			case 4:
				fprintf(arquivo_pontos,"Zona Norte");
				for(i = 0; i < 37; i++)
					fprintf(arquivo_pontos," ");
				fprintf(arquivo_pontos,"|");
				break;
			case 5:
				fprintf(arquivo_pontos,"Zona Oeste");
				for(i = 0; i < 37; i++)
					fprintf(arquivo_pontos," ");
				fprintf(arquivo_pontos,"|");
				break;
			}
			fprintf(arquivo_pontos,"\n\t| Total Pedidos: %4d", aux->total_pedidos);
			for(i = 0; i < 40; i++)
				 fprintf(arquivo_pontos," ");
			fprintf(arquivo_pontos,"|");
			fprintf(arquivo_pontos,"\n\t| Valor total vendido: R$%7.2f", aux->valor_total_vendas);
			for(i = 0; i < 29; i++)
				 fprintf(arquivo_pontos," ");
			fprintf(arquivo_pontos,"|");
			fprintf(arquivo_pontos,"\n\t|");
			for(i = 0; i < 60; i++)
				fprintf(arquivo_pontos,"_");
			fprintf(arquivo_pontos,"|\n");
		}
	}
	else
		printf("\n\tERRO! Impossivel abrir o arquivo.");
	fclose(arquivo_pontos);
}

//Desaloca os pontos(Lista)
Pontos* Desaloca_Pontos(Pontos *ponto){
	Pontos *aux1 = ponto, *aux2;
	while(aux1 != NULL){
		aux2 = aux1->prox;
		//desaloca primeiro a fila de pedidos
		aux1->pedidos = Desaloca_Pedidos(aux1->pedidos);
		free(aux1);
		aux1 = aux2;
	}
	return NULL;
}
