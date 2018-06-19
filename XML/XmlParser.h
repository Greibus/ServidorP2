//
// Created by kisung on 11/06/18.
//

#ifndef SERVIDORP2_XMLPARSER_H
#define SERVIDORP2_XMLPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <cstring>
#include "../Trees/LinkedList.h"
#include "../MusicManager/Song.h"

//#include "../PugiXML/pugixml.hpp"

using namespace rapidxml;

class XmlParser {
public:

    std::string xmlWrite(LinkedList<Song*> *list, int low, int high);
    std::string xmlWrite(LinkedList<Song*> *list);
    std::string xmlWrite(Song*);
    std::string xmlWrite(char*, int totalBytes, int bits, long rate, int channels, size_t buffer);
    std::string xmlWrite(std::string);
};


#endif //SERVIDORP2_XMLPARSER_H
