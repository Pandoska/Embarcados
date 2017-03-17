#include<stdlib.h>
#include<stdio.h>

int main (int argc, char **argv)
{
	char nome[30];
	printf("Qual o seu nome?\n");
	//scanf("%s", nome);
	gets(nome);	
	printf("Ola %s!\n",nome);
	return 0;
}
