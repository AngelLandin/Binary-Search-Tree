#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree { // Definición de la clase BinarySearchTree
private:
    struct Node { // Definición de la estructura Node (nodo del árbol) es privada
        int value; // valor del nodo
        Node* left; // hijo izquierdo
        Node* right; // hijo derecho

        Node(int value){ // constructor del nodo
            this->value = value; // asigna el valor al nodo
            this->left = nullptr; // inicializa el hijo izquierdo como nulo
            this->right = nullptr; // inicializa el hijo derecho como nulo
        }
    };


public:
    // Nodo principal (root)
    Node* root;

    // Constructor
    BinarySearchTree();

    // Destructor
    ~BinarySearchTree();  

    
    // Firmas de Métodos de la estructura BST
    bool insert(int value);

    bool search(Node* currentNode, int value);
    bool search(int value);

    void inorder(Node* currentNode);
    void inorder();
    void preorder(Node* currentNode);
    void preorder();
    void postorder(Node* currentNode);
    void postorder();

    Node* removeNode(Node* currentNode, int value);
    void removeNode(int value);


    //Metodo auxiliar para encontrar el valor minimo en el arbol
    int minValue(Node* currentNode);

    void display();

    void destroyTree(Node* currentNode);
    void display(Node* currentNode, string prefix, bool isLeft);


};

#endif // BINARYSEARCHTREE_H_INCLUDED
