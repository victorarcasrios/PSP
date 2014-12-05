#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fp;
	char text[10] = "Hola";

	fp = open("FIFO1", 1);

	if(fp == -1){
		perror("Error al crear el FIFO");
		exit(EXIT_FAILURE);
	}

	while(strncmp(text, ".", 1) != 0){
		printf("Introduce mensaje: ");
		scanf("%10s", text);

		printf("\nMando el mensaje -> %s\n", text);
		write(fp, text, strlen(text));
	}	

	printf("\nProductor finalizado\n");
	return 0;
}