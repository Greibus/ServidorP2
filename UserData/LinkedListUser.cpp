//
// Created by tony on 13/05/18.
//
#include <iostream>
#include "LinkedListUser.h"
#include "../json.hpp"



using nlohmann::json;
using namespace std;



template<class T>
void LinkedListUser<T>::addLast(T user, T name,T lastName, T age, T genders, T password, T friends) {
    NodeUser<T> *nodeTempPtr = new NodeUser<T>(user, name, lastName, age , genders, password, friends);
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

template<class T>
bool LinkedListUser<T>::search(T user) {
    if (isEmpty()){
        return  false;
    } else {
        NodeUser<T> *head = first;
        while(head->ptrNext != nullptr){
            if (head->getUser() == user){
                return true;
            }else {
                head = head->ptrNext;
            }

        }
        return false;

    }
}

template <class T>
void LinkedListUser<T>::delUser(T user){
    if (isEmpty()){
        cout << "No se encontro usuario" << endl;
    } else {
        NodeUser<T> *head = first;
        while(head->ptrNext != nullptr){
            if (head->ptrNext->getUser() != user){
                head = head->ptrNext;
            }else {
                NodeUser<T> *sigSig = head->ptrNext->ptrNext;
                delete head->ptrNext;
                head->ptrNext = sigSig;
                cout << "Usuario eliminado" << endl;

            }

        }
        cout << "Usuario no encontrado" << endl;

    }
}


template <class T>
bool LinkedListUser<T>::isEmpty()  {
    if (first == nullptr) {
        return true;
    } else {
        return false;
    }

}




template <class T>
json LinkedListUser <T>::toJson() {
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
