#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

#include "ctree.h"

using namespace ranges;

namespace cfg {

inline void write_section(std::ostream& sout, const std::string& section) {
  sout << "[" << section << "]" << std::endl;
}

inline void write_kv(std::ostream& sout, const std::string& key,
                     const std::string& value) {
  sout << key << "=" << value << std::endl;
}

inline int write(std::ostream& sout, ctree& ctree) {
  auto sections = ctree | views::keys;
  for (auto& section : sections) {
    write_section(sout, section);
    for (const auto& [k, v] : ctree[section]) write_kv(sout, k, v);
  }
  return 0;
}

inline int write_ini(const std::string& path, ctree& ctree) {
  std::ofstream ofs(path);
  if (!ofs) return 1;

  return write(ofs, ctree);
}

}  // namespace cfg
