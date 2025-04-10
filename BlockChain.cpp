#include "Blockchain.hpp"
#include <iostream>

Blockchain::Blockchain() {
    
    chain.push_back(Block("dataset/block1.csv", ""));
}

std::string Blockchain::getLatestBlockHash() {
    return chain.back().getBlockHash();
}

void Blockchain::addBlock(const std::string& filename) {
    // Get the hash of the previous block to pass to the new block
    std::string previousHash = getLatestBlockHash();
    
    // Create a new block with the previous block's hash and the new data file
    chain.push_back(Block(filename, previousHash));
}

void Blockchain::printChain() {
    for (int i = 0; i < chain.size(); ++i) {
        std::cout << "Block #" << i + 1 << std::endl;
        std::cout << "Previous Hash: " << chain[i].getPrevHash() << std::endl;
        std::cout << "Block Hash: " << chain[i].getBlockHash() << std::endl;
        std::cout << "Merkle Root Hash: " << chain[i].get_Root_Hash() << std::endl;
        std::cout << std::endl;
    }
}