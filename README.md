[![Build Status](https://circleci.com/gh/ryangraham/cfg.svg?style=svg)](https://circleci.com/gh/ryangraham/cfg)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/ryangraham/cfg/master/LICENSE)

# CFG

An INI parser library for C++.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Installation

Install cfg using [Homebrew](https://brew.sh/).

```
brew tap ryangraham/cfg
brew install cfg
```

## Usage

```
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
```
Output...
```
Okta
----------
enable_keychain=true
organization=scooterz
username=ryang

Okta.username: ryang

[Okta]
enable_keychain=true
organization=scooterz
username=ryang
```

## Examples

See [examples](https://github.com/ryangraham/cfg/tree/master/examples/).
