/*
Realiza   un   programa   que   permita   elegir   si   la   comunicación   es   de   padre   a   hijo   o   de   hijo   a  
padre   (ya   sea   en   el   programa   o   pasándole   un   parámetro).   Además   el   programa   debe  
permitir la introducción del mensaje de comunicación en ambos tipos de comunicación. 
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void fatherTalks();
void sonTalks();

pid_t fatherID, sonID;
int talk = -1;
char message[100];
char buffer[100];	
int fd[2];

void main(){

	pipe(fd);

	// Creamos al hijo y guardamos ambas pids (padre e hijo)
	if(fork() == 0){
		sonID = getpid();
		fatherID = getppid();
		printf("Creados hijo (%d) y padre (%d)\n", sonID, fatherID);
	}

	while(talk != 0){
		printf("¿Quien habla?\n¿Padre (1) o hijo (2)? ...\t");
		scanf("%d", &talk);
		printf("\n¿Que dice? ...\t");
		fgets(message, sizeof(message), stdin);	

		switch(talk){
			case 0:
				printf("Adios\n");
				break;
			case 1:
				// Padre
				fatherTalks();
				break;
			case 2:
				// Hijo
				sonTalks();
				break;
			default:
				printf("%d\n", getpid());
		}
	}
}

void fatherTalks(){
	int recibido = 0;

	while(recibido == 0)
	{
		if(getpid() == fatherID)
		{
			close(fd[0]);
			write(fd[1], message, strlen(message));
			printf("Padre (%d) dice %s\n", getpid(), message);
			wait(NULL);
		}else{
			close(fd[1]);
			read(fd[0], buffer, sizeof(buffer));
			printf("Hijo (%d) recibe %s\n", getpid(), buffer);
			recibido = 1;
		}
	}
}

void sonTalks(){
	int recibido = 0;

	while(recibido == 0)
	{
		if(getpid() == sonID)
		{
			close(fd[0]);
			write(fd[1], message, strlen(message));
			printf("Hijo (%d) dice %s\n", getpid(), message);
		}else{
			close(fd[1]);
			read(fd[0], buffer, sizeof(buffer));
			printf("Padre (%d) recibe %s\n", getpid(), buffer);
			wait(NULL);
		}
	}	
}