#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <range/v3/all.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "cfg/ctree.h"
#include "cfg/lexer.h"
#include "cfg/parser.h"
#include "doctest/doctest.h"

using namespace ranges;

namespace cfg {

int read(std::istream& sin, ctree& ctree) {
  auto lex = [](const std::string& s) {
    lexer lexer(s);
    return lexer.tokens();
  };
  auto tokenized_lines = getlines(sin) | views::transform(lex);

  parser parser(ctree);
  for (auto&& line : tokenized_lines) {
    parser.parse(line);
  }
  return 0;
}

int read_ini(const std::string& path, ctree& ctree) {
  std::fstream ifs(path);
  if (!ifs) return 1;

  return read(ifs, ctree);
}

}  // namespace cfg

TEST_CASE("read") {
  std::string config =
      "[Okta]\n"
      "organization=scooterz\n"
      "username=ryang\n"
      "enable_keychain=true\n";
  std::istringstream input(config);
  cfg::ctree ctree;
  cfg::read(input, ctree);

  auto username = ctree["Okta"]["username"];

  CHECK(username == "ryang");
}
