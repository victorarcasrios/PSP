// Crea un programa que simula el paso por un puente de tres procesos (donde sólo puede 
// pasar un proceso).  Primero deberá pasar el más joven y por último el más viejo.  
// Salida esperada del programa 
// >Creo proceso 1. 
// > Creo proceso 2 
// > Creo proceso 3 
// > Paso puente proceso 3 y termina. 
// > Paso puente proceso 2 y termina. 
// > Paso puente proceso 1 y termina. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ERROR -1
#define AT_SON 0

void main(){
	pid_t father_pid, ps_pids[3];
	char creationMessage[] = "Creado proceso hijo numero #%d (PID=%d)\n";
	char bridgeMessage[] = "Paso puente proceso hijo numero #%d (PID=%d) y termina\n";

	printf("Entra el padre PID=%d\n", getpid());
	father_pid = getpid();

	if( getpid() == father_pid ){
		int i;
		for(i = 0; i < 3; i++){
			switch(fork()){
				case ERROR:
					perror("Error en el primer FORK");
					exit(EXIT_FAILURE);
					break;
				case AT_SON:
					printf(creationMessage, i+1, getpid());
					sleep(10 - i*4);
					printf(bridgeMessage, i+1, getpid());
					exit(EXIT_SUCCESS);
					break;
			}
		}

	sleep(10);
	exit(EXIT_SUCCESS);
	}
}