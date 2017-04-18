#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]	){
	FILE *fp;
	char string[100];
	int i;
	fp = fopen("ola_mundo.txt","w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo");
		exit(0);
	}
	printf("Digite a string:");
	gets(string);
	for(i=0; string[i]; i++) putc(string[i], fp);
	putc('\n', fp);	
	fclose(fp);
	return 0;
}

