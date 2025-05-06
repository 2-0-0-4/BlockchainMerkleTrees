#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <vector>
#include "Block.hpp"

class Blockchain {
private:
    std::vector<Block> chain;
    std::string getLatestBlockHash(); // helper function to get the latest block hash
public:
    Blockchain();
    void addBlock(const std::string& filename); // add new block
    void printChain(); // print the entire blockchain
    void saveChain( std::string filename) ;
    bool verifyFromFile(std::string filename);

};

#endif