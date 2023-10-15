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
    int puntosVida;
};

// Declaración de funciones
void MenuInicial();
int CargarGuardianes(struct Guardian cartas[]);
void CrearMazoAleatorio(struct Guardian cartas[], struct CartasSeleccionadas mazo[], int numCartas, int numCartasEnMazo);
void SeleccionarCartasIniciales(struct CartasSeleccionadas mazo[], int numCartasEnMazo, struct CartasSeleccionadas baraja[], int numCartasIniciales);
void BucleTurnos(struct Guardian cartas[], struct CartasSeleccionadas manoJugador[], struct CartasSeleccionadas manoComputadora[], int numCartas, int *jugadorpuntosVida, int *computadorapuntosVida); // Cambio en la firma de la función
void MostrarCartas(struct Guardian cartas[], int numCartas);
void MostrarMazo(struct CartasSeleccionadas baraja[], int numCartasIniciales, const char* mensaje);

int main() {
    srand(time(NULL));

    int numCartas = 0;
    struct Guardian cartas[MAX_CARTAS];
    
    int turno = 1;
    
    struct Jugador jugador;
    struct Jugador computadora;
    
    // Los puntos de vida para el jugador y la computadora
    int jugadorpuntosVida = 3;
    int computadorapuntosVida = 3;
    
    jugador.puntosVida = 3;
    computadora.puntosVida = 3;

    numCartas = CargarGuardianes(cartas);
 
    struct CartasSeleccionadas mazoJugador[CARTAS_EN_MAZO];
    struct CartasSeleccionadas mazoComputadora[CARTAS_EN_MAZO];
    struct CartasSeleccionadas manoJugador[CARTAS_INICIALES];
    struct CartasSeleccionadas manoComputadora[CARTAS_INICIALES];

    int opcion;
    int vercartas;

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
                Sleep(5000);
                printf("AHORA SE MOSTRARAN LAS ESCOGIDAS POR LA COMPUTADORA\n");
                Sleep(5000);

                // Seleccionar 3 cartas del mazo de la computadora
                SeleccionarCartasAleatorias(mazoComputadora, CARTAS_EN_MAZO, manoComputadora, CARTAS_INICIALES);

                // Mostrar las cartas seleccionadas por la computadora
                MostrarMazo(manoComputadora, CARTAS_INICIALES, "CARTAS DE LA COMPUTADORA:");
                
                Sleep(5000);
                printf("LISTO PARA EMPEZAR LA BATALLA?...");
                Sleep(5000);
                system ("cls");
                
                // Es aqui donde comienza el bucle de los turnos del juego
                BucleTurnos(cartas, manoJugador, manoComputadora, numCartas, &jugadorpuntosVida, &computadorapuntosVida);
                break;
            case 3:
                printf("OPCION HISTORIAL DE PARTIDAS\n");
                break;
            case 4:
                printf("OPCION CERRAR\n");
                printf("GRACIAS POR JUGAR CLASH OF THE GUARDIANS :D\n");
                break;
        }
    } while (opcion <= 0 || opcion >= 5 || opcion !=4);

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
            eleccion--;
        } while (eleccion < 0 || eleccion >= numCartasEnMazo || mazo[eleccion].barajaEnJuego == 0);

        baraja[i] = mazo[eleccion];
        mazo[eleccion].barajaEnJuego = 0;
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

void BucleTurnos(struct Guardian cartas[], struct CartasSeleccionadas manoJugador[], struct CartasSeleccionadas manoComputadora[], int numCartas, int *jugadorpuntosVida, int *computadorapuntosVida) {
    int turno = 1;
    while (*jugadorpuntosVida > 0 && *computadorapuntosVida > 0) {
        printf("\n[ESTADO ACTUAL DE PARTIDA]\n");
        printf("VIDAS JUGADOR: %d\n", *jugadorpuntosVida);
        printf("VIDAS COMPUTADORA: %d\n", *computadorapuntosVida);

        if (turno == 1) {
            printf("\n[TURNO DEL JUGADOR]\n");
            MostrarMazo(manoJugador, CARTAS_INICIALES, "Tus cartas seleccionadas:");

            int cartabatalla;
            do {
                printf("SELECCIONA UN GUARDIAN PARA LA BATALLA [1-3]: ");
                scanf("%d", &cartabatalla);
            } while (cartabatalla < 1 || cartabatalla > 3);

            int dano = manoJugador[cartabatalla - 1].guardianes.PA - manoComputadora[0].guardianes.PD;
            if (dano <= 0) {
                dano = 0;
            }
            printf("\n%s ATACA A LA COMPUTADORA POR %d PUNTOS DE DANO\n", manoJugador[cartabatalla - 1].guardianes.nombre, dano);
            *computadorapuntosVida -= dano;

            if (*computadorapuntosVida <= 0) {
                printf("\n%s HA DERROTADO AL GUARDIAN DE LA COMPUTADORA\n", manoJugador[cartabatalla - 1].guardianes.nombre);
                break;
            }
        } else {
        	printf("\nESPERE UN SEGUNDO...\n");
            Sleep(5000);
            printf("\n[TURNO DE LA COMPUTADORA]: \n");
            int cartabatalla = rand() % 3;
            int dano = manoComputadora[cartabatalla].guardianes.PA - manoJugador[0].guardianes.PD;

            if (dano <= 0) {
                dano = 0;
            }
            Sleep(5000);
            printf("\n%s ATACA AL JUGADOR POR %d PUNTOS DE DANO!\n", manoComputadora[cartabatalla].guardianes.nombre, dano);
            *jugadorpuntosVida -= dano;

            if (*jugadorpuntosVida <= 0) {
                printf("%s HA DERROTADO AL GUARDIAN DEL JUGADOR\n", manoComputadora[cartabatalla].guardianes.nombre);
                break;
            }
        }
        turno = (turno == 1) ? 2 : 1;
    }
    if (*jugadorpuntosVida = 0) {
        printf("\nLA COMPUTADORA HA GANADO LA PARTIDA\n");
    } else {
        printf("\nHAS GANADO LA PARTIDA\n");
    }
}

