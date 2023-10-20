#include <iostream>
using namespace std;

int main(){

    int num1, num2;
    int suma, resta, multi;
    float division, promedio;
    string nombre;

    cout << "Ingrese su nombre porfavor: " << endl;
    cin >> nombre;

    cout << "!Hola " << nombre << " un gusto verte denuevo!" << endl;
    cout << "Ingrese 2 numeros: " << endl;
    cin >> num1;
    cin >> num2;

    suma= num1 + num2;
    resta= num1 - num2;
    multi= num1*num2;
    division= num1 / num2;
    promedio= (num1 + num2) / 2;

    cout << "La suma de " << num1 << " + " << num2 << " es: " << suma << endl;
    cout << "La resta de " << num1 << " - " << num2 << " es: " << resta << endl;
    cout << "La multiplicacion " << num1 << " * " << num2 << " es: " << multi << endl;
    cout << "La division entre " << num1 << " y " << num2 << " es: " << division << endl;
    cout << "El promedio entre " << num1 << " y " << num2 << " es: " << promedio << endl;;

    return 0;
}
