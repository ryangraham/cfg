#include "cfg/token.h"

#include <string>

namespace cfg {

token::token(token_type type, const char* begin, const char* end)
    : type{type}, value(begin, std::distance(begin, end)) {
  type_str = token_type_name(type);
}
token::token(token_type type, const char* begin, int len)
    : type{type}, value(begin, len) {
  type_str = token_type_name(type);
}

bool token::is_identifier() { return type == token_type::IDENTIFIER; }

}  // namespace cfg
