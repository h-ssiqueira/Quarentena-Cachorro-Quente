	printf("\n\t%c",218);
    for(i = 0; i < 60; i++)
        printf("%c",196);
    printf("%c",170);

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
	
	printf("\n\t%c",192);
    for(i = 0; i < 60; i++)
        printf("%c",196);
    printf("%c",217);
