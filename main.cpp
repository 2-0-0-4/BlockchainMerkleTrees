
#include <iostream>
#include "MerkleTree.hpp"
#include "sha256.h"
#include <string>
#include <iostream>
#include <vector>

void print_vector(std::vector<std::string> v){
    for(std::string i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
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
    

    std::vector<std::string> v = {"hello","world","ds2","blockchain"};
    print_vector(v);
    MerkleTree m(v);
    m.Create_Tree();
    std::string x = m.getRootHash();
    std::cout << x <<std::endl;
    
    std::vector<std::string> w = {"hello","world","ds2","blockchain"};
    print_vector(w);
    MerkleTree h(w);
    h.Create_Tree();
    std::string y = h.getRootHash();
    std::cout << y <<std::endl;
    std::cout << (x == y) << std::endl;

    std::vector<std::string> a = {"hello","world!","ds2","blockchain"};
    print_vector(a);
    MerkleTree j(a);
    j.Create_Tree();
    std::string f = j.getRootHash();
    std::cout << f <<std::endl;
    std::cout << (x == f) << std::endl;

    // std::cout << "---------------- proof: -------------------" <<std::endl;
    // for(int p = 0; i<v.size())
    return 0;
}
