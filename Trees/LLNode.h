//
// Created by kisung on 23/02/18.
//

#ifndef LLNODE_H
#define LLNODE_H

#include "../MusicManager/Song.h"

template <class T> class LLNode {

private:
    T valor = nullptr;
    LLNode<T> *right = nullptr;
public:
    LLNode<T>();
    explicit LLNode<T>(T temp);
    void setValor (T temp);
    T getValor ();
    void setRight(LLNode<T> *right);
    LLNode<T> *getRight();

};

#endif //NODE_H
