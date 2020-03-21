#pragma once

#include "parser.hpp"
#include "tokenizer.hpp"
#include <string>

class Calc {
  Tokenizer *tokenizer_;
  Parser *parser_;

public:
  explicit Calc(Tokenizer *tokenizer, Parser *parser);
  double eval(const std::string &text) const;
  ~Calc();
};
