#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]	){
	FILE *fp;
	char arquivo[104];
	char *nome;
	char *idade;
	char temp_nome[5]="nome:";
	char temp_idade[6]="idade:";
	int i;
	sprintf(arquivo, "%s.txt", argv[1]); //escrevendo dentro da string, ao invés da tela.
	fp = fopen(arquivo,"w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo");
		exit(0);
	}
	nome=argv[1];
	for(i=0; temp_nome[i]; i++) putc(temp_nome[i], fp);
	for(i=0; nome[i]; i++) putc(nome[i], fp);
	putc('\n', fp);
	idade=argv[2];	
	for(i=0; temp_idade[i]; i++) putc(temp_idade[i], fp);
	for(i=0; idade[i]; i++) putc(idade[i], fp);
        putc('\n', fp);	
	fclose(fp);
	return 0;
}

