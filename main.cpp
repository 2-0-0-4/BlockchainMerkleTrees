
#include <iostream>
#include "MerkleTree.hpp"
#include "sha256.h"
#include "Block.hpp"
#include "Blockchain.hpp"

   
// int main() {

//     // creating block.
//     Block b("dataset/block1.csv", "0");
//     std::cout << "Root Hash: " << b.get_Root_Hash() << std::endl;

//     // std::cout<< "datablocks content: ";

//     //     b.printfile();

//   // Testcase 1 - block 1
//     // invalid leaf node)
//     std::cout << b.verifyTransaction(0,"2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824") << std::endl;

//     // verification for block 1 (hashvalue of correct leaf node number 3 that is present in the tree)
//     std::string line = "15450240,1645535000,0.511077034,1,1,1,1,88,1448,72,1,75,2107,4790,55,1";
//     line = sha256(line);
//     std::cout << b.verifyTransaction(3, line) << std::endl;


//    // Testcase 2 - block 4
//     Block c("dataset/block4.csv", "0");
//     std::cout << "Root Hash: " << b.get_Root_Hash() << std::endl;


//     // verification for block 4 ( invalid leaf node)
//     std::cout << c.verifyTransaction(0,"2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824") << std::endl;

//     // verification for block 4 (hashvalue of correct leaf node number 3 that is present in the tree)
//     line = "5468684,1559886285,0.476428921,0,0,0,1,39,1049,52,3,94,1400,2346,28,0";
//     line = sha256(line);
//     std::cout << c.verifyTransaction(29, line) << std::endl;

    
//     // Testcase 3 - block 15
//     Block d("dataset/block15.csv", "0");
//     std::cout << "Root Hash: " << d.get_Root_Hash() << std::endl;


//     // verification for block 15 ( hashvalue of invalid leaf node)
//     std::cout << d.verifyTransaction(0,"2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824") << std::endl;

//     // verification for block 15 (hashvalue of correct leaf node number 3 that is present in the tree)
//     line = "15301088,1524145611,0,1,1,1,1,42,1611,81,1,110,1498,2682,29,1";
//     line = sha256(line);
//     std::cout << d.verifyTransaction(91, line) << std::endl;

//     return 0;

// }


// int main() {

//     Blockchain blockchain; // Create a new blockchain
    
    
//     for (int i = 1; i <= 15; ++i) {
//         std::string filename = "dataset/block" + std::to_string(i) + ".csv";
//         blockchain.addBlock(filename);
//     }
    
//     // Print out the entire blockchain
//     blockchain.printChain();
//     // // Verify blockchain integrity
//     std::cout << "Verifying Blockchain..." << std::endl;
//     if (blockchain.verifyChain()) {
//         std::cout << "Blockchain is valid" << std::endl;
//     } else {
//         std::cout << "Blockchain is invalid" << std::endl;
//     }
   
//     return 0;
// }

int main() {
    // PHASE 1: Save Original Blockchain 
    // Blockchain blockchain;
    // for (int i = 1; i <= 15; ++i) {
    //     std::string filename = "dataset/block" + std::to_string(i) + ".csv";
    //     blockchain.addBlock(filename);
    // }
    // blockchain.saveChain("blockchain_meta.txt");
    // std::cout << "Blockchain saved. \n";

    //PHASE 2: Verify After Tampering 
    Blockchain blockchain;
    for (int i = 1; i <= 15; ++i) {
        std::string filename = "dataset/block" + std::to_string(i) + ".csv";
        blockchain.addBlock(filename);
    }

    std::cout << "\nVerifying Blockchain\n";
    if (blockchain.verifyFromFile("blockchain_meta.txt")) {
        std::cout << "Blockchain is VALID ";
    } else {
        std::cout << "Blockchain is INVALID ";
    }

    return 0;
}
