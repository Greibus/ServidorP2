//
// Created by kisung on 28/05/18.
//

#include "Hash.h"

std::string Hash::hash(std::string code) {
    long size = code.length();
    std::string hashed;
    for (int i = 0; i < size ; i+=2){
        hashed += code[i];
    }
    for (int i = 1; i < size ; i+=2){
        hashed += code[i];
    }
    return hashed;
}
