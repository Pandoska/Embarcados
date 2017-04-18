#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]	){
	FILE *fp;
	char arquivo[104];
	char nome[100];
	char idade[5];
	char temp_nome[5]="nome:";
	char temp_idade[6]="idade:";
	int i;
	printf("Digite seu nome:");
	gets(nome);
	sprintf(arquivo, "%s.txt", nome); //escrevendo dentro da string, ao invés da tela.
	printf("Digite sua idade:");
	gets(idade);

	fp = fopen(arquivo,"w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo");
		exit(0);
	}
	for(i=0; temp_nome[i]; i++) putc(temp_nome[i], fp);
	for(i=0; nome[i]; i++) putc(nome[i], fp);
	putc('\n', fp);	
	for(i=0; temp_idade[i]; i++) putc(temp_idade[i], fp);
	for(i=0; idade[i]; i++) putc(idade[i], fp);
        putc('\n', fp);	
	fclose(fp);
	return 0;
}

