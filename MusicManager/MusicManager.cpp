//
// Created by kisung on 22/05/18.
//

#include "MusicManager.h"

void MusicManager::init() {

}


void MusicManager::addNewSong(std::string name) {
    Song *newSong = new Song(name);
    songs->addLast(newSong);
}

void MusicManager::modifySong(std::string name, std::string type, std::string valor) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            if (type == "artist") {
                songs->getIn(i)->setArtist(valor);
            } else if (type == "album") {
                songs->getIn(i)->setAlbum(valor);
            } else if (type == "lyric") {
                songs->getIn(i)->setLyrics(valor);
            } else if (type == "name") {
                songs->getIn(i)->setSongName(valor);
            } else if (type == "year") {
                songs->getIn(i)->setYear(stoi(valor));
            } else if (type == "genre") {
                songs->getIn(i)->setGenre(valor);
            }
        } else {
            //cancion no econtrada;
        }
    }
}

void MusicManager::rateSong(float rate, std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->getIn(i)->setRate(rate);
        } else {
            //cancion no econtrada;
        }
    }
}

void MusicManager::deleteSong(std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->delIn(i);
        } else {
            //cancion no econtrada;
        }
    }
}

LinkedList<Song*>* MusicManager::getByName() {
    LinkedList<Song*> *temp = songs;
    nameSort.quickSort(temp,0,songs->getCount()-1);
    return temp;
}

LinkedList<Song*>* MusicManager::getByAlbum() {
    LinkedList<Song*> *temp = songs;
    albumSort.bubbleSort(temp,songs->getCount());
    return temp;
}

LinkedList<Song*>* MusicManager::getByArtirst() {
    LinkedList<Song*> *temp = songs;

    return temp;
}

void MusicManager::saveSongs() {
    json array;
    for (int i = 0; i<songs->getCount(); i++){
        json json1;
        json1["name"] = songs->getIn(i)->getSongName();
        json1["artist"] = songs->getIn(i)->getArtist();
        json1["album"] = songs->getIn(i)->getAlbum();
        json1["path"] = songs->getIn(i)->getPath();
        json1["genre"] = songs->getIn(i)->getGenre();
        json1["year"] = songs->getIn(i)->getYear();
        json1["rate"] = songs->getIn(i)->getRate();
        json1["lyric"] = songs->getIn(i)->getLyrics();
        array.push_back(json1);
    }
    saveJson.saveInFile(0,array);
}

void MusicManager::drop() {

}

void MusicManager::search(std::string type, std::string name) {
    if (type == "name") {

    } else if (type == "artist"){

    } else if (type == "album") {

    }
}

// funcion para reconstruir cancion que viene del cliente
void MusicManager::encoder() {

}
