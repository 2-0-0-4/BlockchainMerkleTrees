// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdlib>
// #include <ctime>
// #include "MerkleTree.hpp"

// // Utility to print vector of strings
// void print_vector(const std::vector<std::string>& vec) {
//     for (const std::string& s : vec) {
//         std::cout << s << std::endl;
//     }
//     std::cout << "-----------------------" << std::endl;
// }

// // Utility to print Merkle proof
// void print_proof(const std::vector<std::pair<std::string, int>>& proof) {
//     for (const auto& p : proof) {
//         std::cout << (p.second == 0 ? "Left:  " : "Right: ") << p.first << std::endl;
//     }
//     std::cout << "-----------------------" << std::endl;
// }

// // Generates dummy string blocks like "data_0", "data_1", ...
// std::vector<std::string> generate_data(int count) {
//     std::vector<std::string> data;
//     for (int i = 0; i < count; ++i) {
//         data.push_back("data_" + std::to_string(i));
//     }
//     return data;
// }

// // Run one test case
// void run_test_case(const std::string& label, const std::vector<std::string>& dataBlocks) {
//     std::cout << "=== Test Case: " << label << " ===" << std::endl;
//     std::cout << "Input Blocks:" << std::endl;
//     print_vector(dataBlocks);

//     MerkleTree m(dataBlocks);
//     m.Create_Tree();

//     std::vector<std::string> leaf_hashes = m.getLeafHashes();
//     std::cout << "Leaf Hashes:" << std::endl;
//     print_vector(leaf_hashes);

//     std::cout << "Root Hash: " << m.getRootHash() << std::endl;

//     if (leaf_hashes.size() > 1) {
//         int i = rand() % leaf_hashes.size(); // random index
//         std::string correct_hash = leaf_hashes[i];
//         std::string tampered_hash = "tampered_hash_fake";

//         std::cout << "Generating proof for index " << i << "..." << std::endl;
//         std::vector<std::pair<std::string, int>> proof = m.get_proof(i);
//         print_proof(proof);

//         std::cout << "Verifying CORRECT hash..." << std::endl;
//         bool valid1 = m.Verify_Node(i, correct_hash);
//         std::cout << "Result: " << (valid1 ? "SUCCESS" : "FAIL") << std::endl;

//         std::cout << "Verifying TAMPERED hash..." << std::endl;
//         bool valid2 = m.Verify_Node(i, tampered_hash);
//         std::cout << "Result: " << (valid2 ? "SUCCESS (unexpected!)" : "FAIL (expected)") << std::endl;
//     } else {
//         std::cout << "Only one leaf — proof not applicable.\n";
//     }

//     std::cout << "===============================\n" << std::endl;
// }

// int main() {
//     srand(static_cast<unsigned>(time(0))); // Seed for random index selection

//     run_test_case("Single Node Tree", generate_data(1));
//     run_test_case("Tiny Tree", generate_data(2));
//     run_test_case("Small Tree", generate_data(4));
//     run_test_case("Odd Leaves", generate_data(5));
//     run_test_case("Full Tree", generate_data(8));
//     run_test_case("Unbalanced Tree", generate_data(9));
//     run_test_case("Larger Tree", generate_data(10));

//     return 0;
// }
