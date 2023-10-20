#include <iostream>
#include<time.h>
using namespace std;

int main(){
    //Semilla para el numero random.
    srand(time(NULL));

    int lim_inf = 1, lim_sup = 100; // Límites del ejercicio
    int num, adivinar, intento=0; // Se inicializa el turno en 0 debido al bucle While.

    // Se asigna los parámetros al numero aleatorio.
    num = lim_inf + rand()% (lim_sup + 1 - lim_inf);
    cout << "El numero es: "<< num << endl;

    // Condicion de bucle de intentos
    while(num!=adivinar){
        cout << "Ingrese un numero del 1 al 100: " << endl;
        cin >> adivinar;
        intento++;

        // Pistas
        if (num<adivinar){
            cout << "El numero es menor" << endl;
        }
        if (num>adivinar){
            cout << "El numero es mayor" << endl;
        }
        if (num == adivinar){
            cout << "!Has acertado!" << endl;
            cout << "En el intento " << intento << endl;
        }
    }

    return 0;
}
