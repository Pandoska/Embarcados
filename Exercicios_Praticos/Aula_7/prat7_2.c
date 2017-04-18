#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;
	int fd[2];
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();

	// Codigo do filho
	if(pid == 0)
	{
		char buffer_filho[200], msg_filho[200] = "FILHO: Pai, qual é a verdadeira essência da sabedoria?";
		if (write(fd[1], msg_filho, sizeof(msg_filho)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);		
		if(read(fd[0], buffer_filho, 200) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("Valor lido pelo filho = %s\n", buffer_filho);
		sleep(1);
		msg_filho[200] = "FILHO: Mas até uma criança de três anos sabe disso!";
		if (write(fd[1], msg_filho, sizeof(msg_filho)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);
		if(read(fd[0], buffer_filho, 200) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("Valor lido pelo filho = %s\n", buffer_filho);
		return 0;
	}
	// Codigo do pai
	else
	{
		char buffer_pai[200], msg_pai[200] = "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
		sleep(1);		
		if(read(fd[0], buffer_pai, 200) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("Valor lido pelo pai = %s\n", buffer_pai);		
		if (write(fd[1], msg_pai, sizeof(msg_pai)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(2);
		if(read(fd[0], buffer_pai, 200) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("Valor lido pelo pai = %s\n", buffer_pai);
		msg_pai[200] = "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";
		if (write(fd[1], msg_pai, sizeof(msg_pai)) < 0)
			printf("Erro na escrita do pipe\n");
	}
	return 0;
}
