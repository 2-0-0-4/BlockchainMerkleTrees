// #include <iostream>
// #include "sha256.h"
// #include <string>

// std::string sha256(const std::string &data)
// {
//     BYTE hash[32]; // 256 bits = 32 bytes
//     SHA256_CTX ctx;

//     sha256_init(&ctx);
//     sha256_update(&ctx, (const BYTE *)data.c_str(), data.size());
//     sha256_final(&ctx, hash);

//     // Convert bytes to hex string
//     char output[65]; // 64 chars + null terminator
//     for (int i = 0; i < 32; i++)
//         sprintf(output + i * 2, "%02x", hash[i]);

//     return std::string(output);
// }

// int main()
// {
//     std::string input = "Alice sends 10 to Bob";
//     std::string hashed = sha256(input);
//     std::cout << "SHA-256: " << hashed << std::endl;
// }
