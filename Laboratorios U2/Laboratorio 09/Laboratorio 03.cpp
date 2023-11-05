#include <iostream>

using namespace std;

// Creacion de la estructura del Nodo
struct Node{
	int data;								// para que en este caso sean caracteres, se cambia el "int data" por un "char".
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;				// Inicializa el puntero izquierdo como NULL.
	newNode->right = nullptr;				// Inicializa el puntero derecho como NULL.
	return newNode;
}

void inOrder (Node* node) {
    if (node == nullptr){
    	return;
	}
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

// El responsable de insertar un nuevo nodo al arbol binario del 3°er ejercicio.
void insertar (Node*& root, int data){
    if (root == nullptr){
        root = createNode(data);
    }else{
        if (data < root->data){
            insertar(root->left, data);
        }else{
            insertar(root->right, data);
        }
    }
} 

int main(){
	int arreglo[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	int cantidad = sizeof(arreglo) / sizeof(arreglo[0]);
	
	Node* root = nullptr; 					// Para asegurarnos que al iniciarlo esté vacío.
	
	for (int i = 0; i < cantidad; i++) {
        insertar(root, arreglo[i]);
    }
    
    cout << "Recorrido inOrder: ";
    inOrder(root);
    cout << endl;
		    
	return 0;
}

