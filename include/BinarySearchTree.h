#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
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
