//
// Created by kisung on 23/02/18.
//

#ifndef NODE_H
#define NODE_H

template <class T> class LLNode {

private:
    T valor;
    LLNode<T> *right;
public:
    LLNode<T>();
    explicit LLNode<T>(T temp);
    void setValor (T temp);
    T getValor ();
    void setRight(LLNode<T> *right);
    LLNode<T> *getRight();

};

#endif //NODE_H
