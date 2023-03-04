#include <iostream>
#include "include/huffman.h"

int main() {
    // Encode a file
    std::string input_file_path = "../test/input.txt";
    std::string encoded_file_path = "../test/encoded.bin";
    Huffman huffman;
    huffman.encode(input_file_path, encoded_file_path);
    std::cout << "File " << input_file_path << " has been encoded and written to " << encoded_file_path << std::endl;

    // Decode the encoded file
    std::string decoded_file_path = "../test/decoded.txt";
    huffman.decode(encoded_file_path, decoded_file_path);
    std::cout << "File " << encoded_file_path << " has been decoded and written to " << decoded_file_path << std::endl;

    return 0;
}
