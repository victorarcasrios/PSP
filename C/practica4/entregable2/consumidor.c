#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 20
#define TRUE 1

int main(void){
	int fp;
	char buffer[BUFFER_SIZE];
	int nbytes;

	mknod("FIFO1", S_IFIFO|0660, 0);

	while(TRUE)
	{
		fp = open("FIFO1", O_RDONLY);
		nbytes = read(fp, buffer, BUFFER_SIZE-1);
		buffer[nbytes] = '\0';
		printf("Mensaje recibido -> %s\n", buffer);
		close(fp);
		if(strncmp(buffer, ".", 1) == 0)
			break;
	}

	printf("\nConsumidor finalizado\n");
	return 0;
}