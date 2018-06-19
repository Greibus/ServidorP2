//
// Created by rex on 17/06/18.
//

#ifndef DBTRIALS_MEIN_H
#define DBTRIALS_MEIN_H

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <random>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;


class meinSQL
{
public:

    const string url="127.0.0.1:3306";
    const string user="root";
    const string pass="jkljkl";
    const string database="odysseyDB";

    sql::Driver *driver;
    sql::Connection *con;
    sql::ResultSet *res;
    sql::Statement *stmt;

    meinSQL();

    void addAmigos(string nombreAmigo, string nombreUsuario);
    void addSong(string album, string artist, string genre, string lyric, string nombreCancion, string path, string rate, string fecha);
    void addUser(string generoFavorito, string age, string nombreUsuario, string contrasena, string usuario);
    void modSong(string nombreCancion, string editar, string nuevoValor);
    void modUser(string usuario, string editar, string nuevoValor);

    void delSong(string nombreCancion);
    void delUser(string usuario);
    void delAmigo(string usuario, string amigo);

    string searchLetra(string parteLetra);
    vector <string> searchSong(string nombreCancion);
    vector <string> searchUser(string usuario);

    vector <string> listUser();
    vector <string> listSong();

    string recommendFriend(string usuario);


};






#endif //DBTRIALS_MEIN_H
