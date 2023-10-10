#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARTAS 60
#define CARTAS_INICIALES 3
#define CARTAS_PARTIDA 15

//Estructura de los Guardianes con sus caracteristicas
struct Guardian {
	char nombre [50];
	char tipo[50];
	int PV;
	int PA;
	int PD;
};

//Estructura de ls Jugadores con sus caracteristicas
struct Player {
	int Pvida;
	//struct Cartas barajaJugador[cartasIniciales];
	int barajaMano;
};

//Estructura de las Cartas con sus caracteristicas
struct Cartas {
	struct Guardian guardianes;
	int barajaEnJuego;
};

//declaracion de variables fuera del Main para evitar los WARNINGS del código.
//void MenuInicial();
void MenuInicial();
int CargarGuardianes(struct Guardian cartas[]);
void SeleccionarCartasIniciales(struct Guardian cartas[], int numCartas, struct Cartas barajaJugador[], int numCartasIniciales);
void MostrarMazos(struct Cartas barajaJugador1[], struct Cartas barajaJugador2[], int numCartasIniciales);

//void CargarGuardianes(struct Guardian cartas[], int*numCartas);

int main(){
	srand(time(NULL));
	
	int numCartas=0;	
	struct Guardian cartas[MAX_CARTAS];
	
	numCartas = CargarGuardianes(cartas);
    
    struct Cartas manoJugador1[CARTAS_INICIALES];
    struct Cartas manoJugador2[CARTAS_INICIALES];

    SeleccionarCartasIniciales(cartas, numCartas, manoJugador1, CARTAS_INICIALES);
    SeleccionarCartasIniciales(cartas, numCartas, manoJugador2, CARTAS_INICIALES);
	
	MenuInicial();
	//CargarGuardianes(cartas, &numCartas);
	
	int opcion;
	
	//Le pide al usuario que ingrese una de las 4 opciones en pantalla mediante teclado con un DO WHILE, ya que valida mediante la condición que el valor ingresado se encuentre entre 1 y 4.
	do {
		printf ("\nSELECCIONE UNA OPCION: \n");
		scanf ("%d", &opcion);
		printf ("HA SELECCIONADO: ");
		//4 opciones a ingresar
		switch (opcion){
			case 1:	
			printf("OPCION CREAR CARTA\n");
			break;
			case 2: 
			printf("OPCION EMPEZAR JUEGO\n");
			SeleccionarCartasIniciales(cartas, numCartas, manoJugador1, CARTAS_INICIALES);
			break;
			case 3:
			printf("OPCION HISTORIAL DE PARTIDAS\n");
			break;
			case 4:
			printf("OPCION CERRAR\n");
			break;
		}
	} while (opcion <=0 || opcion>=5); //condición para validar que el valor ingresado por teclado se encuentre en el intervalo solicitado.
	
	//Imprime las cartas cargadas del archivo de texto, cada una indicada por un Nombre, tipo, puntos de vida, ataque y defensa correspondientes.
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

//Funcion que permite al código cargar los datos del archivo "Guardians.txt" que contiene todas las cartas en juego de forma predeterminada.
int CargarGuardianes(struct Guardian cartas[]) {
    FILE *archivo = fopen("Guardians.txt", "r");
    if (archivo == NULL) {
        perror("\n*cueck*\nERROR AL ABRIR EL ARCHIVO TEXTO\n");
        exit(1);
    }

    int numCartas = 0;

    while (numCartas < MAX_CARTAS &&
           fscanf(archivo, "%[^,], %[^,], %d, %d, %d\n", cartas[numCartas].nombre, cartas[numCartas].tipo, &cartas[numCartas].PV, &cartas[numCartas].PA, &cartas[numCartas].PD) == 5) {
        numCartas++;
    }

    fclose(archivo);
    return numCartas;
}

//Menu del juego que le indica al jugador las opciones a seleccionar.
void MenuInicial(){
	printf("--------------------[CLASH OF THE GUARDIANS]--------------------\n");
	printf("-----[OPCIONES]\n");
	printf("1-CREAR UNA CARTA\n");
	printf("2-EMPEZAR JUEGO\n");
	printf("3-MOSTRAR HISTORIAL\n");
	printf("4-SALIR DEL JUEGO\n");
}

void SeleccionarCartasIniciales(struct Guardian cartas[], int numCartas, struct Cartas barajaJugador[], int numCartasIniciales) {
    printf("SELECCIONA TUS CARTAS INICIALES (NUMEROS DEL 1 al %d):\n", numCartas);
    for (int i = 0; i < numCartasIniciales; i++) {
        int eleccion;
        do {
            printf("CARTA %d: ", i + 1);
            scanf("%d", &eleccion);
            eleccion--; // Ajustar a índice base 0
        } while (eleccion < 0 || eleccion >= numCartas || cartas[eleccion].PV == -1);

        barajaJugador[i].guardianes = cartas[eleccion];
        barajaJugador[i].barajaEnJuego = 1; // La carta está en juego
        cartas[eleccion].PV = -1; // Marcar la carta como seleccionada
    }
}

void MostrarMazos(struct Cartas manoJugador1[], struct Cartas manoJugador2[], int numCartasIniciales) {
    printf("\nMazo del Jugador 1:\n");
    for (int i = 0; i < numCartasIniciales; i++) {
        printf("Nombre: %s\n", manoJugador1[i].guardianes.nombre);
        printf("Tipo: %s\n", manoJugador1[i].guardianes.tipo);
        printf("PV: %d\n", manoJugador1[i].guardianes.PV);
        printf("PA: %d\n", manoJugador1[i].guardianes.PA);
        printf("PD: %d\n", manoJugador1[i].guardianes.PD);
        printf("\n");
    }

    printf("\nMazo del Jugador 2 (Computadora):\n");
    for (int i = 0; i < numCartasIniciales; i++) {
        printf("Nombre: %s\n", manoJugador2[i].guardianes.nombre);
        printf("Tipo: %s\n", manoJugador2[i].guardianes.tipo);
        printf("PV: %d\n", manoJugador2[i].guardianes.PV);
        printf("PA: %d\n", manoJugador2[i].guardianes.PA);
        printf("PD: %d\n", manoJugador2[i].guardianes.PD);
        printf("\n");
    }
}

