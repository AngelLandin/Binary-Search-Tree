// archivo que implementa los métodos definidos en BinarySearchTree.h
#include "../include/BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    this->root = nullptr;
} //constructor del árbol, inicializa la raíz como nulllptr

bool BinarySearchTree::insert(int value){ //método para insertar un nuevo valor en el árbol
    Node* newNode = new Node(value); //crea un nuevo nodo con el valor del parámetro
    if (this->root == nullptr) { //si la raíz es nula, asigna el nuevo nodo como raíz
        root = newNode;
        return true;
    }
    //si no, recorre el árbol para encontrar la posición correcta del nuevo nodo
    Node* temp = root; //nodo temporal para recorrer el árbol
    while (true){ //bucle infinito que se rompe al insertar el nodo
        if (newNode->value == temp->value) return false; //si el valor ya existe, no se inserta y retorna false

        if (newNode->value < temp->value) {//si el valor es menor, va a la izquierda
            if (temp->left == nullptr){
                temp->left = newNode; // si el hijo izquierdo es nulo, inserta el nuevo nodo aquí
                return true;
            }
            temp = temp->left; //si no, sigue bajando por la izquierda
        } else {
            if (temp->right == nullptr){ //si el valor es mayor, va a la derecha
                temp->right = newNode; // si el hijo derecho es nulo, inserta el nuevo nodo aquí
                return true;
            }
            temp = temp->right; //si no, sigue bajando por la derecha
        }
    }
}

bool BinarySearchTree::search(Node* currentNode, int value){//método recursivo para buscar un valor en el árbol
    if (currentNode == nullptr) return false; //si el nodo actual es nulo, retorna false (no encontrado)

    if (currentNode->value == value) return true; //si el valor del nodo actual es igual al valor buscado, retorna true (encontrado)

    if (currentNode->value > value){ //si el valor buscado es menor, busca en el subárbol izquierdo
        return search(currentNode->left, value); //llamada recursiva al subárbol izquierdo
    } else { //si el valor buscado es mayor, busca en el subárbol derecho
        return search(currentNode->right, value); //llamada recursiva al subárbol derecho
    }
}

bool BinarySearchTree::search(int value){ //método público para buscar un valor, inicia la búsqueda desde la raíz
    return search(root, value); //llama a la función recursiva comenzando desde la raíz
}

void BinarySearchTree::inorder(Node* currentNode){ // recorrido inorder (izquierda, raíz, derecha)
    if (currentNode != nullptr){ //si el nodo actual no es nulo se ejecuta el recorrido
        inorder(currentNode->left); // recorre de forma recursiva el subárbol izquierdo
        std::cout << currentNode->value << " "; //una vez recorrido el nodo izquierdo, se imprime el valor del nodo actual
        inorder(currentNode->right); // finalmente, recorre de forma recursiva el subárbol derecho
    }
}

void BinarySearchTree::inorder(){
    inorder(root); //llama a la función recursiva comenzando desde la raíz, esto cuando no se pasa ningún nodo específico
}

void BinarySearchTree::preorder(Node* currentNode){ // recorrido preorder (raíz, izquierda, derecha)
    if (currentNode != nullptr){ //si el nodo actual no es nulo se ejecuta el recorrido
        std::cout << currentNode->value << " "; //primero se imprime el valor del nodo actual
        preorder(currentNode->left); // luego recorre de forma recursiva el subárbol izquierdo
        preorder(currentNode->right); // finalmente, recorre de forma recursiva el subárbol derecho
    }
}

void BinarySearchTree::preorder(){
    preorder(root); //llama a la función recursiva comenzando desde la raíz, esto cuando no se pasa ningún nodo específico
}

void BinarySearchTree::postorder(Node* currentNode){ // recorrido postorder (izquierda, derecha, raíz)
    if (currentNode != nullptr){ //si el nodo actual no es nulo se ejecuta el recorrido
        postorder(currentNode->left); // recorre de forma recursiva el subárbol izquierdo
        postorder(currentNode->right); // recorre de forma recursiva el subárbol derecho
        std::cout << currentNode->value << " "; // finalmente, se imprime el valor del nodo actual
    }
}

void BinarySearchTree::postorder(){
    postorder(root); //llama a la función recursiva comenzando desde la raíz, esto cuando no se pasa ningún nodo específico
}

BinarySearchTree::Node* BinarySearchTree::removeNode(BinarySearchTree::Node* currentNode, int value) { //método recursivo para eliminar un nodo con un valor específico
    if (currentNode == nullptr) return nullptr; //si el nodo actual es nulo, retorna nulo (valor no encontrado)

    if (value < currentNode->value){ //si el valor a eliminar es menor que el valor del nodo actual, busca en el subárbol izquierdo
        currentNode->left = removeNode(currentNode->left, value); //llamada recursiva al subárbol izquierdo
    } else if (value > currentNode->value){ //si el valor a eliminar es mayor que el valor del nodo actual, busca en el subárbol derecho
        currentNode->right = removeNode(currentNode->right, value); //llamada recursiva al subárbol derecho
    } else { //si el valor del nodo actual es igual al valor a eliminar, se procede a eliminar el nodo
        if (currentNode->left == nullptr && currentNode->right == nullptr){ //caso 1: el nodo es una hoja (sin hijos)
            delete currentNode;
            return nullptr;
        } else if(currentNode->left == nullptr){ //caso 2: el nodo tiene solo un hijo derecho
            Node* temp = currentNode->right; //guarda el hijo derecho en un nodo temporal
            delete currentNode; //elimina el nodo actual
            return temp; //retorna el hijo derecho para que el padre del nodo actual lo enlace directamente
        } else if (currentNode->right == nullptr){ //caso 3: el nodo tiene solo un hijo izquierdo
            Node* temp = currentNode->left; //guarda el hijo izquierdo en un nodo temporal
            delete currentNode; //elimina el nodo actual
            return temp; //retorna el hijo izquierdo para que el padre del nodo actual lo enlace directamente
        } else { //caso 4: el nodo tiene dos hijos
            //encuentra el valor mínimo en el subárbol derecho
            int subTreeMin = minValue(currentNode->right); //llama al método auxiliar para encontrar el valor mínimo
            currentNode->value = subTreeMin; //reemplaza el valor del nodo actual con el valor mínimo encontrado
            //elimina el nodo que tenía el valor mínimo en el subárbol derecho
            currentNode->right = removeNode(currentNode->right, subTreeMin);
        }

    }

    return currentNode; //retorna el nodo actual (posiblemente modificado) para que el padre lo enlace correctamente
}

int BinarySearchTree::minValue(Node* currentNode){ //método auxiliar para encontrar el valor mínimo en un subárbol
    while(currentNode->left != nullptr){ //recorre el subárbol hacia la izquierda hasta encontrar el nodo más a la izquierda
        currentNode = currentNode->left; //actualiza el nodo actual al hijo izquierdo
    }

    return currentNode->value; //retorna el valor del nodo más a la izquierda (valor mínimo)
}

void BinarySearchTree::removeNode(int value){ //método para eliminar un nodo con un valor específico, inicia la eliminación desde la raíz

    root = removeNode(root, value);

}

// Destructor: libera toda la memoria del árbol
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root); //llama al método auxiliar para destruir el árbol comenzando desde la raíz
}

void BinarySearchTree::destroyTree(Node* currentNode) { //método auxiliar para destruir el árbol de forma recursiva
    if (currentNode != nullptr) {//si el nodo actual no es nulo, continúa con la destrucción
        destroyTree(currentNode->left); //destruye el subárbol izquierdo de forma recursiva
        destroyTree(currentNode->right); //destruye el subárbol derecho de forma recursiva
        delete currentNode; //elimina el nodo actual
    }
}

// Display visual del árbol
void BinarySearchTree::display(Node* currentNode, std::string prefix, bool isLeft) {
    if (currentNode != nullptr) { //si el nodo actual no es nulo, continúa con la visualización
        std::cout << prefix; // imprime el prefijo para la estructura del árbol
        std::cout << (isLeft ? "├──" : "└──" ); //determina si es un hijo izquierdo o derecho para la visualización
        std::cout << currentNode->value << std::endl; //imprime el valor del nodo actual

        display(currentNode->left, prefix + (isLeft ? "│   " : "    "), true);//llamada recursiva para el hijo izquierdo, actualizando el prefijo
        display(currentNode->right, prefix + (isLeft ? "│   " : "    "), false); //llamada recursiva para el hijo derecho, actualizando el prefijo
    }
}

void BinarySearchTree::display() {
    if (root == nullptr) { //si la raíz es nula, el árbol está vacío
        std::cout << "(Árbol vacío)" << std::endl;
    } else { //si no, inicia la visualización desde la raíz
        display(root, "", false);
    }
}