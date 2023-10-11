#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_CARTAS 60
#define CARTAS_INICIALES 3
#define CARTAS_EN_MAZO 15

// Estructura de los Guardianes con sus características
struct Guardian {
    char nombre[50];
    char tipo[50];
    int PV;
    int PA;
    int PD;
};

// Estructura para las cartas seleccionadas por un jugador
struct CartasSeleccionadas {
    struct Guardian guardianes;
    int barajaEnJuego;
};

// Estructura del jugador para el sistema de batalla
struct Jugador {
    struct CartasSeleccionadas mano[CARTAS_INICIALES];
    int puntosVida; // Puntos de vida del jugador o la computadora
};

// Declaración de funciones
void MenuInicial();
int CargarGuardianes(struct Guardian cartas[]);
void CrearMazoAleatorio(struct Guardian cartas[], struct CartasSeleccionadas mazo[], int numCartas, int numCartasEnMazo);
void SeleccionarCartasIniciales(struct CartasSeleccionadas mazo[], int numCartasEnMazo, struct CartasSeleccionadas baraja[], int numCartasIniciales);
void MostrarCartas(struct Guardian cartas[], int numCartas);
void MostrarMazo(struct CartasSeleccionadas baraja[], int numCartasIniciales, const char* mensaje);

int main() {
    srand(time(NULL));

    int numCartas = 0;
    struct Guardian cartas[MAX_CARTAS];
    
    int turno = 1; // 1 para el jugador, 2 para la computadora

    numCartas = CargarGuardianes(cartas);

    struct CartasSeleccionadas mazoJugador[CARTAS_EN_MAZO];
    struct CartasSeleccionadas mazoComputadora[CARTAS_EN_MAZO];
    struct CartasSeleccionadas manoJugador[CARTAS_INICIALES];
    struct CartasSeleccionadas manoComputadora[CARTAS_INICIALES];

    int opcion;

    do {
        MenuInicial();

        printf("\nSELECCIONE UNA OPCION: \n");
        scanf("%d", &opcion);
        printf("HAS SELECCIONADO: ");

        switch (opcion) {
            case 1:
                printf("OPCION CREAR CARTA\n");
                break;
            case 2:
                printf("OPCION EMPEZAR JUEGO\n");

                // Crea mazos aleatorios de 15 cartas cada uno, para el jugador y para la computadora respectivamente.
                CrearMazoAleatorio(cartas, mazoJugador, numCartas, CARTAS_EN_MAZO);
                CrearMazoAleatorio(cartas, mazoComputadora, numCartas, CARTAS_EN_MAZO);

                // Mostrar el mazo del jugador
                MostrarMazo(mazoJugador, CARTAS_EN_MAZO, "TU MAZO DE 15 CARTAS ES: \n");

                // Seleccionar 3 cartas del mazo del jugador
                SeleccionarCartasIniciales(mazoJugador, CARTAS_EN_MAZO, manoJugador, CARTAS_INICIALES);

                // Mostrar las cartas seleccionadas por el jugador
                MostrarMazo(manoJugador, CARTAS_INICIALES, "Tus cartas seleccionadas:");
                
                printf("ESPERE UN SEGUNDO...\n");
                Sleep (5000);
                printf("AHORA SE MOSTRARAN LAS ESCOGIDAS POR LA COMPUTADORA\n");
				Sleep (5000);
				
                // Seleccionar 3 cartas del mazo de la computadora
                SeleccionarCartasAleatorias(mazoComputadora, CARTAS_EN_MAZO, manoComputadora, CARTAS_INICIALES);

                // Mostrar las cartas seleccionadas por la computadora
                MostrarMazo(manoComputadora, CARTAS_INICIALES, "CARTAS DE LA COMPUTADORA:");
                
                // Aquí comienza el bucle de turnos
                while (1) {
                    if (turno == 1) {
                        // Turno del jugador
                        printf("TURNO DEL JUGADOR\n");
                        // Aquí puedes permitir que el jugador realice acciones, como jugar una carta.
                    } else {
                        // Turno de la computadora
                        printf("TURNO DE LA COMPUTADORA\n");
                        // Implementa la lógica de la computadora para seleccionar y jugar una carta.
                    }

                    // Actualiza el turno (alternancia entre 1 y 2)
                    turno = (turno == 1) ? 2 : 1;

                    // Aquí puedes agregar lógica para verificar el final del juego.
                    // Si se cumple una condición de finalización, rompe el bucle de turnos.
                }
                break;
            case 3:
                printf("OPCION HISTORIAL DE PARTIDAS\n");
                break;
            case 4:
                printf("OPCION CERRAR\n");
                break;
        }
    } while (opcion <= 0 || opcion >= 5);

    //printf("\nCARTAS CARGADAS DESDE ARCHIVO:\n");
    //MostrarCartas(cartas, numCartas);

    return 0;
}

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

void MenuInicial() {
    printf("--------------------[CLASH OF THE GUARDIANS]--------------------\n");
    printf("-----[OPCIONES]\n");
    printf("1-CREAR UNA CARTA\n");
    printf("2-EMPEZAR JUEGO\n");
    printf("3-MOSTRAR HISTORIAL\n");
    printf("4-SALIR DEL JUEGO\n");
}

void CrearMazoAleatorio(struct Guardian cartas[], struct CartasSeleccionadas mazo[], int numCartas, int numCartasEnMazo) {
    int cartasDisponibles[MAX_CARTAS];
    int numCartasDisponibles = numCartas;

    for (int i = 0; i < numCartas; i++) {
        cartasDisponibles[i] = i;
    }

    // Selección aleatoria de cartas para el mazo
    for (int i = 0; i < numCartasEnMazo; i++) {
        int cartaAleatoria = rand() % numCartasDisponibles;
        int eleccion = cartasDisponibles[cartaAleatoria];

        mazo[i].guardianes = cartas[eleccion];
        mazo[i].barajaEnJuego = 1;

        for (int j = cartaAleatoria; j < numCartasDisponibles - 1; j++) {
            cartasDisponibles[j] = cartasDisponibles[j + 1];
        }
        numCartasDisponibles--;
    }
}

void SeleccionarCartasAleatorias(struct CartasSeleccionadas mazo[], int numCartasEnMazo, struct CartasSeleccionadas baraja[], int numCartasIniciales) {
    for (int i = 0; i < numCartasIniciales; i++) {
        int cartaAleatoria;
        do {
            cartaAleatoria = rand() % numCartasEnMazo;
        } while (mazo[cartaAleatoria].barajaEnJuego == 0);

        baraja[i] = mazo[cartaAleatoria];
    }
}

void SeleccionarCartasIniciales(struct CartasSeleccionadas mazo[], int numCartasEnMazo, struct CartasSeleccionadas baraja[], int numCartasIniciales) {
    printf("SELECCIONA TUS CARTAS INICIALES (NUMEROS DEL 1 al %d):\n", numCartasEnMazo);
    for (int i = 0; i < numCartasIniciales; i++) {
        int eleccion;
        do {
            printf("CARTA %d: ", i + 1);
            scanf("%d", &eleccion);
            eleccion--; // Ajustar a índice base 0
        } while (eleccion < 0 || eleccion >= numCartasEnMazo || mazo[eleccion].barajaEnJuego == 0);

        baraja[i] = mazo[eleccion];
        mazo[eleccion].barajaEnJuego = 0; // Marcar la carta como seleccionada
    }
}

void MostrarCartas(struct Guardian cartas[], int numCartas) {
    printf("\n[MAZO DE CARTAS OFICIAL]:\n");
    for (int i = 0; i < numCartas; i++) {
        printf("Nombre: %s\n", cartas[i].nombre);
        printf("Tipo: %s\n", cartas[i].tipo);
        printf("PV: %d\n", cartas[i].PV);
        printf("PA: %d\n", cartas[i].PA);
        printf("PD: %d\n", cartas[i].PD);
        printf("\n");
    }
}

void MostrarMazo(struct CartasSeleccionadas baraja[], int numCartasIniciales, const char* mensaje) {
    printf("\n%s\n", mensaje);
    for (int i = 0; i < numCartasIniciales; i++) {
        printf("Nombre: %s\n", baraja[i].guardianes.nombre);
        printf("Tipo: %s\n", baraja[i].guardianes.tipo);
        printf("PV: %d\n", baraja[i].guardianes.PV);
        printf("PA: %d\n", baraja[i].guardianes.PA);
        printf("PD: %d\n", baraja[i].guardianes.PD);
        printf("\n");
    }
}

