#pragma once

#include <map>
#include <string>

namespace cfg {

typedef std::map<std::string, std::string> kv_map;
typedef std::map<std::string, kv_map> ctree;

}  // namespace cfg