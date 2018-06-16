
#include <stdio.h>

#include <huffmandecoder.h>



int main()
{
    string str = "geeks for geeks";
    string encodedString, decodedString;

    HuffmanDecoder huffDecoder;


    huffDecoder.calcFreq(str, str.length());
    huffDecoder.HuffmanCodes(str.length());
    cout << "Character With their Frequencies:\n";
    for (auto v=huffDecoder.codes.begin(); v!=huffDecoder.codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;

    for (auto i: str)
        encodedString+=huffDecoder.codes[i];

    cout << "\nEncoded Huffman data:\n" << encodedString << endl;

    decodedString = huffDecoder.decode_file(huffDecoder.minHeap.top(), encodedString);
    cout << "\nDecoded Huffman Data:\n" << decodedString << endl;



    return 0;
}
