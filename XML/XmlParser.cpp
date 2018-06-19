//
// Created by kisung on 11/06/18.
//

#include "XmlParser.h"

template <typename T> std::string tostr(const T& t) {
    std::ostringstream os;
    os<<t;
    return os.str();
}

std::string XmlParser::xmlWrite(LinkedList<Song *> *list, int low, int high) {
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "SongList");
    doc.append_node(root);

    xml_node<>* bounds = doc.allocate_node(node_element,"Offsets");
    xml_node<>* top = doc.allocate_node(node_element, "Top");
    xml_node<>* bot = doc.allocate_node(node_element, "Bot");
    top->value(std::to_string(high).c_str());
    bot->value(std::to_string(low).c_str());
    bounds->append_node(top);
    bounds->append_node(bot);
    root->append_node(bounds);

    for (int i = 0 ; i < list->getCount() ; i ++){
        Song* actual;

        xml_node<>* child = doc.allocate_node(node_element, "Song");

        xml_node<>* name = doc.allocate_node(node_element, "Name");
        xml_node<>* artist = doc.allocate_node(node_element, "Artist");
        xml_node<>* album = doc.allocate_node(node_element, "Album");
        xml_node<>* genre = doc.allocate_node(node_element, "Genre");
        xml_node<>* rate = doc.allocate_node(node_element, "Rate");
        xml_node<>* year = doc.allocate_node(node_element, "Year");

        actual = list->getIn(i);

        name->value(actual->getSongName().c_str());
        artist->value(actual->getArtist().c_str());
        album->value(actual->getAlbum().c_str());
        genre->value(actual->getGenre().c_str());
        rate->value(tostr(actual->getRate()).c_str());
        year->value(tostr(actual->getYear()).c_str());

        child->append_node(name);
        child->append_node(artist);
        child->append_node(album);
        child->append_node(genre);
        child->append_node(rate);
        child->append_node(year);
        root->append_node(child);
    }

// Convert doc to string if needed
    std::string xml_as_string;
    print(std::back_inserter(xml_as_string), doc, 0);
    return xml_as_string;
}

std::string XmlParser::xmlWrite(LinkedList<Song *> *list) {
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "Search");
    doc.append_node(root);

    for (int i = 0 ; i < list->getCount() ; i ++){
        Song* actual;

        xml_node<>* child = doc.allocate_node(node_element, "Song");

        xml_node<>* name = doc.allocate_node(node_element, "Name");
        xml_node<>* artist = doc.allocate_node(node_element, "Artist");
        xml_node<>* album = doc.allocate_node(node_element, "Album");
        xml_node<>* genre = doc.allocate_node(node_element, "Genre");
        xml_node<>* rate = doc.allocate_node(node_element, "Rate");
        xml_node<>* year = doc.allocate_node(node_element, "Year");

        actual = list->getIn(i);

        name->value(actual->getSongName().c_str());
        artist->value(actual->getArtist().c_str());
        album->value(actual->getAlbum().c_str());
        genre->value(actual->getGenre().c_str());
        rate->value(tostr(actual->getRate()).c_str());
        year->value(tostr(actual->getYear()).c_str());

        child->append_node(name);
        child->append_node(artist);
        child->append_node(album);
        child->append_node(genre);
        child->append_node(rate);
        child->append_node(year);

        root->append_node(child);
    }

// Convert doc to string if needed
    std::string xml_as_string;
    print(std::back_inserter(xml_as_string), doc, 0);
    return xml_as_string;
}

std::string XmlParser::xmlWrite(Song *actual) {
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "Search");
    doc.append_node(root);

    xml_node<>* child = doc.allocate_node(node_element, "Song");

    xml_node<>* name = doc.allocate_node(node_element, "Name");
    xml_node<>* artist = doc.allocate_node(node_element, "Artist");
    xml_node<>* album = doc.allocate_node(node_element, "Album");
    xml_node<>* genre = doc.allocate_node(node_element, "Genre");
    xml_node<>* rate = doc.allocate_node(node_element, "Rate");
    xml_node<>* year = doc.allocate_node(node_element, "Year");

    child->append_node(name);
    child->append_node(artist);
    child->append_node(album);
    child->append_node(genre);
    child->append_node(rate);
    child->append_node(year);
    root->append_node(child);

// Convert doc to string if needed
    std::string xml_as_string;
    print(std::back_inserter(xml_as_string), doc, 0);
    return xml_as_string;
}

std::string XmlParser::xmlWrite(char *buffering, int totalBytes, int bits,
                                long rate, int channels, size_t buffer) {
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "Streaming");
    doc.append_node(root);

    xml_node<>* format = doc.allocate_node(node_element, "Format");

    xml_node<>* totalB = doc.allocate_node(node_element, "TotalBytes");
    xml_node<>* bit = doc.allocate_node(node_element, "Bits");
    xml_node<>* rateN = doc.allocate_node(node_element, "Rate");
    xml_node<>* channel = doc.allocate_node(node_element, "Channels");
    xml_node<>* buff = doc.allocate_node(node_element, "Buffer");

    totalB->value(tostr(totalBytes).c_str(),tostr(totalBytes).size());
//    std::cout<<tostr(totalBytes).c_str()<<std::endl;
    bit->value(tostr(bits).c_str());
    rateN->value(tostr(rate).c_str());
    channel->value(tostr(channels).c_str());
    buff->value(tostr(buffer).c_str());

    format->append_node(totalB);
    format->append_node(bit);
    format->append_node(rateN);
    format->append_node(channel);
    format->append_node(buff);
    root->append_node(format);

    xml_node<>* child = doc.allocate_node(node_element, "Stream");

    xml_node<>* name = doc.allocate_node(node_element, "Name");
    xml_node<>* page = doc.allocate_node(node_cdata, "Page");

    name->value("hola");
//    auto buffered = reinterpret_cast<short*>(buffering);
    page->value(buffering,buffer* sizeof(short));

    child->append_node(name);
    child->append_node(page);

    root->append_node(child);

// Convert doc to string if needed
    std::string xml_as_string;
    print(std::back_inserter(xml_as_string), doc, 0);
    return xml_as_string;
}

std::string XmlParser::xmlWrite(std::string msg) {
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "Message");
    doc.append_node(root);

    xml_node<>* child = doc.allocate_node(node_element, "User");

    child->value(msg.c_str());

    root->append_node(child);

// Convert doc to string if needed
    std::string xml_as_string;
    print(std::back_inserter(xml_as_string), doc, 0);
    return xml_as_string;
}
