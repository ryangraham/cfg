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

  // auto is_identifier = [](token token) { return token.is_identifier(); };
  // auto yield_value = [](token token) { return token.value; };
  // auto columns = tokens | views::filter(is_identifier) |
  //                views::transform(yield_value) |
  //                to<std::vector<std::string>>();

  // Why doesn't this work?
  // return views::zip(field_names, columns) | to<std::map>();
  // for (size_t i = 0; i < field_names.size(); ++i)
  //   row[field_names[i]] = columns[i];
}

}  // namespace cfg
