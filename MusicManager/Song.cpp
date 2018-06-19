//
// Created by kisung on 20/05/18.
//

#include "Song.h"

const std::string &Song::getSongName() const {
    return songName;
}

void Song::setSongName(const std::string &songName) {
    Song::songName = songName;
}

const std::string &Song::getArtist() const {
    return artist;
}

void Song::setArtist(const std::string &artist) {
    Song::artist = artist;
}

const std::string &Song::getAlbum() const {
    return album;
}

void Song::setAlbum(const std::string &album) {
    Song::album = album;
}

const std::string &Song::getLyrics() const {
    return lyrics;
}

void Song::setLyrics(const std::string &lyrics) {
    Song::lyrics = lyrics;
}

const std::string &Song::getRate() const {
    return rate;
}

void Song::setRate(const std::string &rate) {
    Song::rate = rate;
}

const std::string &Song::getPath() const {
    return path;
}

void Song::setPath(const std::string &path) {
    Song::path = path;
}

const std::string &Song::getGenre() const {
    return genre;
}

void Song::setGenre(const std::string &genre) {
    Song::genre = genre;
}

const std::string &Song::getYear() const {
    return year;
}

void Song::setYear( std::string year) {
    Song::year = year;
}

Song::Song(std::string name) {
    this->songName = name;
}

Song::Song(std::string name, std::string artist, std::string album, std::string genre,
           std::string path, std::string year) {
    this->songName = name;
    this->artist = artist;
    this->album = album;
    this->genre = genre;
    this->path = path;
    this->year = year;
}
