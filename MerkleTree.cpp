#include "MerkleTree.hpp"
#include "sha256.h"


MerkleTree::MerkleTree(/* args */)
{
}

MerkleTree::~MerkleTree()
{
}

Node* MerkleTree::create_tree(std::vector<std::string> dataBlocks){

    //list of leafnodes with the hashvalues
     for(const std::string &data : dataBlocks){
        current_level.push_back(new Node(sha256(data)));
    }

    //while the vector does not become 1(only root left)
    while(current_level.size()>1){

        std::vector<Node*> next_level;

        for(int i= 0; i < current_level.size(); i= i+2){

            if(current_level.size()>i+1){
                next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i+1]->hashval))); //hash the combined hashvalues of i and i+1
                //make parent 
                current_level[i]->parent = next_level.back();
                current_level[i+1]->parent = next_level.back();

            }else{
                next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i]->hashval)));  //if i+1 not available, combine i+i
                //make parent 
                current_level[i]->parent = next_level.back();
            }
        }

        current_level = next_level; //move to the upper level 


    }

    return current_level.front(); //return pointer to the root of the merkle tree


}
 