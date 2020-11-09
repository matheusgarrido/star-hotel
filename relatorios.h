#include <stdio.h>
#include <stdlib.h>

void imprimir_mes(int mes){
	switch(mes){
			case 0:
				printf("janeiro");
				break;
			case 1:
				printf("fevereiro");
				break;
			case 2:
				printf("março");
				break;
			case 3:
				printf("abril");
				break;
			case 4:
				printf("maio");
				break;
			case 5:
				printf("junho");
				break;
			case 6:
				printf("julho");
				break;
			case 7:
				printf("agosto");
				break;
			case 8:
				printf("setembro");
				break;
			case 9:
				printf("outubro");
				break;
			case 10:
				printf("novembro");
				break;
			case 11:
				printf("dezembro");
				break;
	}
}

//Struct para armazenar os dados recebidos do txt + dados a serem cadastrados
struct reserva{
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

int demanda(char usuario[20], int adm) {
	system("CLS");
	printf("\n\t\tRELATÓRIO DE DEMANDA");
	struct reserva estadia[100][10];	
	int i, j, n[10];
	int indisp[10];	
	int tipoq[3];
	for (j=0; j<3; j++) tipoq[j]=0;
	FILE *F;
	for (j=1; j<=10; j++){
		switch (j){
			case 1:
				F = fopen("estadia/quarto1.txt", "r");
				break;
			case 2:
				F = fopen("estadia/quarto2.txt", "r");
				break;
			case 3:
				F = fopen("estadia/quarto3.txt", "r");
				break;
			case 4:
				F = fopen("estadia/quarto4.txt", "r");
				break;
			case 5:
				F = fopen("estadia/quarto5.txt", "r");
				break;
			case 6:
				F = fopen("estadia/quarto6.txt", "r");
				break;
			case 7:
				F = fopen("estadia/quarto7.txt", "r");
				break;
			case 8:
				F = fopen("estadia/quarto8.txt", "r");
				break;
			case 9:
				F = fopen("estadia/quarto9.txt", "r");
				break;
			case 10:
				F = fopen("estadia/quarto10.txt", "r");
				break;
		}		
		fscanf(F, "%d", &n[j]);		
		fscanf(F, "%d", &indisp[j]);			
		//Receber dados salvos no txt de um determinado quarto
		for (i=0; i<n[j]; i++){
			fscanf(F, "%s", &estadia[i][j].nome);
			fscanf(F, "%s", &estadia[i][j].cpf);
			fscanf(F, "%s", &estadia[i][j].tel);
			fscanf(F, "%d", &estadia[i][j].e);
			if (estadia[i][j].e==1){
				fscanf(F, "%s", &estadia[i][j].email);			
			}
			fscanf(F, "%d", &estadia[i][j].d1);
			fscanf(F, "%d", &estadia[i][j].m1);
			fscanf(F, "%d", &estadia[i][j].a1);
			fscanf(F, "%d", &estadia[i][j].d2);
			fscanf(F, "%d", &estadia[i][j].m2);
			fscanf(F, "%d", &estadia[i][j].a2);
			fscanf(F, "%d", &estadia[i][j].q_adultos);
			fscanf(F, "%d", &estadia[i][j].q_criancas);
			fscanf(F, "%d", &estadia[i][j].pagamento);
			if (estadia[i][j].pagamento==1){
				fscanf(F, "%d", &estadia[i][j].forma_pag);			
			}
			fscanf(F, "%f", &estadia[i][j].valor);
		}
		
		if (j>=1&&j<=3) tipoq[0]+=n[j];
		else if (j>=4&&j<=7) tipoq[1]+=n[j];
		else tipoq[2]+=n[j];		
		
		fclose(F);
	}
	
	int soz[10], cas[10], col[10], fam[10];
	int so=0, ca=0, co=0, fa=0;
	int tot_reservas=0;
	int tot_indisp=0;	
	int mes[12];
	for (j=0; j<12; j++) mes[j]=0;		
	for (j=1; j<=10; j++){		
		tot_reservas+=n[j];
		tot_indisp+=indisp[j];
		soz[j]=0;
		cas[j]=0;
		col[j]=0;
		fam[j]=0;	
		for (i=0; i<n[j]; i++){
			if (estadia[i][j].q_criancas==0){
				switch(estadia[i][j].q_adultos){
					case 1:
						soz[j]++;
						so++;
						break;
					case 2:
						cas[j]++;							
						ca++;
						break;
					default:
						col[j]++;
						co++;
				}
			}
			else{
				fam[j]++;	
				fa++;				
			}
			mes[estadia[i][j].m1-1]++;
		}
	}
	
	//Calcular demanda por mês
	int maior_mes[2], pos_mes[2];
	maior_mes[0]=0;
	maior_mes[1]=0;
	pos_mes[0]=0;
	pos_mes[1]=0;
	for (j=0; j<12; j++){
		if (mes[j]>=maior_mes[0]){			
			maior_mes[1]=maior_mes[0];
			pos_mes[1]=pos_mes[0];
			
			maior_mes[0]=mes[j];
			pos_mes[0]=j;
		}
		else if(mes[j]>=maior_mes[1]){
			maior_mes[1]=mes[j];
			pos_mes[1]=j;
		}
	}
	
	
	//Calcular demanda por quarto
	int maior_quarto[2], pos_quarto[2];
	maior_quarto[0]=0;
	maior_quarto[1]=0;
	pos_quarto[0]=0;
	pos_quarto[1]=0;
	for (j=0; j<11; j++){
		if (n[j]>=maior_quarto[0]){			
			maior_quarto[1]=maior_quarto[0];
			pos_quarto[1]=pos_quarto[0];
			
			maior_quarto[0]=n[j];
			pos_quarto[0]=j;
		}
		else if(n[j]>=maior_quarto[1]){
			maior_quarto[1]=n[j];
			pos_quarto[1]=j;
		}		
	}	
	
	if (tot_reservas!=0){
		float perc, perc2;
		printf("\nTotal de reservas: %d\n", tot_reservas);
		printf("Reservas em quartos comuns: %d\n", tipoq[0]);
		printf("Reservas em quartos com ar condicionado: %d\n", tipoq[1]);
		printf("Reservas em suítes: %d\n", tipoq[2]);
		printf("Total de vezes que quartos estavam indisponíveis: %d\n\n", tot_indisp);
		
		perc = (n[pos_quarto[0]]*100)/tot_reservas;		
		if (perc!=100){
			perc2 = (n[pos_quarto[1]]*100)/tot_reservas;
			printf("Quartos mais reservados: %d (%.0f%%) e %d (%.0f%%)\n", pos_quarto[0], perc, pos_quarto[1], perc2);
		}
		else printf("Quarto mais reservado: %d (%.0f%%)\n", pos_quarto[0], perc);
		
		perc = (mes[pos_mes[0]]*100)/tot_reservas;	
		if (perc!=100){
			printf("Meses com mais reservas: ");
			imprimir_mes(pos_mes[0]);
			perc2 = (mes[pos_mes[1]]*100)/tot_reservas;
			printf(" (%.0f%%) e ", perc);
			imprimir_mes(pos_mes[1]);
			printf(" (%.0f%%)\n", perc2);
		}
		else {
			printf("Mês com mais reservas: ");
			imprimir_mes(pos_mes[0]);
			printf(" (%.0f%%)\n", perc);
		}
		
		printf("\nReservas do tipo Família: %d reservas\n", fa);
		printf("Reservas do tipo Casal: %d reservas\n", ca);
		printf("Reservas do tipo Coletivo: %d reservas\n", co);
		printf("Reservas do tipo Sozinho: %d reservas\n", so);
	}
	else printf("\nNão há hospedagens reservadas.");
	
	printf("\n\n");
	system("pause");
	gerenciar_relatorios(usuario, adm);		
	
	return 0;
}

int pagamentos(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tRELATÓRIO DE PAGAMENTOS");
	struct reserva estadia[100][10];
	int i, j, n[10];
	int indisp[10];		
	FILE *F;
	for (j=1; j<=10; j++){
		switch (j){
			case 1:
				F = fopen("estadia/quarto1.txt", "r");
				break;
			case 2:
				F = fopen("estadia/quarto2.txt", "r");
				break;
			case 3:
				F = fopen("estadia/quarto3.txt", "r");
				break;
			case 4:
				F = fopen("estadia/quarto4.txt", "r");
				break;
			case 5:
				F = fopen("estadia/quarto5.txt", "r");
				break;
			case 6:
				F = fopen("estadia/quarto6.txt", "r");
				break;
			case 7:
				F = fopen("estadia/quarto7.txt", "r");
				break;
			case 8:
				F = fopen("estadia/quarto8.txt", "r");
				break;
			case 9:
				F = fopen("estadia/quarto9.txt", "r");
				break;
			case 10:
				F = fopen("estadia/quarto10.txt", "r");
				break;
		}		
		fscanf(F, "%d", &n[j]);		
		fscanf(F, "%d", &indisp[j]);			
		//Receber dados salvos no txt de um determinado quarto
		for (i=0; i<n[j]; i++){
			fscanf(F, "%s", &estadia[i][j].nome);
			fscanf(F, "%s", &estadia[i][j].cpf);
			fscanf(F, "%s", &estadia[i][j].tel);
			fscanf(F, "%d", &estadia[i][j].e);
			if (estadia[i][j].e==1){
				fscanf(F, "%s", &estadia[i][j].email);			
			}
			fscanf(F, "%d", &estadia[i][j].d1);
			fscanf(F, "%d", &estadia[i][j].m1);
			fscanf(F, "%d", &estadia[i][j].a1);
			fscanf(F, "%d", &estadia[i][j].d2);
			fscanf(F, "%d", &estadia[i][j].m2);
			fscanf(F, "%d", &estadia[i][j].a2);
			fscanf(F, "%d", &estadia[i][j].q_adultos);
			fscanf(F, "%d", &estadia[i][j].q_criancas);
			fscanf(F, "%d", &estadia[i][j].pagamento);
			if (estadia[i][j].pagamento==1){
				fscanf(F, "%d", &estadia[i][j].forma_pag);			
			}
			fscanf(F, "%f", &estadia[i][j].valor);
		}
		fclose(F);
	}
	
	int tot_reservas=0;
	int npago=0, dpago=0, cpago=0;
	for (j=1; j<=10; j++){		
		tot_reservas+=n[j];		
		for (i=0; i<n[j]; i++){
			if (estadia[i][j].pagamento==1){
				if (estadia[i][j].forma_pag==0) dpago++;
				else cpago++;
			}
			else npago++;			
		}
	}
		
	
	if (tot_reservas!=0){
		float perc;
		printf("\nTotal de reservas: %d\n", tot_reservas);
		perc = (npago*100)/tot_reservas;
		printf("Reservas não pagas: %d (%.0f%%)\n", npago, perc);
		perc = (dpago*100)/tot_reservas;
		printf("Reservas pagas em dinheiro: %d (%.0f%%)\n", dpago, perc);
		perc = (cpago*100)/tot_reservas;
		printf("Reservas pagas em cartão: %d (%.0f%%)\n", cpago, perc);
	}
	else printf("\nNão há hospedagens reservadas.");
	
	
	printf("\n\n");
	system("pause");
	gerenciar_relatorios(usuario, adm);		
	return 0;
}

struct man{
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

int custos_manutencao(char usuario[20], int adm){
	system("CLS");
	printf("\n\t\tRELATÓRIO DE CUSTOS DE MANUTENÇÃO");
	struct man manu[100];
	int i, j, n;	
	FILE *M;	
	M = fopen("manutencao.txt", "r");		
	fscanf(M, "%d", &n);		
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
		
	int npago=0, pago=0;
	float vp=0, vn=0;
	for (i=0; i<n; i++){
		if (manu[i].pagamento==1) {
			pago++;
			vp+=manu[i].valor;
		}		
		else {
			npago++;
			vn+=manu[i].valor;
		} 
	}		
	
	if (n!=0){
		float perc;
		printf("\nTotal de manutenções: %d\n\n", n);
		if (pago!=0){
			perc = (pago*100)/n;
			printf("Manutenções pagas: %d (%.0f%%)\n", pago, perc);		
			perc = (vp*100)/(vp+vn);
			printf("Total pago: %.2f (%.0f%%)\n\n", vp, perc);
		}
		else printf("Nenhuma manutenção foi paga.\n\n");
		
		if (npago!=0){
			perc = (npago*100)/n;
			printf("Manutenções não pagas: %d (%.0f%%)\n", npago, perc);
			perc = (vn*100)/(vp+vn);
			printf("Total não pago: %.2f (%.0f%%)\n\n", vn, perc);
		}
		else printf("Não há manutenção a ser paga.\n\n");
	}
	else printf("\nNão há manutenções agendadas.");
	
	
	printf("\n\n");
	system("pause");
	gerenciar_relatorios(usuario, adm);		
	return 0;
}

struct func{
	char nome[50];
	char cpf[12];
	char endereco [100];
	float salario;
	int id;
	char usuario[20];
	char senha[10];
	int adm;
};

int salarios(char usuario[20], int adm){	
	system("CLS");
	printf("\n\t\tRELATÓRIOS DE SALÁRIOS\n");
	setlocale(LC_ALL,"Portuguese");
	struct func fun[100];
	FILE *F;
	int n, i;
	F= fopen("funcionario.txt","r");
	fscanf(F,"%d",&n);
	float meds=0, mais=0, mens=999999;
	int pmai, pmen;
	for(i=0; i<n; i++){
		fscanf(F,"%s",&fun[i].nome);
		fscanf(F,"%s",&fun[i].cpf);	
		fscanf(F,"%s",&fun[i].endereco);
		fscanf(F,"%f",&fun[i].salario);
		fscanf(F,"%d",&fun[i].id);
		fscanf(F,"%s",&fun[i].usuario);
		fscanf(F,"%s",&fun[i].senha);
		fscanf(F,"%d",&fun[i].adm);	
		
		meds+=fun[i].salario;
		if (fun[i].salario>=mais) {
			pmai=i;
			mais=fun[i].salario;
		}
		if (fun[i].salario<=mens) {
			pmen=i;
			mens=fun[i].salario;
		}
	}
	fclose(F);		
	
	if (n!=0){
		printf("\nTotal de funcionários: %d\n", n);
		printf("Custo total de salários: R$ %.2f\n", (meds));
		printf("Salário médio: R$ %.2f\n\n", (meds/n));
		
		if (n!=1){
			printf("Funcionário com maior salário: %s (R$ %.2f)\n", fun[pmai].nome, fun[pmai].salario);
			printf("Funcionário com menor salário: %s (R$ %.2f)\n\n\n", fun[pmen].nome, fun[pmen].salario);		
		}
		else printf("\n");
		
	}	
	system("pause");
	gerenciar_relatorios(usuario, adm);
	return 0;
}

struct produtox{
	int cod;
	char nome[100];
	float preco;
	int quant_atual;
	int quant_tot;
	int min;
};

int estoque(char usuario[20], int adm){	
	system("CLS");
	fflush(stdin);
	setlocale(LC_ALL,"Portuguese");
	printf("\n\t\tRELATÓRIOS DE ESTOQUE");
	struct produtox prod[100];
	FILE *P;
	int n, i;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	int maiorsaida=0, pmaior, totest=0;
	float totvalor=0;
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
		
		totest+=prod[i].quant_atual;
		totvalor+=(prod[i].preco*prod[i].quant_atual);		
		
		if (prod[i].quant_tot-prod[i].quant_atual>=maiorsaida) {
			pmaior=i;
			maiorsaida=prod[i].quant_tot-prod[i].quant_atual;
		}
	}
	fclose(P);
	
	if (n!=0){
		printf("\nTotal de produtos: %d (%d unidades)\n", n, totest);
		printf("Valor total do estoque: R$ %.2f\n", (totvalor));
		if (n!=1) printf("Produto mais usado: %s (Saídas: %d)\n\n\n", prod[pmaior].nome, (prod[pmaior].quant_tot-prod[pmaior].quant_atual));
		else printf("\n\n");
	}
	else printf("\nNão há produtos cadastrados.\n");
	
	system("pause");
	gerenciar_relatorios(usuario, adm);
	return 0;
}
