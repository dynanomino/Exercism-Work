#pragma once

#include <string>

namespace atbash_cipher {

    std::string encode(std::string input);

    std::string decode(std::string input);

    int is_a_punctuation(char c);

    std::string cipher (std::string input, bool is_decode);

// TODO: add your solution here

}  // namespace atbash_cipher
