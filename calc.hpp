#pragma once

#include <memory>
#include <string>

#include "parser.hpp"
#include "tokenizer.hpp"

class Calc {
  std::unique_ptr<Tokenizer> tokenizer_;
  std::unique_ptr<Parser> parser_;

 public:
  Calc(std::unique_ptr<Tokenizer> tokenizer, std::unique_ptr<Parser> parser);
  double eval(const std::string &text) const;
};
