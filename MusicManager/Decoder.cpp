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
    }
}

Decoder::~Decoder() {
    free(buffer);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
}
