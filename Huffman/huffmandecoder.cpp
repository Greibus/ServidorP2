#include "huffmandecoder.h"

HuffmanDecoder::HuffmanDecoder()
{

}

bool a = true;

// utility function to store map each character with its
// frequency in input string
void HuffmanDecoder::calcFreq(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}



// function to build the Huffman tree and store it
// in minHeap
void HuffmanDecoder::HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}



// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void HuffmanDecoder::storeCodes(struct MinHeapNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}



// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string HuffmanDecoder::decode_file(struct MinHeapNode* root, string s)
{
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;

        // reached leaf node
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    //cout<<ans<<endl;
    return ans+'\0';
}




// utility function to print characters along with
// their huffman value
void HuffmanDecoder::printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}




string HuffmanDecoder::Encode(string toEncode)
{

    freq.clear();

    codes.clear();

    string encodedString;

    // calcula frecuencias de cada caracter y crea el hashmap de frecuencias
    calcFreq(toEncode, toEncode.length());


    // calcula el hashmap con los codigos huffman de cada caracter
    HuffmanCodes(toEncode.length());


    for (auto i: toEncode)
        encodedString+=codes[i];


    return encodedString;
}



string HuffmanDecoder::Decode(string toDecode)
{
    if (!a){
        /*string decodedString;

    decodedString = decode_file(minHeap.top(), toDecode);

    return decodedString;*/


        string output = "";
        string tempStr = "";


        cout<<"to decode : " << toDecode << endl;

        if(!codes.empty()){

            for(char& c : toDecode) {

                tempStr += c;



                for ( auto it = codes.begin(); it != codes.end(); ++it  )
                {

                    if(tempStr.compare(it->second) == 0)
                    {

                        output += it->first;
                        tempStr ="";
                    }

                    //std::cout << it->first << '\t' << it->second << std::endl;
                }

            }
            return output;
        }
    }


}

void HuffmanDecoder::xmlToCodes(string xmlString)
{
    codes.clear();

    xml_document doc;


    doc.load_string(xmlString.c_str());

    xml_node msg = doc.child("message");

    for (pugi::xml_node character: msg.children())
    {
        //cout << child.name()<<" elemento: " << child.child("key").value() << ", " << child.child("code").value()<< endl;
        cout<< "key: " <<character.child("key").child_value() << endl;
        cout<< "code: " <<character.child("code").child_value() << endl;


        string key = string(character.child("key").child_value()).c_str();
        string code = string(character.child("code").child_value());

        if (key == "_"){
            codes.insert(std::pair<char, string>(' ', code));
        } else {
            codes.insert( std::pair<char, string>(key.at(0), code));
        }









        for ( auto it = codes.begin(); it != codes.end(); ++it  )
        {
           std::cout << it->first << '\t' << it->second << std::endl;
        }
    }



}


string HuffmanDecoder::codesToXml()
{

}

string HuffmanDecoder::datareload(int a){
    if (a == 1){
        string b = "011000000101111100111110111111010000000110110111010110001111110101010010001011000101011110001001110111101111000011110000110011101011011010100110001000110101101011110000111110110011010000111100111101100001001111101001111110111010101001111010111001000010111111011001111001110110111100000011110011100010011011100011010111001100110111100011110101111110110010001101011100110011011110001111111101001101111010101001001011010100100000001111011110000011111010001000110111101101111011010010100100100010011001111101111010101001001000110010011010101011111000011110111000001010011000011011100001100011010110110110101001100001101110000100000111111101100000001111100111011011110000001111001110001001101110001101011100110011011110001111010111111";
        return b;
    } else if (a == 2){
        string b = "<?xml version=1.0 encoding=UTF-8 standalone=no?><message><character><key>A</key><code>11111010</code></character><character><key>F</key><code>011010</code></character><character><key>G</key><code>0001000</code></character><character><key>N</key><code>0001001</code></character><character><key>P</key><code>0001100</code></character><character><key>T</key><code>0001101</code></character><character><key>U</key><code>10001</code></character><character><key>V</key><code>1111001</code></character><character><key>_</key><code>0100</code></character><character><key>a</key><code>1001</code></character><character><key>\"</key><code>001</code></character><character><key>c</key><code>111000</code></character><character><key>d</key><code>10000</code></character><character><key>e</key><code>1101</code></character><character><key>f</key><code>000011</code></character><character><key>g</key><code>011011</code></character><character><key>i</key><code>1100</code></character><character><key>l</key><code>1111010</code></character><character><key>-</key><code>11110000</code></character><character><key>m</key><code>1111011</code></character><character><key>.</key><code>0001010</code></character><character><key>n</key><code>11101</code></character><character><key>/</key><code>000001</code></character><character><key>o</key><code>0111</code></character><character><key>0</key><code>11110001</code></character><character><key>1</key><code>0001011</code></character><character><key>r</key><code>1011</code></character><character><key>s</key><code>1010</code></character><character><key>t</key><code>000111</code></character><character><key>u</key><code>111001</code></character><character><key>v</key><code>000000</code></character><character><key>w</key><code>11111000</code></character><character><key>x</key><code>11111001</code></character><character><key>8</key><code>11111011</code></character><character><key>&lt;</key><code>01100</code></character><character><key>=</key><code>0101</code></character><character><key>&gt;</key><code>111111</code></character><character><key>?</key><code>000010</code></character></message>";
        return b;
    } else if (a == 3 ){
        string b = "  18  000\n"
                   "n  10  0010\n"
                   "u  5  00110\n"
                   "p  2  001110\n"
                   "v  3  001111\n"
                   "t  5  01000\n"
                   "g  5  01001\n"
                   "m  5  01010\n"
                   "=  3  010110\n"
                   "f  3  010111\n"
                   "r  12  0110\n"
                   "\"  6  01110\n"
                   "/  7  01111\n"
                   "e  26  100\n"
                   "a  14  1010\n"
                   "o  7  10110\n"
                   "_  3  101110\n"
                   "2  1  10111100\n"
                   "F  1  10111101\n"
                   "-  1  10111110\n"
                   "0  1  10111111\n"
                   "<  15  1100\n"
                   ">  15  1101\n"
                   "d  4  111000\n"
                   "l  2  1110010\n"
                   "G  2  1110011\n"
                   "1  2  1110100\n"
                   "?  2  1110101\n"
                   "3  1  11101100\n"
                   "T  1  11101101\n"
                   "c  2  1110111\n"
                   "q  2  1111000\n"
                   "U  2  1111001\n"
                   "8  1  11110100\n"
                   "V  1  11110101\n"
                   "x  1  11110110\n"
                   ".  1  11110111\n"
                   "i  9  11111";
        return b;
    }
}
