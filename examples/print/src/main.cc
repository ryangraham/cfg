#include <cfg/cfg.h>

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string input_file_name = "../input.ini";
  cfg::ctree ctree;

  // Parse ini file
  cfg::read_ini(input_file_name, ctree);

  // Print ctree (nested maps)
  auto section_names = ctree | views::keys;
  for (auto& section : section_names) {
    std::cout << section << std::endl;
    std::cout << std::string(10, '-') << std::endl;
    for (const auto& [k, v] : ctree[section])
      std::cout << k << "=" << v << std::endl;
  }

  return 0;
}
