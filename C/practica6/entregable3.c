// Realiza lo mismo que en el ejercicio anterior pero con la siguiente configuración de 
// procesos: 
// padre 
//          /   \ 
//         /     \ 
//        /       \ 
//       /         \ 
//      /           \  
//   hijo1         hijo2 
//                   | 
//                   | 
//                   | 
//             hijo3 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define ERROR -1
#define AT_SON 0

void printErrorAndDie();

void main(){
	pid_t father_pid, sons_pids[2], grandson_pid;
	int forkReturn;

	father_pid = getpid();

	if( getpid() == father_pid ){
		// Creacion PRIMER hijo
		switch(forkReturn = fork()){
			case ERROR:
				printErrorAndDie();
				break;
			case AT_SON:
				printf("Yo soy el primer hijo, mi padre es PID=%d, yo soy %d\n", getppid(), getpid());
				exit(EXIT_SUCCESS);
				break;
			default:// At father
				// Creacion SEGUNDO hijo
				switch( forkReturn = fork() ){
					case ERROR:
						printErrorAndDie();
						break;
					case AT_SON:
						printf("Yo soy el segundo hijo, mi padre es PID=%d, yo soy %d\n", getppid(), getpid());
						// Creacion NIETO
						switch( forkReturn = fork()){
							case ERROR:
								printErrorAndDie();
								break;
							case AT_SON:// Unexpected result
								printf("Yo soy el nieto, getppid() me devuelve a mi abuelo PID=%d, yo soy PID=%d\n", getppid(), getpid());
								exit(EXIT_SUCCESS);
								break;
							default:// Expected result
								printf("El nieto debería ser PID=%d, yo soy su padre, PID=%d\n", forkReturn, getpid());
								break;
						}
						exit(EXIT_SUCCESS);
						break;
				}
			wait(NULL);
			exit(EXIT_SUCCESS);
		}
	}
	
}

void printErrorAndDie(){	
	perror("Error al crear HIJO 1");
	exit(EXIT_FAILURE);
}