#include "calc.hpp"
#include <iostream>
#include <stack>

using namespace std;

double Calc::eval(const string &text) const {
  auto tokens = tokenizer_->tokenize(text);
  auto nodes = parser_->parse(tokens);
  stack<double> s;
  for (auto node : nodes) {
    node->Act(s);
  }
  auto result = s.top();

  for (auto node: nodes) {
    delete node;
  }

  return result;
}
Calc::Calc(Tokenizer *tokenizer, Parser *parser)
    : tokenizer_(tokenizer), parser_(parser) {}
Calc::~Calc() {
  cout << "~Calc" << endl;
  delete tokenizer_;
  delete parser_;
}
