//
// Created by tony on 13/05/18.
//

#include "LinkedListUser.h"
#include <iostream>
#include <jmorecfg.h>
#include "../json.hpp"


using nlohmann::json;
using namespace std;



template<class T>
void LinkedListUser<T>::addLast(T user, T name, T age, T genders, T password, T friends) {
    NodeUser<T> *nodeTempPtr = new NodeUser<T>(user, name, age , genders, password, friends);
    nodeTempPtr->ptrNext = nullptr;
    if (isEmpty()) {
        first = nodeTempPtr;
    } else {
        NodeUser<T> *head = first;
        while(head->ptrNext != nullptr){
            head = head->ptrNext;
        }
        head->ptrNext = nodeTempPtr;
    }
}






template <typename T>
bool LinkedListUser<T>::isEmpty()  {
    if (first == nullptr) {
        return true;
    } else {
        return false;
    }

}




template <typename T>
json LinkedListUser <T>::ToJson(){
    string name, user,age, friends, password, genders;


    struct nodo {
        string user;
        string name;
        string age ;
        string genders;
        string password;
        string friends;
    };



    NodeUser<T> *temp = first;
    json userJ;
    json nameJ;
    json ageJ;
    json gendersJ;
    json passwordJ;
    json friendsJ;
    json total;
    json lista;



    while (temp != nullptr){
        name = temp->getName();
        user = temp->getUser();
        age = temp->getAge();
        friends = temp->getFriends();
        password = temp->getPassword();
        genders = temp->getGenders();


        lista["user"] = temp->getUser();
        lista["name"] = temp->getName();
        lista["age"] = temp->getAge();
        lista["Genders"] = temp->getGenders();
        lista["password"] = temp->getPassword();
        lista["friends"] = temp->getFriends();



        total.push_back(lista);



        temp = temp->ptrNext;


    }

    return total;
}
