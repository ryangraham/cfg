#pragma once

#include <ostream>
#include <string>

#include "ctree.h"

namespace cfg {

void write_section(std::ostream& sout, const std::string& section);

void write_kv(std::ostream& sout, const std::string& key,
              const std::string& value);

int write(std::ostream& sout, ctree& ctree);

int write_ini(const std::string& path, ctree& ctree);

}  // namespace cfg
