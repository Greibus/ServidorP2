
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Server/Servidor.h"
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>

#include "XML/XmlParser.h"
#include "MusicManager/MusicManager.h"
#include "MusicManager/Song.h"
#include "UserData/Hash.h"

using namespace std;
using namespace rapidxml;

int main(){

//    Song *song = new Song("Calea");
//    song->setArtist("Madonna");
//    song->setAlbum("loquillos");
//    song->setGenre("Rock");
//    song->setYear(1999);
//    song->setRate(1.2);
//
//    XmlParser xmlParser;
//    std::cout<<xmlParser.xmlWrite(song) << std::endl;
//
//    MusicManager *musicManager = new MusicManager();
//    musicManager->init();
//    std::cout<<xmlParser.xmlWrite(musicManager->getByName()) << std::endl;
//
//    musicManager->getSong("The House Of The Rising Sun");
//    std::cout<<xmlParser.xmlWrite(musicManager->getPage(),0,0,0,0,0);

//    std::cout << "Iniciando Servidor" << std::endl;
//    Servidor servidor = Servidor();
//    servidor.iniciar();
//    XmlParser xmlParser;
//
//    MusicManager *musicManager = new MusicManager();
//    musicManager->init();
////    string hola =xmlParser.xmlWrite(musicManager->getByName());
//
//    musicManager->getSong("The House Of The Rising Sun");
//
//    short *ln = reinterpret_cast<short *>(musicManager->getPage());
//
//    string hola = xmlParser.xmlWrite(musicManager->getPage(),musicManager->totalBytes,musicManager->m_bits,
//                                     musicManager->m_rate,musicManager->m_channels,musicManager->m_buffer);
//
//    std::cout<< hola << endl;

//    xml_document<> doc;
//    char* cstr = new char[hola.size() + 1];  // Create char buffer to store string copy
//    strcpy (cstr, hola.c_str());             // Copy string into char buffer
//    doc.parse<0>(cstr);

//    std::cout << doc.first_node()->first_node()->first_node()->next_sibling()->value();

    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

    return 0;
}
