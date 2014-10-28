// Implementa  un programa que cree un hijo. El hijo debe escribir “Soy el hijo” diez veces. 
// El padre debe escribir “Soy el padre” diez veces. El padre debe esperar a que termine el 
// hijo y mostrar el mensaje “Mi proceso hijo ya ha terminado”.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){

	int forkReturn = fork();
	int i;

	if( forkReturn == -1 ){
		perror("ERROR: Creacion fallida de proceso hijo [FORK]");
		exit(EXIT_FAILURE);
	}
	else if( forkReturn == 0 ){
		for(i = 0; i < 10; i++){
			printf("Soy el HIJO\n");
		}
	}else{
		for(i = 0; i < 10; i++){
			printf("Soy el PADRE\n");
		}
		wait(NULL);
		printf("Mi proceso hijo ya ha terminado\n");		
	}

	exit(EXIT_SUCCESS);
}