#pragma once

#include <string>
#include <vector>

#include "ctree.h"
#include "token.h"

namespace cfg {

struct parser {
 public:
  parser(ctree& ctree);

  void parse(std::vector<token> tokens);

 private:
  ctree* ctree_;
  std::string current_section;
  void do_section(std::vector<token> tokens);

  void do_kv(std::vector<token> tokens);
};

}  // namespace cfg
