
#include <iostream>
#include <fstream>
#include <vector>
#include "Server/Servidor.h"
#include <rapidxml/rapidxml.hpp>

#include "XML/XmlParser.h"


int main(){

//    XmlParser xmlParser;
//    std::cout<<xmlParser.xmlWrite("hola");

    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

    return 0;

}
