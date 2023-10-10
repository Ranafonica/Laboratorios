#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

                // Crear mazos aleatorios para el jugador y la computadora
                CrearMazoAleatorio(cartas, mazoJugador, numCartas, CARTAS_EN_MAZO);
                CrearMazoAleatorio(cartas, mazoComputadora, numCartas, CARTAS_EN_MAZO);

                // Mostrar el mazo del jugador
                MostrarMazo(mazoJugador, CARTAS_EN_MAZO, "Tu mazo de 15 cartas:");

                // Seleccionar 3 cartas del mazo del jugador
                SeleccionarCartasIniciales(mazoJugador, CARTAS_EN_MAZO, manoJugador, CARTAS_INICIALES);

                // Mostrar el mazo de la computadora
                MostrarMazo(mazoComputadora, CARTAS_EN_MAZO, "Mazo de la Computadora:");

                // Seleccionar 3 cartas del mazo de la computadora
                SeleccionarCartasIniciales(mazoComputadora, CARTAS_EN_MAZO, manoComputadora, CARTAS_INICIALES);

                // Mostrar las cartas seleccionadas por el jugador y la computadora
                MostrarMazo(manoJugador, CARTAS_INICIALES, "Tus cartas seleccionadas:");
                MostrarMazo(manoComputadora, CARTAS_INICIALES, "Cartas de la Computadora:");
                break;
            case 3:
                printf("OPCION HISTORIAL DE PARTIDAS\n");
                break;
            case 4:
                printf("OPCION CERRAR\n");
                break;
        }
    } while (opcion <= 0 || opcion >= 5);

    printf("\nCARTAS CARGADAS DESDE ARCHIVO:\n");
    MostrarCartas(cartas, numCartas);

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

