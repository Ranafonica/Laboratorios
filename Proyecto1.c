#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxCartas 60
#define cartasIniciales 3
#define cartasPartida 15


struct Guardian {
	char nombre [20];
	int PV;
	int PA;
	int PD;
};

struct Player {
	int Pvida;
	//struct Cartas barajaJugador[cartasIniciales];
	int barajaMano;
};

struct Cartas {
	struct Guardian guardianes;
	int barajaEnJuego;
};

int main (){
	
	CargarGuardianes();
	MenuInicial();
	
	int opcion;
	
	do {
		printf ("\nSELECCIONE UNA OPCION: \n");
		scanf ("%d", &opcion);
		
		switch (opcion){
			case 1:	
			printf("OPCION CREAR CARTA\n");
			break;
			case 2: 
			printf("OPCION EMPEZAR JUEGO\n");
			break;
			case 3:
			printf("OPCION HISTORIAL DE PARTIDAS\n");
			break;
			case 4:
			printf("OPCION CERRAR\n");
			break;
		}
	} while (opcion <=0 || opcion>=5);
	

	return 0;
}

void CargarGuardianes(){
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
