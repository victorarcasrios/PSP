/*
Abuelo ­­­­ fork () ­­­> Hijo ­­­­­ fork() ­­­­> nieto 
 
Realiza   un   programa   llamado   tresgeneraciones.c   en   el   que   el   árbol   cubra   tres   
generaciones   y   la salida   debe   ser   contranatura   es   decir   siempre   tendrá   el   
orden:   nieto,   padre,   abuelo,   la   salida   al  ejecutarlo será debe ser la siguiente: 
 
txipi@neon:~$ ./tresgeneraciones 
Soy el nieto (15565, hijo de 15564) 
Soy el padre (15564, hijo de 15563) 
Soy el abuelo (15563, hijo de 15471) 
txipi@neon:~$ pgrep bash 
15471
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	pid_t abuelo, padre, nieto;	
	int statusPadre, statusNieto;

	abuelo = getpid();
	padre = fork();
	if(padre == 0){
		padre = getpid();
		nieto = fork();
		if(nieto == 0){
			nieto = getpid();
		} 
	}

	//scope nieto
	if(getpid() == nieto){
		printf("Soy el nieto (%d, hijo de %d)\n", getpid(), getppid());
	}

	//scope padre
	if(getpid() == padre){
		waitpid(nieto, &statusNieto, 0);
		printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
	}

	//scope hijo
	if(getpid() == abuelo){
		waitpid(padre, &statusPadre, 0);		
		printf("Soy el abuelo (%d, hijo de %d)\n", getpid(), getppid());
	}

}