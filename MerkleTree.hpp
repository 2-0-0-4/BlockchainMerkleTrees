#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <string>
#include <vector>

struct Node
{
    Node *parent;
    Node *right;
    Node *left;
    std::string hashval;
    Node(std::string hashval) : hashval(hashval), parent(nullptr), right(nullptr), left(nullptr) {}
};

class MerkleTree
{
private:
    std::vector<Node *> leaf_nodes;
    Node *root_pointer;
    std::string root_hash;
    Node *create_tree(std::vector<Node *> current_level);
    std::vector<std::string> get_proof(int i);

public:
    MerkleTree();                                    // ctor
    MerkleTree(std::vector<std::string> dataBlocks); // parametrized ctor
    void Create_Tree();                              // creates tree and returns root
    std::string getRootHash();
    Node *getRootPointer();
    bool Verify_Node(int txn_num, std::string hash_value);
    void Remove_Node(int i);
    ~MerkleTree();
};

#endif