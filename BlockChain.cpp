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



void Blockchain::saveChain( std::string filename)  {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Error saving blockchain!" << std::endl;
        return;
    }

    for ( Block& block : chain) {
        out << block.getPrevHash() << "\n";
        out << block.get_Root_Hash() << "\n";
        out << block.getBlockHash() << "\n";
        out << "===\n";
    }

    out.close();
}

bool Blockchain::verifyFromFile( std::string filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Error reading blockchain metadata!" << std::endl;
        return false;
    }

    std::string storedPrevHash, storedMerkle, storedBlockHash, line;
    int index = 0;

    while (std::getline(in, storedPrevHash)) {
        std::getline(in, storedMerkle);
        std::getline(in, storedBlockHash);
        std::getline(in, line); // ===

        if (index >= chain.size()) {
            std::cerr << "This data has more blocks than actual blockchain!" << std::endl;
            return false;
        }

        Block& current = chain[index];
        if (current.getPrevHash() != storedPrevHash ||
            current.get_Root_Hash() != storedMerkle ||
            current.getBlockHash() != storedBlockHash) {
            std::cerr << "Block " << index  << " has been tampered!" << std::endl;
            return false;
        }

        ++index;
    }

    return true;
}
