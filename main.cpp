
#include <iostream>
#include <fstream>
#include <vector>
#include "Server/Servidor.h"
#include "UserData/LinkedListUser.cpp"
#include "../../rapidxml/rapidxml.hpp"


using namespace std;

int main(){


    LinkedListUser<string> listaUser;
    std::cout << "Iniciando Servidor" << std::endl;
    listaUser.addLast("asd", "asd", "asd", "sda", "asd", "asd", "asd");
    listaUser.addLast("asd", "asd", "asd", "sda", "asd", "asd", "asd");
    listaUser.search("asd");
    listaUser.delUser("asd");
    listaUser.isEmpty();
    //Servidor servidor = Servidor();
    //servidor.iniciar();
    return 0;

}
