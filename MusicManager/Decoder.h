//
// Created by kisung on 20/05/18.
//

#ifndef SERVIDORP2_DECODER_H
#define SERVIDORP2_DECODER_H

#include <fstream>
#include <mpg123.h>
#include <out123.h>

#define BITS 8

class Decoder {
private:
    int err;
    mpg123_handle *mh = mpg123_new(NULL, &err);
    unsigned char *buffer;
    size_t buffer_size;
    size_t done;
    int channels, encoding;
    long rate;

    std::string name;

public:
    int totalBytes;
    int m_bits;
    long m_rate;
    int m_channels;
    int m_buffer;

    Decoder();
    ~Decoder();

    void decode(std::string name);
    char* getNextPage();
    char* getPage(int byte);

    int getTotalBytes() const;

    int getM_bits() const;

    long getM_rate() const;

    int getM_channels() const;

    int getM_buffer() const;
};


#endif //SERVIDORP2_DECODER_H
