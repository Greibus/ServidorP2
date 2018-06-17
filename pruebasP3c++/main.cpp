
#include <stdio.h>

#include <huffmandecoder.h>



int main()
{
    string str = "<Message><jsonMsg> this is an example for huffman encoding </jsonMsg> </Message>";
    string encodedString, decodedString;

    HuffmanDecoder huffDecoder;

    cout<< "to encode: " << str << endl;


    // transforma string a codigo huffman
    encodedString = huffDecoder.Encode(str);


    // tranforma codigo huffman a string
    decodedString = huffDecoder.Decode(encodedString);





    cout << "\nEncoded Huffman data:\n" << encodedString << endl;
    cout << "\nDecoded Huffman Data:\n" << decodedString << endl;



    return 0;
}
