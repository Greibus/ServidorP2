//
// Created by kisung on 20/05/18.
//

#ifndef SERVIDORP2_SONGNODE_H
#define SERVIDORP2_SONGNODE_H

#include <string>

class Song {
private:
    std::string songName;
    std::string artist;
    std::string album;
    std::string lyrics;
    std::string path;
    std::string genre;
    int rate = 0;
    int year = 0;

public:
    explicit Song (std::string name);

    explicit Song (std::string name, std::string artist, std::string album, std::string genre,
                   std::string path, int year);

    int getYear() const;

    void setYear(int year);

    const std::string &getGenre() const;

    void setGenre(const std::string &genre);

    const std::string &getPath() const;

    void setPath(const std::string &path);

    float getRate() const;

    void setRate(float rate);

    const std::string &getSongName() const;

    void setSongName(const std::string &songName);

    const std::string &getArtist() const;

    void setArtist(const std::string &artist);

    const std::string &getAlbum() const;

    void setAlbum(const std::string &album);

    const std::string &getLyrics() const;

    void setLyrics(const std::string &lyrics);
};


#endif //SERVIDORP2_SONGNODE_H
