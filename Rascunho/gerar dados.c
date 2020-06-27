///gerar dados nºs aleatórios
/*
Gerar entre 3 e 5 pontos  de  cachorro  quente; 

Gerar entre 5 e 15 pedidos para  cada  ponto;
Gerar entre 1 e 5 itens para  cada  pedido,
	•  Item: pode ter a descrição  padrão  “cachorro  quente”; 
	•  Quantidade:  sortear  aleatoriamente  entre  1  e  5;
	•  Valor  unitário:  sortear  aleatoriamente  entre  R$  10,00  e  R$ 15,00
*/
/*
srand(time(NULL);
rand()%100+1;
*/


void gerar_pontos(Pontos **ponto, int *numeropedido){
	int i, j, k, pnts, xp, pedidos, entrega, quantidade, itens;
	float valor;
	
	pnts = rand()%5+1;//geração de nº aleatório dos pontos
	while(pnts < 3)
        pnts = rand()%5+1;
	for(i = 0; i < pnts;i++){ // cadastra cada ponto
		xp = rand()%3+1; // escolhe o nível de experiência
        Insere_Ponto(&(*ponto),i+1,xp);
		pedidos = rand()%15+1; // sorteia o nº de pedidos
		while(pedidos < 5)
			pedidos = rand()%15+1;
		for(j = 0; j < pedidos; j++){ // cadastra os pedidos
			entrega = rand()%5+1; // sorteia a região de entrega
			Insere_Pedidos(*ponto, *numeropedido, entrega, i+1);
			(*numeropedido)++; 
			quantidade = rand()%5+1; // sorteia a quantidade de itens
			for(k = 0; k < quantidade; k++){ // cadastro dos itens
				itens = rand()%5+1; // sorteia a quantidade de cada item
				valor = rand()%1500; // sorteia o preço
				while(valor < 999)
					valor = rand()%1500;
				valor /= 100;
				Insere_Itens(*ponto,itens,i+1,valor,"cachorro quente","\0");
			}
			Insere_Valor_totais(*ponto,i+1);
		}
	}
}
