#ifndef MERKLE_TREE_HPP
#define MERKLE_TREE_HPP

#include <string>
#include <vector>
#include <string>
struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    std::string hashval;
    Node(std::string hashval) : hashval(hashval), parent(nullptr), left(nullptr), right(nullptr) {}
};

class MerkleTree
{
private:
    // std::vector<Node*> current_level;
    std::vector<Node *> leaf_nodes;
    Node *root_pointer;
    std::string root_hash;
<<<<<<< HEAD
    Node* create_tree(std::vector<Node *> leaf_nodes); // recursive definition
    std::vector<std::string> get_proof(int i);

=======
    // Node* MerkleTree::create_tree(std::vector<Node*> leaf_nodes);
    Node* create_tree(std::vector<Node*> leaf_nodes);
 //recursive definition
    // Node* create_tree(std::vector<std::string> dataBlocks); //datablocks obtained from csv files , creates tree and returns root
    // MerkleTree(); //ctor
    // MerkleTree(std::vector<std::string> dataBlocks); //parametrized ctor
>>>>>>> f92fd37e5410728cd3222f33f2019750648e62c0
public:
    MerkleTree();                                          // ctor
    MerkleTree(std::vector<std::string> dataBlocks);       // parametrized ctor
    void Create_Tree();                                    // creates tree and returns root
    bool Verify_Node(int txn_num, std::string hash_value); //checks if node is in tree
    std::string getRootHash();
    Node *getRootPointer();
    void Remove_Node(int i);
    ~MerkleTree();
};

#endif