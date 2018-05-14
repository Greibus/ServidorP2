//
// Created by tony on 13/05/18.
//

#include "NodeUser.h"


template<class T>
NodeUser<T>::NodeUser( T &user, T &name, T &age, T &genders, T &password,  T & friends):
        user(user), name(name), age(age), genders(genders), password(password), friends(friends),  ptrNext(0)
{

}



template<class T>
void NodeUser<T>::setName(T name) {
    this->name = name;
}

template<class T>
T NodeUser<T>::getName() {
    return name;
}
template<class T>
void NodeUser<T>::setAge(T age) {
    this->age = age;
}

template<class T>
T NodeUser<T>::getAge() {
    return age;
}

template<class T>
void NodeUser<T>::setUser(T user) {
    this->user = user;
}

template<class T>
T NodeUser<T>::getUser() {
    return user;
}

template<class T>
void NodeUser<T>::setFriends(T friends) {
    this->friends = friends;
}

template<class T>
T NodeUser<T>::getFriends() {
    return friends;
}
template<class T>
void NodeUser<T>::setGenders(T genders) {
    this->genders = genders;
}

template<class T>
T NodeUser<T>::getGenders() {
    return genders;
}

template<class T>
void NodeUser<T>::setPassword(T password) {
    this->password = password;
}

template<class T>
T NodeUser<T>::getPassword() {
    return password;
}


