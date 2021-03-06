//
// Created by kisung on 15/05/18.
//

#include "SaveJson.h"

//type para el tipo de json que se esta guardando, 0 para usuarios, 1 para musica.
void SaveJson::saveInFile(int type, json json1) {

    std::ofstream file;

    if ( type == 0 ) {
        file.open("../.metadata/users.json", std::ios::binary | std::ios::out);
    } else if ( type == 1 ) {
        file.open("../.metadata/music.json", std::ios::binary | std::ios::out);
    }
    file.clear();
    file << json1;
    file.close();
}

json SaveJson::getInFile(int type) {
    std::ifstream file;

    if ( type == 0 ) {
        file.open("../.metadata/users.json",std::ios::in);
    } else if ( type == 1 ) {
        file.open("../.metadata/music.json",std::ios::in);
    }

    json j = json::parse(file);

    file.close();
    return j;

}
