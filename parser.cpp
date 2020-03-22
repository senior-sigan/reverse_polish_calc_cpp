#include "parser.hpp"

#include <memory>

#include "double_node.hpp"
#include "iostream"
#include "operator_node.hpp"
#include "utils.hpp"

using namespace std;

vector<unique_ptr<INode>> Parser::parse(const vector<string> &tokens) const {
  vector<unique_ptr<INode>> nodes{};

  for (const auto &token : tokens) {
    if (IsNumber(token)) {
      auto value = ParseDouble(token);
      nodes.push_back(make_unique<DoubleNode>(value));
      continue;
    }
    if (IsOperator(token)) {
      auto op = operations_.at(token).get();
      nodes.push_back(make_unique<OperatorNode>(op));
      continue;
    }

    std::cerr << "[ERROR] unexpected token " << token << std::endl;
    exit(-1);  // TODO: throw exception
  }

  return nodes;
}
bool Parser::IsOperator(const std::string &token) const {
  return operations_.count(token) == 1;
}
