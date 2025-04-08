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
    
public:
    MerkleTree(/* args */);
    Node* create_tree(std::vector<std::string> dataBlocks);
    void check_if_in_tree();
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