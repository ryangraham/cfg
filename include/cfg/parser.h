#pragma once

#include <map>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "ctree.h"
#include "token.h"

using namespace ranges;

namespace cfg {

void parse(std::vector<token> tokens, ctree& root) {
  for (auto& token : tokens) std::cout << token.type_str << std::endl;
}

}  // namespace cfg
