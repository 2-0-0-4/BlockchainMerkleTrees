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
        std::string prev_hash;  // Store previous block's hash
    public:
        Block(const std::string& filename, const std::string& prevHash = ""); 
        int readfile(const std::string& filename);
        void printfile();
        std::string get_Root_Hash();
        std::string getBlockHash();  // Get the hash of the current block
        std::string getPrevHash();   // Get the previous block's hash


};


#endif