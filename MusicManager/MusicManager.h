//
// Created by kisung on 22/05/18.
//

#ifndef SERVIDORP2_SONGMANAGER_H
#define SERVIDORP2_SONGMANAGER_H

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

using json = nlohmann::json;

struct index {
    string value;
    int pos;
};

class MusicManager {
private:
    QuickSort nameSort;
    RadixSort artistSort;
    BubbleSort albumSort;

    SaveJson saveJson;

    LinkedList<Song*> *songs = new LinkedList<Song*>();

//    BTree<index> *names = new BTree<index>();
//    AVLTree<index> *artists = new AVLTree<index>();
//    LinkedList<index> *albums = new LinkedList<index>();

public:
    void init();

    void addNewSong(std::string name);
    void modifySong(std::string name, std::string type, std::string valor);
    void rateSong(float rate, std::string name);
    void deleteSong(std::string name);
    void search(std::string, std::string);

    LinkedList<Song*>* getByName();
    LinkedList<Song*>* getByAlbum();
    LinkedList<Song*>* getByArtirst();

    void drop();

    void encoder();

    void saveSongs();

};


#endif //SERVIDORP2_SONGMANAGER_H
