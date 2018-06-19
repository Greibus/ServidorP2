
#include <iostream>
#include <fstream>
#include <vector>
#include "Server/Servidor.h"
#include <rapidxml/rapidxml.hpp>

#include "XML/XmlParser.h"
#include "MusicManager/MusicManager.h"
#include "MusicManager/Song.h"

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

    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

    return 0;

}
