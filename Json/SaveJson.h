//
// Created by kisung on 15/05/18.
//

#ifndef SERVIDORP2_SAVEUSERS_H
#define SERVIDORP2_SAVEUSERS_H

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class SaveJson {

public:
    void saveInFile(int type, json json1);
    json getInFile(int type);
};


#endif //SERVIDORP2_SAVEUSERS_H
