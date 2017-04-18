#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, const char *argv[])
{
	int fp,i, idade;
	char nome[100];
	printf("digite seu nome: ");
	gets(nome);
	printf("\ndigite sua idade: ");
	scanf("%d",&idade);
	
	fp = open ("%s.txt", O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	for(i=0; nome[i]; i++)
		write(fp, &(nome[i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\n", 1);
	write(fp, &idade, sizeof(int));
	write(fp, "\n", 1);
	close(fp);

	return 0;

}
