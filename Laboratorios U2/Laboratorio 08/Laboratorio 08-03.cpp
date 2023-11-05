#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Node{
		int data;
		Node* left;
		Node* right;
	};
class LinkedList{
	private:
		
	public:
		LinkedList();
		void createNode();
		void insertar();
		void buscar();
		void elminar();
		void imprimir();
};

void Node* createNode(int data){
	Node* newNode = new node
	newNode->data = data;
	
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void LinkedList::insertar(Node* root, int data){
	
	if (root == NULL){
		root = createNode(data);
	}
	else if (data <= root->data){
		root ->left = insert (root->left, data);
	}
	else{
		root ->right = insert (root->right, data);
	}
	return root;
}

void LinkedList::buscar(Node* root, int data){
	if (root == NULL){
		return false;
	}
	else if (root->data == data){
		return true;
	}
	else if (data <= root ->data){
		return search(root -> left, data);
	}
	else{
		return search(root -> right, data);
	}
}

void LinkedList::eliminar(Node*, int llave){
	if (root = NULL){
		return root;
	}
	if (llave < root->data){
		root->left = eliminar(root->left, llave);
		
	}else if(llave > root->data){
		root->right = eliminar(root->right, llave);
	}else{
		if (root->left == NULL){
			Node* temp = root ->right;
			delete root;
			return temp;
			
		} else if (root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
		Node* temp = root->right;
		while (temp->left != NULL){
			temp = temp->left;
		}
		
		root->datos = temp->data;
		root->right = eliminar(root->right, temp->data);
	}
	
	return root;
	
}

void LinkedList::imprimir(Node*, root){
	if (root == NULL){
		return;
	}
	cout << root->data << " ";
	
	imprimir(root->left);
	imprimir(root->right);
}

int main (){
	
	return 0;
}
