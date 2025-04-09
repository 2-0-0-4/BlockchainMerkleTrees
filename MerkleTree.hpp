#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <string>
#include <vector>
#include <string>
struct Node
{
    Node* parent;
    std::string hashval;
    Node(std::string hashval): hashval(hashval), parent(nullptr) {}
    
};

class MerkleTree
{
private:
    std::vector<Node*> current_level;
    std::vector<Node*> leaf_nodes;
    Node* root_pointer;
    std::string root_hash;
    Node* MerkleTree::create_tree(std::vector<Node*> leaf_nodes); //recursive definition
    // Node* create_tree(std::vector<std::string> dataBlocks); //datablocks obtained from csv files , creates tree and returns root
    // MerkleTree(); //ctor
    // MerkleTree(std::vector<std::string> dataBlocks); //parametrized ctor
public:
    MerkleTree(); //ctor
    MerkleTree(std::vector<std::string> dataBlocks); //parametrized ctor
    void Create_Tree(); //creates tree and returns root 
    bool in_tree(int index, std::string data); //(if we are going through the tree should we declare left and right pointers also?)
    std::string getRootHash();
    Node* getRootPointer();
    ~MerkleTree();
};

#endif