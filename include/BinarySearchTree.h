#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

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
    
    // Firmas de Métodos de la estructura BST
    bool insert(int value);
    bool search(int value);
};

#endif // BINARYSEARCHTREE_H_INCLUDED
