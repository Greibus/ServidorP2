//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_AVLTREE_H
#define SERVIDORPROYECTO2_AVLTREE_H


#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

//Probar, se usa para el nombre del artista de la cancion.

using namespace std;

// Node Declaration

template <class T>
struct avlNode
{
    T data;
    struct avlNode<T> *left;
    struct avlNode<T> *right;
};


// Class Declaration

template <class T>
class AVLTree {

public:
    avlNode<T> *root;
    int height(avlNode<T> *);
    int diff(avlNode<T> *);
    avlNode<T> *rrRotation(avlNode<T> *);
    avlNode<T> *llRotation(avlNode<T> *);
    avlNode<T> *lrRotation(avlNode<T> *);
    avlNode<T> *rlRotation(avlNode<T> *);
    avlNode<T> *balance(avlNode<T> *);
    avlNode<T> *insert(avlNode<T> *, T );
    void display(avlNode<T> *, T);
    void inorder(avlNode<T> *);
    void preorder(avlNode<T> *);
    void postorder(avlNode<T> *);
    AVLTree() {
        root = NULL;
    }
};

#endif //SERVIDORPROYECTO2_AVLTREE_H
