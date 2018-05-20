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
    int totalBytes;

public:
    explicit Decoder(std::string);

};


#endif //SERVIDORP2_DECODER_H
