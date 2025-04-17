
#include <iostream>
#include "MerkleTree.hpp"
#include "sha256.h"
#include "Block.hpp"
#include "Blockchain.hpp"

// int main() {
//     // creating block.
//     Block b("dataset/block15.csv");
//     std::cout << "Root Hash: " << b.get_Root_Hash() << std::endl;

    
//     std::cout<< "datablocks content: ";
//         b.printfile();

//     return 0;
// }



// Block chain
// int main() {
//     Blockchain blockchain; // Create a new blockchain
    
    
//     for (int i = 1; i <= 15; ++i) {
//         std::string filename = "dataset/block" + std::to_string(i) + ".csv";
//         blockchain.addBlock(filename);
//     }
    
//     // Print out the entire blockchain
//     blockchain.printChain();
    
//     return 0;
// }

void print_vector(std::vector<std::string> v){
    int x = 0;
    for(std::string i : v){
        std::cout <<x++<<":"<< i << std::endl;
    }
    std::cout << std::endl;
}

int main(){

    std::vector<std::string> v = {"hello","world","ds2","blockchain","pls"};
    print_vector(v);
    MerkleTree m(v);
    m.Create_Tree();
    std::string x = m.getRootHash();
    std::vector<std::string> hashes = m.getLeafHashes();
    print_vector(hashes);
    std::cout << x <<std::endl;
    
    // std::vector<std::string> w = {"hello","world","ds2","blockchain"};
    // print_vector(w);
    // MerkleTree h(w);
    // h.Create_Tree();
    // std::string y = h.getRootHash();
    // std::cout << y <<std::endl;
    // std::cout << (x == y) << std::endl;

    // std::vector<std::string> a = {"hello","world!","ds2","blockchain"};
    // print_vector(a);
    // MerkleTree j(a);
    // j.Create_Tree();
    // std::string f = j.getRootHash();
    // std::cout << f <<std::endl;
    // std::cout << (x == f) << std::endl;

    // std::cout << "---------------- proof: -------------------" <<std::endl;
    // for(int p = 0; p<v.size();p++){
    //     std::cout<< p << std::endl;
    //     std::vector<std::string> proof = m.get_proof(p);
    //     print_vector(proof);
    //     std::cout<< "------------------------------------" << std::endl;

    // }
    std::cout << m.Verify_Node(0,"2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824")
    <<m.Verify_Node(1,"486ea46224d1bb4fb680f34f7c9ad96a8f24ec88be73ea8e5a6c65260e9cb8a7")
    << m.Verify_Node(2,"75e7a56a890f3b1a085c89ff77a4b51874d9142343c8c2e1d297cfc85b0f30cc")
    <<m.Verify_Node(3,"ef7797e13d3a75526946a3bcf00daec9fc9c9c4d51ddc7cc5df888f74dd434d1")
    <<m.Verify_Node(4,"c8f1413fe5b6cb2cb588f7bfa576f1b0590515058f9e2be5b913b23ac5ef96d");
    return 0;
}