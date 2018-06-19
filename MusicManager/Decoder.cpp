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

    bits = mpg123_encsize(encoding) * BITS;
}

char *Decoder::getNextPage() {

    if(mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
        auto buffertf = reinterpret_cast<char *>(buffer);
//        short *tst = reinterpret_cast<short *>(buffer);

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

    if (mpg123_seek_frame(mh,byte/mpg123_outblock(mh),SEEK_SET)>= 0) {

        mpg123_read(mh, buffer, buffer_size, 0);
        auto *buffertf = reinterpret_cast<char *>(buffer);
        return buffertf;
//        short *tst = reinterpret_cast<short *>(buffer);

    }
}
