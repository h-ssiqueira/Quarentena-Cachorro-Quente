	printf("\n\t%c",218);
    for(i = 0; i < 60; i++)
        printf("%c",196);
    printf("%c",170);

    printf("\n\t%c N%c pedido: %4d Regi%co de entrega: %d - ",179,167,<nº pedido>,198,<nº regiao entrega>);
    switch(<regiao de entrega>){
        case 1:
            printf("Centro");
			for(i = 0; i < 14; i++)
				printf(" ");
			printf("%c",179);
            break;
        case 2:
            printf("Zona Sul");
			for(i = 0; i < 10; i++)
				printf(" ");
			printf("%c",179);
            break;
        case 3:
            printf("Zona Leste");
			for(i = 0; i < 8; i++)
				printf(" ");
			printf("%c",179);
            break;
        case 4:
            printf("Zona Norte");
			for(i = 0; i < 8; i++)
				printf(" ");
			printf("%c",179);
            break;
        case 5:
            printf("Zona Oeste");
			for(i = 0; i < 8; i++)
				printf(" ");
			printf("%c",179);
            break;
    }
    printf("\n\t%cTempo de entrega: %3d min ",179,<tempo de entrega>);
	for(i = 0; i < 33; i++)
		printf(" ");
	printf("%c",179);

    ///pilha
    printf("\n\t%cITEM\t QUANTIDADE \t VALOR UNIDADE \t\t SUBTOTAL   %c",179,179);
    for(aux...){
        //calculo do tamanho da string
        //60 - strlen = nº de espaços
		n = strlen(<item>);
		n = 59 - n;
        printf("\n\t%c %s",179,<item>);
		for(i = 0; i < n; i++)
			printf(" ");
        printf("%c",179);

        printf("\n\t%c\t%d\t%.f\t\t\t\t%.2f%c",179,<qnt>,<valor uni>,<subtotau>,179);

        if(strcmp(<observacao>,'\0') != 0)
            printf("\n\t%c Observa%c%ces:%s",179,135,228,<obs>);
            ///calculo de espaços da obs...
            ///60-(strlen + 14)
			n = strlen(<observacao>);
			n = 60 - (n + 14);
			for(i = 0; i < n; i++)
				printf(" ");
            printf("%c",179);
    }

    ///de volta na fila
    printf("\n\t%c TOTAL:\t\t\t\t\t\t%.2f%c",179,<total>,179);
	
	printf("\n\t%c",192);
    for(i = 0; i < 60; i++)
        printf("%c",196);
    printf("%c",217);
