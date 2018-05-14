//
// Created by tony on 13/05/18.
//

#ifndef SERVIDORP2_LINKEDLISTUSER_H
#define SERVIDORP2_LINKEDLISTUSER_H


#include <sys/user.h>
#include "NodeUser.cpp"
#include "../json.hpp"
using nlohmann::json;

template <class T>
class LinkedListUser {
private:
    NodeUser<T> *first;
    int cont = 0;

public:
    void addLast(T user, T name, T lastName, T age, T genders, T password, T friends);
    void addIn(int pos, T num);
    void delLast();
    void delIn(int pos);
    T getIn(int pos);
    int getCount();
    json ToJson();
    bool isEmpty();



};


#endif //SERVIDORP2_LINKEDLISTUSER_H
