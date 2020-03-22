#include "calc.hpp"

#include <stack>

using namespace std;

double Calc::eval(const string &text) const {
  auto tokens = tokenizer_->tokenize(text);
  auto nodes = parser_->parse(tokens);
  stack<double> s;
  for (auto &node : nodes) {
    node->Act(s);
  }
  auto result = s.top();

  return result;
}
Calc::Calc(std::unique_ptr<Tokenizer> tokenizer, std::unique_ptr<Parser> parser)
    : tokenizer_(std::move(tokenizer)), parser_(std::move(parser)) {}
