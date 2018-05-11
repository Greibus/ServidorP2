//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_BINARYTREE_H
#define SERVIDORPROYECTO2_BINARYTREE_H

#include <iostream>
#include <cstdlib>
#include <sstream>

//Revisar y probar, uso para poner los usuarios.

using namespace std;

template <class T>
struct node {
//        node(T valor, node *izquierda, node *derecha){
//            this->valor = valor;
//            this->left = izquierda;
//            this->right = derecha;
//        };
    T valor;
    node<T> *left = NULL;
    node<T> *right = NULL;

};

template <class T>
class BinaryTree {
    /**
     * @brief estructura del nodo con el valor, izquierda y derecha
     */

private:

    node<T> *root;
    stringstream texto;

    /**
     * @brief imprimir imprime el arbol, funcion auxiliar de imprimir, parte logica
     * @param root en la primer llamada es el root
     * @param contador para ir acomodando el arbol
     */
    void imprimir(node<T> * root, int contador);

    /**
     * @brief funcion auxiliar de enocotrarMenor, parte logica
     * @param menor , inicia con el root del arbol
     * hasta encontrar el menor
     * @return retorna el elemento menor del arbol
     */
    node<T>* encontrarMenor(node<T>* menor);

    /**
     * @brief funcion auxiliar de enocotrarMayor, parte logica
     * @param mayor , inicia con el root del arbol
     * hasta encontrar el mayor
     * @return retorna el elemento mayor del arbol
     */
    node<T>* encontrarMayor(node<T>* mayor);

    /**
     * @brief funcion auxiliar de insertar, parte logica
     * @param elemento a insertar
     * @param current primera vez en entrar el root
     * @return el elemento ya insertado en el arbol
     */
    node<T>* insertar(T elemento, node<T>*current);


    /**
     * @brief funcion auxiliar de eliminar, parte logica
     * @param elemento a eliminar
     * @param current en la primera entrada el root
     * @return el arbol sin el elemento a eliminar si estaba
     */
    node<T>* eliminar(T elemento, node<T>*current);

public:
    //Constructor
    BinaryTree();

    /**
     * @brief imprimir, imprime el arbol
     */
    void imprimir();


    /**
     * @brief encuentra el valor menor del arbol
     * @return el valor menor
     */
    node<T> *encontrarMenor();

    /**
     * @brief encuentra el valor mayor del arbol
     * @return el valor mayor
     */
    node<T>* encontrarMayor();

    /**
     * @brief inserta un elemento al arbol
     * @param elemento a insertar
     */
    void insertar(T elemento);

    /**
     * @brief eliminar un elemento del arbol
     * @param elemento a eliminar
     */
    void eliminar(T elemento);
};

#endif //SERVIDORPROYECTO2_BINARYTREE_H
