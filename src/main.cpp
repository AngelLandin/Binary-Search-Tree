#include <iostream>
#include "../include/BinarySearchTree.h"
using namespace std;


int main()
{
    /*
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);


    //cout << myBST->root->left->right->value << endl;
    
    cout << "Contains 27: " << myBST->search(27) <<endl;
    cout << "Contains 17: " << myBST->search(17) <<endl;
    cout << "Contains 76: " << myBST->search(76) <<endl;

    cout << "Recorrido inorder ";
    myBST->inorder();
    cout << endl;

    cout << "Recorrido preorder ";
    myBST->preorder();
    cout << endl;

    cout << "Recorrido postorder ";
    myBST->postorder();
    cout << endl;

    cout << "---------------------- PRUEBA minVALUE ---------------------- \n";
    cout << "\nMinValue from root:\n";
    cout << myBST->minValue(myBST->root);

    cout << "\n\nMinValue from root->right:\n";
    cout << myBST->minValue(myBST->root->right);
    */

    BinarySearchTree* myBST2 = new BinarySearchTree();
    myBST2->insert(2);
    myBST2->insert(1);
    myBST2->insert(3);

    /*

        2
       / \
      1   3

    */

    cout << "\nBefore Deleting (2) Node:\n";
    cout << "------------------------------";
    cout << "\nRoot: " << myBST2->root->value << endl;
    cout << "Root->Left: " << myBST2->root->left->value << endl;
    cout << "Root->Right: " << myBST2->root->right->value << endl;

    myBST2->removeNode(2);

    /*
        3
       / \
      1   nullptr
    */

    cout << "\n\nAfter Deleting (2) Node:\n";
    cout << "------------------------------";
    cout << "\nRoot: " << myBST2->root->value << endl;
    cout << "Root->Left: " << myBST2->root->left->value << endl;
    cout << "Root->Right: " << myBST2->root->right << endl;
    return 0;
}
