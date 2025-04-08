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
    Node* root_pointer;
    std::string root_hash;
    
public:
    MerkleTree(/* args */);
    Node* create_tree(std::vector<std::string> dataBlocks); //datablocks obtained from csv files , creates tree and returns root
    void check_if_in_tree();
    
public:
    MerkleTree(); //ctor
    MerkleTree(std::vector<Node> nodes); //parametrized ctor
    Node* Create_Tree(std::vector<std::string> dataBlocks); //creates tree and returns root 
    bool in_tree(int index, std::string data); //(if we are going through the tree should we declare left and right pointers also?)
    std::string getRootHash();
    Node* getRootPointer();
    ~MerkleTree();
};

#endif