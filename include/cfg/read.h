#pragma once

#include <istream>
#include <string>

#include "ctree.h"

namespace cfg {

int read(std::istream& sin, ctree& ctree);

int read_ini(const std::string& path, ctree& ctree);

}  // namespace cfg
