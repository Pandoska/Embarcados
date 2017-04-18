#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i,numero;
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{
		for(i=0;i<10;i++){
			if(read(fd[0], &numero, sizeof(int)) < 0) 
				printf("Erro na leitura do pipe\n");
			else
				printf("%d\n", numero);
			sleep(1);
		}
		return 0;
	}
	// Codigo do pai
	else
	{	
		for(i=0;i<10;i++){		
			if (write(fd[1], &i, sizeof(int)) < 0)
				printf("Erro na escrita do pipe\n");
			sleep(1);
		}
	}
	return 0;
}
