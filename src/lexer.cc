#include "cfg/lexer.h"

#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "cfg/token.h"

using namespace ranges;

namespace cfg {

lexer::lexer(const std::string& line) : begin(line.c_str()) {}

std::vector<token> lexer::tokens() {
  std::vector<token> results;

  token token = next();
  results.push_back(token);

  while (token.type != token_type::END) {
    token = next();
    results.push_back(token);
  }

  return results;
}

char lexer::peek() const { return *begin; }
char lexer::get() { return *begin++; }

token lexer::next() {
  while (is_space(peek())) get();

  char c = peek();
  if (c == '\0') return atom(token_type::END);

  if (in_greedy_context) return value();

  switch (c) {
    case '[':
      return atom(token_type::LEFTBRACKET);
    case ']':
      return atom(token_type::RIGHTBRACKET);
    case '=':
      in_greedy_context = true;
      return atom(token_type::EQUAL);
    default:
      return identifier();
  }
}

token lexer::value() {
  const char* start = begin;
  get();
  while (is_value(peek())) get();
  return token(token_type::VALUE, start, begin);
}

token lexer::atom(token_type type) { return token(type, begin++, 1); }
token lexer::identifier() {
  const char* start = begin;
  get();
  while (is_identifier(peek())) get();
  return token(token_type::IDENTIFIER, start, begin);
}

bool lexer::is_space(char c) {
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

bool lexer::is_identifier(char c) {
  if (c == '\0') return false;

  static constexpr std::string_view valid =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz"
      "_-";  // -_
  return valid.find(c) != std::string::npos;
}

bool lexer::is_value(char c) {
  if (c == '\0') return false;

  return true;
}

}  // namespace cfg
