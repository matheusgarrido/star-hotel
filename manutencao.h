#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int xverificar_ano(){
	int a, x=0;
	do {
		printf("Ano: ");
		scanf("%d", &a);
		if (a < 2017) {
			printf("Ano inv�lido. (Valores v�lidos: acima de 2017)\n");
			x=1;
		}
		else {
			x=0;
			printf("\n");
		}
	} while (x == 1);
	return a;
}

//Verificar se o valor para m�s � v�lido
int xverificar_mes(int a){
	int m, x=0;
	do {
		printf("M�s: ");
		scanf("%d", &m);
		if (a == 2017){
			if (m<6 || m>12){
				printf("M�s inv�lido. (Valores v�lidos: 6-12)\n");		
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}	
		}
		else {
			if (m < 1 || m > 12) {
				printf("M�s inv�lido. (Valores v�lidos: 1-12)\n");		
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

//Verificar se o dia � v�lido de acordo com a quantidade total de dias de um m�s
int xverificar_dia(int a, int m){
	int d, x=0;
	do {
		printf("Dia: ");
		scanf("%d", &d);		
		if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
			if (d < 1 || d > 31){
				printf("Dia inv�lido. (Valores v�lidos para este m�s: 1-31)\n");				
				x=1;
			}
			else {
				x=0;
				printf("\n");
			}
		}
		else if (m==4||m==6||m==9||m==11){
			if (d<1 || d>30){
				printf("Dia inv�lido. (Valores v�lidos para este m�s: 1-30)\n");
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
					printf("Dia inv�lido. (Valores v�lidos para este m�s: 1-29)\n");
					x=1;
				}
				else {
					x=0;
					printf("\n");
				}		
			}
			else {
				if (d < 1 || d>28){
					printf("Dia inv�lido. (Valores v�lidos para este m�s: 1-28)\n");
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

//Criar um long com a quantidade total de dias entre 1/1/2017 e a data importada para este m�todo
long xquantidade_dias(int d, int m, int a){
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

//Struct para armazenar os dados recebidos do txt + dados a serem cadastrados
struct manutencao{
	char nomemanu[50];
	char profissional[50];
	char tel[12];
	int e;
	char email[50];
	int d1;
	int m1;
	int a1;
	int d2;
	int m2;
	int a2;
	float valor;
	int pagamento;
};

int agendar_manutencao(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tAGENDAR MANUTEN��O\n");	
	struct manutencao manu[100];
	FILE *M;	
	M = fopen("manutencao.txt", "r");
	int i, n, disponibilidade=0;
	fscanf(M, "%d", &n);	
	//Receber dados salvos no txt do determinada manuten��o		
	for (i=0; i<n; i++){
		fscanf(M, "%s", &manu[i].nomemanu);
		fscanf(M, "%s", &manu[i].profissional);
		fscanf(M, "%s", &manu[i].tel);
		fscanf(M, "%d", &manu[i].e);
		if (manu[i].e==1) fscanf(M, "%s", &manu[i].email);	
		fscanf(M, "%d", &manu[i].d1);
		fscanf(M, "%d", &manu[i].m1);
		fscanf(M, "%d", &manu[i].a1);
		fscanf(M, "%d", &manu[i].d2);
		fscanf(M, "%d", &manu[i].m2);
		fscanf(M, "%d", &manu[i].a2);
		fscanf(M, "%f", &manu[i].valor);	
		fscanf(M, "%d", &manu[i].pagamento);
	}
	fclose(M);
	//Inserir dados relacionados �s datas
	printf("\n\n\tDATA DE IN�CIO\n");		
	manu[n].a1 = xverificar_ano();
 	manu[n].m1 = xverificar_mes(manu[n].a1);
	manu[n].d1 = xverificar_dia(manu[n].a1, manu[n].m1);	
	printf("\n\n\tDATA DE T�RMINO\n");	
	manu[n].a2 = xverificar_ano();
	manu[n].m2 = xverificar_mes(manu[n].a2);
	manu[n].d2 = xverificar_dia(manu[n].a2, manu[n].m2);
	fflush(stdin);
	
	long q_dias1, q_dias2, q_dif;
	q_dias1 = xquantidade_dias(manu[n].d1, manu[n].m1, manu[n].a1);
	q_dias2 = xquantidade_dias(manu[n].d2, manu[n].m2, manu[n].a2);	
	q_dif = q_dias2-q_dias1+1;
		
	//Mensagem de erro caso as datas estejam invertidas
	if (q_dias1>q_dias2) {
		printf("\n\nErro de verifica��o de disponibilidade.\nA data de in�cio (%d/%d/%d) ocorrer� antes da data de t�rmino (%d/%d/%d).\n",
				manu[n].d1, manu[n].m1, manu[n].a1, manu[n].d2, manu[n].m2, manu[n].a2);
		system("pause");
		system("cls");
		agendar_manutencao(usuario, adm);
	}
	
	//Informar dados da manuten��o
	system("cls");
	printf("\n\n\t\tDADOS DA MANUTEN��O\n");	
	printf("Nome da manuten��o: ");					
	gets(manu[n].nomemanu);
	fflush(stdin);
	printf("Nome do profissional: ");
	gets(manu[n].profissional);
	fflush(stdin);					
	printf("Telefone: ");
	gets(manu[n].tel);
	fflush(stdin);					
	printf("Possui e-mail? (1-Sim / 2-N�o): ");
	scanf("%d", &manu[n].e);
	fflush(stdin);
	if (manu[n].e==1){
		printf("E-mail: ");
		gets(manu[n].email);
		fflush(stdin);						
	}
	else manu[n].e=0;
	printf("Custo: R$ ");
	scanf("%f", &manu[n].valor);
	
	//Confirmar finaliza��o de agendamento
	int concluir_agendamento;
	do{
		system("cls");
		printf("\n\t\tDADOS DA MANUTEN��O\n");
		printf("Data de in�cio: %d/%d/%d\n", manu[n].d1, manu[n].m1, manu[n].a1);
		printf("Data de t�rmino: %d/%d/%d\n", manu[n].d2, manu[n].m2, manu[n].a2);
		printf("Nome da manuten��o: %s\n", manu[n].nomemanu);
		printf("Nome do profissional: %s\n", manu[n].profissional);
		printf("Telefone: %s\n", manu[n].tel);
		if (manu[n].e==1) printf("E-mail: %s\n", manu[n].email);
		else printf("N�o possui e-mail\n");
		printf("Custo da manuten��o: R$ %.2f\n",manu[n].valor);
		manu[n].pagamento=0;
		printf("\n\t1 - Concluir agendamento");
		printf("\n\t2 - Cancelar agendamento");
		printf("\n\tDeseja concluir a agendamento? ");
		
		scanf("%d", &concluir_agendamento);
		switch (concluir_agendamento){
			case 1:
				printf("\nAgendamento conclu�do com sucesso!\n");
				break;
			case 2:
				printf("\nAgendamento cancelado.\n");
				break;
			default:
				printf("Valor inv�lido. Informe novamente.\n");
				system("pause");
				break;
		}
	} while (concluir_agendamento!=1 && concluir_agendamento!=2);
	
	if (concluir_agendamento==1){
		M = fopen("manutencao.txt", "w");
		n++;
		//Inserir dados ao txt
		fprintf(M, "%d\n", n);
		for (i=0; i<n; i++){
			fprintf(M, "%s\n", manu[i].nomemanu);
			fprintf(M, "%s\n", manu[i].profissional);
			fprintf(M, "%s\n", manu[i].tel);
			fprintf(M, "%d\n", manu[i].e);
			if (manu[i].e==1) fprintf(M, "%s\n", manu[i].email);
			fprintf(M, "%d\n", manu[i].d1);
			fprintf(M, "%d\n", manu[i].m1);
			fprintf(M, "%d\n", manu[i].a1);
			fprintf(M, "%d\n", manu[i].d2);
			fprintf(M, "%d\n", manu[i].m2);
			fprintf(M, "%d\n", manu[i].a2);
			fprintf(M, "%f\n", manu[i].valor);	
			fprintf(M, "%d\n", manu[i].pagamento);
		}
		fclose(M);
	}
	system("pause");
	controle_manu(usuario, adm);	
	return 0;
}

int alterar_manutencao(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tALTERAR MANUTEN��O\n");
	struct manutencao manu[100];
	FILE *M;
	M = fopen("manutencao.txt", "r");
	int i, n, disponibilidade=0;
	fscanf(M, "%d", &n);	
	//Receber dados salvos no txt do determinada manuten��o		
	for (i=0; i<n; i++){
		fscanf(M, "%s", &manu[i].nomemanu);
		fscanf(M, "%s", &manu[i].profissional);
		fscanf(M, "%s", &manu[i].tel);
		fscanf(M, "%d", &manu[i].e);
		if (manu[i].e==1) fscanf(M, "%s", &manu[i].email);	
		fscanf(M, "%d", &manu[i].d1);
		fscanf(M, "%d", &manu[i].m1);
		fscanf(M, "%d", &manu[i].a1);
		fscanf(M, "%d", &manu[i].d2);
		fscanf(M, "%d", &manu[i].m2);
		fscanf(M, "%d", &manu[i].a2);
		fscanf(M, "%f", &manu[i].valor);			
		fscanf(M, "%d", &manu[i].pagamento);
	}
	fclose(M);
	
	//Inserir dados relacionados �s datas
	printf("\n\n\t\tBUSCAR DATA DE MANUTEN��O\n");
	printf("Informe a data de in�cio, de t�rmino ou uma data entre o per�odo de manuten��o.\n\n");
	int d, m, a;
	a = xverificar_ano();
 	m = xverificar_mes(a);
	d = xverificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o m�todo quantidade_dias()
	long q_dias;
	q_dias = xquantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
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
			qdx = xquantidade_dias(manu[i].d1, manu[i].m1, manu[i].a1);
			qdy = xquantidade_dias(manu[i].d2, manu[i].m2, manu[i].a2);
			if (q_dias>=qdx&&q_dias<=qdy){
				busca=0;
				printf("Manuten��o localizada.\n\n");
				
				printf("\t\tDADOS DA MANUTEN��O\n");
				printf("Data de in�cio: %d/%d/%d\n", manu[i].d1, manu[i].m1, manu[i].a1);
				printf("Data de t�rmino: %d/%d/%d\n", manu[i].d2, manu[i].m2, manu[i].a2);
				printf("Nome da manuten��o: %s\n", manu[i].nomemanu);
				printf("Profissional: %s\n", manu[i].profissional);
				printf("Telefone: %s\n", manu[i].tel);
				if (manu[i].e==1) printf("E-mail: %s\n", manu[i].email);
				else printf("N�o possui e-mail\n");
				printf("Custo da manuten��o: R$ %.2f\n\n",manu[i].valor);
				
				if (manu[i].pagamento==1) printf("  **Esta manuten��o j� foi paga.\n\n");					
				else printf("  **Esta manuten��o ainda n�o foi paga.\n\n");				
				system("pause");
				
				int x=0;
				long q_dias1, q_dias2, q_dif;
				do{
					system("cls");
					x=1;		
					printf("\n\t\tNOVOS DADOS");
					//Inserir dados relacionados �s datas de entradas e sa�da
					printf("\n\n\t\tDATA DE IN�CIO\n");
					manu[i].a1 = xverificar_ano();
	 				manu[i].m1 = xverificar_mes(manu[i].a1);
					manu[i].d1 = xverificar_dia(manu[i].a1, manu[i].m1);				
					printf("\n\n\t\tDATA DE T�RMINO\n");				
					manu[i].a2 = xverificar_ano();
					manu[i].m2 = xverificar_mes(manu[i].a2);
					manu[i].d2 = xverificar_dia(manu[i].a2, manu[i].m2);
					
					q_dias1 = xquantidade_dias(manu[i].d1, manu[i].m1, manu[i].a1);
					q_dias2 = xquantidade_dias(manu[i].d2, manu[i].m2, manu[i].a2);
					
					q_dif = q_dias2-q_dias1+1;
			
					//Mensagem de erro caso as datas de entrada e sa�da estejam invertidas
					if (q_dias1>q_dias2) {
						printf("\n\nErro de verifica��o de disponibilidade.\nA data de in�cio (%d/%d/%d) ocorrer� antes da data de t�rmino (%d/%d/%d).\n",
								manu[i].d1, manu[i].m1, manu[i].a1, manu[i].d2, manu[i].m2, manu[i].a2);
						system("pause");
						x=0;
					}
				} while (x==0);
				
				//Menu para verificar disponibilidade
				system("cls");				
				printf("\n\t\tMANUTEN��O DESEJADA\n");
				printf("Data de in�cio: %d/%d/%d\n", manu[i].d1, manu[i].m1, manu[i].a1);
				printf("Data de t�rmino: %d/%d/%d\n", manu[i].d2, manu[i].m2, manu[i].a2);
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
						qda = quantidade_dias(manu[j].d1, manu[j].m1, manu[j].a1);
						qdb = quantidade_dias(manu[j].d2, manu[j].m2, manu[j].a2);
						if ((q_dias1>=qda&&q_dias1<=qdb)||(q_dias2>=qda&&q_dias2<=qdb)){
							if ((q_dias1<qdx&&q_dias1>qdy)||(q_dias2<qdx&&q_dias2>qdy)){
								disponibilidade=0;
								printf("Manuten��o n�o dispon�vel nestas datas.\n");	
							}
						}
					}
				}
				
				//Informar quantidade de h�spedes	
				if (disponibilidade==1){					
					fflush(stdin);
					printf("\n\n\t\tDADOS DA MANUTEN��O\n");	
					printf("Nome da manuten��o: ");	
					gets(manu[i].nomemanu);
					fflush(stdin);
					printf("Nome do profissional: ");
					gets(manu[i].profissional);
					fflush(stdin);					
					printf("Telefone: ");
					gets(manu[i].tel);
					fflush(stdin);					
					printf("Possui e-mail? (1-Sim / 2-N�o): ");
					scanf("%d", &manu[i].e);
					fflush(stdin);
					if (manu[i].e==1){
						printf("E-mail: ");
						gets(manu[i].email);
						fflush(stdin);						
					}
					else manu[i].e=0;
					printf("Custo: R$ ");
					scanf("%f", &manu[i].valor);
							
					int alterar;
					do{							
						system("cls");
						printf("\n\t\tDADOS DA MANUTEN��O\n");
						printf("Data de in�cio: %d/%d/%d\n", manu[n].d1, manu[n].m1, manu[n].a1);
						printf("Data de t�rmino: %d/%d/%d\n", manu[n].d2, manu[n].m2, manu[n].a2);
						printf("Nome da manuten��o: %s\n", manu[n].nomemanu);
						printf("Nome do profissional: %s\n", manu[n].profissional);
						printf("Telefone: %s\n", manu[n].tel);
						if (manu[n].e==1){
							printf("E-mail: %s\n", manu[n].email);
						}
						else printf("N�o possui e-mail\n");
						printf("Custo da manuten��o: R$ %.2f\n",manu[i].valor);	
						if (manu[i].pagamento==1) printf("  **Esta manuten��o j� foi paga.\n\n");					
						else printf("  **Esta manuten��o ainda n�o foi paga.\n\n");		
								
						printf("\n\t1 - Concluir altera��o");
						printf("\n\t2 - Cancelar altera��o");
						printf("\n\tDeseja concluir a altera��o? ");
						
						scanf("%d", &alterar);
						switch (alterar){
							case 1:
								printf("\nAltera��o conclu�da com sucesso!\n");
								break;
							case 2:
								printf("\nAltera��o cancelada.\n");
								break;
							default:
								printf("Valor inv�lido. Informe novamente.");
								system("pause");
								break;
						}
					} while (alterar!=1 && alterar!=2);
					
					//Salvar dados da reversa no txt
					if (alterar==1){
						M = fopen("manutencao.txt", "w");						
						//Inserir dados ao txt
						fprintf(M, "%d\n", n);
						for (i=0; i<n; i++){
							fprintf(M, "%s\n", manu[i].nomemanu);
							fprintf(M, "%s\n", manu[i].profissional);
							fprintf(M, "%s\n", manu[i].tel);
							fprintf(M, "%d\n", manu[i].e);
							if (manu[i].e==1) fprintf(M, "%s\n", manu[i].email);
							fprintf(M, "%d\n", manu[i].d1);
							fprintf(M, "%d\n", manu[i].m1);
							fprintf(M, "%d\n", manu[i].a1);
							fprintf(M, "%d\n", manu[i].d2);
							fprintf(M, "%d\n", manu[i].m2);
							fprintf(M, "%d\n", manu[i].a2);
							fprintf(M, "%f\n", manu[i].valor);
							fprintf(M, "%d\n", manu[i].pagamento);
						}
						fclose(M);
					}
				}
			}
		}
	}
	
	if (busca==1){
		printf("N�o h� manuten��es nesta data.\n");
	}
	
	system("pause");
	controle_manu(usuario, adm);	
	return 0;
}

int excluir_manutencao(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tALTERAR MANUTEN��O\n");
	struct manutencao manu[100];
	FILE *M;
	M = fopen("manutencao.txt", "r");
	int i, n, disponibilidade=0;
	fscanf(M, "%d", &n);	
	//Receber dados salvos no txt do determinada manuten��o		
	for (i=0; i<n; i++){
		fscanf(M, "%s", &manu[i].nomemanu);
		fscanf(M, "%s", &manu[i].profissional);
		fscanf(M, "%s", &manu[i].tel);
		fscanf(M, "%d", &manu[i].e);
		if (manu[i].e==1) fscanf(M, "%s", &manu[i].email);	
		fscanf(M, "%d", &manu[i].d1);
		fscanf(M, "%d", &manu[i].m1);
		fscanf(M, "%d", &manu[i].a1);
		fscanf(M, "%d", &manu[i].d2);
		fscanf(M, "%d", &manu[i].m2);
		fscanf(M, "%d", &manu[i].a2);
		fscanf(M, "%f", &manu[i].valor);
		fscanf(M, "%d", &manu[i].pagamento);					
	}
	fclose(M);
	
	//Inserir dados relacionados �s datas
	printf("\n\n\tBUSCAR DATA DE MANUTEN��O\n");
	printf("Informe a data de in�cio, de t�rmino ou uma data entre o per�odo de manuten��o.\n\n");
	int d, m, a;
	a = xverificar_ano();
 	m = xverificar_mes(a);
	d = xverificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o m�todo quantidade_dias()
	long q_dias;
	q_dias = xquantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
	printf("Data: %d/%d/%d\n\n", d, m, a);
	printf("\t\tREALIZANDO BUSCA");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=1;
	int excluir;
	long qdx, qdy;
	for (i=0; i<n; i++){
		qdx = xquantidade_dias(manu[i].d1, manu[i].m1, manu[i].a1);
		qdy = xquantidade_dias(manu[i].d2, manu[i].m2, manu[i].a2);
		if (q_dias>=qdx&&q_dias<=qdy){
			z=0;
			printf("Manuten��o localizada.\n\n");				
			printf("\t\tDADOS DA MANUTEN��O\n");
			printf("Data de in�cio: %d/%d/%d\n", manu[i].d1, manu[i].m1, manu[i].a1);
			printf("Data de t�rmino: %d/%d/%d\n", manu[i].d2, manu[i].m2, manu[i].a2);
			printf("Nome da manuten��o: %s\n", manu[i].nomemanu);
			printf("Profissional: %s\n", manu[i].profissional);
			printf("Telefone: %s\n", manu[i].tel);
			if (manu[i].e==1) printf("E-mail: %s\n", manu[i].email);
			else printf("N�o possui e-mail\n");
			printf("Custo da manuten��o: R$ %.2f\n\n",manu[i].valor);
			if (manu[i].pagamento==1) printf("  **Esta manuten��o j� foi paga.\n\n");					
			else printf("  **Esta manuten��o ainda n�o foi paga.\n\n");	
			
			printf("\n\t1 - Excluir manuten��o");
			printf("\n\t2 - Cancelar exclus�o");
			printf("\n\tDeseja concluir a exclus�o? ");
			scanf("%d", &excluir);			
	
		} while(excluir!=1 && excluir!=2);	
		switch (excluir){
			case 1:
				printf("\nManuten��o exclu�da com sucesso!\n");								
				break;
			case 2:
				printf("\nManuten��o n�o exclu�da.\n");
				break;
			default:
				printf("\nValor inv�lido. Informe novamente.\n");
				system("pause");
				break;
		}
		if (excluir==1){
			M=fopen("manutencao.txt","w");
			fprintf(M, "%d\n", n-1);			
			long qda, qdb;
			int j;					
			for (j=0; j<n; j++){
				qda = xquantidade_dias(manu[j].d1, manu[j].m1, manu[j].a1);
				qdb = xquantidade_dias(manu[j].d2, manu[j].m2, manu[j].a2);						
				if (q_dias>=qda&&q_dias<=qdb){}					
				else {							
					fprintf(M, "%s\n", manu[j].nomemanu);
					fprintf(M, "%s\n", manu[j].profissional);
					fprintf(M, "%s\n", manu[j].tel);
					fprintf(M, "%d\n", manu[j].e);
					if (manu[j].e==1) fprintf(M, "%s\n", manu[j].email);
					fprintf(M, "%d\n", manu[j].d1);
					fprintf(M, "%d\n", manu[j].m1);
					fprintf(M, "%d\n", manu[j].a1);
					fprintf(M, "%d\n", manu[j].d2);
					fprintf(M, "%d\n", manu[j].m2);
					fprintf(M, "%d\n", manu[j].a2);
					fprintf(M, "%f\n", manu[j].valor);
					fprintf(M, "%d\n", manu[j].pagamento);
				}
			}
			fclose(M);
		}	
	}
	if (z==1){
		printf("N�o h� manuten��es nesta data.\n");
	}
	
	system("pause");
	controle_manu(usuario, adm);	
	return 0;
}


int listar_manutencao(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tLISTAR MANUTEN��ES\n");
	struct manutencao manu[100];
	FILE *M;
	M = fopen("manutencao.txt", "r");
	int i, n, disponibilidade=0;
	fscanf(M, "%d", &n);	
	//Receber dados salvos no txt do determinada manuten��o		
	for (i=0; i<n; i++){
		fscanf(M, "%s", &manu[i].nomemanu);
		fscanf(M, "%s", &manu[i].profissional);
		fscanf(M, "%s", &manu[i].tel);
		fscanf(M, "%d", &manu[i].e);
		if (manu[i].e==1) fscanf(M, "%s", &manu[i].email);	
		fscanf(M, "%d", &manu[i].d1);
		fscanf(M, "%d", &manu[i].m1);
		fscanf(M, "%d", &manu[i].a1);
		fscanf(M, "%d", &manu[i].d2);
		fscanf(M, "%d", &manu[i].m2);
		fscanf(M, "%d", &manu[i].a2);
		fscanf(M, "%f", &manu[i].valor);
		fscanf(M, "%d", &manu[i].pagamento);
		
		printf("%s\n", manu[i].nomemanu);
		printf("%s (Telefone: %s)\n", manu[i].profissional, manu[i].tel);		
		printf("%d/%d/%d - %d/%d/%d\n", manu[i].d1, manu[i].m1, manu[i].a1, manu[i].d2, manu[i].m2, manu[i].a2);
		if (manu[i].pagamento==1) printf("Manuten��o paga");
		else printf("Manuten��o n�o paga");					
		printf(" - R$ %.2f\n\n", manu[i].valor);
	}	
	if (n==0){
		printf("N�o h� manuten��es agendadas.\n");
	}	
	
	system("pause");
	controle_manu(usuario, adm);	
	return 0;
}


int manu_pagamento(char usuario[20], int adm){
system("CLS");
	printf("\n\t\tREGISTRAR PAGAMENTO DE MANUTEN��O\n");
	struct manutencao manu[100];
	FILE *M;
	M = fopen("manutencao.txt", "r");
	int i, n, disponibilidade=0;
	fscanf(M, "%d", &n);	
	//Receber dados salvos no txt do determinada manuten��o		
	for (i=0; i<n; i++){
		fscanf(M, "%s", &manu[i].nomemanu);
		fscanf(M, "%s", &manu[i].profissional);
		fscanf(M, "%s", &manu[i].tel);
		fscanf(M, "%d", &manu[i].e);
		if (manu[i].e==1) fscanf(M, "%s", &manu[i].email);	
		fscanf(M, "%d", &manu[i].d1);
		fscanf(M, "%d", &manu[i].m1);
		fscanf(M, "%d", &manu[i].a1);
		fscanf(M, "%d", &manu[i].d2);
		fscanf(M, "%d", &manu[i].m2);
		fscanf(M, "%d", &manu[i].a2);
		fscanf(M, "%f", &manu[i].valor);
		fscanf(M, "%d", &manu[i].pagamento);					
	}
	fclose(M);
	
	//Inserir dados relacionados �s datas
	printf("\n\n\tBUSCAR DATA DE MANUTEN��O\n");
	printf("Informe a data de in�cio, de t�rmino ou uma data entre o per�odo de manuten��o.\n\n");
	int d, m, a;
	a = xverificar_ano();
 	m = xverificar_mes(a);
	d = xverificar_dia(a, m);
		
	//long com a quantidade total de dias entre 1/1/2017 e a datas importadas para o m�todo quantidade_dias()
	long q_dias;
	q_dias = xquantidade_dias(d, m, a);
	
	//Menu para realizar busca
	system("cls");
	printf("\n\t\tDATA EM BUSCA\n");
	printf("Data: %d/%d/%d\n\n", d, m, a);
	printf("\t\tREALIZANDO BUSCA");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=1, p;
	int excluir;
	long qdx, qdy;
	for (i=0; i<n; i++){
		qdx = xquantidade_dias(manu[i].d1, manu[i].m1, manu[i].a1);
		qdy = xquantidade_dias(manu[i].d2, manu[i].m2, manu[i].a2);
		if (q_dias>=qdx&&q_dias<=qdy){
			z=0;
			printf("Manuten��o localizada.\n\n");
			printf("\t\tDADOS DA MANUTEN��O\n");
			printf("Data de in�cio: %d/%d/%d\n", manu[i].d1, manu[i].m1, manu[i].a1);
			printf("Data de t�rmino: %d/%d/%d\n", manu[i].d2, manu[i].m2, manu[i].a2);
			printf("Nome da manuten��o: %s\n", manu[i].nomemanu);
			printf("Profissional: %s\n", manu[i].profissional);
			printf("Telefone: %s\n", manu[i].tel);
			if (manu[i].e==1) printf("E-mail: %s\n\n", manu[i].email);
			else printf("N�o possui e-mail\n\n");
			
			if (manu[i].pagamento==1){
				printf("  **Esta reserva j� foi paga.\n\n");
				system("pause");
				controle_manu(usuario, adm);
			}
			else {
				printf("Custo da manuten��o: R$ %.2f",manu[i].valor);
				printf("\n\n\tConcluir pagamento? (1-Sim / 2-N�o) ");
				scanf("%d", &p);
				switch (p){
					case 1:
						printf("\nPagamento realizado com sucesso!\n");
						manu[i].pagamento=1;													
						break;
					case 2:
						printf("\nPagamento n�o realizado.\n");												
						break;
					default:
						printf("Valor inv�lido. Informe novamente.\n");
						system("pause");
						break;
				}
			}		
	
		} while(p!=1 && p!=2);	
		
		if (p==1){
			M=fopen("manutencao.txt","w");
			fprintf(M, "%d\n", n);			
			long qda, qdb;
			int j;					
			for (j=0; j<n; j++){		
				fprintf(M, "%s\n", manu[j].nomemanu);
				fprintf(M, "%s\n", manu[j].profissional);
				fprintf(M, "%s\n", manu[j].tel);
				fprintf(M, "%d\n", manu[j].e);
				if (manu[j].e==1) fprintf(M, "%s\n", manu[j].email);
				fprintf(M, "%d\n", manu[j].d1);
				fprintf(M, "%d\n", manu[j].m1);
				fprintf(M, "%d\n", manu[j].a1);
				fprintf(M, "%d\n", manu[j].d2);
				fprintf(M, "%d\n", manu[j].m2);
				fprintf(M, "%d\n", manu[j].a2);
				fprintf(M, "%f\n", manu[j].valor);
				fprintf(M, "%d\n", manu[j].pagamento);
			}
			fclose(M);
		}	
	}
	if (z==1){
		printf("N�o h� manuten��es nesta data.\n");
	}	
	system("pause");
	controle_manu(usuario, adm);	
	return 0;
}
