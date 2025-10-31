#include <iostream>
#include "../include/BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    myBST->insert(27);

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
    return 0;
}
