/*
Realiza   un   programa   en   C   que   cree   un   proceso   (tendremos   2   procesos   uno   padre   y   otro   hijo).  
El   programa   definirá   una   variable   entera   y   le   dará   el   valor   6.   El   proceso   padre   incrementará  
dicho   valor   en   5   y   el   hijo   restará   5.   Se   deben   mostrar   los   valores   en   pantalla.   A   continuación   se  
muestra ejemplo de la ejecución. 
 
david@david­OEM ~/pss $ ./actividad2 
Soy el Padre.Valor variable 1 
Soy el hijo.Valor variable 11 
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	int variable = 1;

	// Sin orden especificado
	if(fork() == 0)
		printf("Soy el Hijo. Valor de la variable -> %d\n", (variable-5));
	else
		printf("Soy el Padre. Valor de la variable -> %d\n", (variable+5));	

	/*
	Explica el resultado del programa (recuerda los cambios de contextos explicados en la teoría). 

	Resultado obtenido:
	Soy el Padre. Valor de la variable -> 6
	Soy el Hijo. Valor de la variable -> -4

	Ambos incrementan e imprimen su propia copia de la variable (pues los enteros como variable primitiva 
	que son, siempre son modificados por valor, no por referencia)
	*/
}