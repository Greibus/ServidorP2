//
// Created by kisung on 20/05/18.
//

#include "Decoder.h"

Decoder::Decoder() {
    mpg123_init();
    buffer_size = mpg123_outblock(mh) * 8;
    buffer = (unsigned char *) malloc(buffer_size * sizeof(unsigned char)) ;
}

void Decoder::decode(std::string name) {
    mpg123_open(mh, name.c_str());
    mpg123_getformat(mh, &rate, &channels, &encoding);

    totalBytes = static_cast<int>(mpg123_length(mh) * 4);
    m_bits = mpg123_encsize(encoding) * BITS;
    m_rate = rate;
    m_channels = channels;
    m_buffer = static_cast<int>(buffer_size);
}

char *Decoder::getNextPage() {
    char *buffertf;

//    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
    if(mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
        buffertf = reinterpret_cast<char *>(buffer);
//        short *tst = reinterpret_cast<short *>(buffer);
//        std::cout << *tst << std::endl;
//        std::cout << totalBytes << std::endl;
        return buffertf;
    } else {
        return "false";
    }
}

Decoder::~Decoder() {
    free(buffer);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
}

char *Decoder::getPage(int byte) {
    char *buffertf;

//    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
//    if(mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
//        buffertf = reinterpret_cast<char *>(buffer);
//        short *tst = reinterpret_cast<short *>(buffer);
//        std::cout << *tst << std::endl;
//        std::cout << totalBytes << std::endl;
//        return buffertf;
//    }

    if (mpg123_seek_frame(mh,byte/mpg123_outblock(mh),SEEK_SET)>= 0) {

//    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
        mpg123_read(mh, buffer, buffer_size, 0);
        char *buffertf = reinterpret_cast<char *>(buffer);
        return buffertf;
//        short *tst = reinterpret_cast<short *>(buffer);

    }
}

int Decoder::getTotalBytes() const {
    return totalBytes;
}

int Decoder::getM_bits() const {
    return m_bits;
}

long Decoder::getM_rate() const {
    return m_rate;
}

int Decoder::getM_channels() const {
    return m_channels;
}

int Decoder::getM_buffer() const {
    return m_buffer;
}
