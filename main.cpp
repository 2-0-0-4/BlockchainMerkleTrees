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

int main(){

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