#pragma once

#include "cfg.hpp"

#include <array>
#include <string>
#include <map>


using Let_t = std::array<std::string, LET_H>;

std::map<char, Let_t> alphabet;