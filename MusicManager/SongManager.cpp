//
// Created by kisung on 22/05/18.
//

#include "SongManager.h"

void SongManager::init() {

}


void SongManager::addNewSong(std::string name) {
    Song *newSong = new Song();
    newSong->setSongName(name);
    songs->addLast(newSong);
}

void SongManager::modifySong(std::string name, std::string type, std::string valor) {
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

void SongManager::rateSong(float rate, std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->getIn(i)->setRate(rate);
        } else {
            //cancion no econtrada;
        }
    }
}

void SongManager::deleteSong(std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->delIn(i);
        } else {
            //cancion no econtrada;
        }
    }
}

void SongManager::getByName() {
    
}

void SongManager::getByAlbum() {

}

void SongManager::getByArtirst() {

}

void SongManager::saveSongs() {

}

void SongManager::drop() {

}

void SongManager::search(std::string) {

}


// funcion para reconstruir cancion que viene del cliente
void SongManager::encoder() {

}
