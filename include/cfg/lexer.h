#pragma once

#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "token.h"

using namespace ranges;

namespace cfg {

struct lexer {
 public:
  lexer(const std::string& line);

  std::vector<token> tokens();

 private:
  char peek() const;
  char get();

  token next();

  token value();

  token atom(token_type type);
  token identifier();

  bool is_space(char c);

  bool is_identifier(char c);

  bool is_value(char c);

  bool in_greedy_context = false;
  const char* begin = nullptr;
};

}  // namespace cfg
