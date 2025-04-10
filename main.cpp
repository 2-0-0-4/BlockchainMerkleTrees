
#include <iostream>
#include "MerkleTree.hpp"
#include "sha256.h"
#include "Block.hpp"

// final
int main() {

    Block b("dataset/block15.csv");
    std::cout << "Root Hash: " << b.get_Root_Hash() << std::endl;
    return 0;
}
