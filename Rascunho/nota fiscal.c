
void imprime_nota_lista(*Pontos ponto){
    system("color e0");///lista
    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\t\tDog%co do Z%c\t-\tPonto %d ",198,130,ponto->regiao);
    switch(ponto->regiao){
        case 1:
            printf("centro");
            break;
        case 2:
            printf("zona sul");
            break;
        case 3:
            printf("zona leste");
            break;
        case 4:
            printf("zona norte");
            break;
        case 5:
            printf("zona oeste");
            break;
    }///lista
    imprime_nota_fila(ponto->pedidos->inicio);
}

void imprime_nota_pilha(Itens *pilha){
    ///pilha começo
    printf("\n\tItem\tquantidade\tvalor unidade\t\tsubtotal");
    printf("\n\t");
    for(int i = 0; i < 60; i++)
        printf("-");
    for(Nop *aux = pilha->inicio; aux != NULL; aux = aux->prox){
        printf("\n\t%s",pilha->inicio->item);
        printf("\n\t\t\t%d\t%.2f\t\t\t%.2f",aux->quantidade,aux->valor_unidade,aux->valor_total_tipo);
        if(strcmp(pilha->inicio->observacao,'\0') != 0)
            printf("\n\tObserva%c%ces:%s",135,228,pilha->inicio->observacao);
    }
}

void imprime_nota_fila(Nof *aux){
    int i;
    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\tN%c pedido: %d",167,aux->numero_pedido);
    printf("\n\tRegi%co de entrega: %d - ",198,aux->regiao_entrega);
    switch(aux->regiao_entrega){
        case 1:
            printf("centro");
            break;
        case 2:
            printf("zona sul");
            break;
        case 3:
            printf("zona leste");
            break;
        case 4:
            printf("zona norte");
            break;
        case 5:
            printf("zona oeste");
            break;
    }
    printf("\n\tTempo de entrega: %d min",aux->tempo);
    imprime_nota_pilha(aux->unidades);
    printf("\n\t");
    for(i = 0; i < 60; i++)
        printf("-");
    printf("\n\tTOTAL:\t\t\t\t\t\t%.2f",aux->valor_total_pedido);
    system("color ");///lembrar de voltar ao mesmo estilo do cmd
}


