#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <string>
#include <vector>
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
    ~MerkleTree();
};

#endif