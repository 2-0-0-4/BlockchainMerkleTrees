#include "MerkleTree.hpp"
#include "sha256.h"

MerkleTree::MerkleTree() {}

MerkleTree::MerkleTree(std::vector<std::string> dataBlocks)
{
    // list of leafnodes with the hashvalues
    for (const std::string &data : dataBlocks)
    {
        this->leaf_nodes.push_back(new Node(sha256(data)));
    }
    this->root_pointer = nullptr;
}

void MerkleTree::delete_node(Node *node) {
    if (node == nullptr) {
        return;
    }

    //preventing double deletion when there are odd num of leaves
    if (node->left && node->left != node->right) {
        delete_node(node->left);
        delete_node(node->right);
    } else if (node->left) {
        delete_node(node->left);  // only once if same
    }

    delete node;
}

MerkleTree::~MerkleTree() {
    //deletion from root:
    delete_node(root_pointer); 
    leaf_nodes.clear();
}

Node *MerkleTree::create_tree(std::vector<Node *> current_level)
{

    if (current_level.size() == 1)
    {
        return current_level.back(); // if only root left return
    }

    std::vector<Node *> next_level;

    for (int i = 0; i < current_level.size(); i = i + 2)
    {

        if (current_level.size() > i + 1)
        {
            next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i + 1]->hashval))); // hash the combined hashvalues of i and i+1
            // std::cout << i << " " << i + 1 << " " << sha256(current_level[i]->hashval + current_level[i + 1]->hashval) << std::endl;
            // make parent
            current_level[i]->parent = next_level.back();
            current_level[i + 1]->parent = next_level.back();
            next_level.back()->left = current_level[i];
            next_level.back()->right = current_level[i + 1];
        }
        else
        {
            next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i]->hashval))); // if i+1 not available, combine i+i
            // make parent
            // std::cout << i << " " << sha256(current_level[i]->hashval + current_level[i]->hashval) << std::endl;
            current_level[i]->parent = next_level.back();
            next_level.back()->left = current_level[i];
            next_level.back()->right = current_level[i];
        }
    }

    // recursive definition
    return create_tree(next_level);
}

void MerkleTree::Create_Tree()
{

    root_pointer = create_tree(leaf_nodes);
    root_hash = root_pointer->hashval;

    // return root_pointer;
}

std::string MerkleTree::getRootHash()
{

    return root_hash;
}

Node *MerkleTree::getRootPointer()
{

    return root_pointer;
}

std::vector<std::string> MerkleTree::getLeafHashes()
{
    std::vector<std::string> hashes;
    for (Node *i : leaf_nodes)
    {
        hashes.push_back(i->hashval);
    }
    return hashes;
}

bool MerkleTree::Verify_Node(int txn_num, std::string hash_value)
{
    // std::cout << "root check: " << (root_hash==root_pointer->hashval)<<std::endl;
    std::vector<std::pair<std::string, int>> path = get_proof(txn_num);
    std::string curr_hash = hash_value;
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i].second == 1) // right sibling so concantenate to the right
            curr_hash = sha256(curr_hash + path[i].first);
        if (path[i].second == 0) // left sibling so concantenate to the left
            curr_hash = sha256(path[i].first + curr_hash);
    }
    return (curr_hash == root_pointer->hashval) ? true : false;
}

void MerkleTree::Remove_Node(int i)
{
    delete leaf_nodes[i];                     // delete the pointer at i
    leaf_nodes.erase(leaf_nodes.begin() + i); // delete ith pos of vector
    Create_Tree();                            // update hashes
}

std::vector<std::pair<std::string, int>> MerkleTree::get_proof(int i)
{
    // left = 0, right = 1
    Node *curr_node = leaf_nodes[i];
    std::vector<std::pair<std::string, int>> path;
    while (curr_node != root_pointer)
    {
        Node *parent_node = curr_node->parent;
        if (parent_node->left == curr_node)
        {
            path.push_back({(parent_node->right->hashval), 1}); // sibling is right
        }
        else if (parent_node->right == curr_node)
        {
            path.push_back({(parent_node->left->hashval), 0}); // sibling is left
        }

        curr_node = parent_node;
    }
    return path;
}
