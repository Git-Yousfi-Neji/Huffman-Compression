#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>

struct Node {
    char symbol;
    int frequency;
    Node* left;
    Node* right;
    Node(char s, int f) : symbol(s), frequency(f), left(nullptr), right(nullptr) {}
};

class Huffman {
public:
    Huffman();
    ~Huffman();
    int a=0;
    
    void encode(std::string input_file_path, std::string output_file_path);
    void decode(std::string input_file_path, std::string output_file_path);
private:
    Node* root=nullptr;
    Node* construct_huffman_tree(std::unordered_map<char, int> & frequencies);
    
    
    void generate_huffman_codes(Node* node, std::string code);
    void delete_huffman_tree(Node* node);
    std::unordered_map<char, std::string> huffman_codes_;
};

#endif // HUFFMAN_H
