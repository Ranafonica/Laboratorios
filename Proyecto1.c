#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Guardian {
	char nombre [20];
	int PV;
	int PA;
	int PD;
};

struct Player {
	int Pvida;
	
};

struct Cartas {
	
};

int main (){
	
	MenuInicial();
	
	int opcion;
	
	printf ("\nSELECCIONE UNA OPCION: \n");
	scanf ("%d", &opcion);
	
	if (opcion == 1){
		printf("\nOPCION CREAR CARTA\n");
		//crear carta
	}
	else if (opcion == 2){
		printf("\nOPCION EMPEZAR JUEGO\n");
		//empezar juego
	}
	else if (opcion == 3){
		printf("\nOPCION HISTORIAL DE PARTIDAS\n");
		//muestra historial de partidas
	}
	else if (opcion == 4){
		printf("\nOPCION CERRAR\n");
		//salir del juego
	}

	return 0;
}

void CargarGuardianes (){
	FILE *archivo = fopen ("Guardianes.txt", "r");
	if (archivo = NULL){
		perror ("*cueck* ERROR AL ABRIR ARCHIVO ;(");
		exit(1);
	}
}

void MenuInicial(){
	printf("--------------------[CLASH OF THE GUARDIANS]--------------------\n");
	printf("-----[OPCIONES]\n");
	printf("1-CREAR UNA CARTA\n");
	printf("2-EMPEZAR JUEGO\n");
	printf("3-MOSTRAR HISTORIAL\n");
	printf("4-SALIR DEL JUEGO\n");
}
