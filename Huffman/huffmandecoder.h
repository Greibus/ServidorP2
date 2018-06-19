#ifndef HUFFMANDECODER_H
#define HUFFMANDECODER_H

#include <bits/stdc++.h>
#include <stdio.h>

#include "pugixml.hpp"


using namespace std;

using namespace pugi;



// A Huffman tree node
struct MinHeapNode
{
    char data;             // One of the input characters
    int freq;             // Frequency of the character
    MinHeapNode *left, *right; // Left and right child

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};




// utility function for the priority queue
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};




class HuffmanDecoder
{
public:

    // mapea cada caracter con su valor huffman
    map<char, string> codes;

    //guarda la frecuencia de cada caracter
    map<char, int> freq;

    // STL priority queue to store heap tree, with respect
    // to their heap root node value
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;




    HuffmanDecoder();

    void calcFreq(string str, int n);

    void HuffmanCodes(int size);

    void storeCodes(struct MinHeapNode* root, string str);

    string decode_file(struct MinHeapNode* root, string s);

    void printCodes(struct MinHeapNode* root, string str);


    string Encode(string toEncode);

    string Decode(string toDecode);

    string datareload(int a);


    void xmlToCodes(string xmlString);

    string codesToXml();

};







#endif // HUFFMANDECODER_H
