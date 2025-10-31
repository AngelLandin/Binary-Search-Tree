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
    



    // 🌱 Crear el árbol dinámicamente
    BinarySearchTree* bst = new BinarySearchTree();

    std::cout << "=== INSERTANDO NODOS ===" << std::endl;
    bst->insert(8);
    bst->insert(3);
    bst->insert(10);
    bst->insert(1);
    bst->insert(6);
    bst->insert(14);
    bst->insert(4);
    bst->insert(7);
    bst->insert(13);

    std::cout << "\n=== DISPLAY DEL ÁRBOL ===" << std::endl;
    bst->display();

    std::cout << "\n=== RECORRIDOS ===" << std::endl;
    std::cout << "Inorder: "; bst->inorder(); std::cout << std::endl;
    std::cout << "Preorder: "; bst->preorder(); std::cout << std::endl;
    std::cout << "Postorder: "; bst->postorder(); std::cout << std::endl;

    std::cout << "\n=== BUSQUEDA ===" << std::endl;
    std::cout << "Buscar 6: " << (bst->search(6) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscar 15: " << (bst->search(15) ? "Encontrado" : "No encontrado") << std::endl;

    std::cout << "\n=== ELIMINACIONES ===" << std::endl;
    bst->removeNode(1);   // eliminar hoja
    bst->removeNode(6);   // eliminar nodo con dos hijos
    bst->removeNode(10);  // eliminar nodo con un hijo

    std::cout << "\nÁrbol después de eliminar 1, 6 y 10:" << std::endl;
    bst->display();

    std::cout << "\nInorder final: ";
    bst->inorder();
    std::cout << std::endl;

    std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;

    // 💣 Liberar memoria manualmente
    delete bst;
    return 0;
}
