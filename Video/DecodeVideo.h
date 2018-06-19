//
// Created by kisung on 18/06/18.
//

#ifndef SERVIDORP2_DECODEVIDEO_H
#define SERVIDORP2_DECODEVIDEO_H

#include <string>
#include <cppcodec/base64_default_rfc4648.hpp>
#include <vector>
#include <iostream>
#include <fstream>

using base64 = cppcodec::base64_rfc4648;

class DecodeVideo {
public:
    base64 base;

    void decode(std::string b64file, std::string name);
};


#endif //SERVIDORP2_DECODEVIDEO_H
