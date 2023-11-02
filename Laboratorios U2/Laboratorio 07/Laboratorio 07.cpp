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

bool buscar(Nodo* root, int datos){
	if (root == NULL){
		return false;
	}
	else if (root->datos == datos){		
		return true;
	}
	else if (datos<= root -> datos){		
		return buscar (root->left, datos);
	}else{		
		return buscar (root->right, datos);
	}
}

Nodo* eliminarNodo(Nodo* root, int llave){
	if (root = NULL){
		return root;
	}
	if (llave < root->datos){
		root->left = eliminarNodo(root->left, llave);
		
	}else if(llave > root->datos){
		root->right = eliminarNodo(root->right, llave);
	}else{
		if (root->left == NULL){
			Nodo* temp = root ->right;
			delete root;
			return temp;
		} else if (root->right == NULL){
			Nodo* temp = root->left;
			delete root;
			return temp;
		}
		
		Nodo* temp = root->right;
		while (temp->left != NULL){
			temp = temp->left;
		}
		
		root->datos = temp->datos;
		root->right = eliminarNodo(root->right, temp->datos);
	}
	
	return root;
}

int main (){
	Nodo* root = NULL;
	
	int ingreso, totalnum, search, eliminar, opcion, llave=0;
	
	cout << "Laboratorio 07-Arboles Binarios";
	cout << "\n" << endl;
	cout << "Porfavor Ingrese la opcion a escoger:" << endl;
	cout << "1-Agregar Numero Positivo" << endl;
	cout << "2-Buscar Numero Especifico, Minimo y Maximo" << endl;
	cout << "3-Borrar Numero de la Raiz" << endl;
	cout << "4-Implementar Arbol General" << endl;
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
			root = agregar(root, 23); // Valores de prueba para la búsqueda de numeros.
			root = agregar(root, 15); // Valores de prueba para la búsqueda de numeros.
			
			cout << "Ingrese valor a buscar: " << endl;
			cin >> search;
			
			if(buscar(root, search)==true){
				cout << "VALOR ENCONTRADO";
			
			}
			else if(buscar(root, search)==false){
				cout << "VALOR NO ENCONTRADO";
			
			}
			
			break;
		}
		case 3:{
			root = agregar(root, 23); // Valores de prueba para la búsqueda de numeros.
			root = agregar(root, 15); // Valores de prueba para la búsqueda de numeros.
			
			cout << "Ingrese el valor a eliminar: " << endl;
			cin >> eliminar;
			llave = eliminar;
			
			if (buscar(root, eliminar)== true){
				cout << "NUMERO ENCONTRADO" <<endl;
				
				eliminarNodo(root, llave);
				cout << "NUMERO ELIMINADO";
				
			}else if(buscar(root,eliminar)== false){
				cout << "NUMERO NO ENCONTRADO" <<endl;
			}
			break;
		}			
	}


return 0;
}
