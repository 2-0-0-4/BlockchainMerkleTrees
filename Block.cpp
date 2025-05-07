#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Block.hpp"
#include "sha256.h"

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

Block::Block(const std::string& filename, const std::string& prevHash) {
    prev_hash = prevHash; 
    readfile(filename);
    merkle_tree = new MerkleTree(datablocks); 
    merkle_tree->Create_Tree();
}


std::string Block::get_Root_Hash() {
    return merkle_tree->getRootHash();
}

std::string Block::getBlockHash() {
    // I am not sure if this is the best way to creat block hash.
    return sha256(get_Root_Hash() + prev_hash);
}

std::string Block::getPrevHash() {
    return prev_hash;
}

bool Block::verifyTransaction(int index, const std::string& hash) {
    return merkle_tree->Verify_Node(index, hash);
}

Block::~Block(){}