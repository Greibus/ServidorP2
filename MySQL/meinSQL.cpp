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
