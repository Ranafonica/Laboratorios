#include <iostream>
#include <list>
#include <string>

using namespace std;

long Factorial (int numero) {
    if (numero == 0){
    	return 1;
	}
    else{
    	return numero * Factorial(numero - 1);
	}
}

int Fibonacci (int cantidad) {
    if (cantidad <= 1) {
        return cantidad;
    }
	else{
        return Fibonacci(cantidad - 1) + Fibonacci(cantidad - 2);
    }
}

bool EsPalindrome (string oracion, int inicio, int fin) {
    if (inicio >= fin){
    	return true;
	}
    if (oracion[inicio] != oracion[fin]){
    	return false;
	}
    return EsPalindrome(oracion, inicio + 1, fin - 1);
}

int main (){
	
	int opcion;
	
	//Main menu
	cout << "Laboratorio 06 Unidad 02" << endl;
	cout << "Menu inicial:" << endl;
	
	
	do {
		cout << "Escoge Ejercicio a mostrar (1-5): " << endl;
		cin >> opcion;
		
		switch (opcion){
			case 1:{
				cout << "[Ejercicio 1]" << endl;
				list < int > Listanum;
				
				int total;
				double numero;
				
				cout << "Ingrese cantidad de numeros a ingresar: " << endl;
				cin >> total;
				
				for (int i = 0; i < total; i++){
					cout << "Ingrese un numero" << endl;
					cin >> numero;
					Listanum.push_back(numero);
				}
				// Operacion suma
				int suma = 0;
				for (double numaux : Listanum){
					suma += numaux;
				}
				// Operacion promedio (una sola declaracion de variable)
				double promedio = suma / total;
				
				// Operacion producto
				int producto = 1;
				
				for (int numaux : Listanum){
					producto *= numaux;
				} 
				
				// Resultados por pantalla
				cout << "Resultado de la suma: " << suma << endl;
				cout << "Resultado del promedio: " << promedio << endl;
				cout << "Resultado del producto: " << producto << endl;
				
				// Impresion de lista
				/*for (int i: Listanum) {
	                    cout << i << " ";
	                }
	            cout << endl;*/
	            break;
			}
			case 2:{
				cout << "[Ejercicio 2]" << endl;
				int numero;
				
				cout << "Ingrese un numero entero positivo: " << endl;
				cin >> numero;
				
				// Calculo de Factorial.
				cout << "El Factorial de " << numero << "es " << Factorial(numero) << endl;
				break;
			} 
			case 3: {
				cout << "[Ejercicio 3]" << endl; 
				int cantidad;
				
				cout << "Ingrese la cantidad de elementos a calcular en secuencia de Fibonacci: " << endl;
	            cin >> cantidad;
	            
	            cout << "Los numeros de la secuencia Fibonacci son " << cantidad << " elementos: " << endl;
	            cout << Fibonacci(cantidad) << "" << endl; // declaracion de funcion "Fibonacci" anteriormente creada.
	
				break;
			} 
	
			case 4:{
				cout << "[Ejercicio 4]" << endl;
				string palabra;
				
				cout << "Ingrese una palabra: " << endl;
				getline(cin, palabra); // la utilicé para leer toda la línea incluyendo los espacios en blanco y almacenarla en la variable "palabra".
				
				if (EsPalindrome(palabra, 0, palabra.length() - 1)){
					cout << "La palabra ingresada es un Palindromo" << endl;
				}
				else {
					cout << "La palabra ingresada NO es un Palindromo" << endl;
				}
				break;
			}
		}
	}while (opcion < 1 || opcion > 4);
	
	return 0;
	
}
