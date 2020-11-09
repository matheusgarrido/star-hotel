#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "valores.h"
#include "hospedagens.h"
#include "funcionarios.h"
#include "relatorios.h"
#include "manutencao.h"
#include "estoque.h"

int main() {
	fflush(stdin);
	setlocale(LC_ALL,"Portuguese");	
	struct funcionario fun[100];
	
	FILE *F;
	int n, i, s, contadm=0;
	F= fopen("funcionario.txt","r");
	fscanf(F,"%d",&n);
	for(i=0; i<n; i++){
		fscanf(F,"%s",&fun[i].nome);
		fscanf(F,"%s",&fun[i].cpf);	
		fscanf(F,"%s",&fun[i].endereco);
		fscanf(F,"%f",&fun[i].salario);
		fscanf(F,"%d",&fun[i].id);
		fscanf(F,"%s",&fun[i].usuario);
		fscanf(F,"%s",&fun[i].senha);
		fscanf(F,"%d",&fun[i].adm);
		if (fun[i].adm==1) contadm++;
	}
	fclose(F);
	
	if(n==0||contadm==0) {
		primeiro_funcionario();		
		alterar_valores(0, 1);
		system("CLS");
		printf("\n\n\tConfigura��o inicial do sistema conclu�da!\n\n");
		system("pause");
		main();
	}
	
	int tentativas=1, x=0;
	char usuario[20], senha[10];
	do{
		system("CLS");
		printf("\n\t\tSTAR HOTEL\n");		
		printf("Nome de Usu�rio: ");
		gets(usuario);
		fflush(stdin);
		printf("Senha: ");
		gets(senha);
		fflush(stdin);
		x=0;
		for(i=0; i<n; i++){
			if (strcmpi(usuario, fun[i].usuario)==0&&strcmp(senha, fun[i].senha)==0){
				x=1;				
				printf("\nBem-vindo, %s, e bom servi�o.\n\n", fun[i].nome);
				system("pause");				
				menuprincipal(usuario, fun[i].adm);
			}
		}
		if(x==0){
			switch(tentativas){
			case 1:
				printf("\nUsu�rio e senha incorretos. Informe novamente.\n");
				system("pause");
				break;
			case 2:
				printf("\nUsu�rio e senha incorretos. Informe mais uma vez.\n");
				system("pause");
				break;
			case 3:
				printf("\nUsu�rio e senha incorretos. Sem mais tentativas.\n");
				break;				
			}
		}
		tentativas++;		
	} while(x==0&&tentativas<=3);
	return 0;
}

int menuprincipal(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	system("CLS");
	int op;
	//ADMINISTRADOR
	if (adm==1){
		printf("\n\t\tMENU PRINCIPAL\n");
		printf("\t1. Controle de hospedagens\n");
		printf("\t2. Controle de funcion�rios\n");
		printf("\t3. Controle de manuten��es\n");
		printf("\t4. Controle de estoque\n");
		printf("\t5. Gerenciar relat�rios\n");
		printf("\t6. Alterar valores\n");
		printf("\t7. Trocar de usu�rio\n");
		printf("\t8. Sair\n");
		printf("\nEscolha a a��o: ");
		scanf("%d", &op);
		switch (op){
			case 1:
				controle_hospedagem(usuario, adm);
				break;
			case 2:
				controle_funcionarios(usuario, adm);
				break;
			case 3:
				controle_manu(usuario, adm);
				break;
			case 4:
				controle_estoque(usuario, adm);
				break;
			case 5:
				gerenciar_relatorios(usuario, adm);
				break;
			case 6:
				alterar_valores(usuario, adm);
				break;
			case 7:
				main();
				break;
			case 8:
				break;
			default:
				printf("Op��o inv�lida. Tente novamente.\n");
				system("pause");
				menuprincipal(usuario, adm);
		}
	}
	//Funcion�rio comum
	else {
		printf("\n\t\tMENU PRINCIPAL\n");	
		printf("\t1. Controle de hospedagens\n");		
		printf("\t2. Controle de manuten��es\n");
		printf("\t3. Controle de estoque\n");
		printf("\t4. Trocar de usu�rio\n");
		printf("\t5. Sair\n");
		printf("\nEscolha a a��o: ");
		scanf("%d", &op);
		switch (op){
			case 1: 
				controle_hospedagem(usuario, adm);
				break;	
			case 2:
				controle_manu(usuario, adm);
				break;
			case 3:
				controle_estoque(usuario, adm);
				break;
			case 4:
				main();
				break;
			case 5:
				break;
			default:
				printf("Op��o inv�lida. Tente novamente.\n");
				system("pause");
				menuprincipal(usuario, adm);
		}
	}
	return 0;
}

int controle_hospedagem (char usuario[20], int adm) {	
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("\n\t\tCONTROLE DE HOSPEDAGEM\n");
	printf("\t1. Listar reservas\n");
	printf("\t2. Reservar quarto\n");
	printf("\t3. Realizar pagamento\n");
	printf("\t4. Alterar reserva\n");
	printf("\t5. Cancelar reserva\n");
	printf("\t6. Voltar ao menu principal\n");
	
	int op;
	printf("\nEscolha a a��o: ");
	scanf("%d", &op);	
	switch (op){
		case 1: 			
			listar_reservas(usuario, adm);
			break;
		case 2: 			
			reservar_quarto(usuario, adm);
			break;		
		case 3: 			
			realizar_pagamento(usuario, adm);
			break;		
		case 4:
			alterar_reserva(usuario, adm);
			break;
		case 5:
			cancelar_reserva(usuario, adm);
			break;		
		case 6:
			menuprincipal(usuario, adm);
			break;
		default:
			printf("Op��o inv�lida. Tente novamente.\n");
			system("pause");
			controle_hospedagem(usuario, adm);
	}
	return 0;
}

int controle_funcionarios(char usuario[20], int adm) {
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("\n\t\tCONTROLE DE FUNCION�RIOS\n");
	printf("\t1. Listar funcion�rios\n");
	printf("\t2. Cadastrar funcion�rio\n");
	printf("\t3. Editar funcion�rio\n");
	printf("\t4. Excluir funcion�rio\n");
	printf("\t5. Alterar usu�rio/senha\n");
	printf("\t6. Tornar administrador\n");
	printf("\t7. Voltar ao menu principal\n");
	
	int op;
	printf("\nEscolha a a��o: ");
	scanf("%d", &op);
	switch (op){
		case 1:
			listar_funcionarios(usuario, adm);
			break;
		case 2:
			cadastrar_funcionario(usuario, adm);
			break;
		case 3:
			editar_funcionario(usuario, adm);
			break;
		case 4:
			excluir_funcionario(usuario, adm);
			break;
		case 5:
			alterar_senha(usuario, adm);
			break;
		case 6:
			tornar_adm(usuario, adm);
			break;
		case 7:
			menuprincipal(usuario, adm);
			break;
		default:
			printf("Op��o inv�lida. Tente novamente.\n");
			system("pause");
			controle_funcionarios(usuario, adm);
	}
	return 0;
}

int controle_manu(char usuario[20], int adm) {
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("\n\t\tCONTROLE DE MANUTEN��ES\n");
	printf("\t1. Listar manuten��es\n");
	printf("\t2. Agendar manuten��o\n");
	printf("\t3. Registrar pagamento\n");
	printf("\t4. Alterar manuten��o\n");
	printf("\t5. Excluir manuten��o\n");
	printf("\t6. Voltar ao menu principal\n");
	
	int op; 
	printf("\nEscolha a a��o: ");
	scanf("%d", &op);
	switch (op){
		case 1:
			listar_manutencao(usuario, adm);
			break;
		case 2:
			agendar_manutencao(usuario, adm);
			break;
		case 3:
			manu_pagamento(usuario, adm);
			break;		
		case 4:
			alterar_manutencao(usuario, adm);
			break;
		case 5:
			excluir_manutencao(usuario, adm);
			break;
		case 6:
			menuprincipal(usuario, adm);
			break;
		default:
			printf("Op��o inv�lida. Tente novamente.\n");
			system("pause");
			controle_manu(usuario, adm);
	}
	return 0;
}

int controle_estoque (char usuario[20], int adm) {
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("\n\t\tCONTROLE DE ESTOQUE\n");
	printf("\t1. Listar produtos\n");
	printf("\t2. Cadastrar produto\n");
	printf("\t3. Editar produto\n");
	printf("\t4. Gerenciar entrada/sa�da\n");
	printf("\t5. Excluir produto\n");
	printf("\t6. Voltar ao menu principal\n");
	
	int op;
	printf("\nEscolha a a��o: ");
	scanf("%d", &op);
	switch (op){
		case 1:
			listar_estoque(usuario, adm);
			break;
		case 2:
			cadastrar_estoque(usuario, adm);
			break;
		case 3:
			editar_estoque(usuario, adm);
			break;
		case 4:
			entrada_saida(usuario, adm);
			break;
		case 5:
			excluir_estoque(usuario, adm);
			break;
		case 6:
			menuprincipal(usuario, adm);
			break;
		default:
			printf("Op��o inv�lida. Tente novamente.\n");
			system("pause");
			controle_estoque(usuario, adm);
	}
	return 0;
}

int gerenciar_relatorios(char usuario[20], int adm) {
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("\n\t\tGERENCIAR RELAT�RIOS\n");
	printf("\t1. Relat�rio de demanda\n");
	printf("\t2. Relat�rio de pagamentos\n");
	printf("\t3. Relat�rio de custos de manuten��o\n");
	printf("\t4. Relat�rio de sal�rios\n");
	printf("\t5. Relat�rio de estoque\n");
	printf("\t6. Voltar ao menu principal\n");
	
	int op;
	printf("\nEscolha a a��o: ");
	scanf("%d", &op);
	switch (op){
		case 1:
			demanda(usuario, adm);
			break;
		case 2:
			pagamentos(usuario, adm);
			break;
		case 3:
			custos_manutencao(usuario, adm);
			break;
		case 4:
			salarios(usuario, adm);
			break;
		case 5:
			estoque(usuario, adm);
			break;
		case 6:
			menuprincipal(usuario, adm);
			break;
		default:
			printf("Op��o inv�lida. Tente novamente.\n");
			system("pause");
			gerenciar_relatorios(usuario, adm);
	}
	return 0;
}
