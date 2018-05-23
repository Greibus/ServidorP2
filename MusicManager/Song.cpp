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

float Song::getRate() const {
    return rate;
}

void Song::setRate(float rate) {
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

int Song::getYear() const {
    return year;
}

void Song::setYear(int year) {
    Song::year = year;
}

