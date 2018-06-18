#include "huffmandecoder.h"

HuffmanDecoder::HuffmanDecoder()
{

}



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
