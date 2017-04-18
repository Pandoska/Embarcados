#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, const char *argv[])
{
	int fp,i;
	char string[100] = "ola mundo!";
	
	fp = open ("ola_mundo.txt", O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\n", 1);
	close(fp);

	return 0;

}
