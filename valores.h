#include <stdio.h>
#include <stdlib.h>

int alterar_valores (char usuario[20], int adm) {
	system("CLS");
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
	
	float qcomum[2], qar[2], qsuite[2];
	printf("\n\t\tVALORES DOS QUARTOS\n");
	printf("\n\tVALORES ATUAIS\n");	
	printf("Quarto comum: R$ %.2f por adulto / R$ %.2f por criança\n", val[0][0], val[0][1]);
	printf("Quarto com ar condicionado: R$ %.2f por adulto / R$ %.2f por criança\n", val[1][0], val[1][1]);
	printf("Suíte: R$ %.2f por adulto / R$ %.2f por criança\n", val[2][0], val[2][1]);
	
	printf("\n\tNOVOS VALORES\n");
	printf("QUARTO COMUM (1-3)\n");
	printf("Adultos: R$ ");
	scanf ("%f", &qcomum[0]);
	printf("Crianças: R$ ");
	scanf ("%f", &qcomum[1]);
	printf("\nQUARTO COM AR CONDICIONADO (4-7)\n");
	printf("Adultos: R$ ");
	scanf ("%f", &qar[0]);
	printf("Crianças: R$ ");
	scanf ("%f", &qar[1]);
	printf("\nSUÍTE (8-10)\n");
	printf("Adultos: R$ ");
	scanf ("%f", &qsuite[0]);
	printf("Crianças: R$ ");
	scanf ("%f", &qsuite[1]);
	
	V = fopen("valores/quartos.txt", "w");
	fprintf(V, "%f\n", qcomum[0]);
	fprintf(V, "%f\n", qcomum[1]);
	fprintf(V, "%f\n", qar[0]);
	fprintf(V, "%f\n", qar[1]);
	fprintf(V, "%f\n", qsuite[0]);
	fprintf(V, "%f\n", qsuite[1]);
	fclose(V);
	
	printf("\n\nValores atualizados com sucesso.\n");
	system("pause");
	
	menuprincipal(usuario, adm);	
	return 0;
}
