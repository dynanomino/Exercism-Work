#pragma once

#include <string>
#include <vector>
#include <map>

namespace protein_translation {

    extern std::map<std::string, std::string> map_protein;

    std::vector<std::string> proteins(std::string input);

}  // namespace protein_translation
