#include <iostream>
using namespace std;

struct Registro {
	int nota1;
	int nota2;
	int nota3;
	float promedio;
};

struct Alumno {
	string nombre;
	int edad;
	int matricula;
	Registro registro;
};

void IngresoDatos(Alumno& alumno){
	cout<< "Ingrese nombre: " << endl;
	cin >> alumno.nombre;
	cout << "Ingrese edad: " << endl;
	cin >> alumno.edad;
	cout << "Ingrese matricula: " << endl;
	cin >> alumno.matricula;

	cout << "Ingrese notas: " << endl;
	cin >> alumno.registro.nota1;
	cin >> alumno.registro.nota2;
	cin >> alumno.registro.nota3;
}

void CalculoPromedio(Registro& registro){
	registro.promedio = (registro.nota1 + registro.nota2 + registro.nota3)/3;
}

void ImpresiondeDatos(Alumno& alumno){
	cout << "ESTUDIANTE:" << endl;
	cout << "Nombre: " << alumno.nombre << endl;
	cout << "Edad: " << alumno.edad << endl;
	cout << "Matricula: " << alumno.matricula << endl;
	
	cout << "Notas: " << alumno.registro.nota1 << " " << alumno.registro.nota2 << " " << alumno.registro.nota3 << " " << endl;
	cout << "Promedio: " << alumno.registro.promedio << endl;
}
int main (){
	
	Alumno alumno;
	
	IngresoDatos(alumno);
	
	CalculoPromedio(alumno.registro);
	
	ImpresiondeDatos(alumno);
	
	return 0;
}
