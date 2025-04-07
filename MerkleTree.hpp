#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <vector>
struct Node
{
    Node* parent;
    
};

class MerkleTree
{
private:
    std::vector<Node> leaf_nodes;
    
public:
    MerkleTree(/* args */);
    void create_tree();
    void check_if_in_tree();
    ~MerkleTree();
};

#endif