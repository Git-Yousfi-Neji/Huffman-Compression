#include "../include/huffman.h"

#include <iostream>
#include <vector>
#include <bitset>

// Helper function to compare two nodes based on frequency
struct NodeCompare {
    bool operator()(const Node* a, const Node* b) const {
        return a->frequency > b->frequency;
    }
};

//Huffman::Huffman() {}
Huffman::Huffman()  {}


Huffman::~Huffman() {
    delete_huffman_tree(root);
}

void Huffman::encode(std::string input_file_path, std::string output_file_path) {
    a+=10;
    // Open input file for reading
    std::ifstream input_file(input_file_path, std::ios::in | std::ios::binary);
    if (!input_file) {
        std::cerr << "Error: Unable to open input file " << input_file_path << std::endl;
        return;
    }

    // Create output file for writing
    std::ofstream output_file(output_file_path, std::ios::out | std::ios::binary);
    if (!output_file) {
        std::cerr << "Error: Unable to open output file " << output_file_path << std::endl;
        return;
    }

    // Count the frequency of each symbol in the input file
    std::unordered_map<char, int> frequencies;
    char c;
    while (input_file.get(c)) {
        frequencies[c]++;
    }

    // Construct the Huffman tree from the frequency map
    root = construct_huffman_tree(frequencies);

    // Generate Huffman codes for each symbol in the tree
    generate_huffman_codes(root, "");

    // Write the Huffman codes to the output file
    int code_count = 0;
    char code_buffer = 0;
    input_file.clear();
    input_file.seekg(0, std::ios::beg);
    while (input_file.get(c)) {
        std::string code = huffman_codes_[c];
        for (char bit : code) {
            code_buffer <<= 1;
            if (bit == '1') {
                code_buffer |= 1;
            }
            code_count++;
            if (code_count == 8) {
                output_file.put(code_buffer);
                code_buffer = 0;
                code_count = 0;
            }
        }
    }

    // Write the last byte if it is not complete
    if (code_count > 0) {
        code_buffer <<= (8 - code_count);
        output_file.put(code_buffer);
    }

    // Close input and output files
    input_file.close();
    output_file.close();
}


void Huffman::decode(std::string input_file_path, std::string output_file_path) {
a+=20;
    // Open input file for reading
    std::ifstream input_file(input_file_path, std::ios::in | std::ios::binary);
    if (!input_file) {
        std::cerr << "Error: Unable to open input file " << input_file_path << std::endl;
        return;
    }

    // Create output file for writing
    std::ofstream output_file(output_file_path, std::ios::out | std::ios::binary);
    if (!output_file) {
        std::cerr << "Error: Unable to open output file " << output_file_path << std::endl;
        return;
    }

    // Read the Huffman codes from the input file
    std::vector<bool> code_bits;
    char c;
    while (input_file.get(c)) {
        std::bitset<8> byte(c);
        for (int i = 0; i < 8; i++) {
            code_bits.push_back(byte.test(7 - i));
        }
    }

    // Traverse the Huffman tree to decode the input file
    Node* node = root;
    for (bool bit : code_bits) {
        if (bit == 0) {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->right ==nullptr && node->left==nullptr) {
            output_file.put(node->symbol);
            node = root;
        }
    }

    // Close input and output files
    input_file.close();
    output_file.close();
}



Node* Huffman::construct_huffman_tree(std::unordered_map<char, int>& frequencies) {
std::priority_queue<Node*, std::vector<Node*>, NodeCompare> nodes;
for (const auto& kv : frequencies) {
Node* node = new Node(kv.first, kv.second);
nodes.push(node);
}
while (nodes.size() > 1) {
    Node* left = nodes.top();
    nodes.pop();
    Node* right = nodes.top();
    nodes.pop();

    Node* parent = new Node('\0', left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;

    nodes.push(parent);
}

return nodes.top();
}
void Huffman::generate_huffman_codes(Node* node, std::string code) {
if (node == nullptr) {
return;
}
if (node->right == nullptr && node->left==nullptr ) {
    huffman_codes_[node->symbol] = code;
}

generate_huffman_codes(node->left, code + "0");
generate_huffman_codes(node->right, code + "1");
}
void Huffman::delete_huffman_tree(Node* node) {
if (node == nullptr) {
return;
} 
delete_huffman_tree(node->left);
delete_huffman_tree(node->right);

delete node;
}
