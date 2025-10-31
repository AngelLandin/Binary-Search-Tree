#include "../include/BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

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

void BinarySearchTree::inorder(Node* currentNode){
    if (currentNode != nullptr){
        inorder(currentNode->left);
        std::cout << currentNode->value << " ";
        inorder(currentNode->right);
    }
}

void BinarySearchTree::inorder(){
    inorder(root);
}

void BinarySearchTree::preorder(Node* currentNode){
    if (currentNode != nullptr){
        std::cout << currentNode->value << " ";
        preorder(currentNode->left);
        preorder(currentNode->right);
    }
}

void BinarySearchTree::preorder(){
    preorder(root);
}

void BinarySearchTree::postorder(Node* currentNode){
    if (currentNode != nullptr){
        postorder(currentNode->left);
        postorder(currentNode->right);
        std::cout << currentNode->value << " ";
    }
}

void BinarySearchTree::postorder(){
    postorder(root);
}

BinarySearchTree::Node* BinarySearchTree::removeNode(BinarySearchTree::Node* currentNode, int value) {
    if (currentNode == nullptr) return nullptr;

    if (value < currentNode->value){
        currentNode->left = removeNode(currentNode->left, value);
    } else if (value > currentNode->value){
        currentNode->right = removeNode(currentNode->right, value);
    } else {
        if (currentNode->left == nullptr && currentNode->right == nullptr){
            delete currentNode;
            return nullptr;
        } else if(currentNode->left == nullptr){
            Node* temp = currentNode->right;
            delete currentNode;
            return temp;
        } else if (currentNode->right == nullptr){
            Node* temp = currentNode->left;
            delete currentNode;
            return temp;
        } else {
            int subTreeMin = minValue(currentNode->right);
            currentNode->value = subTreeMin;
            currentNode->right = removeNode(currentNode->right, subTreeMin);
        }

    }

    return currentNode;
}

int BinarySearchTree::minValue(Node* currentNode){
    while(currentNode->left != nullptr){
        currentNode = currentNode->left;
    }

    return currentNode->value;
}

void BinarySearchTree::removeNode(int value){

    root = removeNode(root, value);

}

// Destructor: libera toda la memoria del árbol
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(Node* currentNode) {
    if (currentNode != nullptr) {
        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }
}

// Display visual del árbol
void BinarySearchTree::display(Node* currentNode, std::string prefix, bool isLeft) {
    if (currentNode != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << currentNode->value << std::endl;

        display(currentNode->left, prefix + (isLeft ? "│   " : "    "), true);
        display(currentNode->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void BinarySearchTree::display() {
    if (root == nullptr) {
        std::cout << "(Árbol vacío)" << std::endl;
    } else {
        display(root, "", false);
    }
}