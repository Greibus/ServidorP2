//
// Created by kisung on 22/05/18.
//

#ifndef SERVIDORP2_SONGMANAGER_H
#define SERVIDORP2_SONGMANAGER_H

#include <cppcodec/base64_default_rfc4648.hpp>
#include "../Trees/BTree.h"
#include "../Trees/AVLTree.h"
#include "../Sort/BubbleSort.h"
#include "../Sort/QuickSort.h"
#include "../Sort/RadixSort.h"
#include "../Sort/QuickSortA.h"
#include "../Trees/LinkedList.h"
#include "Song.h"
#include <nlohmann/json.hpp>
#include <string>
#include "../Json/SaveJson.h"
#include "Decoder.h"
#include "../MusicManager/MusicManager.h"
#include "../MySQL/meinSQL.h"

using json = nlohmann::json;
using base64 = cppcodec::base64_rfc4648;

class MusicManager {
private:
    QuickSort nameSort;
    QuickSortA artistSort;
    BubbleSort albumSort;

    meinSQL m;

    Decoder *decoder = nullptr;

    base64 base;
    SaveJson saveJson;
    LinkedList<Song*> *songs = new LinkedList<Song*>();

//    BTree<Song*> *names2 = new BTree<Song*>();
//    AVLTree<Song*> *artists2 = new AVLTree<Song*>();

    LinkedList<Song*> *names = new LinkedList<Song*>();
    LinkedList<Song*> *artists = new LinkedList<Song*>();
    LinkedList<Song*> *albums = new LinkedList<Song*>();

    void makeTree();

    Song *playingSong = nullptr;

public:
    int totalBytes;
    int m_bits;
    long m_rate;
    int m_channels;
    size_t m_buffer;

    void init();

    std::string addNewSong(std::string name);
    void modifySong(std::string name, std::string type, std::string valor);
    void rateSong(std::string rate, std::string name);
    void deleteSong(std::string name);
    Song *search(std::string, std::string);

    LinkedList<Song*>* getByName();
    LinkedList<Song*>* getByAlbum();
    LinkedList<Song*>* getByArtirst();

    void getSong(std::string name);

    void encoder(std::string b64file, std::string name);

    void saveSongs();

    char* getPage();

    char* getPage(int pos);
};


#endif //SERVIDORP2_SONGMANAGER_H
