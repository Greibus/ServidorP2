//
// Created by tony on 13/05/18.
//

#ifndef SERVIDORP2_LINKEDLISTUSER_H
#define SERVIDORP2_LINKEDLISTUSER_H


#include <sys/user.h>
#include "NodeUser.cpp"
//#include "../json.hpp"
#include <nlohmann/json.hpp>
using nlohmann::json;
using namespace std;

template <class T>
class LinkedListUser {
private:
    NodeUser<T> *first = nullptr;
    int cont = 0;

public:
    void addLast(T user, T name, T lastName, T age, T genders, T password, T friends);
    bool search(T user);
    bool verifyPass(T user, T password);
    void delUser(T user);
    void delIn(int pos);
    json toJson();
    bool isEmpty();

};


#endif //SERVIDORP2_LINKEDLISTUSER_H
