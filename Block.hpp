#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MerkleTree.hpp"

class Block {
    private:
        std::vector<std::string> datablocks;
        MerkleTree merkle_tree; 
    public:
        Block(const std::string& filename); 
        int readfile(const std::string& filename);
        void printfile();
        std::string get_Root_Hash();


};


#endif