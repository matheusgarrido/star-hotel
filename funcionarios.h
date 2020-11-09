#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

struct funcionario{
	char nome[50];
	char cpf[12];
	char endereco [100];
	float salario;
	int id;
	char usuario[20];
	char senha[10];
	int adm;
};

int primeiro_funcionario(){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	int n=0, i, s;
	printf("\n\t\tPRIMEIRA UTILIZAÇÃO\n");
	printf(" Para continuar é necessário ter no mínimo um funcionário administrador\ncadastrado no sistema.\n\n");
	system("pause");
	
	system("CLS");
	printf("\n\t\tCADASTRAR FUNCIONÁRIO");	
	printf("\n\n\tDADOS PESSOAIS\n");
	printf("Nome: ");
	gets(fun[n].nome);
	fflush(stdin);
	printf ("\nCPF: ");
	gets(fun[n].cpf);
	fflush(stdin);						
	printf("\nEndereço: ");
	gets(fun[n].endereco);
	fflush(stdin);
	printf("\nSalário: R$ ");
	scanf ("%f", &fun[n].salario);
	int x;
	printf("\n\n\tDADOS NA EMPRESA\n");		
	do{	
		x=0;	
		printf("Identificação do funcionário: ");
		scanf ("%d", &fun[n].id);
		fflush(stdin);
		for(i=0; i<n; i++){
			if(fun[n].id==0){
				x=1;
				printf("Código de identificação inválido.\n");
			}
		}
	} while (x==1);	
	printf("\nNome de usuário: ");
	gets(fun[n].usuario);
	fflush(stdin);
	printf("\nSenha: ");
	gets(fun[n].senha);
	fflush(stdin);
	printf("\nTornar administrador (1-Sim / 2-Não)? 1\n");
	fun[n].adm=1;
	
	n++;
	FILE *F;
	F=fopen("funcionario.txt","w");
	fprintf(F,"%d\n",n);	
	for(i=0;i<n;i++){
	    fprintf(F,"%s\n", fun[i].nome);
		fprintf(F,"%s\n", fun[i].cpf);
		fprintf(F,"%s\n", fun[i].endereco);
		fprintf(F,"%f\n", fun[i].salario);
		fprintf(F,"%d\n", fun[i].id);
		fprintf(F,"%s\n", fun[i].usuario);
		fprintf(F,"%s\n", fun[i].senha);
		fprintf(F,"%d\n", fun[i].adm);
	}
	fclose(F);	
	printf ("\n\nPrimeiro funcionário cadastrado.\n");
	system("pause");
	return 0;
}

void cadastrar_funcionario(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	
	FILE *F;
	int n, i, s;
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
	}
	fclose(F);	
	
	fflush(stdin);
	system ("CLS");			
	printf("\n\t\tCADASTRAR FUNCIONÁRIO");		
	printf("\n\n\tDADOS PESSOAIS\n");
	printf("Nome: ");
	gets(fun[n].nome);
	fflush(stdin);
	printf ("\nCPF: ");
	gets(fun[n].cpf);
	fflush(stdin);						
	printf("\nEndereço: ");
	gets(fun[n].endereco);
	fflush(stdin);
	printf("\nSalário: R$ ");
	scanf ("%f", &fun[n].salario);
	
	int x;
	printf("\n\n\tDADOS NA EMPRESA\n");		
	do{	
		x=0;	
		printf("Identificação do funcionário: ");
		scanf ("%d", &fun[n].id);
		fflush(stdin);
		for(i=0; i<n; i++){
			if (fun[n].id==fun[i].id){
				x=1;
				printf("Esse código de identificação já está sendo utilizado.\n");
			}
			else if(fun[n].id==0){
				x=1;
				printf("Código de identificação inválido.\n");
			}
		}
	} while (x==1);		
	do{	
		x=0;
		printf("\nNome de usuário: ");
		gets(fun[n].usuario);
		fflush(stdin);
		for(i=0; i<n; i++){
			if (strcmpi(fun[n].usuario, fun[i].usuario)==0){
				x=1;
				printf("Este nome de usuário já está sendo utilizado.");
			}
		}
	} while (x==1);	
	printf("\nSenha: ");
	gets(fun[n].senha);
	fflush(stdin);
	printf("\nTornar administrador (1-Sim / 2-Não)? ");
	scanf ("%d", &fun[n].adm);
	fflush(stdin);
	if (fun[n].adm!=1) fun[n].adm=0;
	
	n++;
	F=fopen("funcionario.txt","w");
	fprintf(F,"%d\n",n);	
	for(i=0;i<n;i++){
	    fprintf(F,"%s\n", fun[i].nome);
		fprintf(F,"%s\n", fun[i].cpf);
		fprintf(F,"%s\n", fun[i].endereco);
		fprintf(F,"%f\n", fun[i].salario);
		fprintf(F,"%d\n", fun[i].id);
		fprintf(F,"%s\n", fun[i].usuario);
		fprintf(F,"%s\n", fun[i].senha);
		fprintf(F,"%d\n", fun[i].adm);		
	}
	fclose(F);
	
	printf ("\n\nDeseja cadastrar novos funcionários (1-Sim / 2-Não)? ");
	scanf ("%d",&s);
	if (s==1) cadastrar_funcionario(usuario, adm);
	else controle_funcionarios(usuario, adm);
}

//=========================================================================

int editar_funcionario(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	
	FILE *F;
	int n, i, s;
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
	}
	fclose(F);	
	
	fflush(stdin);
	system ("CLS");			
	printf("\n\t\tEDITAR FUNCIONÁRIO\n");
	int id;
	printf("Identificação do funcionário: ");
	scanf ("%d", &id);
	fflush(stdin);
	printf("\n\n\tPROCURANDO FUNCIONÁRIO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=0;
	for(i=0; i<n; i++){
		if (id==fun[i].id){
			z=1;
			printf("Funcionário localizado.");
			printf("\n\n\tDADOS ATUAIS\n");
			printf("Nome: %s\n", fun[i].nome);
			printf("CPF: %s\n", fun[i].cpf);
			printf("Endereço: %s\n", fun[i].endereco);
			printf("Salário: R$ %.2f\n", fun[i].salario);			
			system("pause");
			
			system("CLS");
			printf("\n\tNOVOS DADOS");
			printf("\n\n\tDADOS PESSOAIS\n");
			printf("Nome: ");
			gets(fun[i].nome);
			fflush(stdin);
			printf ("\nCPF: ");
			gets(fun[i].cpf);
			fflush(stdin);						
			printf("\nEndereço: ");
			gets(fun[i].endereco);
			fflush(stdin);
			printf("\nSalário: R$ ");
			scanf ("%f", &fun[i].salario);
			
			F=fopen("funcionario.txt","w");
			fprintf(F,"%d\n",n);
			for(i=0;i<n;i++){				
				fprintf(F,"%s\n", fun[i].nome);
				fprintf(F,"%s\n", fun[i].cpf);
				fprintf(F,"%s\n", fun[i].endereco);
				fprintf(F,"%f\n", fun[i].salario);
				fprintf(F,"%d\n", fun[i].id);
				fprintf(F,"%s\n", fun[i].usuario);
				fprintf(F,"%s\n", fun[i].senha);
				fprintf(F,"%d\n", fun[i].adm);		
				
			}
			fclose(F);
		}
	}
	if(z==0){
		printf("Funcionário não encontrado.\n");		
	}
	
	system("pause");
	controle_funcionarios(usuario, adm);
	return 0;
}

//==============================================================

int excluir_funcionario(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	
	FILE *F;
	int n, i, s, cont_adm=0;
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
		//if (fun[i].adm==1)cont_adm++;
	}
	fclose(F);
	
	fflush(stdin);
	system ("CLS");			
	printf("\n\t\tEXCLUIR FUNCIONÁRIO\n");		
	int id;
	printf("Identificação do funcionário: ");
	scanf ("%d", &id);
	fflush(stdin);
	printf("\n\n\tPROCURANDO FUNCIONÁRIO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=0;
	int excluir;
	for(i=0; i<n; i++){
		if (id==fun[i].id){
			z=1;
			do{
				printf("Funcionário localizado.");
				printf("\n\n\tDADOS ATUAIS\n");
				printf("Nome: %s\n", fun[i].nome);
				printf("CPF: %s\n", fun[i].cpf);
				printf("Endereço: %s\n", fun[i].endereco);
				printf("Salário: R$ %.2f\n", fun[i].salario);
				if(fun[i].adm==1) printf("\n  Este é um administrador.\n");	
				if (strcmpi(fun[i].usuario, usuario)==0){
					printf("\n  Não é permitido excluir você mesmo.\n");
					excluir=2;
				}
				else{
						printf("\n\t1 - Excluir funcionário");
						printf("\n\t2 - Cancelar exclusão");
						printf("\n\tDeseja concluir a exclusão? ");
						scanf("%d", &excluir);	
				}
			} while(excluir!=1 && excluir!=2);	
			switch (excluir){
				case 1:
					printf("\nFuncionário excluído com sucesso!\n");								
					break;
				case 2:
					printf("\nFuncionário não excluído.\n");
					break;
				default:
					printf("Valor inválido. Informe novamente.\n");
					system("pause");
					break;
			}
			if (excluir==1){
				//Inserir dados ao txt
				F=fopen("funcionario.txt","w");
				fprintf(F, "%d\n", n-1);							
				int j;						
				for (j=0; j<n; j++){					
					if (id==fun[j].id){}					
					else {					
						fprintf(F,"%s\n", fun[j].nome);
						fprintf(F,"%s\n", fun[j].cpf);
						fprintf(F,"%s\n", fun[j].endereco);
						fprintf(F,"%f\n", fun[j].salario);
						fprintf(F,"%d\n", fun[j].id);
						fprintf(F,"%s\n", fun[j].usuario);
						fprintf(F,"%s\n", fun[j].senha);
						fprintf(F,"%d\n", fun[j].adm);
					}
				}
				fclose(F);
			}
		}		
	}
	if (z==0){
		printf("Funcionário não encontrado.\n");		
	}
	system("pause");
	controle_funcionarios(usuario, adm);
	return 0;	
}


int listar_funcionarios(char usuario[20], int adm){
	//Informar quarto desejado
	system("CLS");	
	printf("\n\t\tLISTAR FUNCIONÁRIOS\n");
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	FILE *F;
	int n, i;
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
		
		printf("%s (Identificação: %d)\n", fun[i].nome, fun[i].id);
		printf("Endereço: %s\n", fun[i].endereco);		
		printf("Salário: R$ %.2f\n", fun[i].salario);
		if (fun[i].adm==1) printf("Nome de usuário: %s (usuário administrador)\n\n", fun[i].usuario);
		else printf("Nome de usuário: %s\n\n", fun[i].usuario);
	}
	fclose(F);		
	
	system("pause");
	controle_funcionarios(usuario, adm);
	return 0;
}

int alterar_senha(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	
	FILE *F;
	int n, i;
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
	}
	fclose(F);	
			
	char us[20], se[10];	
	int tentativas=1, x=0;	
	do{
		fflush(stdin);
		system ("CLS");			
		printf("\n\t\tALTERAR USUÁRIO/SENHA\n");
		printf("\n\tDADOS ATUAIS\n");		
		printf("Usuário: ");	
		gets(us);
		fflush(stdin);
		printf("Senha: ");	
		gets(se);
		fflush(stdin);
		x=0;
		for(i=0; i<n; i++){
			if (strcmpi(us, fun[i].usuario)==0&&strcmp(se, fun[i].senha)==0){
				x=1;				
				printf("\n\n\tNOVOS DADOS\n");			
				printf("Usuário: ");
				gets(fun[i].usuario);
				fflush(stdin);
				printf ("Senha: ");
				gets(fun[i].senha);
				fflush(stdin);
				
				printf("\nUsuário e senha atualizados.\n");
				
				F=fopen("funcionario.txt","w");
				fprintf(F,"%d\n",n);
				for(i=0;i<n;i++){
					fprintf(F,"%s\n", fun[i].nome);
					fprintf(F,"%s\n", fun[i].cpf);
					fprintf(F,"%s\n", fun[i].endereco);
					fprintf(F,"%f\n", fun[i].salario);
					fprintf(F,"%d\n", fun[i].id);
					fprintf(F,"%s\n", fun[i].usuario);
					fprintf(F,"%s\n", fun[i].senha);
					fprintf(F,"%d\n", fun[i].adm);
				}
				fclose(F);
			}
		}
		if(x==0){
			switch(tentativas){
			case 1:
				printf("\nUsuário e senha incorretos. Informe novamente.\n");
				system("pause");
				break;
			case 2:
				printf("\nUsuário e senha incorretos. Informe mais uma vez.\n");
				system("pause");
				break;
			case 3:
				printf("\nUsuário e senha incorretos. Sem mais tentativas.\n");
				break;				
			}
		}		
		tentativas++;		
	} while(x==0&&tentativas<=3);	
	system("pause");
	controle_funcionarios(usuario, adm);	
	return 0;
}

int tornar_adm(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct funcionario fun[100];
	
	FILE *F;
	int n, i, s;
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
	}
	fclose(F);	
	
	fflush(stdin);
	system ("CLS");			
	printf("\n\t\tTORNAR UM ADMINISTRADOR NO SISTEMA\n");
	int id;
	printf("Identificação do funcionário: ");
	scanf ("%d", &id);
	fflush(stdin);
	printf("\n\n\tPROCURANDO FUNCIONÁRIO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=0;
	int j;
	for(i=0; i<n; i++){
		if (id==fun[i].id){
			z=1;
			int x=0;
			printf("Funcionário localizado.");
			printf("\n\n\tDADOS ATUAIS\n");
			printf("Nome: %s\n", fun[i].nome);
			printf("CPF: %s\n", fun[i].cpf);
			printf("Endereço: %s\n", fun[i].endereco);
			printf("Salário: R$ %.2f\n", fun[i].salario);
			if (fun[i].adm==1) printf("\n  **Já é um administrador.\n");
			printf("\nTornar este funcionário em um administrador (1-Sim / 2-Não)? ");
			scanf("%d", &x);						
			if (x==1){
				printf("\nEste usuário agora é um administrador.\n");
				fun[i].adm=1;
				F=fopen("funcionario.txt","w");
				fprintf(F,"%d\n",n);
				for(j=0;j<n;j++){
					fprintf(F,"%s\n", fun[j].nome);
					fprintf(F,"%s\n", fun[j].cpf);
					fprintf(F,"%s\n", fun[j].endereco);
					fprintf(F,"%f\n", fun[j].salario);
					fprintf(F,"%d\n", fun[j].id);
					fprintf(F,"%s\n", fun[j].usuario);
					fprintf(F,"%s\n", fun[j].senha);
					fprintf(F,"%d\n", fun[j].adm);	
				}
				fclose(F);
			}
			else {
				if (strcmpi(fun[i].usuario, usuario)==0){
					printf("\nNão é permitido tornar a si mesmo em um usuário comum.\n");					
				}
				else{
					printf("\nEste usuário agora não é um administrador.\n");
					fun[i].adm=0;
					F=fopen("funcionario.txt","w");
					fprintf(F,"%d\n",n);
					for(j=0;j<n;j++){
						fprintf(F,"%s\n", fun[j].nome);
						fprintf(F,"%s\n", fun[j].cpf);
						fprintf(F,"%s\n", fun[j].endereco);
						fprintf(F,"%f\n", fun[j].salario);
						fprintf(F,"%d\n", fun[j].id);
						fprintf(F,"%s\n", fun[j].usuario);
						fprintf(F,"%s\n", fun[j].senha);
						fprintf(F,"%d\n", fun[j].adm);	
					}
					fclose(F);
				}				
			}
		}
	}
	if(z==0){
		printf("Funcionário não encontrado.\n");		
	}
	
	system("pause");
	controle_funcionarios(usuario, adm);
	return 0;
}
