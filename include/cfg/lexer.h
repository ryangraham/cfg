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
  lexer(const std::string& line) : begin(line.c_str()) {}

  std::vector<token> tokens() {
    std::vector<token> results;

    token token = next();
    results.push_back(token);

    while (token.type != token_type::END) {
      token = next();
      results.push_back(next());
    }

    return results;
  }

 private:
  char peek() const { return *begin; }
  char get() { return *begin++; }

  token next() {
    while (is_space(peek())) get();

    switch (peek()) {
      case '\0':
        return atom(token_type::END);
      case '[':
        return atom(token_type::LEFTBRACKET);
      case ']':
        return atom(token_type::RIGHTBRACKET);
      default:
        return identifier();
    }
  }

  token atom(token_type type) { return token(type, begin++, 1); }
  token identifier() {
    const char* start = begin;
    get();
    while (is_identifier(peek())) get();
    return token(token_type::IDENTIFIER, start, begin);
  }

  bool is_space(char c) {
    switch (c) {
      case ' ':
      case '\t':
      case '\r':
      case '\n':
        return true;
      default:
        return false;
    }
  }

  bool is_identifier(char c) {
    switch (c) {
      case '\0':
        return false;
      default:
        return true;
    }
  }

  const char* begin = nullptr;
};

}  // namespace cfg