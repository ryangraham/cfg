#pragma once

#include <map>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "ctree.h"
#include "token.h"

using namespace ranges;

namespace cfg {

struct parser {
 public:
  parser(ctree& ctree) : ctree_(&ctree) {}

  void parse(std::vector<token> tokens) {
    std::vector<token_type> const section = {
        token_type::LEFTBRACKET, token_type::IDENTIFIER,
        token_type::RIGHTBRACKET, token_type::END};
    std::vector<token_type> const kv = {token_type::IDENTIFIER,
                                        token_type::EQUAL, token_type::VALUE,
                                        token_type::END};
    auto token_types =
        tokens | views::transform([](auto& token) { return token.type; }) |
        to<std::vector<token_type>>;

    if (equal(section, token_types)) {
      do_section(tokens);
      return;
    }

    if (equal(kv, token_types)) {
      do_kv(tokens);
      return;
    }
  }

 private:
  ctree* ctree_;
  std::string current_section;
  void do_section(std::vector<token> tokens) {
    current_section = tokens[1].value;
    (*ctree_)[current_section];
  }

  void do_kv(std::vector<token> tokens) {
    std::string k{tokens[0].value};
    std::string v{tokens[2].value};

    (*ctree_)[current_section][k] = v;
  }
};

}  // namespace cfg
