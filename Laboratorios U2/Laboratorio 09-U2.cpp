#include <iostream>
using namespace std;

// enum categoria ciclista.
enum Categoria {
	Juvenil,
	Senior, 
	Veterano
};

// estructura para asginar la información del ciclista.
struct Ciclista {
	string nombre;
	int edad;
	string club;
	Categoria categoria;
};

// Funcion que asigna la categoría segun parámetros establecidos.
Categoria AsignarCategoria(int edad){
	
	if (edad <= 18){
		return Juvenil;
	}
	if (edad > 18 && edad <= 40){
		return Senior;
	}
	if (edad > 40){
		return Veterano;
	}
}

// Void que entrega los datos del ciclista para mejorar la vista del código.
void DatosCiclista (Ciclista ciclista){
	cout << "Datos del ciclista:" << endl;
    cout << "Nombre: " << ciclista.nombre << endl;
    cout << "Edad: " << ciclista.edad << endl;
    cout << "Club: " << ciclista.club << endl;
}

int main (){
	
	Ciclista ciclista;
	
	cout << "Ingrese su nombre: " << endl;
	cin >> ciclista.nombre;
	
	cout << "Ingrese su edad: " << endl;
	cin >> ciclista.edad;
	
	cout << "Ingrese nombre del club al que pertenece: " << endl;
	cin >> ciclista.club;
	
	// Se asigna la categoría.
	ciclista.categoria = AsignarCategoria(ciclista.edad);
	
	// Se llama la función al main.
	DatosCiclista(ciclista);
	
	// Definimos la categoría en función de asignacion previa con un Switch.
	cout << "Categoria: ";
    switch (ciclista.categoria) {
        case Juvenil:
            cout << "Juvenil" << endl;
            break;
        case Senior:
            cout << "Senior" << endl;
            break;
        case Veterano:
            cout << "Veterano" << endl;
            break;
    }
	return 0;
}
