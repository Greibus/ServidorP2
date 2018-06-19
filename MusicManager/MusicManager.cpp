//
// Created by kisung on 22/05/18.
//

#include "MusicManager.h"

template <typename T> std::string tostr(const T& t) {
    std::ostringstream os;
    os<<t;
    return os.str();
}

void MusicManager::init() {
    int counter = 0;
    json json1 = saveJson.getInFile(1);
    for (int i = 0; i< json1.size(); i++) {
        json songjson = json1[i];
        std::string name = songjson["name"];
        std::string path = songjson["path"];
        std::string genre = songjson["genre"];
        int rate = songjson["rate"];
        int year = songjson["year"];
        std::string album = songjson["album"];
        std::string artist = songjson["artist"];
        std::string lyric = songjson["lyric"];
        Song *newSong = new Song(name);
        newSong->setPath(path);
        newSong->setGenre(genre);
        newSong->setRate(rate);
        newSong->setYear(year);
        newSong->setAlbum(album);
        newSong->setArtist(artist);
        newSong->setLyrics(lyric);
        songs->addLast(newSong);
        counter++;
    }
    songs->setCount(counter);
    makeTree();
}


std::string MusicManager::addNewSong(std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {
        if (songs->getIn(i)->getSongName() == name) {
            return "false";
        }
    }
    Song *newSong = new Song(name);
    newSong->setPath("../Musica/"+name+".mp3");
    songs->addLast(newSong);
    saveSongs();
    makeTree();
    return "true";
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
    saveSongs();
    makeTree();
}

void MusicManager::rateSong(int rate, std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->getIn(i)->setRate(rate);
        } else {
            //cancion no econtrada;
        }
    }
    saveSongs();
    makeTree();
}

void MusicManager::deleteSong(std::string name) {
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            songs->delIn(i);
        } else {
            //cancion no econtrada;
        }
    }
    m.delSong(name);
    makeTree();
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
    artistSort.quickSortA(temp,0,songs->getCount()-1);
    return temp;
}

void MusicManager::saveSongs() {
    Song* song;
//    json array;
    for (int i = 0; i<songs->getCount(); i++){
//        json json1;
        song = songs->getIn(i);
//        json1["name"] = songs->getIn(i)->getSongName();
//        json1["artist"] = songs->getIn(i)->getArtist();
//        json1["album"] = songs->getIn(i)->getAlbum();
//        json1["path"] = songs->getIn(i)->getPath();
//        json1["genre"] = songs->getIn(i)->getGenre();
//        json1["year"] = songs->getIn(i)->getYear();
//        json1["rate"] = songs->getIn(i)->getRate();
//        json1["lyric"] = songs->getIn(i)->getLyrics();
//        array.push_back(json1);
        if (m.searchSong(song->getSongName()).size() == 0) {
            m.addSong(song->getAlbum(), song->getArtist(), song->getGenre(), song->getLyrics(),
                      song->getSongName(), song->getPath(), tostr(song->getRate()), tostr(song->getYear()));
        }
    }
//    saveJson.saveInFile(1,array);
}

Song* MusicManager::search(std::string type, std::string value) {
    if (type == "name") {
        for (int co = 0; co < names->getCount(); co++) {
            if (names->getIn(co)->getAlbum() == value) {
                return names->getIn(co);
            }
        }
    } else if (type == "artist"){
        for (int co = 0; co < artists->getCount(); co++) {
            if (artists->getIn(co)->getAlbum() == value) {
                return artists->getIn(co);
            }
        }
    } else if (type == "album") {
        for (int co = 0; co < albums->getCount(); co++) {
            if (albums->getIn(co)->getAlbum() == value) {
                return albums->getIn(co);
            }
        }
    }
}

// funcion para reconstruir cancion que viene del cliente
std::string MusicManager::encoder(std::string b64file, std::string name) {
    if (addNewSong(name) == "true"){
        std::vector<uint8_t> bytes = base.decode(b64file.c_str(), b64file.length());
        std::ofstream file("../Musica/" + name + ".mp3", std::ios::binary);
        file.write(reinterpret_cast<char*> (&bytes[0]), bytes.size() * sizeof(bytes[0]));
        file.close();
        return "true";
    } else {
        return "false";
    }
}

// Esta funcion es para llamar a una cancion en memoria para ser decodificada
// y luego usarse para el paginado. Solo se una vez por cancion.
void MusicManager::getSong(std::string name) {
    delete decoder;
    decoder = new Decoder();
    for (int i = 0; i < songs->getCount(); i++ ) {

        if (songs->getIn(i)->getSongName() == name) {
            decoder = new Decoder();
            decoder->decode(songs->getIn(i)->getPath());
            playingSong = songs->getIn(i);
            totalBytes = decoder->totalBytes;
            m_bits = decoder->bits;
            m_rate = decoder->rate;
            m_channels = decoder->channels;
            m_buffer = decoder->buffer_size;

        } else {
            //cancion no econtrada;
        }
    }

}

char *MusicManager::getPage() {
    return decoder->getNextPage();
}

char *MusicManager::getPage(int pos) {
    return nullptr;
}

void MusicManager::makeTree() {
    delete names;
    delete artists;
    delete albums;

    names = new LinkedList<Song*>();
    artists = new LinkedList<Song*>();
    albums = new LinkedList<Song*>();

    for (int j = 0; j < songs->getCount() ; j++){
        names->addLast(songs->getIn(j));
        artists->addLast(songs->getIn(j));
        albums->addLast(songs->getIn(j));
    }
}
