
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
#include "MySQL/meinSQL.h"

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

//    XmlParser xmlParser;
//
//    MusicManager *musicManager = new MusicManager();
//    musicManager->init();
//
//    musicManager->getSong("The House Of The Rising Sun");
//
//    short *ln = reinterpret_cast<short *>(musicManager->getPage());
//
//    string hola = xmlParser.xmlWrite(musicManager->getPage(),musicManager->totalBytes,musicManager->m_bits,
//                                     musicManager->m_rate,musicManager->m_channels,musicManager->m_buffer);
//
//    std::cout<< xmlParser.xmlWrite(musicManager->getByName()) << endl;
//
//    xml_document<> doc;
//    char* cstr = new char[hola.size() + 1];  // Create char buffer to store string copy
//    strcpy (cstr, hola.c_str());             // Copy string into char buffer
//    doc.parse<0>(cstr);

//    std::cout << doc.first_node()->first_node()->first_node()->next_sibling()->value();

    std::cout << "Iniciando Servidor" << std::endl;
    Servidor servidor = Servidor();
    servidor.iniciar();

//    meinSQL m;

//    m.addSong("Odisea","Ozuna","Reggaeton","Quiero Repetir...","Quiero Repetir","home","20/10","2017");
//    m.addSong("Unica", "Ozuna", "Reggaeton", "Ella es unica...", "Unica", "home","20/10","2018");
//    m.addSong("Golden", "Romeao Santos", "Reggaeton", "Bella y sensual, sobre natural...","Bella y Sensual", "home", "10/10", "2017");

//    m.addUser("Reggaeton","20","Jung","123","bakkim");
//    m.addUser("Rock","20","Ian", "abc","cobjim");
//    m.addUser("Reggaeton","20","Esteban","zxc","acastillon");
//    m.addUser("Reggaeton","20", "Roberto","robrob", "robthebob");

    //m.addAmigos("BEELZEBUB", "BELIAL");
//    m.delAmigo("BELIAL","BEELZEBUB");
//    m.modSong("Unica", "album", "Unica");
//    m.modSong("Quiero Repetir", "rate", "20/20");

//    m.delSong("Quiero Repetir");
//    m.delUser("bakkim");


    //cout << m.searchLetra("sens");
    //cout << m.searchSong("Quiero Repetir")[0];

    //cout << m.searchUser("bakkim")[1];

//    cout << m.recommendFriend("bakkim");
//    vector<string> ha = m.searchSong("Quiero Repetir");
//
//    cout<< ha.size();
//    m.modUser("robthebob","generoFavorito","Reggaeton");
//    m.modUser("acastillon","generoFavorito", "Reggaeton");


    return 0;
}
