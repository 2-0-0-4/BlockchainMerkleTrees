#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Block.hpp"

int Block:: readfile(const std::string& filename) {
    std::ifstream file(filename); 
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        datablocks.push_back(line);
    }

    file.close();

    return 0;
}

void Block::printfile() {
    for (const std::string& entry : datablocks) {
        std::cout << entry << std::endl;
    }
}

Block::Block(const std::string& filename) {
    readfile(filename);
    merkle_tree = MerkleTree(datablocks); // pass data to MerkleTree
    merkle_tree.Create_Tree(); 
}


std::string Block:: get_Root_Hash(){
   
    std::string x = merkle_tree.getRootHash();
 
    return x;
}