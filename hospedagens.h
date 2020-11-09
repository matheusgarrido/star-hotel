#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int verificar_ano(){
	int a, x=0;
	do {
		printf("Ano: ");
		scanf("%d", &a);
		if (a < 2017) {
			printf("Ano inválido. (Valores válidos: acima de 2017)\n");
			x=1;
		}
		else {
			x=0;
			printf("\n");
		}
	} while (x == 1);
	return a;
}

//Verificar se o valor para mês é válido
int verificar_mes(int a){
	int m, x=0;
	do {
		printf("Mês: ");
		scanf("%d", &m);
		if (a == 2017){
			if (m<6 || m>12){
				printf("Mês inválido. (Valores válidos: 6-12)\n");		
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}	
		}
		else {
			if (m < 1 || m > 12) {
				printf("Mês inválido. (Valores válidos: 1-12)\n");		
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}		
		}
	} while (x == 1);
	return m;
}

//Verificar se o dia é válido de acordo com a quantidade total de dias de um mês
int verificar_dia(int a, int m){
	int d, x=0;
	do {
		printf("Dia: ");
		scanf("%d", &d);		
		if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
			if (d < 1 || d > 31){
				printf("Dia inválido. (Valores válidos para este mês: 1-31)\n");				
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}
		}
		else if (m==4||m==6||m==9||m==11){
			if (d<1 || d>30){
				printf("Dia inválido. (Valores válidos para este mês: 1-30)\n");
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}		
		}
		else {
			if ((a%4==0 && a%100!=0) ||a%400==0){
				if (d < 1 || d>29){
					printf("Dia inválido. (Valores válidos para este mês: 1-29)\n");
					x=1;
				}
				else {
					x=0;
					printf("\n");
				}		
			}
			else {
				if (d < 1 || d>28){
					printf("Dia inválido. (Valores válidos para este mês: 1-28)\n");
					x=1;
				}
				else {
					x=0;
					printf("\n");
				}		
			}
		}
	} while (x==1);
	return d;
}

//Criar um long com a quantidade total de dias entre 1/1/2017 e a data importada para este método
long quantidade_dias(int d, int m, int a){
	int d_ano=0, d_mes=0;
	int mes[2][11] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30},
					  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30}};
	while (a>2017){
		a--;
		if ((a%4==0 && a%100!=0) || a%400==0){
			d_ano+=366;			
		}
		else{
			d_ano+=365;	
		}
	}
	while (m>1){
		m--;
		if ((a%4==0 && a%100!=0) || a%400==0){
			d_mes+=mes[1][m];
		}
		else{
			d_mes+=mes[0][m];
		}
	}
	return (d_ano + d_mes + d);
}

float valor_estadia(int quarto, int adultos, int criancas, int dias){
	FILE *V;
	V = fopen("valores/quartos.txt", "r");
	float val[3][2];
	fscanf(V, "%f", &val[0][0]);
	fscanf(V, "%f", &val[0][1]);
	fscanf(V, "%f", &val[1][0]);
	fscanf(V, "%f", &val[1][1]);
	fscanf(V, "%f", &val[2][0]);
	fscanf(V, "%f", &val[2][1]);
	fclose(V);
	
	float preco;
	if (quarto>=1&&quarto<=3) preco=(val[0][0] * adultos) + (val[0][1] * criancas);
	else if (quarto>=4&&quarto<=7) preco=(val[1][0] * adultos) + (val[1][1] * criancas);
	else preco=(val[2][0] * adultos) + (val[2][1] * criancas);
	preco*=dias;
	
	return preco;
}

//Struct para armazenar os dados recebidos do txt + dados a serem cadastrados
struct hospedagem{
	char nome[50];
	char cpf[12];
	char tel[12];
	int e;
	char email[50];
	int d1;
	int m1;
	int a1;
	int d2;
	int m2;
	int a2;
	int q_adultos;
	int q_criancas;	
	int pagamento;
	int forma_pag;
	float valor;
};


// =====================================================================================================


//Cadastrar reserva de quarto
int reservar_quarto(char usuario[20], int adm){
	//Informar quarto desejado	
	system("CLS");
	int quarto;
	printf("\n\t\tRESERVAR QUARTO\n");
	do {
		printf("Quarto: ");
		scanf("%d", &quarto);
		if (quarto < 1 || quarto > 10){
			printf("Valor inválido para número do quarto. (Valores válidos: 1-10)\n\n");
		}
	} while (quarto<1 || quarto >10);
	
	struct hospedagem estadia[100];
	FILE *Q;
	//Buscar txt relacionado ao quarto
	switch (quarto){
		case 1:
			Q = fopen("estadia/quarto1.txt", "r");
			break;
		case 2:
			Q = fopen("estadia/quarto2.txt", "r");
			break;
		case 3:
			Q = fopen("estadia/quarto3.txt", "r");
			break;
		case 4:
			Q = fopen("estadia/quarto4.txt", "r");
			break;
		case 5:
			Q = fopen("estadia/quarto5.txt", "r");
			break;
		case 6:
			Q = fopen("estadia/quarto6.txt", "r");
			break;
		case 7:
			Q = fopen("estadia/quarto7.txt", "r");
			break;
		case 8:
			Q = fopen("estadia/quarto8.txt", "r");
			break;
		case 9:
			Q = fopen("estadia/quarto9.txt", "r");
			break;
		case 10:
			Q = fopen("estadia/quarto10.txt", "r");
			break;
	}		
	int i, n, disponibilidade=0;	
	fscanf(Q, "%d", &n);	
	int indisp;
	fscanf(Q, "%d", &indisp);	
	//Receber dados salvos no txt do determinado quarto			
	for (i=0; i<n; i++){
		fscanf(Q, "%s", &estadia[i].nome);
		fscanf(Q, "%s", &estadia[i].cpf);
		fscanf(Q, "%s", &estadia[i].tel);
		fscanf(Q, "%d", &estadia[i].e);
		if (estadia[i].e==1){
			fscanf(Q, "%s", &estadia[i].email);			
		}
		fscanf(Q, "%d", &estadia[i].d1);
		fscanf(Q, "%d", &estadia[i].m1);
		fscanf(Q, "%d", &estadia[i].a1);
		fscanf(Q, "%d", &estadia[i].d2);
		fscanf(Q, "%d", &estadia[i].m2);
		fscanf(Q, "%d", &estadia[i].a2);
		fscanf(Q, "%d", &estadia[i].q_adultos);
		fscanf(Q, "%d", &estadia[i].q_criancas);
		fscanf(Q, "%d", &estadia[i].pagamento);
		if (estadia[i].pagamento==1){
			fscanf(Q, "%d", &estadia[i].forma_pag);			
		}
		fscanf(Q, "%f", &estadia[i].valor);
	}
	fclose(Q);				
	
	//Inserir dados relacionados às datas de entradas e saída
	printf("\n\n\t\tDATA DE ENTRADA\n");		
	estadia[n].a1 = verificar_ano();
 	estadia[n].m1 = verificar_mes(estadia[n].a1);
	estadia[n].d1 = verificar_dia(estadia[n].a1, estadia[n].m1);	
	printf("\n\n\t\tDATA DE SAÍDA\n");	
	estadia[n].a2 = verificar_ano();
	estadia[n].m2 = verificar_mes(estadia[n].a2);
	estadia[n].d2 = verificar_dia(estadia[n].a2, estadia[n].m2);
		
	//longs com a quantidade total de dias entre 1/1/2017 e a datas importadas para o método quantidade_dias()
	long q_dias1, q_dias2, q_dif;
	q_dias1 = quantidade_dias(estadia[n].d1, estadia[n].m1, estadia[n].a1);
	q_dias2 = quantidade_dias(estadia[n].d2, estadia[n].m2, estadia[n].a2);
	//Calcular números de dias hospedados
	q_dif = q_dias2-q_dias1+1;
		
	//Mensagem de erro caso as datas de entrada e saída estejam invertidas
	if (q_dias1>q_dias2) {
		printf("\n\nErro de verificação de disponibilidade.\nA data de entrada (%d/%d/%d) ocorrerá antes da data de saída (%d/%d/%d).\n",
				estadia[n].d1, estadia[n].m1, estadia[n].a1, estadia[n].d2, estadia[n].m2, estadia[n].a2);
		system("pause");
		system("cls");
		reservar_quarto(usuario, adm);
	}
	
	//Menu para verificar disponibilidade
	system("cls");
	printf("\n\t\tESTADIA DESEJADA\n");
	printf("Quarto: %d\n", quarto);

	printf("Data de entrada: %d/%d/%d\n", estadia[n].d1, estadia[n].m1, estadia[n].a1);
	printf("Data de saída: %d/%d/%d\n", estadia[n].d2, estadia[n].m2, estadia[n].a2);
	printf("Dias de hospedagem: %d\n\n\n", q_dif);
	printf("\tVERIFICANDO DISPONIBILIDADE");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	//Verificar disponibilidade do quarto
	if (n==0){		
		disponibilidade=1;
	}
	else {
		disponibilidade=1;		
		long qdx, qdy;
		for (i=0; i<n; i++){
			qdx = quantidade_dias(estadia[i].d1, estadia[i].m1, estadia[i].a1);
			qdy = quantidade_dias(estadia[i].d2, estadia[i].m2, estadia[i].a2);
			if ((q_dias1>=qdx&&q_dias1<=qdy)||(q_dias2>=qdx&&q_dias2<=qdy)){
				disponibilidade=0;
				printf("Quarto não disponível nestas datas.\n");
				//Adicionar +1 busca pelo quarto
				indisp++;
				switch (quarto){
				case 1:
					Q = fopen("estadia/quarto1.txt", "w");
					break;
				case 2:
					Q = fopen("estadia/quarto2.txt", "w");
					break;
				case 3:
					Q = fopen("estadia/quarto3.txt", "w");
					break;
				case 4:
					Q = fopen("estadia/quarto4.txt", "w");
					break;
				case 5:
					Q = fopen("estadia/quarto5.txt", "w");
					break;
				case 6:
					Q = fopen("estadia/quarto6.txt", "w");
					break;
				case 7:
					Q = fopen("estadia/quarto7.txt", "w");
					break;
				case 8:
					Q = fopen("estadia/quarto8.txt", "w");
					break;
				case 9:
					Q = fopen("estadia/quarto9.txt", "w");
					break;
				case 10:
					Q = fopen("estadia/quarto10.txt", "w");
					break;
				}
				//Inserir dados ao txt
				fprintf(Q, "%d\n", n);
				fprintf(Q, "%d\n", indisp);
				for (i=0; i<n; i++){
					fprintf(Q, "%s\n", estadia[i].nome);
					fprintf(Q, "%s\n", estadia[i].cpf);
					fprintf(Q, "%s\n", estadia[i].tel);
					fprintf(Q, "%d\n", estadia[i].e);
					if (estadia[i].e==1) fprintf(Q, "%s\n", estadia[i].email);
					fprintf(Q, "%d\n", estadia[i].d1);
					fprintf(Q, "%d\n", estadia[i].m1);
					fprintf(Q, "%d\n", estadia[i].a1);
					fprintf(Q, "%d\n", estadia[i].d2);
					fprintf(Q, "%d\n", estadia[i].m2);
					fprintf(Q, "%d\n", estadia[i].a2);
					fprintf(Q, "%d\n", estadia[i].q_adultos);
					fprintf(Q, "%d\n", estadia[i].q_criancas);	
					fprintf(Q, "%d\n", estadia[i].pagamento);	
					if (estadia[i].pagamento==1) fprintf(Q, "%d\n", estadia[i].forma_pag);
					fprintf(Q, "%f\n", estadia[i].valor);
				}
				fclose(Q);
			}
		}
	}
	
	//Informar quantidade de hóspedes	
	if (disponibilidade==1){
		printf("Há vaga.");
		printf("\n\n\n\tQUANTIDADE DE HÓSPEDES NO QUARTO\n");
		printf("Limite de hóspedes por quarto: 4 pessoas\n\n");		
		do {
			printf("Quantidade de adultos: ");
			scanf("%d", &estadia[n].q_adultos);
			fflush(stdin);
			if (estadia[n].q_adultos>4 || estadia[n].q_adultos<1){
				printf("Informação inválida. (Valores válidos: 1-4)\n");
			}
		} while (estadia[n].q_adultos>4||estadia[n].q_adultos<1);
		printf("\n");
		int xc=0;
		do {
			if (estadia[n].q_adultos==4){
				estadia[n].q_criancas=0;
				printf("Quantidade de crianças: 0");
				xc=1;
			}
			else{
				printf("Quantidade de crianças: ");
				scanf("%d",  &estadia[n].q_criancas);
				fflush(stdin);
				switch(estadia[n].q_adultos){
					case 1:
						if (estadia[n].q_criancas>3||estadia[n].q_criancas<0){
							printf("Informação inválida. (Valores válidos: 0-3 crianças)\n");
							xc=0;
						}
						else xc=1;
						break;
					case 2:					
						if (estadia[n].q_criancas>2||estadia[n].q_criancas<0){
							printf("Informação inválida. (Valores válidos: 0-2 crianças)\n");
							xc=0;
						}
						else xc=1;
						break;
					case 3:
						if (estadia[n].q_criancas>1||estadia[n].q_criancas<0){
							printf("Informação inválida. (Valores válidos: 0-1 criança)\n");
							xc=0;
						}
						else xc=1;
				}		
			}
		} while (xc==0);
		
		//Informar dados do cliente
		printf("\n\n\t\tDADOS PESSOAIS\n");	
		printf("Nome: ");					
		gets(estadia[i].nome);
		fflush(stdin);
		printf("CPF: ");
		gets(estadia[i].cpf);
		fflush(stdin);					
		printf("Telefone: ");
		gets(estadia[i].tel);
		fflush(stdin);					
		printf("Possui e-mail (1-Sim / 2-Não)? ");
		scanf("%d", &estadia[i].e);
		fflush(stdin);
		if (estadia[i].e==1){
			printf("E-mail: ");
			gets(estadia[i].email);
			fflush(stdin);						
		}
		else estadia[i].e=0;		
				
		//Confirmar finalização de reserva
		int concluir_reserva;
		do{		
			system("cls");
			printf("\n\t\tDADOS DA RESERVA\n");
			printf("Data de entrada: %d/%d/%d\n", estadia[n].d1, estadia[n].m1, estadia[n].a1);
			printf("Data de saída: %d/%d/%d\n", estadia[n].d2, estadia[n].m2, estadia[n].a2);
			printf("Dias de hospedagem: %d\n", q_dif);
			printf("Cliente: %s\n", estadia[n].nome);
			printf("CPF: %s\n", estadia[n].cpf);
			printf("Telefone: %s\n", estadia[n].tel);
			if (estadia[n].e==1){
				printf("E-mail: %s\n", estadia[n].email);
			}
			else printf("Não possui e-mail\n");
			printf("Quantidade de hóspedes: %d (%d adultos e %d crianças)\n", (estadia[n].q_adultos+estadia[n].q_criancas), estadia[n].q_adultos, estadia[n].q_criancas);
			estadia[n].valor = valor_estadia(quarto, estadia[n].q_adultos, estadia[n].q_criancas, q_dif);
			printf("Valor da estadia: R$ %.2f\n\n", estadia[n].valor);
						
			printf("\n\t1 - Concluir reserva");
			printf("\n\t2 - Cancelar reserva");
			printf("\n\tDeseja concluir a reserva? ");
			
			scanf("%d", &concluir_reserva);
			switch (concluir_reserva){
				case 1:
					printf("\nReserva concluída com sucesso!\n");
					break;
				case 2:
					printf("\nReserva cancelada.\n");
					break;
				default:
					printf("Valor inválido. Informe novamente.");
					system("pause");
					break;
			}
		} while (concluir_reserva!=1 && concluir_reserva!=2);
		
		//Salvar dados da reversa no txt
		if (concluir_reserva==1){			
			switch (quarto){
				case 1:
					Q = fopen("estadia/quarto1.txt", "w");
					break;
				case 2:
					Q = fopen("estadia/quarto2.txt", "w");
					break;
				case 3:
					Q = fopen("estadia/quarto3.txt", "w");
					break;
				case 4:
					Q = fopen("estadia/quarto4.txt", "w");
					break;
				case 5:
					Q = fopen("estadia/quarto5.txt", "w");
					break;
				case 6:
					Q = fopen("estadia/quarto6.txt", "w");
					break;
				case 7:
					Q = fopen("estadia/quarto7.txt", "w");
					break;
				case 8:
					Q = fopen("estadia/quarto8.txt", "w");
					break;
				case 9:
					Q = fopen("estadia/quarto9.txt", "w");
					break;
				case 10:
					Q = fopen("estadia/quarto10.txt", "w");
					break;
			}
			n++;
			//Inserir dados ao txt
			fprintf(Q, "%d\n", n);
			fprintf(Q, "%d\n", indisp);
			for (i=0; i<n; i++){
				fprintf(Q, "%s\n", estadia[i].nome);
				fprintf(Q, "%s\n", estadia[i].cpf);
				fprintf(Q, "%s\n", estadia[i].tel);
				fprintf(Q, "%d\n", estadia[i].e);
				if (estadia[i].e==1) fprintf(Q, "%s\n", estadia[i].email);
				fprintf(Q, "%d\n", estadia[i].d1);
				fprintf(Q, "%d\n", estadia[i].m1);
				fprintf(Q, "%d\n", estadia[i].a1);
				fprintf(Q, "%d\n", estadia[i].d2);
				fprintf(Q, "%d\n", estadia[i].m2);
				fprintf(Q, "%d\n", estadia[i].a2);
				fprintf(Q, "%d\n", estadia[i].q_adultos);
				fprintf(Q, "%d\n", estadia[i].q_criancas);	
				fprintf(Q, "%d\n", estadia[i].pagamento);	
				if (estadia[i].pagamento==1) fprintf(Q, "%d\n", estadia[i].forma_pag);
				fprintf(Q, "%f\n", estadia[i].valor);	
			}
			fclose(Q);
		}		
	}
	system("pause");
	controle_hospedagem(usuario, adm);
	return 0;
}

// =====================================================================================================

int alterar_reserva(char usuario[20], int adm){
	//Informar quarto desejado
	system("CLS");
	int quarto;
	printf("\n\t\tALTERAR RESERVA\n");
	do {
		printf("Quarto: ");
		scanf("%d", &quarto);
		if (quarto < 1 || quarto > 10){
			printf("Valor inválido para número do quarto. (Valores válidos: 1-10)\n\n");
		}
	} while (quarto<1 || quarto >10);
	
	struct hospedagem estadia[100];
	FILE *Q;
	//Buscar txt relacionado ao quarto
	switch (quarto){
		case 1:
			Q = fopen("estadia/quarto1.txt", "r");
			break;
		case 2:
			Q = fopen("estadia/quarto2.txt", "r");
			break;
		case 3:
			Q = fopen("estadia/quarto3.txt", "r");
			break;
		case 4:
			Q = fopen("estadia/quarto4.txt", "r");
			break;
		case 5:
			Q = fopen("estadia/quarto5.txt", "r");
			break;
		case 6:
			Q = fopen("estadia/quarto6.txt", "r");
			break;
		case 7:
			Q = fopen("estadia/quarto7.txt", "r");
			break;
		case 8:
			Q = fopen("estadia/quarto8.txt", "r");
			break;
		case 9:
			Q = fopen("estadia/quarto9.txt", "r");
			break;
		case 10:
			Q = fopen("estadia/quarto10.txt", "r");
			break;
	}
	int i, n;
	fscanf(Q, "%d", &n);
	int indisp;
	fscanf(Q, "%d", &indisp);		
	//Receber dados salvos no txt do determinado quarto			
	for (i=0; i<n; i++){
		fscanf(Q, "%s", &estadia[i].nome);
		fscanf(Q, "%s", &estadia[i].cpf);
		fscanf(Q, "%s", &estadia[i].tel);
		fscanf(Q, "%d", &estadia[i].e);
		if (estadia[i].e==1){
			fscanf(Q, "%s", &estadia[i].email);
		}
		fscanf(Q, "%d", &estadia[i].d1);
		fscanf(Q, "%d", &estadia[i].m1);
		fscanf(Q, "%d", &estadia[i].a1);
		fscanf(Q, "%d", &estadia[i].d2);
		fscanf(Q, "%d", &estadia[i].m2);
		fscanf(Q, "%d", &estadia[i].a2);
		fscanf(Q, "%d", &estadia[i].q_adultos);
		fscanf(Q, "%d", &estadia[i].q_criancas);
		fscanf(Q, "%d", &estadia[i].pagamento);
		if (estadia[i].pagamento==1) fscanf(Q, "%d", &estadia[i].forma_pag);
		fscanf(Q, "%f", &estadia[i].valor);				
	}
	fclose(Q);
	
	//Inserir dados relacionados às datas de entradas e saída
	printf("\n\n\t\tBUSCAR DATA DE ESTADIA\n");
	printf("Informe a data de entrada, de saída ou uma data entre o período de estadia.\n\n");
	int d, m, a;
	a = verificar_ano();
 	m = verificar_mes(a);
	d = verificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o método quantidade_dias()
	long q_dias;
	q_dias = quantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
	printf("Quarto: %d\n", quarto);	
	printf("Data: %d/%d/%d\n\n", d, m, a);	
	printf("\t\tREALIZANDO BUSCA");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	//Verificar disponibilidade do quarto
	int busca=0;
	if (n==0){		
		busca=1;		
	}
	else {
		busca=1;		
		long qdx, qdy;
		for (i=0; i<n; i++){
			qdx = quantidade_dias(estadia[i].d1, estadia[i].m1, estadia[i].a1);
			qdy = quantidade_dias(estadia[i].d2, estadia[i].m2, estadia[i].a2);
			if (q_dias>=qdx&&q_dias<=qdy){
				busca=0;
				printf("Reserva localizada.\n\n");
				
				printf("\t\tDADOS DA RESERVA\n");
				printf("Data de entrada: %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1);
				printf("Data de saída: %d/%d/%d\n", estadia[i].d2, estadia[i].m2, estadia[i].a2);
				long q_difz;
				q_difz = qdy-qdx+1;
				printf("Dias de hospedagem: %d\n", q_difz);
				printf("Cliente: %s\n", estadia[i].nome);
				printf("CPF: %s\n", estadia[i].cpf);
				printf("Telefone: %s\n", estadia[i].tel);
				if (estadia[i].e==1){
					printf("E-mail: %s\n", estadia[i].email);
				}
				else printf("Não possui e-mail\n");
				printf("Quantidade de hóspedes: %d (%d crianças e %d adultos)\n", (estadia[i].q_adultos+estadia[i].q_criancas), estadia[i].q_adultos, estadia[i].q_criancas);				
				printf("Valor da estadia: R$ %.2f\n\n", estadia[i].valor);
				
				if (estadia[i].pagamento==1) printf("  **Esta reserva já foi paga.\n\n");					
				else printf("  **Esta reserva ainda não foi paga.\n\n");
				system("pause");
				
				int x=0;
				long q_dias1, q_dias2, q_dif;
				do{					
					system("cls");
					x=1;		
					printf("\n\t\tNOVOS DADOS");
					//Inserir dados relacionados às datas de entradas e saída
					printf("\n\n\t\tDATA DE ENTRADA\n");
					estadia[i].a1 = verificar_ano();
	 				estadia[i].m1 = verificar_mes(estadia[i].a1);
					estadia[i].d1 = verificar_dia(estadia[i].a1, estadia[i].m1);				
					printf("\n\n\t\tDATA DE SAÍDA\n");				
					estadia[i].a2 = verificar_ano();
					estadia[i].m2 = verificar_mes(estadia[i].a2);
					estadia[i].d2 = verificar_dia(estadia[i].a2, estadia[i].m2);
					
					q_dias1 = quantidade_dias(estadia[i].d1, estadia[i].m1, estadia[i].a1);
					q_dias2 = quantidade_dias(estadia[i].d2, estadia[i].m2, estadia[i].a2);
					//Calcular números de dias hospedados
					q_dif = q_dias2-q_dias1+1;				
			
					//Mensagem de erro caso as datas de entrada e saída estejam invertidas
					if (q_dias1>q_dias2) {
						printf("\n\nErro de verificação de disponibilidade.\nA data de entrada (%d/%d/%d) ocorrerá antes da data de saída (%d/%d/%d).\n",
								estadia[i].d1, estadia[i].m1, estadia[i].a1, estadia[i].d2, estadia[i].m2, estadia[i].a2);
						system("pause");
						x=0;
					}
				} while (x==0);
				
				//Menu para verificar disponibilidade
				system("cls");				
				printf("\n\t\tESTADIA DESEJADA\n");
				printf("Quarto: %d\n", quarto);
				printf("Data de entrada: %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1);
				printf("Data de saída: %d/%d/%d\n", estadia[i].d2, estadia[i].m2, estadia[i].a2);
				printf("Dias de hospedagem: %d\n\n\n", q_dif);
				printf("\tVERIFICANDO DISPONIBILIDADE");
				Sleep(1200);
				printf(".");
				Sleep(1200);
				printf(".");
				Sleep(1200);
				printf(".\n");
	
				//Verificar disponibilidade do quarto
				int disponibilidade=0;
				if (n==0){		
					disponibilidade=1;		
				}
				else {
					disponibilidade=1;
					long qda, qdb;
					int j;
					for (j=0; j<n; j++){
						qda = quantidade_dias(estadia[j].d1, estadia[j].m1, estadia[j].a1);
						qdb = quantidade_dias(estadia[j].d2, estadia[j].m2, estadia[j].a2);
						if ((q_dias1>=qda&&q_dias1<=qdb)||(q_dias2>=qda&&q_dias2<=qdb)){
							if ((q_dias1<qdx&&q_dias1>qdy)||(q_dias2<qdx&&q_dias2>qdy)){
								disponibilidade=0;
								printf("Quarto não disponível nestas datas.\n");	
							}							
						}
					}
				}
				
				//Informar quantidade de hóspedes	
				if (disponibilidade==1){
					printf("Há vaga.");
					printf("\n\n\n\tQUANTIDADE DE HÓSPEDES NO QUARTO\n");
					printf("Limite de hóspedes por quarto: 4 pessoas\n\n");		
					do {
						printf("Quantidade de adultos: ");
						scanf("%d", &estadia[i].q_adultos);
						fflush(stdin);
						if (estadia[i].q_adultos>4 || estadia[i].q_adultos<1){
							printf("Informação inválida. (Valores válidos: 1-4)\n");
						}
					} while (estadia[i].q_adultos>4||estadia[i].q_adultos<1);
					printf("\n");
					int xc=0;
					do {
						if (estadia[i].q_adultos==4){
							estadia[i].q_criancas=0;
							printf("Quantidade de crianças: 0");
							xc=1;
						}
						else{
							printf("Quantidade de crianças: ");
							scanf("%d",  &estadia[i].q_criancas);
							fflush(stdin);
							switch(estadia[i].q_adultos){
								case 1:
									if (estadia[i].q_criancas>3||estadia[i].q_criancas<0){
										printf("Informação inválida. (Valores válidos: 0-3 crianças)\n");
										xc=0;
									}
									else xc=1;
									break;
								case 2:					
									if (estadia[i].q_criancas>2||estadia[i].q_criancas<0){
										printf("Informação inválida. (Valores válidos: 0-2 crianças)\n");
										xc=0;
									}
									else xc=1;
									break;
								case 3:
									if (estadia[i].q_criancas>1||estadia[i].q_criancas<0){
										printf("Informação inválida. (Valores válidos: 0-1 criança)\n");
										xc=0;
									}
									else xc=1;
							}		
						}
					} while (xc==0);
					
					//Informar dados do cliente
					printf("\n\n\t\tDADOS PESSOAIS\n");		
					printf("Nome: ");					
					gets(estadia[i].nome);
					fflush(stdin);					
					printf("CPF: ");
					gets(estadia[i].cpf);
					fflush(stdin);					
					printf("Telefone: ");
					gets(estadia[i].tel);
					fflush(stdin);					
					printf("Possui e-mail (1-Sim / 2-Não)? ");
					scanf("%d", &estadia[i].e);
					fflush(stdin);
					if (estadia[i].e==1){
						printf("E-mail: ");
						gets(estadia[i].email);
						fflush(stdin);						
					}
					else estadia[i].e=0;
							
					//Confirmar finalização de reserva
					int alterar;
					do{
						system("cls");
						printf("\n\t\tDADOS DA RESERVA\n");
						printf("Data de entrada: %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1);
						printf("Data de saída: %d/%d/%d\n", estadia[i].d2, estadia[i].m2, estadia[i].a2);
						printf("Dias de hospedagem: %d\n", q_dif);
						printf("Cliente: %s\n", estadia[i].nome);
						printf("CPF: %s\n", estadia[i].cpf);
						printf("Telefone: %s\n", estadia[i].tel);
						if (estadia[i].e==1){
							printf("E-mail: %s\n", estadia[i].email);
						}
						else printf("Não possui e-mail\n");
						printf("Quantidade de hóspedes: %d (%d adultos e %d crianças)\n", (estadia[i].q_adultos+estadia[i].q_criancas), estadia[i].q_adultos, estadia[i].q_criancas);						
						estadia[i].valor = valor_estadia(quarto, estadia[i].q_adultos, estadia[i].q_criancas, q_dif);
						printf("Valor da estadia: R$ %.2f\n\n", estadia[i].valor);
						
						if (estadia[i].pagamento==1) printf("  **Esta reserva já foi paga.\n\n");
						else printf("  **Esta reserva ainda não foi paga.\n\n");
									
						printf("\n\t1 - Atualizar reserva");
						printf("\n\t2 - Cancelar atualização");
						printf("\n\tDeseja concluir a atualização? ");
						
						scanf("%d", &alterar);
						switch (alterar){
							case 1:
								printf("\nAtualização concluída com sucesso!\n");								
								break;
							case 2:
								printf("\nAtualização cancelada.\n");								
								break;
							default:
								printf("Valor inválido. Informe novamente.\n");
								system("pause");
								break;
						}
					} while (alterar!=1 && alterar!=2);
					
					//Salvar dados da reversa no txt
					if (alterar==1){
						switch (quarto){
							case 1:
								Q = fopen("estadia/quarto1.txt", "w");
								break;
							case 2:
								Q = fopen("estadia/quarto2.txt", "w");
								break;
							case 3:
								Q = fopen("estadia/quarto3.txt", "w");
								break;
							case 4:
								Q = fopen("estadia/quarto4.txt", "w");
								break;
							case 5:
								Q = fopen("estadia/quarto5.txt", "w");
								break;
							case 6:
								Q = fopen("estadia/quarto6.txt", "w");
								break;
							case 7:
								Q = fopen("estadia/quarto7.txt", "w");
								break;
							case 8:
								Q = fopen("estadia/quarto8.txt", "w");
								break;
							case 9:
								Q = fopen("estadia/quarto9.txt", "w");
								break;
							case 10:
								Q = fopen("estadia/quarto10.txt", "w");
								break;
						}						
						//Inserir dados ao txt
						fprintf(Q, "%d\n", n);
						fprintf(Q, "%d\n", indisp);
						for (i=0; i<n; i++){						
							fprintf(Q, "%s\n", estadia[i].nome);
							fprintf(Q, "%s\n", estadia[i].cpf);
							fprintf(Q, "%s\n", estadia[i].tel);
							fprintf(Q, "%d\n", estadia[i].e);
							if (estadia[i].e==1) fprintf(Q, "%s\n", estadia[i].email);
							fprintf(Q, "%d\n", estadia[i].d1);
							fprintf(Q, "%d\n", estadia[i].m1);
							fprintf(Q, "%d\n", estadia[i].a1);
							fprintf(Q, "%d\n", estadia[i].d2);
							fprintf(Q, "%d\n", estadia[i].m2);
							fprintf(Q, "%d\n", estadia[i].a2);
							fprintf(Q, "%d\n", estadia[i].q_adultos);
							fprintf(Q, "%d\n", estadia[i].q_criancas);	
							fprintf(Q, "%d\n", estadia[i].pagamento);	
							if (estadia[i].pagamento==1) fprintf(Q, "%d\n", estadia[i].forma_pag);
							fprintf(Q, "%f\n", estadia[i].valor);	
						}
						fclose(Q);
					}
				}
			}
		}
	}
	
	if (busca==1){
		printf("Não há reserva por este quarto nesta data.\n");
	}
	system("pause");
	controle_hospedagem(usuario, adm);
	return 0;
}


// ====================================================================================================


int cancelar_reserva(char usuario[20], int adm){
	//Informar quarto desejado
	system("CLS");
	int quarto;
	printf("\n\t\tCANCELAR RESERVA\n");
	do {
		printf("Quarto: ");
		scanf("%d", &quarto);
		if (quarto < 1 || quarto > 10){
			printf("Valor inválido para número do quarto. (Valores válidos: 1-10)\n\n");
		}
	} while (quarto<1 || quarto >10);
	
	struct hospedagem estadia[100];
	FILE *Q;
	//Buscar txt relacionado ao quarto
	switch (quarto){
		case 1:
			Q = fopen("estadia/quarto1.txt", "r");
			break;
		case 2:
			Q = fopen("estadia/quarto2.txt", "r");
			break;
		case 3:
			Q = fopen("estadia/quarto3.txt", "r");
			break;
		case 4:
			Q = fopen("estadia/quarto4.txt", "r");
			break;
		case 5:
			Q = fopen("estadia/quarto5.txt", "r");
			break;
		case 6:
			Q = fopen("estadia/quarto6.txt", "r");
			break;
		case 7:
			Q = fopen("estadia/quarto7.txt", "r");
			break;
		case 8:
			Q = fopen("estadia/quarto8.txt", "r");
			break;
		case 9:
			Q = fopen("estadia/quarto9.txt", "r");
			break;
		case 10:
			Q = fopen("estadia/quarto10.txt", "r");
			break;
	}		
	int i, n;
	fscanf(Q, "%d", &n);
	int indisp;
	fscanf(Q, "%d", &indisp);		
	//Receber dados salvos no txt do determinado quarto			
	for (i=0; i<n; i++){
		fscanf(Q, "%s", &estadia[i].nome);
		fscanf(Q, "%s", &estadia[i].cpf);
		fscanf(Q, "%s", &estadia[i].tel);
		fscanf(Q, "%d", &estadia[i].e);
		if (estadia[i].e==1){
			fscanf(Q, "%s", &estadia[i].email);
		}
		fscanf(Q, "%d", &estadia[i].d1);
		fscanf(Q, "%d", &estadia[i].m1);
		fscanf(Q, "%d", &estadia[i].a1);
		fscanf(Q, "%d", &estadia[i].d2);
		fscanf(Q, "%d", &estadia[i].m2);
		fscanf(Q, "%d", &estadia[i].a2);
		fscanf(Q, "%d", &estadia[i].q_adultos);
		fscanf(Q, "%d", &estadia[i].q_criancas);
		fscanf(Q, "%d", &estadia[i].pagamento);
		if (estadia[i].pagamento==1) fscanf(Q, "%d", &estadia[i].forma_pag);
		fscanf(Q, "%f", &estadia[i].valor);	
	}
	fclose(Q);
	
	//Inserir dados relacionados às datas de entradas e saída
	printf("\n\n\t\tBUSCAR DATA DE ESTADIA\n");
	printf("Informe a data de entrada, de saída ou uma data entre o período de estadia.\n\n");
	int d, m, a;
	a = verificar_ano();
 	m = verificar_mes(a);
	d = verificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o método quantidade_dias()
	long q_dias;
	q_dias = quantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
	printf("Quarto: %d\n", quarto);	
	printf("Data: %d/%d/%d\n\n", d, m, a);	
	printf("\t\tREALIZANDO BUSCA");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	//Verificar disponibilidade do quarto
	int busca=0;
	if (n==0){		
		busca=1;		
	}
	else {				
		busca=1;		
		long qdx, qdy;
		for (i=0; i<n; i++){
			qdx = quantidade_dias(estadia[i].d1, estadia[i].m1, estadia[i].a1);
			qdy = quantidade_dias(estadia[i].d2, estadia[i].m2, estadia[i].a2);
			if (q_dias>=qdx&&q_dias<=qdy){
				busca=0;
				int cancelar;
				do{				
					printf("Reserva localizada.\n\n");					
					printf("\t\tDADOS DA RESERVA\n");
					printf("Data de entrada: %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1);
					printf("Data de saída: %d/%d/%d\n", estadia[i].d2, estadia[i].m2, estadia[i].a2);
					long q_difz;
					q_difz = qdy-qdx+1;
					printf("Dias de hospedagem: %d\n", q_difz);
					printf("Cliente: %s\n", estadia[i].nome);
					printf("CPF: %s\n", estadia[i].cpf);
					printf("Telefone: %s\n", estadia[i].tel);
					if (estadia[i].e==1){
						printf("E-mail: %s\n", estadia[i].email);
					}
					else printf("Não possui e-mail\n");
					printf("Quantidade de hóspedes: %d (%d adultos e %d crianças)\n\n", (estadia[i].q_adultos+estadia[i].q_criancas), estadia[i].q_adultos, estadia[i].q_criancas);				
					printf("Valor da estadia: R$ %.2f\n\n", estadia[i].valor);
					
					if (estadia[i].pagamento==1) printf("  **Esta reserva já foi paga.\n\n");					
					else printf("  **Esta reserva ainda não foi paga.\n\n");					
					
					printf("\n\t1 - Confirmar cancelamento de reserva");
					printf("\n\t2 - Não cancelar a reserva");
					printf("\n\tDeseja concluir o cancelamento? ");					
					scanf("%d", &cancelar);
					switch (cancelar){
						case 1:
							printf("\nReserva cancelada com sucesso!\n");								
							break;
						case 2:
							printf("\nReserva não cancelada.\n");
							break;
						default:
							printf("Valor inválido. Informe novamente.\n");
							system("pause");
							break;
					}
				} while (cancelar!=1 && cancelar!=2);
				
				if (cancelar==1){
					switch (quarto){
						case 1:
							Q = fopen("estadia/quarto1.txt", "w");
							break;
						case 2:
							Q = fopen("estadia/quarto2.txt", "w");
							break;
						case 3:
							Q = fopen("estadia/quarto3.txt", "w");
							break;
						case 4:
							Q = fopen("estadia/quarto4.txt", "w");
							break;
						case 5:
							Q = fopen("estadia/quarto5.txt", "w");
							break;
						case 6:
							Q = fopen("estadia/quarto6.txt", "w");
							break;
						case 7:
							Q = fopen("estadia/quarto7.txt", "w");
							break;
						case 8:
							Q = fopen("estadia/quarto8.txt", "w");
							break;
						case 9:
							Q = fopen("estadia/quarto9.txt", "w");
							break;
						case 10:
							Q = fopen("estadia/quarto10.txt", "w");
							break;
					}			
					
					//Inserir dados ao txt
					fprintf(Q, "%d\n", n-1);
					fprintf(Q, "%d\n", indisp);			
					long qda, qdb;
					int j;						
					for (j=0; j<n; j++){
						qda = quantidade_dias(estadia[j].d1, estadia[j].m1, estadia[j].a1);
						qdb = quantidade_dias(estadia[j].d2, estadia[j].m2, estadia[j].a2);						
						if (q_dias>=qda&&q_dias<=qdb){}					
						else {							
							fprintf(Q, "%s\n", estadia[j].nome);
							fprintf(Q, "%s\n", estadia[j].cpf);
							fprintf(Q, "%s\n", estadia[j].tel);
							fprintf(Q, "%d\n", estadia[j].e);
							if (estadia[j].e==1) fprintf(Q, "%s\n", estadia[j].email);
							fprintf(Q, "%d\n", estadia[j].d1);
							fprintf(Q, "%d\n", estadia[j].m1);
							fprintf(Q, "%d\n", estadia[j].a1);
							fprintf(Q, "%d\n", estadia[j].d2);
							fprintf(Q, "%d\n", estadia[j].m2);
							fprintf(Q, "%d\n", estadia[j].a2);
							fprintf(Q, "%d\n", estadia[j].q_adultos);
							fprintf(Q, "%d\n", estadia[j].q_criancas);
							fprintf(Q, "%d\n", estadia[i].pagamento);
							if (estadia[i].pagamento==1) fprintf(Q, "%d\n", estadia[i].forma_pag);
							fprintf(Q, "%f\n", estadia[i].valor);
						}
					}			
					fclose(Q);
				}
			}
		}		
	}	
	if (busca==1){
		printf("Não há reserva por este quarto nesta data.\n");
	}
	system("pause");
	controle_hospedagem(usuario, adm);
	return 0;
}

int realizar_pagamento(char usuario[20], int adm){
	//Informar quarto desejado
	system("CLS");
	int quarto;
	printf("\n\t\tCANCELAR RESERVA\n");
	do {
		printf("Quarto: ");
		scanf("%d", &quarto);
		if (quarto < 1 || quarto > 10){
			printf("Valor inválido para número do quarto. (Valores válidos: 1-10)\n\n");
		}
	} while (quarto<1 || quarto >10);
	
	struct hospedagem estadia[100];
	FILE *Q;
	//Buscar txt relacionado ao quarto
	switch (quarto){
		case 1:
			Q = fopen("estadia/quarto1.txt", "r");
			break;
		case 2:
			Q = fopen("estadia/quarto2.txt", "r");
			break;
		case 3:
			Q = fopen("estadia/quarto3.txt", "r");
			break;
		case 4:
			Q = fopen("estadia/quarto4.txt", "r");
			break;
		case 5:
			Q = fopen("estadia/quarto5.txt", "r");
			break;
		case 6:
			Q = fopen("estadia/quarto6.txt", "r");
			break;
		case 7:
			Q = fopen("estadia/quarto7.txt", "r");
			break;
		case 8:
			Q = fopen("estadia/quarto8.txt", "r");
			break;
		case 9:
			Q = fopen("estadia/quarto9.txt", "r");
			break;
		case 10:
			Q = fopen("estadia/quarto10.txt", "r");
			break;
	}		
	int i, n;
	fscanf(Q, "%d", &n);
	int indisp;
	fscanf(Q, "%d", &indisp);		
	//Receber dados salvos no txt do determinado quarto			
	for (i=0; i<n; i++){
		fscanf(Q, "%s", &estadia[i].nome);
		fscanf(Q, "%s", &estadia[i].cpf);
		fscanf(Q, "%s", &estadia[i].tel);
		fscanf(Q, "%d", &estadia[i].e);
		if (estadia[i].e==1){
			fscanf(Q, "%s", &estadia[i].email);
		}
		fscanf(Q, "%d", &estadia[i].d1);
		fscanf(Q, "%d", &estadia[i].m1);
		fscanf(Q, "%d", &estadia[i].a1);
		fscanf(Q, "%d", &estadia[i].d2);
		fscanf(Q, "%d", &estadia[i].m2);
		fscanf(Q, "%d", &estadia[i].a2);
		fscanf(Q, "%d", &estadia[i].q_adultos);
		fscanf(Q, "%d", &estadia[i].q_criancas);
		fscanf(Q, "%d", &estadia[i].pagamento);
		if (estadia[i].pagamento==1) fscanf(Q, "%d", &estadia[i].forma_pag);
		fscanf(Q, "%f", &estadia[i].valor);	
	}
	fclose(Q);
	
	//Inserir dados relacionados às datas de entradas e saída
	printf("\n\n\t\tBUSCAR DATA DE ESTADIA\n");
	printf("Informe a data de entrada, de saída ou uma data entre o período de estadia.\n\n");
	int d, m, a;
	a = verificar_ano();
 	m = verificar_mes(a);
	d = verificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o método quantidade_dias()
	long q_dias;
	q_dias = quantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
	printf("Quarto: %d\n", quarto);	
	printf("Data: %d/%d/%d\n\n", d, m, a);	
	printf("\t\tREALIZANDO BUSCA");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	//Verificar disponibilidade do quarto
	int busca=0;
	if (n==0){		
		busca=1;		
	}
	else {				
		busca=1;		
		long qdx, qdy;
		for (i=0; i<n; i++){
			qdx = quantidade_dias(estadia[i].d1, estadia[i].m1, estadia[i].a1);
			qdy = quantidade_dias(estadia[i].d2, estadia[i].m2, estadia[i].a2);
			if (q_dias>=qdx&&q_dias<=qdy){
				busca=0;
				int p;
				do{				
					printf("Reserva localizada.\n\n");					
					printf("\t\tDADOS DA RESERVA\n");
					printf("Data de entrada: %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1);
					printf("Data de saída: %d/%d/%d\n", estadia[i].d2, estadia[i].m2, estadia[i].a2);
					long q_difz;
					q_difz = qdy-qdx+1;
					printf("Dias de hospedagem: %d\n", q_difz);
					printf("Cliente: %s\n", estadia[i].nome);
					printf("CPF: %s\n", estadia[i].cpf);
					printf("Telefone: %s\n", estadia[i].tel);
					if (estadia[i].e==1){
						printf("E-mail: %s\n", estadia[i].email);
					}
					else printf("Não possui e-mail\n");
					printf("Quantidade de hóspedes: %d (%d adultos e %d crianças)\n\n", (estadia[i].q_adultos+estadia[i].q_criancas), estadia[i].q_adultos, estadia[i].q_criancas);									
								
					if (estadia[i].pagamento==1){
						printf("  **Esta reserva já foi paga.\n\n");
						system("pause");
						controle_hospedagem(usuario, adm);
					}					 
					else {
						printf("\nValor: R$ %.2f", estadia[i].valor);
						printf("\n\t1 - Em dinheiro");
						printf("\n\t2 - Em cartão");
						printf("\n\t3 - Cancelar pagamento");
						printf("\n\n\tPagamento: ");
						scanf("%d", &p);
						switch (p){
							case 1:
								printf("\nPagamento realizado com sucesso!\n");
								estadia[i].pagamento=1;
								estadia[i].forma_pag=0;								
								break;
							case 2:
								printf("\nPagamento realizado com sucesso!\n");
								estadia[i].pagamento=1;
								estadia[i].forma_pag=1;
								break;
							case 3:
								printf("\nPagamento não realizado.\n");
								estadia[i].pagamento=0;								
								break;
							default:
								printf("Valor inválido. Informe novamente.\n");
								system("pause");
								break;
						}
					}
				} while (p!=1 && p!=2 && p!=3);
				
				switch (quarto){
					case 1:
						Q = fopen("estadia/quarto1.txt", "w");
						break;
					case 2:
						Q = fopen("estadia/quarto2.txt", "w");
						break;
					case 3:
						Q = fopen("estadia/quarto3.txt", "w");
						break;
					case 4:
						Q = fopen("estadia/quarto4.txt", "w");
						break;
					case 5:
						Q = fopen("estadia/quarto5.txt", "w");
						break;
					case 6:
						Q = fopen("estadia/quarto6.txt", "w");
						break;
					case 7:
						Q = fopen("estadia/quarto7.txt", "w");
						break;
					case 8:
						Q = fopen("estadia/quarto8.txt", "w");
						break;
					case 9:
						Q = fopen("estadia/quarto9.txt", "w");
						break;
					case 10:
						Q = fopen("estadia/quarto10.txt", "w");
						break;
				}
				//Inserir dados ao txt
				fprintf(Q, "%d\n", n);
				fprintf(Q, "%d\n", indisp);
				for (i=0; i<n; i++){						
					fprintf(Q, "%s\n", estadia[i].nome);
					fprintf(Q, "%s\n", estadia[i].cpf);
					fprintf(Q, "%s\n", estadia[i].tel);
					fprintf(Q, "%d\n", estadia[i].e);
					if (estadia[i].e==1) fprintf(Q, "%s\n", estadia[i].email);
					fprintf(Q, "%d\n", estadia[i].d1);
					fprintf(Q, "%d\n", estadia[i].m1);
					fprintf(Q, "%d\n", estadia[i].a1);
					fprintf(Q, "%d\n", estadia[i].d2);
					fprintf(Q, "%d\n", estadia[i].m2);
					fprintf(Q, "%d\n", estadia[i].a2);
					fprintf(Q, "%d\n", estadia[i].q_adultos);
					fprintf(Q, "%d\n", estadia[i].q_criancas);	
					fprintf(Q, "%d\n", estadia[i].pagamento);	
					if (estadia[i].pagamento==1) fprintf(Q, "%d\n", estadia[i].forma_pag);
					fprintf(Q, "%f\n", estadia[i].valor);
				}
				fclose(Q);				
			}
		}
	}
	if (busca==1){
		printf("Não há reserva por este quarto nesta data.\n");
	}
	system("pause");
	controle_hospedagem(usuario, adm);
	return 0;
}


int listar_reservas(char usuario[20], int adm){
	//Informar quarto desejado
	system("CLS");
	int quarto, x=0;
	printf("\n\t\tLISTAR RESERVAS\n");
	for (quarto=1; quarto<=10; quarto++){
		printf("\n\tQUARTO %d\n", quarto);
		struct hospedagem estadia[100];
		FILE *Q;
		//Buscar txt relacionado ao quarto
		switch (quarto){
			case 1:
				Q = fopen("estadia/quarto1.txt", "r");
				break;
			case 2:
				Q = fopen("estadia/quarto2.txt", "r");
				break;
			case 3:
				Q = fopen("estadia/quarto3.txt", "r");
				break;
			case 4:
				Q = fopen("estadia/quarto4.txt", "r");
				break;
			case 5:
				Q = fopen("estadia/quarto5.txt", "r");
				break;
			case 6:
				Q = fopen("estadia/quarto6.txt", "r");
				break;
			case 7:
				Q = fopen("estadia/quarto7.txt", "r");
				break;
			case 8:
				Q = fopen("estadia/quarto8.txt", "r");
				break;
			case 9:
				Q = fopen("estadia/quarto9.txt", "r");
				break;
			case 10:
				Q = fopen("estadia/quarto10.txt", "r");
				break;
		}		
		int i, n;
		fscanf(Q, "%d", &n);
		if (n>0) x=1;
		int indisp;
		fscanf(Q, "%d", &indisp);
		//Receber dados salvos no txt do determinado quarto			
		for (i=0; i<n; i++){
			fscanf(Q, "%s", &estadia[i].nome);
			fscanf(Q, "%s", &estadia[i].cpf);
			fscanf(Q, "%s", &estadia[i].tel);
			fscanf(Q, "%d", &estadia[i].e);
			if (estadia[i].e==1){
				fscanf(Q, "%s", &estadia[i].email);
			}
			fscanf(Q, "%d", &estadia[i].d1);
			fscanf(Q, "%d", &estadia[i].m1);
			fscanf(Q, "%d", &estadia[i].a1);
			fscanf(Q, "%d", &estadia[i].d2);
			fscanf(Q, "%d", &estadia[i].m2);
			fscanf(Q, "%d", &estadia[i].a2);
			fscanf(Q, "%d", &estadia[i].q_adultos);
			fscanf(Q, "%d", &estadia[i].q_criancas);
			fscanf(Q, "%d", &estadia[i].pagamento);
			if (estadia[i].pagamento==1) fscanf(Q, "%d", &estadia[i].forma_pag);
			fscanf(Q, "%f", &estadia[i].valor);	
			
			printf("%s (Telefone: %s)\n", estadia[i].nome, estadia[i].tel);
			printf("%d/%d/%d - %d/%d/%d\n", estadia[i].d1, estadia[i].m1, estadia[i].a1, estadia[i].d2, estadia[i].m2, estadia[i].a2);
			if (estadia[i].pagamento==1) printf("Reserva paga");
			else printf("Reserva não paga");
			printf(" - R$ %.2f\n\n", estadia[i].valor);
			
		}
		if (n==0){
			printf("Não há reservas para este quarto.\n\n");
		}		
		fclose(Q);			
	}	
	
	printf("\n");
	system("pause");
	controle_hospedagem(usuario, adm);
	return 0;
}
