//
// Created by kisung on 23/02/18.
//

#include "LLNode.h"

template<class T>
LLNode<T>::LLNode() {
    valor = nullptr;
    right = nullptr;
}

template<class T>
LLNode<T>::LLNode(T valor) {
    this->valor = valor;
}

template<class T>
void LLNode<T>::setValor(T valor) {
    this->valor = valor;
}

template<class T>
T LLNode<T>::getValor() {
    return valor;
}

template<class T>
void LLNode<T>::setRight(LLNode<T> *right) {
    this->right = right;
}

template<class T>
LLNode<T> *LLNode<T>::getRight() {
    return right;
}

template class LLNode<Song*>;
template class LLNode<std::string>;