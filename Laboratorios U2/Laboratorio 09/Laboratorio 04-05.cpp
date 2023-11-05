#include <iostream>
#include <queue>

using namespace std;

// Creacion de la estructura del Nodo
struct Node{
	int data;													// Para que en este caso sean caracteres, se cambia el "int data" por un "char".
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;									// Inicializa el puntero izquierdo como NULL.
	newNode->right = nullptr;									// Inicializa el puntero derecho como NULL.
	return newNode;
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

bool busquedaProfundidad (Node* node, int objetivo) {
    if (node == nullptr){
    	return false;
	}
    if (node->data == objetivo) {
        return true; 											// El elemento ha sido encontrado.
    }
    if (busquedaProfundidad(node->left, objetivo)) {			// Recorre los subárboles.
        return true;
    }
    if (busquedaProfundidad(node->right, objetivo)) {
        return true;
    }
    return false; 												// El elemento no ha sido encontrado en el subárbol.
}

bool busquedaAmplitud (Node* root) {							// El más complejo a mi opinión personal....
    if (root == nullptr){
    	return;
	} 
    queue<Node*>nodeQueue;
    nodeQueue.push(root);
    
    while (!nodeQueue.empty()) {								// Verifica si Node queue se encuentra vacío o no.
        Node* current = nodeQueue.front();						// Current funciona como puntero que apunta al nodo de la parte frontal de la cola.
        nodeQueue.pop();										// Elmina el nodo de la parte frontal despues de Current.
    	
		cout << current->data << " ";

        if (current->left) {									// Inserta los subárboles en la cola.
            nodeQueue.push(current->left); 						// Primero el izquierdo.
        }
        if (current->right) {
            nodeQueue.push(current->right); 					// Luego el derecho.
        }
    }
}

int main() {
    int arreglo[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
    int cantidad = sizeof(arreglo) / sizeof(arreglo[0]);

    Node* root = nullptr;
    for (int i = 0; i < cantidad; i++) {
        insertar(root, arreglo[i]);
    }

    int objetivo = 12; 											// Elemento a buscar.
    bool encontrado = busquedaProfundidad(root, objetivo);

    if (encontrado) {
        cout << "El elemento " << objetivo << " ha sido encontrado en el arbol." << endl;
    } else {
        cout << "El elemento " << objetivo << " no ha sido encontrado en el arbol." << endl;
    }

    return 0;
}
