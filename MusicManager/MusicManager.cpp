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

void MusicManager::getByName() {
    
}

void MusicManager::getByAlbum() {

}

void MusicManager::getByArtirst() {

}

void MusicManager::saveSongs() {

}

void MusicManager::drop() {

}

void MusicManager::search(std::string) {

}


// funcion para reconstruir cancion que viene del cliente
void MusicManager::encoder() {

}
