#include <iostream>
using namespace std;

// Se hace la estructura del NODO.
struct Nodo{
	int datos;
	Nodo* left;
	Nodo* right;
};

// se crea el nodo.
Nodo* crearNodo(int datos){
	Nodo* nodo= new Nodo;
	nodo->datos = datos;
	
	nodo->left = NULL;
	nodo->right = NULL;

	return nodo;	
}

Nodo* agregar(Nodo* root,  int ingreso){
	if (root == NULL){
		root = crearNodo(ingreso);
		return root;
	}
	// Se determina si el numero ingresado es menor, se irá a la izquierda, y si es mayor a la derecha.
	if(ingreso <= root->datos){
		root->left = agregar(root->left, ingreso);
	}
	else{
		root->right = agregar(root->right, ingreso);
	}
	// Se imprime el resultado.
	//cout << root << endl;
	return root;
}

void imprimir(Nodo* root){
	if (root == NULL){
		return;
	}
	cout << root->datos << " ";
	
	imprimir(root->left);
	imprimir(root->right);
}

bool buscar(Nodo* root, int search){
	if (root == NULL){
		cout << "null " << endl;
		return false;
	}
	else if (root->datos == search){
		cout << "S " << endl;
		return true;
	}
	else if (root->datos > search){
		cout << "M " << endl;
		return buscar (root->left, search);
	}else{
		cout << "AC " << endl;
		return buscar (root->right, search);
	}
}

int main (){
	Nodo* root = NULL;
	
	int ingreso, totalnum, search, opcion;
	
	cout << "Laboratorio 07-Arboles Binarios";
	cout << "\n" << endl;
	cout << "Porfavor Ingrese la opcion a escoger:" << endl;
	cout << "1-Agregar Numero Positivo" << endl;
	cout << "2-Buscar Numero Especifico Minimo y Maximo" << endl;
	cout << "3-Borrar Numero de la Raiz" << endl;
	cout << "4-Cerrar el programa" << endl;
	cin >> opcion;
	switch(opcion){
		case 1:{
			cout << "Ingrese total de Numeros Positivos a agregar: " << endl;
			cin >> totalnum;
			
			for (int i = 0; i < totalnum; i ++){
				cout << i+1<< ":";
				
				cin >> ingreso;
				root = agregar(root, ingreso);
			}
			imprimir(root);
			break;
		}
		case 2:{
			
			break;
		}			
	}


return 0;
}
