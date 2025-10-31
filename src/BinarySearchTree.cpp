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

bool BinarySearchTree::search(Node* currentNode, int value){
    if (currentNode == nullptr) return false;

    if (currentNode->value == value) return true;

    if (currentNode->value > value){
        return search(currentNode->left, value);
    } else {
        return search(currentNode->right, value);
    }
}

bool BinarySearchTree::search(int value){
    return search(root, value);
}
