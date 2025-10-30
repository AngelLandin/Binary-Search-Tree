#include "../include/BinarySearchTree.h"


BinarySearchTree::BinarySearchTree(){
    this->root = nullptr;
}

bool BinarySearchTree::insert(int value){
    Node* newNode = new Node(value);
    if (this->root == nullptr) {
        root = newNode;
        return true;
    }

    Node* temp = root;

    while (true){
        if (newNode->value == temp->value) return false;

        if (newNode->value < temp->value) {
            if (temp->left == nullptr){
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr){
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::search(int value){
    // Verificamos si el arbol esta vacio; Si lo esta, retornamos false, indicando que no existe el valor.
    //if (root == nullptr) return false;

    // Creamos un Nodo temporal, para ir recorriendo el arbol sin modificar la estructura original
    Node* temp = root;

    // Bucle while 
    while (temp != nullptr){
        if (value < temp->value){
            temp = temp->left;
        } else if (value > temp->value){
            temp = temp->right;
        } else {
            return true;
        }
    }

    return false;
}
