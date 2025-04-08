#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <vector>
#include <string>
struct Node
{
    Node* parent;
    std::string hash_value;
    
};

class MerkleTree
{
private:
    std::vector<Node> leaf_nodes;
    std::string root_hash;
    
public:
    MerkleTree(); //ctor
    MerkleTree(std::vector<Node> nodes); //parametrized ctor
    Node* Create_Tree(); //creates tree and returns root 
    bool in_tree(int index, std::string data); //
    std::string getRootHash();
    ~MerkleTree();
};

#endif