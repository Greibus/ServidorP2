//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_BTREE_H
#define SERVIDORPROYECTO2_BTREE_H

#include "../MusicManager/Song.h"

#define MAX 4
#define MIN 2
#include <iostream>
using namespace std;

template <class T>
struct btreeNode {
    T* val[MAX + 1];
    int count;
    btreeNode *link[MAX + 1];
};

// Revisar y probar el arbol, definir como se va usar para los nombres de las canciones.

template <class T>
class BTree {
public:

    btreeNode<T> *roots;

    btreeNode<T>* createNode(T val, btreeNode<T> *child);
    void addValToNode(T val, int pos, btreeNode<T> *node, btreeNode<T> *child);
    void splitNode(T val, T *pval, int pos,
                   btreeNode<T> *node, btreeNode<T> *child, btreeNode<T> **newNode);
    int setValueInNode(T val, T *pval,btreeNode<T> *node, btreeNode<T> **child);
    void insertion(T val);
    void copySuccessor(btreeNode<T> *myNode, int pos);
    void removeVal(btreeNode<T> *myNode, int pos);
    void doRightShift(btreeNode<T> *myNode, int pos);
    void doLeftShift(btreeNode<T> *myNode, int pos);
    void mergeNodes(btreeNode<T> *myNode, int pos);
    void adjustNode(btreeNode<T> *myNode, int pos);
    int delValFromNode(T val,btreeNode<T> *myNode);
    void deletion(T val,btreeNode<T> *myNode);
    void searching(T val, int *pos, btreeNode<T> *myNode);
//    void traversal(btreeNode<T> *myNode);
};


#endif //SERVIDORPROYECTO2_BTREE_H
