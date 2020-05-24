#pragma once

#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "ctree.h"
#include "lexer.h"
#include "parser.h"

using namespace ranges;

namespace cfg {

int read(std::istream& sin, ctree& root) {
  auto lex = [](const std::string& s) {
    lexer lexer(s);
    return lexer.tokens();
  };
  auto tokenized_lines = getlines(sin) | views::transform(lex);

  for (auto&& line : tokenized_lines) {
    parse(line, root);
  }
  return 0;
}

int read_ini(const std::string& path, ctree& ctree) {
  std::fstream ifs(path);
  if (!ifs) return 1;

  return read(ifs, ctree);
}

}  // namespace cfg