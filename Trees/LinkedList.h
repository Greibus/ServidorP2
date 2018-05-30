//
// Created by kisung on 24/02/18.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LLNode.h"
#include "../MusicManager/Song.h"

// Usado para el nombre de lo albumes en las cancion, ordenado y buscado con binary search.

template <class T>
class LinkedList {
private:
    LLNode<T> *first = nullptr;
    int counter = 0;

public:
    /**
     * @brief Constructor de la clase.
     */
    LinkedList<T>();
    /**
     *
     * @param num
     * @brief Recibe un valor T para insertar en la lista de primero.
     *
     */
    void setFirst(T num);
    /**
     *
     * @return
     * @brief Retorna el primero valor insertado.
     */
    T getFirst();
    /**
     *
     * @param num
     * @brief Recibe un valor T para insertar en la lista de ultimo.
     */
    void addLast(T num);
    /**
     *
     * @param num
     * @brief Recibe un valor T para insertar de primero.
     *
     */
    void addFirst(T num);
    /**
     *
     * @param pos
     * Parametro de posicion con respecto de la lista.
     * @param num
     * @brief Valor T a insertar en el indice.
     */
    void addIn(int pos, T num);
    /**
     * @brief Esta funcion eliminar el ultmo dato de la lista.
     */
    void delLast();
    /**
     * @brief Esta funcion eliminar el primer dato de la lista.
     */
    void delFirst();
    /**
     *
     * @param pos
     * @brief Elimina por posicion.
     */
    void delIn(int pos);
    /**
     *
     * @param pos
     * Recibeo una posicion en la lista.
     * @return
     * @brief Retorna el valor en posicion del entero dado.
     */
    T getIn(int pos);
    /**
     *
     * @return
     * @brief Retorna la cantidad de valores en la lista.
     */
    int getCount();
    /**
     *
     * @param pos
     * @param num
     * @brief Recibe el valor para modificar en la lista.
     */
    void editIn(int pos, T num);

    void setCount(int counter);
};

#endif //LINKEDLIST_H
