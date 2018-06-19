#include "meinSQL.h"

meinSQL::meinSQL()
{
    driver = get_driver_instance();
    con = driver->connect(url,user,pass);
    con->setSchema(database);
}

void meinSQL::addAmigos(string nombreAmigo, string nombreUsuario)
{
    string start = "INSERT INTO amigos(nombreAmigo,nombreUsuario) VALUES(";
    string a = "\'";
    string b = ",";
    string c = ")";

    stmt= con->createStatement();
    stmt->execute(start+a+nombreAmigo+a+b+a+nombreUsuario+a+c);

}

void meinSQL::addSong(string album, string artist, string genre, string lyric, string nombreCancion, string path,
                      string rate, string fecha)
{
    string start = "INSERT INTO libreria(album, artist, genre, lyric, nombreCancion, path, rate, fecha) VALUES(";
    string a = "\'";    //      '
    string b = ",";     //      ,       coma
    string c = ")";     //      )

//    cout << start+a+album+a+b+a+artist+a+b+a+genre+a+b+a+lyric+a+b+a+nombreCancion+a+b+a+path+a+b+a+rate+a+b+a+fecha+a+b+c << endl;
    stmt= con->createStatement();
    stmt->execute(start+a+album+a+b+a+artist+a+b+a+genre+a+b+a+lyric+a+b+a+nombreCancion+a+b+a+path+a+b+a+rate+a+b+a+fecha+a+c);

}

void meinSQL::addUser(string generoFavorito, string age, string nombreUsuario, string contrasena, string usuario)
{
    string start = "INSERT INTO usuario(generoFavorito, age, nombreUsuario, contrasena, usuario) VALUES(";
    string a = "\'";    //      '
    string b = ",";     //      ,       coma
    string c = ")";     //      )

    stmt=con->createStatement();
    stmt->execute(start+a+generoFavorito+a+b+a+age+a+b+a+nombreUsuario+a+b+a+contrasena+a+b+a+usuario+a+c);
}

void meinSQL::modSong(string nombreCancion, string editar, string nuevoValor)
{
    string a = "\'";    //      '

    stmt=con->createStatement();
    stmt->execute("UPDATE libreria SET " + editar + '=' + a+nuevoValor+a + " WHERE nombreCancion = "+ a+nombreCancion+a);
}

void meinSQL::modUser(string usuario, string editar, string nuevoValor)
{
    string a = "\'";    //      '

    stmt=con->createStatement();
    stmt->execute("UPDATE usuario SET " + editar + '=' + a+nuevoValor+a + " WHERE usuario = "+ a+usuario+a);
}

void meinSQL::delSong(string nombreCancion)
{
    string a = "\'";    //      '
    stmt=con->createStatement();
    stmt->execute("DELETE FROM libreria WHERE nombreCancion=" + a+nombreCancion+a);

}

void meinSQL::delUser(string usuario)
{
    string a = "\'";    //      '
    stmt=con->createStatement();
    stmt->execute("DELETE FROM usuario WHERE usuario=" + a+usuario+a);
}

void meinSQL::delAmigo(string usuario, string amigo)
{
    string a = "\'";    //      '
    stmt=con->createStatement();
    stmt->execute("DELETE FROM amigos WHERE nombreUsuario=" + a+usuario+a + "AND nombreAmigo=" + a+amigo+a);
}

string meinSQL::searchLetra(string parteLetra)
{
    stmt=con->createStatement();

    res = stmt->executeQuery("SELECT * FROM libreria WHERE lyric LIKE '%"+parteLetra+"%'");

    while (res->next()) {
        return res->getString("lyric");
    }
    //return res->getString("lyric");
}

vector <string> meinSQL::searchSong(string nombreCancion)
{
    vector <string> result;
    //string result[8];
    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT * FROM libreria WHERE nombreCancion LIKE '%"+nombreCancion+"%'");

    while (res->next()) {
        int i = 1;
        while (i <= 7)
        {
            result.push_back(res->getString(i));

            i++;
        }
    }

    return result;
}

vector <string> meinSQL::searchUser(string usuario)
{
    vector <string> result;
    stmt = con->createStatement();


    res = stmt->executeQuery("SELECT * FROM usuario WHERE usuario LIKE '%"+usuario+"%'");
    while (res->next()) {
        int i = 1;
        while (i <= 5)
        {
            result.push_back(res->getString(i));

            i++;
        }
    }

    return result;
}

string meinSQL::recommendFriend(string usuario)
{
    string compare = searchUser(usuario)[0];

    vector <string> result;
    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT * FROM usuario WHERE generoFavorito = '" + compare + "'");

    while (res->next())
    {
        if (usuario != res->getString("usuario").asStdString())
        {
            result.push_back(res->getString("usuario"));
        }
    }

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, result.size()-1); // define the range

    return result[distr(eng)];

}

vector <string> meinSQL::listUser()
{
    vector <string> result;
    stmt = con->createStatement();


    res = stmt->executeQuery("SELECT * FROM usuario");
    while (res->next())
    {
        result.push_back(res->getString(5));

    }

    return result;
}

vector <string> meinSQL::listSong()
{
    vector <string> result;
    stmt = con->createStatement();


    res = stmt->executeQuery("SELECT * FROM libreria");
    while (res->next())
    {
        result.push_back(res->getString("nombreCancion"));

    }

    return result;
}