#include <stdio.h>
#include <stdlib.h>

struct produto{
	int cod;
	char nome[100];
	float preco;
	int quant_atual;
	int quant_tot;
	int min;
};

void cadastrar_estoque(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct produto prod[100];
	
	FILE *P;
	int n, i;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
	}
	fclose(P);
	
	fflush(stdin);
	system ("CLS");			
	printf("\n\t\tCADASTRAR PRODUTO\n");
	int x;		
	do{	
		x=0;	
		printf("Código do produto: ");
		scanf ("%d", &prod[n].cod);
		fflush(stdin);
		for(i=0; i<n; i++){
			if (prod[n].cod==prod[i].cod){
				x=1;
				printf("Este código já está sendo utilizado.\n");
			}
			else if(prod[n].cod==0){
				x=1;
				printf("Código inválido.\n");
			}
		}
	} while (x==1);
	printf("\nNome: ");
	gets(prod[n].nome);
	fflush(stdin);	
	printf("\nPreço: R$ ");
	
	scanf ("%f", &prod[n].preco);
	do{			
		printf("\nQuantidade mínima: ");
		scanf ("%d",& prod[n].min);
		fflush(stdin);
		if (prod[n].min<0){				
			printf("Informe um valor maior ou igual a 0.");
		}		
	} while (prod[n].min<0);
	
	do{			
		printf("\nQuantidade de entrada: ");
		scanf ("%d", &prod[n].quant_atual);
		fflush(stdin);
		if (prod[n].quant_atual<prod[n].min){				
			printf("Informe um valor maior ou igual a quantidade mínima (%d).", prod[n].min);
		}
	} while (prod[n].quant_atual<prod[n].min);
	
	prod[n].quant_tot=prod[n].quant_atual;
	
	
	int concluir;
	do{
		system("cls");
		printf("\n\t\tDADOS DO PRODUTO\n");
		printf("Código: %d\n", prod[n].cod);
		printf("Nome: %s\n", prod[n].nome);		
		printf("Preço: R$ %.2f\n", prod[n].preco);		
		printf("Quantidade mínima: %d\n", prod[n].min);
		printf("Quantidade de entrada: %d\n", prod[n].quant_atual);		
				
		printf("\n\t1 - Concluir cadastro");
		printf("\n\t2 - Cancelar cadastro");
		printf("\n\tDeseja concluir o cadastro? ");
		
		scanf("%d", &concluir);
		switch (concluir){
			case 1:
				printf("\nCadastro concluído com sucesso!\n");
				break;
			case 2:
				printf("\nCadastro cancelado.\n");
				break;
			default:
				printf("\nValor inválido. Informe novamente.\n");
				system("pause");
				break;
		}
	} while (concluir!=1 && concluir!=2);	
	
	if (concluir==1){
		n++;
		fclose(P);
		P=fopen("estoque.txt", "w");
		fprintf(P,"%d\n",n);
		for(i=0;i<n;i++){
		    fprintf(P,"%d\n",prod[i].cod);
			fprintf(P,"%s\n",prod[i].nome);
			fprintf(P,"%f\n",prod[i].preco);
			fprintf(P,"%d\n",prod[i].quant_atual);
			fprintf(P,"%d\n",prod[i].quant_tot);
			fprintf(P,"%d\n",prod[i].min);
		}
		fclose(P);
	}
	int s;
	printf ("\n\nDeseja cadastrar novos produtos (1-Sim / 2-Não)? ");
	scanf ("%d", &s);
	if (s==1) cadastrar_estoque(usuario, adm);
	else controle_estoque(usuario, adm);
}

int editar_estoque(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct produto prod[100];
	FILE *P;
	int n, i, s;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
	}
	fclose(P);	
	
	fflush(stdin);
	system ("CLS");
	printf("\n\t\tEDITAR PRODUTO\n");
	int c;
	printf("Código do produto: ");
	scanf ("%d", &c);
	fflush(stdin);
	printf("\n\n\tPROCURANDO PRODUTO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	
	int z=0;
	for(i=0; i<n; i++){
		if (c==prod[i].cod){
			z=1;
			printf("Produto localizado.");
			printf("\n\n\tDADOS ATUAIS\n");
			printf("Produto: %s (Código: %d)\n", prod[i].nome, prod[i].cod);
			printf("Preço: R$ %.2f\n", prod[i].preco);
			printf("Quantidade atual: %d\n", prod[i].quant_atual);
			printf("Quantidade mínima: %d\n", prod[i].min);				
			system("pause");
			
			system("CLS");
			printf("\n  **Os resultados exibidos em Relatórios de Estoque relacionados a este produto também serão alterados.\n\n");
			printf("\n\tNOVOS DADOS\n");
			int x, j;
			do{	
				x=0;	
				printf("Código do produto: ");
				scanf ("%d", &prod[i].cod);
				fflush(stdin);
				for(j=0; j<n; j++){
					if (prod[i].cod==prod[j].cod&&prod[i].cod!=c){
						x=1;
						printf("Este código já está sendo utilizado.\n");
						break;
					}
					else if(prod[i].cod==0){
						x=1;
						printf("Código inválido.\n");
					}
				}
			} while (x==1);
			printf("\nNome: ");
			gets(prod[i].nome);
			fflush(stdin);	
			printf("\nPreço: R$ ");			
			scanf ("%f", &prod[i].preco);
			do{
				printf("\nQuantidade mínima: ");
				scanf ("%d",& prod[i].min);
				fflush(stdin);
				if (prod[i].min<0){				
					printf("Informe um valor maior ou igual a 0.");
				}		
			} while (prod[i].min<0);
			
			do{			
				printf("\nQuantidade de entrada: ");
				scanf ("%d", &prod[i].quant_atual);
				fflush(stdin);
				if (prod[i].quant_atual<prod[i].min){				
					printf("Informe um valor maior ou igual a quantidade mínima (%d).", prod[i].min);
				}
			} while (prod[i].quant_atual<prod[i].min);
			prod[i].quant_tot=prod[i].quant_atual;
			
			P=fopen("estoque.txt","w");
			fprintf(P,"%d\n",n);
			for(i=0;i<n;i++){
				fprintf(P,"%d\n",prod[i].cod);
				fprintf(P,"%s\n",prod[i].nome);
				fprintf(P,"%f\n",prod[i].preco);
				fprintf(P,"%d\n",prod[i].quant_atual);
				fprintf(P,"%d\n",prod[i].quant_tot);
				fprintf(P,"%d\n",prod[i].min);
			}
			fclose(P);
		}
	}
	if(z==0){
		printf("Produto não encontrado.\n");		
	}	
	system("pause");
	controle_estoque(usuario, adm);
	return 0;
}

int excluir_estoque(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct produto prod[100];
	FILE *P;
	int n, i, s;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
	}
	fclose(P);
	
	fflush(stdin);
	system ("CLS");
	printf("\n\t\tEXCLUIR PRODUTO\n");
	int c;
	printf("Código do produto: ");
	scanf ("%d", &c);
	fflush(stdin);
	printf("\n\n\tPROCURANDO PRODUTO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");	
	int z=0;
	int excluir;
	for(i=0; i<n; i++){
		if (c==prod[i].cod){
			z=1;
			do{
				printf("Produto localizado.");
				printf("\n\n\tDADOS ATUAIS\n");
				printf("Produto: %s (%d)\n", prod[i].nome, prod[i].cod);
				printf("Preço: R$ %.2f\n", prod[i].preco);
				printf("Quantidade atual: %d\n", prod[i].quant_atual);
				printf("Quantidade mínima: %d\n", prod[i].min);				
				
				printf("\n\t1 - Excluir produto");
				printf("\n\t2 - Cancelar exclusão");
				printf("\n\tDeseja concluir a exclusão? ");
				scanf("%d", &excluir);	
				
			} while(excluir!=1 && excluir!=2);	
			switch (excluir){
				case 1:
					printf("\nProduto excluído com sucesso!\n");								
					break;
				case 2:
					printf("\nProduto não excluído.\n");
					break;
				default:
					printf("Valor inválido. Informe novamente.\n");
					system("pause");
					break;
			}
			if (excluir==1){				
				P=fopen("estoque.txt","w");
				fprintf(P, "%d\n", n-1);
				int j;						
				for (i=0; i<n; i++){					
					if (c==prod[i].cod){}					
					else {
						fprintf(P,"%d\n",prod[i].cod);
						fprintf(P,"%s\n",prod[i].nome);
						fprintf(P,"%f\n",prod[i].preco);
						fprintf(P,"%d\n",prod[i].quant_atual);
						fprintf(P,"%d\n",prod[i].quant_tot);
						fprintf(P,"%d\n",prod[i].min);
					}
				}
				fclose(P);
			}
		}		
	}
	if (z==0){
		printf("Produto não encontrado.\n");
	}
	system("pause");
	controle_estoque(usuario, adm);	
	return 0;	
}


int listar_estoque(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct produto prod[100];
	FILE *P;
	int n, i, s;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	system("CLS");
	printf("\n\t\tLISTAR ESTOQUE\n");
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
		
		printf("%s (Código: %d)\n", prod[i].nome, prod[i].cod);		
		printf("Preço: %.2f\n", prod[i].preco);
		printf("Estoque atual: %d (Mínimo: %d)\n\n", prod[i].quant_atual, prod[i].min);
	}
	fclose(P);	
	if (n==0){
		printf("Não há produtos cadastrados.\n");
	}		
	system("pause");
	controle_estoque(usuario, adm);		
	return 0;
}

int entrada_saida(char usuario[20], int adm){
	setlocale(LC_ALL,"Portuguese");
	struct produto prod[100];
	FILE *P;
	int n, i, s;
	P = fopen("estoque.txt","r");
	fscanf(P,"%d",&n);
	for(i=0; i<n; i++){
		fscanf(P,"%d",&prod[i].cod);
		fscanf(P,"%s",&prod[i].nome);
		fscanf(P,"%f",&prod[i].preco);
		fscanf(P,"%d",&prod[i].quant_atual);
		fscanf(P,"%d",&prod[i].quant_tot);
		fscanf(P,"%d",&prod[i].min);
	}
	fclose(P);	
	
	fflush(stdin);
	int op;
	system ("CLS");
	printf("\n\t\tGERENCIAR ENTRADA / SAÍDA\n");
	int c;
	printf("Código do produto: ");
	scanf ("%d", &c);
	fflush(stdin);
	printf("\n\n\tPROCURANDO PRODUTO");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".");
	Sleep(1200);
	printf(".\n");
	int q=0;
	int z=0;
	for(i=0; i<n; i++){
		if (c==prod[i].cod){
			z=1;
			printf("Produto localizado.\n");
			system("pause");
			system("CLS");
			do{
				printf("\n\t1. Entrada");
				printf("\n\t2. Saída");
				printf("\n\t3. Voltar ao menu Controle de Estoque");
				printf("\n\n\tInforme a ação desejada: ");
				scanf("%d", &op);				
				switch(op){
					case 1:
						printf("\nQuantidade de entrada: ");						
						scanf ("%d", &q);
						fflush(stdin);
						prod[i].quant_atual+=q;
						prod[i].quant_tot+=q;
						printf("\nQuantidade estocada alterada com sucesso!\n");
						P=fopen("estoque.txt","w");
						fprintf(P,"%d\n",n);
						for(i=0;i<n;i++){
							fprintf(P,"%d\n",prod[i].cod);
							fprintf(P,"%s\n",prod[i].nome);
							fprintf(P,"%f\n",prod[i].preco);
							fprintf(P,"%d\n",prod[i].quant_atual);
							fprintf(P,"%d\n",prod[i].quant_tot);
							fprintf(P,"%d\n",prod[i].min);
						}
						fclose(P);
						break;
					case 2:	
						if (prod[i].min==prod[i].quant_atual){
								printf("\nNão é possível retirar mais pois já está no limite.\n");
								system("pause");
								controle_estoque(usuario, adm);
						}
						else {
							do{
								
								printf("\nQuantidade de saída: ");							
								scanf ("%d", &q);
								fflush(stdin);
								if (prod[i].quant_atual-q<prod[i].min){
									printf("Este valor (%d - %d) ultrapassa a quantidade mínima (%d).", prod[i].quant_atual, q, prod[i].min);
								}
							} while (prod[i].quant_atual-q<prod[i].min);
							prod[i].quant_atual-=q;
							P=fopen("estoque.txt","w");
							fprintf(P,"%d\n",n);
							printf("\nQuantidade estocada alterada com sucesso!\n");
							for(i=0;i<n;i++){
								fprintf(P,"%d\n",prod[i].cod);
								fprintf(P,"%s\n",prod[i].nome);
								fprintf(P,"%f\n",prod[i].preco);
								fprintf(P,"%d\n",prod[i].quant_atual);
								fprintf(P,"%d\n",prod[i].quant_tot);
								fprintf(P,"%d\n",prod[i].min);
							}
							fclose(P);
						}
						break;
					case 3:
						controle_estoque(usuario, adm);
						break;
					default:
						printf("\nValor inválido. Informe novamente.\n");
						system("pause");
						break;					
				}
			} while (op!=1&&op!=2&&op!=3);
		}
	}
		if(z==0){
		printf("Produto não encontrado.\n");
	}	
	system("pause");
	controle_estoque(usuario, adm);
	return 0;
}
