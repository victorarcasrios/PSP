#include <stdio.h>
#include <unistd.h>

void main(){
	pid_t mainPro;
	pid_t hijos[3];
	int carne = 0;
	int hijos_c = 0;
	int aux;

	mainPro = getpid();

	while(hijos_c < 3){
		if(getpid() == mainPro){
			if(fork() != 0){
				hijos[hijos_c] = getpid();
				hijos_c++;
			}
		}
	}

	while(carne < 3){
		if(aux = getpid() == hijos[0] && hijos[0] != -1){
			printf("El proceso %d actua\tCarne = %d\n", aux, carne++);
			hijos[0] = -1;
			carne++;
		}else if(aux = getpid() == hijos[1] && hijos[1] != -1){
			printf("El proceso %d actua\tCarne = %d\n", aux, carne++);
			hijos[1] = -1;
			carne++;
		}else if(aux = getpid() == hijos[2] && hijos[2] != -1){
			printf("El proceso %d actua\tCarne = %d\n", aux, carne++);
			hijos[2] = -1;
			carne++;
		}
		
		/*
		switch(aux = getpid()){
			case hijos[0]:
				printf("El proceso %d actua\tCarne = %d", aux, carne++);
				break;

			case hijos[1]:
				printf("El proceso %d actua\tCarne = %d", aux, carne++);
				break;

			case hijos[2]:
				printf("El proceso %d actua\tCarne = %d", aux, carne++);
				break;
		}
		*/
	}

	printf("Final -> Carne = %d\n", carne);
}