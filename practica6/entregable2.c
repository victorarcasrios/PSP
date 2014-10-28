// Realice un programa en C que genere la siguiente configuración de procesos: 
//         padre 
//          / | \ 
//         /  |  \ 
//        /   |   \ 
//       /    |    \ 
//      /     |     \  
//   hijo1  hijo2  hijo3 
 
// Además, cada hijo deberá mostrar el mensaje "Yo soy el hijo x, mi padre es PID=Y, yo 
// soy PID=z". 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR -1
#define AT_SON 0

void main(){

	char message[] = "Yo soy el hijo %d, mi padre es PID=%d, yo soy PID=%d\n";
	int i, forkReturn;
	pid_t ps[3], father_id;

	father_id = getpid();

	printf("\n\nPID=%d\n\n", getpid());

	if(getpid() == father_id){
		switch(fork()){
			case ERROR:
				exit(EXIT_FAILURE);
				break;
			case AT_SON:
				printf(message, 1, getppid(), getpid());
				exit(EXIT_SUCCESS);
				break;
			default:
				switch(fork()){
					case ERROR:
						exit(EXIT_FAILURE);
						break;
					case AT_SON:						
						printf(message, 2, getppid(), getpid());
						exit(EXIT_SUCCESS);
						break;
					default:
						switch(fork()){
							case ERROR:
								exit(EXIT_FAILURE);
								break;
							case AT_SON:						
								printf(message, 3, getppid(), getpid());
								exit(EXIT_SUCCESS);
								break;
						}
				}
				wait(NULL);
				exit(EXIT_SUCCESS);
		}
	}
}