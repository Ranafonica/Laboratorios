#include <iostream>

using namespace std;

// Creacion de la estructura del Nodo
struct Node{
	char data;						// para que en este caso sean caracteres, se cambia el "int data" por un "char".
	Node* left;
	Node* right;
};

Node* createNode(char data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;		// Inicializa el puntero izquierdo como NULL.
	newNode->right = nullptr;		// Inicializa el puntero derecho como NULL.
	return newNode;
}

void preOrder (Node* node) {
    if (node == nullptr){
    	return;
	}
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder (Node* node) {
    if (node == nullptr){
    	return;
	}
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder (Node* node) {
    if (node == nullptr){
    	return;
	} 
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main(){

	Node* root = createNode('M');					// Nodo N°1.
    root->left = createNode('C');					// Nodo N°2.
    root->right = createNode('Z');					// Nodo N°3.
    root->left->left = createNode('X');				// Nodo N°4.
    root->left->right = createNode('O');			// Nodo N°5.	
    root->right->left = createNode('T');			// Nodo N°6.
    root->right->left->left = createNode('W');		// Nodo N°7.
    root->right->right = createNode('F');			// Nodo N°8.
    
    cout << "Recorrido en preOrder: ";
    preOrder(root);
    cout << endl;

    cout << "Recorrido en inOrder: ";
    inOrder(root);
    cout << endl;

    cout << "Recorrido en postOrder: ";
    postOrder(root);
    cout << endl;

	return 0;
}
