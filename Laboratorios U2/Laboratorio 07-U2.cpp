#include <iostream>
using namespace std;

// Condicion para la comparación de datos ingresados
int comparacion(int n1, int n2){
    int mayor;
    if ( n1>=n2 ){
        mayor=n1;
    }
    else {
        mayor=n2;
    }
    return mayor;
}

int main (){
    int num1, num2;

    cout << "Ingrese primer numero: " << endl;
    cin >> num1;
    cout << "Ingrese segundo numero: " << endl;
    cin >> num2;

    // Validacion de datos ingresados [0-∞] (solo positivos)
    while (num1<0){
        cout << "Ingrese el primer numero: " << endl;
        cin >> num1;
    }
    while (num2<0){
        cout << "Ingrese el segundo numero: " << endl;
        cin >> num2;
    }

    // Mensaje por pantalla de datos calculados
    if (num1<num2 || num1>num2){
        cout << "Numero mas grande: " << comparacion(num1, num2) << endl;
    }else {
        cout << "Numeros ingresados son iguales" << endl;
    }
    return 0;
}


