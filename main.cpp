
#include <iostream>
#include "MerkleTree.hpp"
#include "sha256.h"
#include "Block.hpp"
#include "Blockchain.hpp"

// final
// int main() {

//     Block b("dataset/block15.csv");
//     std::cout << "Root Hash: " << b.get_Root_Hash() << std::endl;
//     return 0;
// }

// #include <iostream>
// #include "Blockchain.hpp"

int main() {
    Blockchain blockchain; // Create a new blockchain
    
    
    for (int i = 1; i <= 15; ++i) {
        std::string filename = "dataset/block" + std::to_string(i) + ".csv";
        blockchain.addBlock(filename);
    }
    
    // Print out the entire blockchain
    blockchain.printChain();
    
    return 0;
}
