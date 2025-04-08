#include "MerkleTree.hpp"

MerkleTree::MerkleTree(){}

MerkleTree::MerkleTree(std::vector<Node> nodes)
{
    for(int i = 0; i<nodes.size();i++){
        leaf_nodes[i] = nodes[i];
    }
}

Node *MerkleTree::Create_Tree()
{
    return nullptr;
}

bool MerkleTree::in_tree(int index, std::string data)
{
    return false;
}

std::string MerkleTree::getRootHash()
{
    return std::string();
}

MerkleTree::~MerkleTree(){}
