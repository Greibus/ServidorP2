//
// Created by kisung on 24/02/18.
//

#include "LinkedList.h"


template<class T>
LinkedList<T>::LinkedList() {
    first = new LLNode<T>();
}


template<class T>
void LinkedList<T>::setFirst(T num) {
    first ->setValor(num);
    counter += 1;
}

template<class T>
T LinkedList<T>::getFirst() {
    return first->getValor();
}

template<class T>
void LinkedList<T>::addLast(T num) {
    if (counter==0){
        first ->setValor(num);
        counter += 1;
    } else {
        LLNode<T> *head = first;
        for (int i=1; i<counter;i++) {
            head = head->getRight();
        }
        head ->setRight(new LLNode<T>(num));
        head = new LLNode<int>();
        delete head;
        counter += 1;
    }
}

template<class T>
void LinkedList<T>::addFirst(T num) {
    LLNode<T> *temp = new LLNode<T>(num);
    temp ->setRight(first);
    first = temp;
    temp = new LLNode<int>();
    delete temp;
    counter += 1;
}

template<class T>
void LinkedList<T>::addIn(int pos, T num) {
    if (pos==0){
        LLNode<T> *temp = new LLNode<T>(num);
        temp ->setRight(this->first);
        first = temp;
        temp = new LLNode<T>();
        delete temp;
        counter += 1;
    } else {
        LLNode<T> *head = first;
        LLNode<T> *temp = new LLNode<T>(num);
        for (int i=0; i<(pos-1);i++) {
            head = head->getRight();
        }
        temp->setRight(head->getRight());
        head ->setRight(temp);
        temp = new LLNode<T>();
        head = new LLNode<T>();
        delete temp;
        delete head;
        counter += 1;
    }
}

template<class T>
void LinkedList<T>::delLast() {
    if (counter == 0) {
        return;
    } else {
        LLNode<T> *head = first;
        for (int i = 1; i < counter; i++) {
            head = head->getRight();
        }
        delete head->getRight();
        head->setRight(nullptr);
        head = new LLNode<T>();
        delete head;
        counter -= 1;
    }
}

template<class T>
void LinkedList<T>::delFirst() {
    if (counter == 0) {
        return;
    } else {
        LLNode<T> *head = first->getRight();
        first = new LLNode<int>();
        delete first;
        first = new LLNode<int>();
        first = head;
        head = new LLNode<int>();
        delete head;
        counter -= 1;
    }
}

template<class T>
void LinkedList<T>::delIn(int pos) {
    if (counter == 0){
        return;
    } else {
        if (pos==0){
            LLNode<T> *head = first;
            first = first->getRight();
            delete head;
            counter -= 1;
        } else {
            LLNode<T> *head = first;
            for (int i = 0; i < (pos - 1); i++) {
                head = head->getRight();
            }
            LLNode<T> *temp = head->getRight()->getRight();
            delete head->getRight();
            head->setRight(temp);
            temp = new LLNode<T>();
            head = new LLNode<T>();
            delete temp;
            delete head;
            counter -= 1;
        }
    }
}

template<class T>
T LinkedList<T>::getIn(int pos) {
    if (pos>=counter) {
        return 0;
    } else if (pos==0){
        return first->getValor();
    } else {
        LLNode<T> *head = first;
        for (int i = 0; i < pos; i++) {
            head = head->getRight();
        }
        return head->getValor();
    }
}

template<class T>
int LinkedList<T>::getCount() {
    return counter;
}

template<class T>
void LinkedList<T>::editIn(int pos,T num) {
    if (pos>=counter) {
        int n = 0;
    } else if (pos==0){
        first->setValor(num);
    } else {
        LLNode<T> *head = first;
        for (int i = 0; i < pos; i++) {
            head = head->getRight();
        }
        head->setValor(num);
    }
}