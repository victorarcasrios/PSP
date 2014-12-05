// Crea un programa que permita elegir el orden de ejecución de dos procesos p1 y p2, 
// mediante la orden introducida en el terminal.  
 
// Ejemplo  
// >programa 12 
// > Soy proceso 1 y termino 
// > Soy proceso 2 y termino 
 
// >programa 21 
// >Soy proceso 2 y termino 
// >Soy proceso 1 y termino 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define TRUE 1
#define ERROR -1
#define AT_SON 0

void ps1sayHi();
void ps2sayHi();
void forkError();

void main(){

	pid_t father_pid = getpid();
	pid_t ps_pids[2];
	int forkReturn, option;

	if( getpid() == father_pid ){
		switch( forkReturn = fork() ){
			case ERROR:
				forkError();
				break;
			case AT_SON:
				signal(SIGUSR1, ps1sayHi);
				break;
			default:
				ps_pids[0] = forkReturn;
				break;
		}

		switch( forkReturn = fork() ){
			case ERROR:
				forkError();
				break;
			case AT_SON:
				signal(SIGUSR1, ps2sayHi);
				break;
			default:
				ps_pids[1] = forkReturn;
				break;

		}
	}

	if(getpid() == father_pid){
		printf("Elige el orden de ejecucion de los dos procesos: (12 o 21)\n");
		scanf("%d", &option);

		printf("\n\t%d", option);
		switch(option){
			case 12:
				kill(ps_pids[0], SIGUSR1);
				kill(ps_pids[1], SIGUSR1);
				break;
			case 21:
				kill(ps_pids[1], SIGUSR1);
				kill(ps_pids[0], SIGUSR1);
				break;
		}		
	}
}

void ps1sayHi(int sig){
	printf("Soy el proceso 1 y termino");
	exit(EXIT_SUCCESS);
}

void ps2sayHi(int sig){
	printf("Soy el proceso 2 y termino");
	exit(EXIT_SUCCESS);
}

void forkError(){
	perror("Error en el primer FORK");
	exit(EXIT_FAILURE);
}
