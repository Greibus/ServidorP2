//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_BINARYTREE_H
#define SERVIDORPROYECTO2_BINARYTREE_H

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class BinaryTree {
    /**
     * @brief estructura del nodo con el valor, izquierda y derecha
     */
    typedef struct node {
        node(int valor, node *izquierda, node *derecha);

        int valor;
        node *left = NULL;
        node *right = NULL;

    } nodo;



public:
    nodo *root;
    //Constructor
    BinaryTree() {
        root = NULL;

    }
    stringstream texto;


    /**
     * @brief imprimir, imprime el arbol
     */
    void imprimir() {
        return imprimir(root, 0);
        cout << texto.str()<< endl;
    }


    /**
     * @brief encuentra el valor menor del arbol
     * @return el valor menor
     */
    nodo *encontrarMenor() {
        if (root == NULL)
            return NULL;
        else
            return encontrarMenor(root);
    }

    /**
     * @brief encuentra el valor mayor del arbol
     * @return el valor mayor
     */
    nodo* encontrarMayor() {
        if (root == NULL)
            return NULL;
        else
            return encontrarMayor(root);
    }

    /**
     * @brief inserta un elemento al arbol
     * @param elemento a insertar
     */
    void insertar(int elemento){
        root = insertar(elemento, root);
    }

    /**
     * @brief eliminar un elemento del arbol
     * @param elemento a eliminar
     */
    void eliminar(int elemento) {
        root = eliminar(elemento, root);

    }


private:
    /**
     * @brief imprimir imprime el arbol, funcion auxiliar de imprimir, parte logica
     * @param root en la primer llamada es el root
     * @param contador para ir acomodando el arbol
     */
    void imprimir(nodo * root, int contador){
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

    /**
     * @brief funcion auxiliar de enocotrarMenor, parte logica
     * @param menor , inicia con el root del arbol
     * hasta encontrar el menor
     * @return retorna el elemento menor del arbol
     */
    nodo* encontrarMenor(nodo* menor){
        if (menor == NULL){
            return NULL;
        } else if (menor->left == NULL) {
            return menor;
        } else
            return encontrarMenor(menor->left);
    }

    /**
     * @brief funcion auxiliar de enocotrarMayor, parte logica
     * @param mayor , inicia con el root del arbol
     * hasta encontrar el mayor
     * @return retorna el elemento mayor del arbol
     */
    nodo* encontrarMayor(nodo* mayor) {
        if (mayor == NULL)
            return NULL;
        else if (mayor->right == NULL)
            return mayor;
        else
            return encontrarMayor(mayor->right);
    }

    /**
     * @brief funcion auxiliar de insertar, parte logica
     * @param elemento a insertar
     * @param current primera vez en entrar el root
     * @return el elemento ya insertado en el arbol
     */
    nodo* insertar(int elemento, nodo*current) {
        if (current == NULL) {
            nodo *nuevo = new nodo(elemento, NULL, NULL);
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


    /**
     * @brief funcion auxiliar de eliminar, parte logica
     * @param elemento a eliminar
     * @param current en la primera entrada el root
     * @return el arbol sin el elemento a eliminar si estaba
     */
    nodo* eliminar(int elemento, nodo*current) {
        if (current == NULL) return current;
        if (elemento < current->valor) {
            current->left = eliminar(elemento, current->left);
        } else if (elemento > current->valor) {
            current->right = eliminar(elemento, current->right);
        } else {
            if (current->left != NULL && current->right != NULL){
                nodo *nodoMenor;
                nodoMenor = encontrarMenor(current->right);
                current->valor = nodoMenor->valor;
                current->right = eliminar(current->valor, current->right);
            } else {
                current = current->left != NULL ? current->left : current->right;
            }
        }
    }



};



#endif //SERVIDORPROYECTO2_BINARYTREE_H
