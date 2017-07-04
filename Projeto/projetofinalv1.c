#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include <linux/i2c-dev.h>

//variáveis globais
int i2c_fd, controle=1;

unsigned int dados_lang[1000], dados_fonte[1000];

//função de saída em caso de travamento
void ctrl_c(int sig)
{
	close(i2c_fd);
	exit(-1);
}

//função que chama o msp e lê o valor adc	
void leitura_analog (void) {
	unsigned char buffer_envio_msp=0x55, msp430_ret, rpi_addr = 0xDA, slave_addr=0x0F;
	unsigned int buffer_adc=0;
	i2c_fd = open("/dev/i2c-1", O_RDWR);
	ioctl(i2c_fd, I2C_SLAVE, slave_addr);
	write(i2c_fd, &buffer_envio_msp, 1);
	usleep(100);
	read(i2c_fd, &msp430_ret, 1);
	buffer_adc = msp430_ret;
	read(i2c_fd, &msp430_ret, 1);
	buffer_adc = buffer_adc +(msp430<<8);
	close(i2c_fd);
}
//função que escreve os dados no arquivo com a data atual
void escreve_arquivo (void){
	char nome_arquivo[250],*buffer_valores, teste="teste";
	
	sprintf(nome_arquivo, "%s.txt",teste/*data atual*/ ); //escrevendo dentro da string, ao invés da tela.
	fp = fopen(nome_arquivo,"w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo");
		exit(0);
	}
	for(int i=0;i<1000;i++){
		sprintf(buffer_valores, "%d , %d \n", dados_lang[i], dados_fonte[i]);
		for(int j=0; buffer_valores[j]; j++)
		putc(buffer_valores[j], fp);
	}
	
}
//função que executa o tratamento do alarme
void int_trata_alarme(int sig){
	leitura_analog();
}

int main(void)
{
	signal(SIGALARM,int_trata_alarme);
	int k=0;	
	while(1){
		if (controle == 1 && k!=1000){
			leitura_analog();
			k++;
			usleep(300);
		}else if (controle == 1 && k==1000){
			escreve_arquivo();
			k=0;
			controle=2;				
			}else if (controle == 2){
				realiza_calculo();
				controle==1;
				sleep(600);				
				}
		}
}
