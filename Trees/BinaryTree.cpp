//
// Created by tony on 09/05/18.
//

#include "BinaryTree.h"


template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;

}

template<class T>
void BinaryTree<T>::imprimir() {
    return imprimir(root, 0);
}

template<class T>
node<T> *BinaryTree<T>::encontrarMenor() {
    if (root == NULL)
        return NULL;
    else
        return encontrarMenor(root);
}

template<class T>
node<T> *BinaryTree<T>::encontrarMayor() {
    if (root == NULL)
        return NULL;
    else
        return encontrarMayor(root);
}

template<class T>
void BinaryTree<T>::insertar(T elemento) {
    root = insertar(elemento, root);
}

template<class T>
void BinaryTree<T>::eliminar(T elemento) {
    root = eliminar(elemento, root);
}

template<class T>
void BinaryTree<T>::imprimir(node<T> *root, int contador) {
    if( root == NULL) {
        return;
    } else {
        imprimir(root->right, contador +1);
        for (int i = 0; i < contador; i++) {
            texto << "            ";
        }
        texto<< " | "+to_string(root->valor)+ " | " <<endl;
        imprimir(root->left, contador +1);
    }
}

template<class T>
node<T> *BinaryTree<T>::encontrarMenor(node<T> *menor) {
    if (menor == NULL){
        return NULL;
    } else if (menor->left == NULL) {
        return menor;
    } else
        return encontrarMenor(menor->left);
}

template<class T>
node<T> *BinaryTree<T>::encontrarMayor(node<T> *mayor) {
    if (mayor == NULL)
        return NULL;
    else if (mayor->right == NULL)
        return mayor;
    else
        return encontrarMayor(mayor->right);
}

template<class T>
node<T> *BinaryTree<T>::insertar(T elemento, node<T> *current) {
    if (current == NULL) {
        auto *nuevo = new node<T>(elemento, NULL, NULL);
        return nuevo;
    }
    if (elemento < current->valor){
        current->left = insertar(elemento, current->left);
    } else if (elemento > current->valor) {
        current->right = insertar(elemento, current->right);
    } else {
        return current;
    }
}

template<class T>
node<T> *BinaryTree<T>::eliminar(T elemento, node<T> *current) {
    if (current == NULL) return current;
    if (elemento < current->valor) {
        current->left = eliminar(elemento, current->left);
    } else if (elemento > current->valor) {
        current->right = eliminar(elemento, current->right);
    } else {
        if (current->left != NULL && current->right != NULL){
            node<T> *nodoMenor;
            nodoMenor = encontrarMenor(current->right);
            current->valor = nodoMenor->valor;
            current->right = eliminar(current->valor, current->right);
        } else {
            current = current->left != NULL ? current->left : current->right;
        }
    }
}
