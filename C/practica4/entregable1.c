#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(){
	int direction, forkReturn, fd[2];
	char message[] = "Buenos dias Padre";
	char buffer[strlen(message)];
	
	if(pipe(fd) == -1){
		perror("ERROR: Creación fallida del PIPE");
		exit(EXIT_FAILURE);
	}

	forkReturn = fork();
	if(forkReturn == -1){
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	else if(forkReturn == 0)
	{
		printf("\nHijo envía mensaje al padre...");
		write(fd[1], message, strlen(message));
	}
	else
	{
		wait(NULL);
		read(fd[0], buffer, sizeof(buffer));
		printf("\nEl padre recibe algo del pipe: %s\n", buffer);
	}
}