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
#include "../Trees/LinkedList.cpp"
#include "Song.h"
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class SongManager {
private:
    QuickSort nameSort;
    RadixSort artistSort;
    BubbleSort albumSort;

    LinkedList<Song*> *songs = new LinkedList<Song*>();

    BTree<std::string> *names = new BTree<std::string>();
    AVLTree<std::string> *artists = new AVLTree<std::string>();
    LinkedList<std::string> *albums = new LinkedList<std::string>();

public:
    void init();

    void addNewSong(std::string name);
    void modifySong(std::string name, std::string type, std::string valor);
    void rateSong(float rate, std::string name);
    void deleteSong(std::string name);
    void search(std::string);

    void getByName();
    void getByAlbum();
    void getByArtirst();
    void drop();

    void encoder();

    void saveSongs();

};


#endif //SERVIDORP2_SONGMANAGER_H
