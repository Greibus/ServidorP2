//
// Created by tony on 13/05/18.
//

#ifndef SERVIDORP2_NODEUSER_H
#define SERVIDORP2_NODEUSER_H


template <class T> class NodeUser {

private:
    T user;
    T name;
    T age;
    T genders;
    T password;
    T friends;
    NodeUser<T> *ptrNext;
public:
    NodeUser (T &, T &, T &, T &, T &,  T &);
    void setUser(T user);
    T getUser();
    void setName(T name);
    T getName();
    void setAge(T age);
    T getAge();
    void setGenders(T gender);
    T getGenders();
    void setPassword(T password);
    T getPassword();
    void setFriends(T friends);
    T getFriends();





};

#endif //SERVIDORP2_NODEUSER_H
