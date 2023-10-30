#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

//Declaracion de clases.
class Rectangle{
	private: //atributos.
		float largo;
		float ancho;	
	public: //metodos.
		Rectangle(float, float); //constructor.
		void calcularArea();
};

// el constructor que nos ayudará a inicializar los atributos.
Rectangle::Rectangle(float _largo, float _ancho){
	_largo = largo;
	_ancho = ancho;
}

void Rectangle::calcularArea(){
	float area = largo * ancho;
	cout << "El Area de un rectangulo de largo " << largo << " y de ancho " << ancho << " es de: " << area << endl;
}

int main (){
	
	Rectangle a1 = Rectangle(30,40);
	a1.calcularArea();
	
	return 0;
}
