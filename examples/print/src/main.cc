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

  // Index into ctree and print
  std::cout << std::endl
            << "Okta.username: " << ctree["Okta"]["username"] << std::endl;

  // Print using built-in writer
  std::cout << std::endl;
  cfg::write(std::cout, ctree);

  return 0;
}
