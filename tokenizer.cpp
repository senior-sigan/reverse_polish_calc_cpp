#include "tokenizer.hpp"

#include <iostream>
#include <sstream>

using namespace std;

vector<string> Tokenizer::tokenize(const string &text) const {
  // <- 1 2 3 4 + 3 -2
  // -> [1,2,3,4,+,3,-2]

  vector<string> tokens{};
  istringstream input(text);

  for (string token; getline(input, token, delimiter_); /*nothing to do*/) {
    tokens.push_back(token);
  }

  return tokens;
}
