#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Point{
	private:
		int x;
		int y;
	public:
		Point(int, int);
		void acceso();
		void definicion();
};

Point::Point(int _x, int _y){
	x = _x;
	y = _y;
}

// mediante esta funcion, se acceden a las variables privadas de la clase Point.
void Point::acceso(){
	if (x==3 && y==4){
		cout << "Has dañado el barco. Felicidades" << endl;
	}
	else {
		cout << "Buena suerte para la proxima" << endl;
	}
}

// Se establecen las reglas, y se establece un objetivo para el usuario.
void Point::definicion(){
	cout << "BIENVENIDO AL JUEGO BATTLESHIP" << endl;
	cout << "Tienes solo 1 intento para atacar el barco ajeno" << endl;
	cout << "\n" << endl;
	
	cout << "Ingrese coordenada en X: " << endl;
	cin >> x;
	
	cout << "Ingrese coordenada en Y: " << endl;
	cin >> y;
}

int main(int x, int y){
	
	Point p1 = Point (x,y);
	p1.definicion();
	p1.acceso();
	
	return 0;
}
