//
// Created by kisung on 19/06/18.
//

#include "DecodeVideo.h"
//
// Created by kisung on 18/06/18.
//

#include "DecodeVideo.h"

void DecodeVideo::decode(std::string b64file, std::string name) {
//    if (addNewSong(name) == "true"){
    std::vector<uint8_t> bytes = base.decode(b64file.c_str(), b64file.length());
    std::ofstream file("../Vid/" + name + ".mp4", std::ios::binary);
    file.write(reinterpret_cast<char*> (&bytes[0]), bytes.size() * sizeof(bytes[0]));
    file.close();
//        return "true";
//    } else {
//        return "false";
//    }
} 