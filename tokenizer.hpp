#pragma once

#include <string>
#include <vector>

class Tokenizer {
  const char delimiter_;

public:
  explicit Tokenizer(char delimiter = ' ') : delimiter_(delimiter) {}

  std::vector<std::string> tokenize(const std::string &text) const;

  virtual ~Tokenizer();
};
