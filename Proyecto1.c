#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTAS 60
#define CARTAS_INICIALES 3
#define CARTAS_PARTIDA 15


struct Guardian {
	char nombre [50];
	char tipo[50];
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
 
void MenuInicial();
void CargarGuardianes(struct Guardian cartas[], int*numCartas);

int main(){
	
	int numCartas=0;	
	struct Guardian cartas[MAX_CARTAS];
	
	MenuInicial();
	CargarGuardianes(cartas, &numCartas);
	
	int opcion;
	
	do {
		printf ("\nSELECCIONE UNA OPCION: \n");
		scanf ("%d", &opcion);
		printf ("HA SELECCIONADO: ");
		
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
	
	printf("\nCARTAS CARGADAS DESDE ARCHIVO:\n");
	for (int i = 0; i < numCartas; i++) {
	    printf("Nombre: %s\n", cartas[i].nombre);
	    printf("Tipo: %s\n", cartas[i].tipo);
	    printf("PV: %d\n", cartas[i].PV);
	    printf("PA: %d\n", cartas[i].PA);
	    printf("PD: %d\n", cartas[i].PD);
	    printf("\n");
	}
	return 0;
}

void CargarGuardianes(struct Guardian cartas[], int*numCartas){
	FILE *archivo = fopen ("Guardians.txt", "r");
	if (archivo == NULL){
		perror ("\n*cueck*\nERROR AL ABRIR EL ARCHIVO TEXTO\n");
		exit(1);
	}
	while (*numCartas < MAX_CARTAS &&
           fscanf(archivo, "%[^,], %[^,], %d, %d, %d\n", cartas[*numCartas].nombre, cartas[*numCartas].tipo, &cartas[*numCartas].PV, &cartas[*numCartas].PA, &cartas[*numCartas].PD)==5){
		(*numCartas)++;
	}
	fclose(archivo);
}

void MenuInicial(){
	printf("--------------------[CLASH OF THE GUARDIANS]--------------------\n");
	printf("-----[OPCIONES]\n");
	printf("1-CREAR UNA CARTA\n");
	printf("2-EMPEZAR JUEGO\n");
	printf("3-MOSTRAR HISTORIAL\n");
	printf("4-SALIR DEL JUEGO\n");
}
