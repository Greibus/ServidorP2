//
// Created by kisung on 20/05/18.
//

#include "Decoder.h"

Decoder::Decoder(std::string musica) {
    mpg123_init();
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*)malloc(buffer_size * sizeof(unsigned char));

    mpg123_open(mh, musica.c_str());

    mpg123_getformat(mh, &rate, &channels, &encoding);

    int doneN = 0;

    //    int driver;
//    ao_device *dev;
//
//    ao_sample_format format;
//
//    ao_initialize();
//    driver = ao_default_driver_id();

//    std::cout<< mpg123_framelength(mh) << std::endl;
//
//    format.bits = mpg123_encsize(encoding) * BITS;
//    format.rate = rate;
//    format.channels = channels;
//    format.byte_format = AO_FMT_NATIVE;
//    format.matrix = 0;
//    dev = ao_open_live(driver, &format, NULL);

    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
//        char *buffertf = reinterpret_cast<char *>(buffer);
//        short *tst = reinterpret_cast<short *>(buffer);
//        std::cout << *tst << std::endl;
        doneN = done;
        totalBytes += done;
//        std::cout << totalBytes << std::endl;
//        ao_play(dev, buffertf, done);
    }

//    std::cout << doneN<< std::endl;
//    std::cout << totalBytes<< std::endl;
//    std::ofstream out("../Musica/res.txt", std::ios::binary);
//    unsigned int counter = 0;
//
//    for (int totalBtyes = 0; mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK; ) {
//        short* tst = reinterpret_cast<short*>(buffer);
//        for (auto i = 0; i < buffer_size / 2; i++) {
//            out<< counter + i<<"\t"<< tst[i] << "\n";
//        }
//        counter += buffer_size/2;
//        totalBtyes += done;
//    }

    free(buffer);
//    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
//    ao_shutdown();
}