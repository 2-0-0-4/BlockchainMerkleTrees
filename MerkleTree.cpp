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

MerkleTree::~MerkleTree()
{
    // delete root_pointer;
    // delete[] leaf_nodes;
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

// MerkleTree::~MerkleTree()
// {
//     // for (Node *node : leaf_nodes)
//     // {
//     //     delete node;
//     // }
//     for(int i = 0; i<leaf_nodes.size();i++){
//         delete leaf_nodes[i];
//     }
//     delete root_pointer;
// }

// Node* MerkleTree::create_tree(std::vector<std::string> dataBlocks){

//     //list of leafnodes with the hashvalues
//      for(const std::string &data : dataBlocks){
//         Node* temp = new Node(sha256(data));
//         current_level.push_back(temp);
//         leaf_nodes.push_back(temp);

//     }

//     //while the vector does not become 1(only root left)
//     while(current_level.size()>1){

//         std::vector<Node*> next_level;

//         for(int i= 0; i < current_level.size(); i= i+2){

//             if(current_level.size()>i+1){
//                 next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i+1]->hashval))); //hash the combined hashvalues of i and i+1
//                 //make parent
//                 current_level[i]->parent = next_level.back();
//                 current_level[i+1]->parent = next_level.back();

//             }else{
//                 next_level.push_back(new Node(sha256(current_level[i]->hashval + current_level[i]->hashval)));  //if i+1 not available, combine i+i
//                 //make parent
//                 current_level[i]->parent = next_level.back();
//             }
//         }

//         current_level = next_level; //move to the upper level

//     }

//     return current_level.front(); //return pointer to the root of the merkle tree

// }

// recursive fucntion