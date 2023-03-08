#include <cstring>
#include <iostream>
#include <string>
#include "include/huffman.h"


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [-c|-d] <filename>\n";
        return 1;
    }
    Huffman huffman;
    if (std::strcmp(argv[1], "-c") == 0) {
        std::cout<<argv[2]<<std::endl;
    // Encode the input file
        huffman.encode(argv[2], "encoded.bin");
    }
    if (std::strcmp(argv[1], "-d") == 0) {
        std::cout<<argv[2]<<std::endl;
        // Decode the encoded file
        huffman.decode(argv[2], "decoded.txt");
    }
    return 0;
}


