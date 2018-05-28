//
// Created by kisung on 22/05/18.
//

#ifndef SERVIDORP2_SONGMANAGER_H
#define SERVIDORP2_SONGMANAGER_H

#include <cppcodec/base32_rfc4648.hpp>
#include "../Trees/BTree.h"
#include "../Trees/AVLTree.h"
#include "../Sort/BubbleSort.h"
#include "../Sort/QuickSort.h"
#include "../Sort/RadixSort.h"
#include "../Trees/LinkedList.h"
#include "Song.h"
#include <nlohmann/json.hpp>
#include <string>
#include "../Json/SaveJson.h"
#include "Decoder.h"

using json = nlohmann::json;
using base64 = cppcodec::base32_rfc4648;

struct index {
    string value;
    int pos;
};

class MusicManager {
private:
    QuickSort nameSort;
    RadixSort artistSort;
    BubbleSort albumSort;

    Decoder *decoder;

    base64 base;
    SaveJson saveJson;
    LinkedList<Song*> *songs = new LinkedList<Song*>();

//    BTree<index> *names = new BTree<index>();
//    AVLTree<index> *artists = new AVLTree<index>();
//    LinkedList<index> *albums = new LinkedList<index>();

public:
    Song *playingSong;

    void init();

    void addNewSong(std::string name);
    void modifySong(std::string name, std::string type, std::string valor);
    void rateSong(float rate, std::string name);
    void deleteSong(std::string name);
    void search(std::string, std::string);

    LinkedList<Song*>* getByName();
    LinkedList<Song*>* getByAlbum();
    LinkedList<Song*>* getByArtirst();

    void getSong(std::string name);

    void encoder(std::string b64file, std::string name);

    void saveSongs();

    char* getPage();

    char* getPage(int pos);

    char* getNextPage();

};


#endif //SERVIDORP2_SONGMANAGER_H
